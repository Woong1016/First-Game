#include "Framework.h"
#include "Circle.h"

Circle::Circle(Vector2 pos, float radius)
    : GameObject(pos) // 생성자는 부모 클래스 만드는 것부터
    , radius(radius)  // 그리고 반지름 설정하기
{
    // 생성하면 원 정보가 만들어진다
}

void Circle::Render(HDC hdc)
{
    // 원 출력 함수

    if (!isActive) return;  // 비활성화 시 출력하지 않음

    int left = (int)(pos.x - radius);   // "원은 중심에서 끝까지의 거리가 모두 같다"
    int right = (int)(pos.x + radius);
    int top = (int)(pos.y - radius);
    int bottom = (int)(pos.y + radius);

    // 위 정보로 '타원'을 만들면 된다 (중심에서 끝까지 거리가 똑같은 타원 = 원)
    Ellipse(hdc, left, top, right, bottom);
}

// 원의 충돌 (원과 다른 그림과의 겹침) 판정

bool Circle::IsCollision(const Vector2& point) const
{
    if (!isActive) return false; // 비활성화 시 연산 생략 ("충돌 아님")

    // 점 충돌 : 점과 원의 중심 간 거리를 재어, 길이가 반지름과 비교해서 어떤지
    
    //float x = pos.x - point.x;  // pos가 더 왼쪽이면 -가 나오겠지만 괜찮다
    //float y = pos.y - point.y;  // 어차피 제곱할 거니까 (- x - = +)
    //
    //float distance = sqrt(x * x + y * y);   //sqrt : 제곱근(루트) 구하기

    // 위 식을 미리 다른 곳에 준비해뒀다가 호출해도 된다
    // * 여기 프레임워크에도 비슷한 기능이 있다
    float distance = (point - pos).Length();
    // * 두 벡터(Vector2)는 +, - 계산이 가능하다
    //   벡터의 뺄셈 : 위치의 경우 거리 관계, 이동의 경우 경유의 방향과 힘의 크기
    // * 결과는 같은 벡터다 = . 연산자로 들어가서 함수 호출이 가능하다

    // 찾아낸 거리가 반지름보다 짧으면 : 원 어디에 있든 분명 경계선 안에 있는 것
    return distance <= radius;

}

bool Circle::IsCollision(const Rect* rect) const
{
  // 원과 사각형의 충돌... 

	//... 에 대한 코드가 사각형에 다 있지 않은가?
	// 그럼 원 입장에서 뭐 하러 일일이 또 따로 적어서 계산하는가?

	// 그냥 사각형에게 떠 넘겨도 되지 않을까?

	return rect->IsCollision(this); // 계산해라! 짬처리
}

bool Circle::IsCollision(const Circle* circle) const
{
    if (!isActive) return false;            // 비활성화 시 연산 생략
    if (!circle->isActive) return false;    // 매개변수 활성화도 살펴보기

    // 원과 원이 충돌하는 것을 판단하는 기준?
    // = 두 원의 중심의 거리를 보면 된다.
    // 이 거리가 두 원의 반지름 합보다 짧으면 충돌

    float distance = (circle->pos - pos).Length();

    return distance < (radius + circle->radius);
}
