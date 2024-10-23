#include "Framework.h"
#include "Ball.h"

Ball::Ball(Vector2 pos, float radius):
    Circle(pos, radius)
{
    // 속력과, 각도와, 최초 위치 정하기

    pos = { CENTER_X, CENTER_Y };   // 중간에 등장

    speed = 200.0f;  // 속력

    angle = 0;      // 각도
}

Ball::~Ball()
{
}

void Ball::Update()
{
    // 조작을 받으면, 각도가 바뀌게
    if (KEY_PRESS(VK_LEFT)) // 왼쪽 입력 시
        angle += 5 * DELTA;
    if (KEY_PRESS(VK_RIGHT)) // 오른쪽 입력 시
        angle -= 5 * DELTA;


    // 위치 바꾸기: 각도를 반영해서

    Vector2 next;
    next.x = cos(angle) * speed * DELTA;
    next.y = -sin(angle) * speed * DELTA;

    // 여기서 DELTA : 시간의 변화를 나타내는 지칭어
    //                대략 0.0n 미만의 수를 나타내는 경우가 많다
    //                갱신될 때마다 변화량이 달라지기 때문에
    //                결과적으로 연산의 빈도를 일정하게 유지해주는 효과가 있다

    // 종점을 공의 위치에 반영
    this->pos = this->pos + next;

    if (this->pos.x >= 1200.0f)
    {
        this->pos.x = 1200.0f;
    }

    else if (this->pos.x <= 80.0f)
    {
        this->pos.x = 80.0f;
    }

    else if (this->pos.y <= 72.0f)
    {
        this->pos.y = 72.0f;
    }

    else if (this->pos.y >= 640.0f)
    {
        this->pos.y = 640.0f;
    }
    



}

void Ball::Render(HDC hdc)
{





    Circle::Render(hdc);     // 자기 자신 출력 (원으로서!)
}
