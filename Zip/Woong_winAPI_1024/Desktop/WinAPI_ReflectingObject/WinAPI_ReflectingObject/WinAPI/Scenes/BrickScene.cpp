#include "Framework.h"
#include "BrickScene.h"

BrickScene::BrickScene()
{
    bricks.resize(brickAmount); // resize : 벡터 함수. 용량 확보 및 기본값 설정
                                // * 미리 용량 확보를 해둬서 매번 벡터가 움직이는
                                //   연산 시간을 줄일 수 있다.

    for (int i = 0; i < brickAmount; ++i) // 벽돌 개수만큼 반복
    {
        // 랜덤 위치
        Vector2 position = { (float)Random(250, WIN_WIDTH - 250), (float)Random(250, WIN_HEIGHT - 250) };

        // 랜덤 크기
        float edge = Random(100, 200);
        Vector2 size = { edge, edge }; // 랜덤 값을 가로 세로에 똑같이 줘서 정사각형으로
        
        bricks[i] = new Brick(position, size); // 벽돌 생성
    }
}

BrickScene::~BrickScene()
{
    // 포인터들 삭제
    for (int i = 0; i < bricks.size(); ++i)
    {
        delete bricks[i];
    }
}

void BrickScene::Update()
{
    for (int i = 0; i < bricks.size(); ++i)
    {
        bricks[i]->Update();
    }

    // 반사 판단!
    for (int i = 0; i < bricks.size(); ++i)
    {
        for (int j = 0; j < bricks.size(); ++j)
        {
            // i가 j인 경우는 제외하고 (continue)
            if (i == j) continue;

            // 두 벽돌이 부딪치면 두 벽돌 모두 반사

            Vector2 overlap = {};   // 충돌 영역 임시 계산용

            if (bricks[i]->IsRectCollision(bricks[j], &overlap))
            {
                bricks[i]->Reflect(overlap);
                // 어차피 모든 벽돌에 전수조사 중이라서 i, j에 각각 반사할 필요는 없다
            }
        }
    }
}

void BrickScene::Render(HDC hdc)
{
    for (int i = 0; i < bricks.size(); ++i)
    {
        bricks[i]->Render(hdc);
    }
}
