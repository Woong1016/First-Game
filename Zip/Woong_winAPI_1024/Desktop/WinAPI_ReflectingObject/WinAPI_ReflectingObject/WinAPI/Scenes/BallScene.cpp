#include "Framework.h"
#include "BallScene.h"

BallScene::BallScene()
{
    Vector2 origin = { CENTER_X, CENTER_Y };
    ball = new Ball(origin, 100.0f);
}

BallScene::~BallScene()
{
    delete ball;
}

void BallScene::Update()
{
    ball->Update();
}

void BallScene::Render(HDC hdc)
{
    ball->Render(hdc);
}
