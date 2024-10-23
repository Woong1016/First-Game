#include "Framework.h"
#include "Ball.h"

Ball::Ball(Vector2 pos, float radius):
    Circle(pos, radius)
{
    // 속력과, 각도와, 최초 위치 정하기

    pos = { CENTER_X, CENTER_Y };   // 중간에 등장

    speed = 50.0f;  // 속력

    //angle = 0;      // 각도
    //angle = GameMath::Random(-1.0f, 1.0f);
    angle = Random(-1.0f, 1.0f); // 윗줄과 같음 (using namespace GameMath 사용중)

    // 속력에서 방향을 찾아내기
    float x = cos(angle) * speed;
    float y = -sin(angle) * speed;
    direction = { x, y };
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

    //Vector2 next;                           // 변수를 여기 만들었더니...
    //next.x = cos(angle) * speed * DELTA;    // 시간은 시간대로 걸리고
    //next.y = -sin(angle) * speed * DELTA;   // 귀찮기도 -> 그래서 멤버 변수로 승격

    // 여기서 DELTA : 시간의 변화를 나타내는 지칭어
    //                대략 0.0n 미만의 수를 나타내는 경우가 많다
    //                갱신될 때마다 변화량이 달라지기 때문에
    //                결과적으로 연산의 빈도를 일정하게 유지해주는 효과가 있다

    // 종점을 공의 위치에 반영
    // this->pos = this->pos + next;

    // -------------------------------------------------------------

    // v2 : 공 가두기. 공의 네 '십자 접점'이 창에 닿으면 튕기게

    // -> if문

    if ((this->pos.x - radius) < 0) // 원의 가장 왼쪽이 창의 왼쪽보다 작다 = 선 넘었다
    {
        // 공 방향 바꾸기 : 가로 방향 진행을 반대로
        // direction.x = direction.x * -1; // 숫자 뒤집기
        direction.x *= -1;              // 같은 코드

        // 다음 가는 방향에서 각도를 찾아낸 후 각도를 뒤집는 것도 가능 (돌아가는 방법)
        // 1. next.x, next.y 구하기
        // 2. angle = -atan(-x, y) <-
        // 3. next 또 구하기...... 번거롭긴 한데 통하긴 통한다
    }
    if ((this->pos.y - radius) < 0) // 창의 위쪽과 비교
    {
        direction.y *= -1;
    }
    if ((this->pos.x + radius) > WIN_WIDTH) // 가장 오른쪽이 창 오른쪽보다 크다 = 선 넘었다
    {
        direction.x *= -1;
    }
    if ((this->pos.y + radius) > WIN_HEIGHT) // 가장 아래쪽이 창 아래보다 크다
    {
        direction.y *= -1;
    }

    // v2 : 방향에 맞추어서 공의 위치를 조정
    this->pos = this->pos + direction * DELTA;
}