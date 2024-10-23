#include "Framework.h"
#include "BallScene.h"

BallScene::BallScene()
{
    
    Vector2 origin = { CENTER_X, CENTER_Y };

    ball = new Ball(origin, 75);


 


}

BallScene::~BallScene()
{
    // 소멸에서 만들어야 되는 거
    // -> 이 씬이 끝났다 = 이 안에 있는 데이터는 더 이상 안 쓴다

    // 그러므로
    delete ball; // 이 메모리를 컴퓨터가 맘대로 써도 된다고 가르쳐준다

    // -> 그래야 나중에 씬이 많은 게임에서도 컴퓨터가 속도를 유지할 수 있다!

}

void BallScene::Update()
{

    ball->Update();
}

void BallScene::Render(HDC hdc)
{
    
    ball->Render(hdc);

}
    
