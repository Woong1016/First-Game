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
    if (!isActive) // isActive 변수가 거짓이면 : 그냥 그리지 말라
        return;

    //위치 기준, 위치에서 크기(의 반)만큼 상하좌우 위치에 변을 만들고
    //이어서 직사각형을 그린다
    int left = (int)(pos.x - size.x * 0.5f);
    int right = (int)(pos.x + size.x * 0.5f);
    int top = (int)(pos.y - size.y * 0.5f);
    int bottom = (int)(pos.y + size.y * 0.5f);

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
    return false;
}
