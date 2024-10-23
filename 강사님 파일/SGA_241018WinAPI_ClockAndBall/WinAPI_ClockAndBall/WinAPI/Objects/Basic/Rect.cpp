#include "Framework.h"

Rect::Rect(Vector2 pos, Vector2 size)
    : GameObject(pos), size(size)
{
}

Rect::Rect(float left, float top, float right, float bottom)
{
    pos.x = (left + right) * 0.5f;
    pos.y = (top + bottom) * 0.5f;

    size.x = abs(right - left);
    size.y = abs(bottom - top);
}

// 사각형에서 Render 함수를 호출하면 아래 코드대로 화면에 나오게 된다
void Rect::Render(HDC hdc)
{
    //if (!isActive) // isActive 변수가 거짓이면 : 그냥 그리지 말라
       // return;

    //위치 기준, 위치에서 크기(의 반)만큼 상하좌우 위치에 변을 만들고
    //이어서 직사각형을 그린다
    int left = (int)(pos.x - size.x * 2.3f);
    int right = (int)(pos.x + size.x * 2.3f);
    int top = (int)(pos.y - size.y * 1.5f);
    int bottom = (int)(pos.y + size.y * 1.5f);

    //Rectangle 함수 실행
    Rectangle(hdc, left, top, right, bottom);
}

bool Rect::IsCollision(const Vector2& point) const
{
    if (!isActive)
        return false;

    if (point.x > Left() && point.x < Right())
    {
        if (point.y > Top() && point.y < Bottom())
            return true;
    }

    return false;
}

bool Rect::IsCollision(const Rect* rect) const
{
    if (!isActive) return false;
    if (!rect->isActive) return false;

    // 사각형의 충돌 원리 : 수평 위치에서 서로가 영역을 침범했는데
    // (다른 말로, "내 왼쪽이 니 오른쪽보다 더 왼쪽")
    // 동시에 수직 관계에서도 서로가 영역을 침범했다...면 충돌이 된 상황

    if (rect->Left() < Right() && rect->Right() > Left())
    {
        if (rect->Top() < Bottom() && rect->Bottom() > Top())
        {
            return true;
        }
    }

    return false;
}

bool Rect::IsCollision(const Circle* circle) const
{
    // 사각형과 원의 충돌

    // 1. 사각형의 경계 변을 기준으로 한 십자 범위에 원이 있으면
    //    원의 반지름과 사각형의 가로세로 크기를 기준으로 판단

    // 2. 십자 범위 밖이면, 사각형의 네 꼭짓점과 원의 중심과의 거리를
    //    원의 반지름과 비교해서 판단
    // ---------------------------------------------------

    // 1. 비활성화 시 수행 안 함
    if (!isActive) return false;
    if (!circle->isActive) return false;

    // 2. 십자 범위 판별 후 비교
    if (circle->pos.x > Left() && circle->pos.x < Right() || //원의 중심이 사각형 가로 안, 혹은
        circle->pos.y > Top() && circle->pos.y < Bottom())  // 원의 중심이 사각형 세로 안
    {
        // 두 조건 중 하나만 충족해도 십자 범위 안으로 들어온 것

        // 이 때 : 사각형의 가로세로 크기(의 반)와 원의 반지름 비교

        Vector2 size(circle->GetRadius() * 2, circle->GetRadius() * 2);
        // x2를 할 경우 원을 감싸는 큰 사각형을 만들어서 통짜 계산 가능
        // -> 통짜 계산? : 원의 4방향 어느 쪽에 상관없이 적용 가능한 반지름 범위 생성
        
        // 원의 가로세로 크기를 나타내는 범위 생성
        Rect tempSize(circle->pos, size);   // 원의 위치, 원의 '크기'

        //이 사각형과 만들어진 '범위'가 충돌하는지 본다
        // = 원의 반지름이 사각형 안으로 들어오는지 본다

        if (IsCollision(&tempSize)) // 위에 있었던 사각형 충돌 함수 이용
            return true;

        else return false;  // 충돌을 안 했으면 그냥 끝
    }

    // * 여기서 원의 중심 거리에서 다시 반지름을 내어서 상하좌우 좌표
        //   + 사각형에서 이어지는 변의 길이 계산 혹은 점 충돌....도 가능

        // -> 지금 작성한 방법은 꼼수지만, 코드의 수가 적다는 것이 장점
        // -> 게임 개발에서 쓰이는 히트박스의 원리

        // 원이 십자 범위였으면 위 코드에서 충돌 여부가 완전히 계산 후, 함수 종료
        // -> 여기까지 코드가 오면, 원이 십자 범위 밖에 있다는 뜻

        // 2. 원이 십자 범위 밖에 있는 경우

        // 사각형의 네 꼭짓점 위치 확인
        // Vector2 edge1, edge2, edge3, edge4; // <- 작성 가능

    Vector2 edge[4]; // <- 이것도 가능
    edge[0] = { Left(), Top() };    // 좌상
    edge[1] = { Left(), Bottom() };    // 좌하
    edge[2] = { Right(), Top() };    // 우상
    edge[3] = { Right(), Bottom() };    // 우하

    //for (int i = 0; i < 4; ++i)
    //{
    //    if (circle->IsCollision(edge[i])) return true;
    //    // 점충돌 확인 후, 충돌이 맞으면 맞다고 반환하고 종료
    //}

    // 여기서 새로운 문법 추가
    for (Vector2 point : edge) // 위쪽 반복문과 기능이 똑같다
    {
        if (circle->IsCollision(point)) return true;
    }

    // for (자료형 name : array) 문법
    // -> array라는 배열을 구성하는 원소를 임시로 name이라고 명명한 후,
    //    배열 속에 있는 모든 원소, 즉 name을 모두 돌아가면서 검사한다
    //    즉, 배열의 크기가 정확히 뭔지 몰라도 알아서 배열을 반복한다

    // 이것을 for each 코드라고 한다
    // -> 속도가 느린 편, 배열에 어떤 원소가 있는지, 자료형을 정확히 알아야 한다
    //    그래서 콘솔 단계나 엔진 단계에서는 그렇게 선호되지는 않고
    //    다만 윈API, DX 단계에서는 어느 정도 쓰이므로 이 참에 경험해봅시다.

    // 여기까지 완전히 왔으면 전혀 충돌하지 않은 것
    return false;
}
