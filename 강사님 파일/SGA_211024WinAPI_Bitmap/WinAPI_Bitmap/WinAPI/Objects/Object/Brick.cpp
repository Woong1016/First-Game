#include "Framework.h"
#include "Brick.h"

Brick::Brick(Vector2 pos, Vector2 size)
    : Rect(pos, size)
{
    // 멤버 이니셜라이저로 만들어도 되지만... (그게 더 빠르지만)
    // 일부러 굳이 한사코 여기서 확실하게 변수 설정을 하기

    isMovable = true;   // 움직이기 : 기본값은 "움직임"으로
                        // (이후 벽돌깨기 등으로 움직이면 안 된다면 false로 설정)

    angle = Random(-1.0f, 1.0f);
    
    speed = 50.0f;

    float x = cos(angle) * speed;
    float y = -sin(angle) * speed;

    direction = { x, y };

    // (옵션) 여기서 좀 더 엄밀한 계산을 하고 싶다면...
    // 바로 위쪽까지 구했던 direction은 말하자면 순수한 방향이 아니고 "다음 진행 좌표"
    // = "이 각도, 이 속력이면 지금부터 n초 뒤에 어느 위치에 있을 거냐?"

    // 그래서, 위 정보에서 속력과 같은 부분을 싹 빼고, 비율만을 남길 수도 있다.
    // -> 순수하게 방향만 남기는 것.

    // 이 때, 가능한 연산 방법은 1. 위 계산에서 speed를 빼는 것 (간편, 단순, 약간의 오류 위험)
    // 2. 계산 할 거 다 한 다음에... 나오는 direction 벡터의 길이를 1로 만들어버리기

    // -> 길이를 1로 = 속력을 1로 고정함으로써 속력에 대한 부가 정보를 거세하는 것.
    // -> 이 연산을 "정규화"라고 한다 (정규 벡터와 동등하게 만든다는 뜻)

    // * 정규 벡터란? : 넓은 의미로는 '길이 1인 벡터', 좁은 의미로는 좌표 구성 값이
    //                 단 하나만, -1 혹은 1이고, 나머지가 모두 0인 벡터

    // 공식보다는 개념과 응용이 중요하므로, 개념에 친숙해집시다.

    // 그래서... 위에 만든 direction을 정규화하기!

    direction.Normalize();  // <- 수행 후, 벡터가 정규화

    // -> 정규화가 되고 나면, 이 벡터는 다시 어떻게 쓰느냐면.....속력을 도로 곱해서 씁니다 ㅋㅋㅋ
    //    그래도 정보를 나누어서 정확히 쓰는 건 중요합니다. (생각보다 조금 더)
}

Brick::~Brick()
{
}

void Brick::Update()
{

    // 방향 x 속력 x 델타로 움직이기
    this->pos = this->pos + direction * speed * DELTA;

    // -> 나중에 speed가 바뀌어도 상관없이 direction에 맞추어서 유연하게 벽돌 움직이기 가능

    if (KEY_PRESS(VK_UP)) // 확인하기 위한 속력 조정 코드
    {
        speed += 1.0f * DELTA;
    }
    if (KEY_PRESS(VK_DOWN))
    {
        speed -= 1.0f * DELTA;
    }

    // 반사...를 하려니 다른 벽돌들의 존재가 필요하네?
    // 반사를 했을 때 적용하기 위한 추가 호출용 함수 작성 후 준비


    // 공 가두기 (창에....)

    if (Left() < 0) // 왼쪽 비교
    {
        direction.x *= -1;
    }
    if (Top() < 0) // 창의 위쪽과 비교
    {
        direction.y *= -1;
    }
    if (Right() > WIN_WIDTH) // 오른쪽 비교
    {
        direction.x *= -1;
    }
    if (Bottom() > WIN_HEIGHT) // 가장 아래쪽이 창 아래보다 크다
    {
        direction.y *= -1;
    }
}

void Brick::Reflect(Vector2 overlapSize)
{
    // 반사가 일어날 경우 (반사 판정은 벽돌들이 객체로 나오는 다른 외부 클래스에서)
    // ...이를테면 풀 매니저나, 씬이라든가?

    // 1. 먼저 해당 충돌을 감지하는 곳에서 overlapSize를 받으면서 충돌 함수를 수행

    // 2. 그런 다음, 이 함수로 overlapSize를 넘겨주고 연산을 시작

    if (overlapSize.x > overlapSize.y)
    {
        //-> 충돌 영역이 양옆으로 퍼졌다 = 교집합이 가로 모양이다 =
        //   두 사각형의 위치 관계는 위아래다 (위아래로 부딪쳤다)

        // 방향을 위아래로 뒤집을 필요가 있다
        direction.y *= -1;
    }
    else 
    {
        // 좌우로 부딪친 상황
        // 물론... 완전 모서리에 45도 각도로 부딪쳤다.... 같은 경우도 원래 있겠지만
        // 그런 행운의 사건은 여기서는 그냥 무시한다

        // 방향 좌우 반전
        direction.x *= -1;
    }
}
