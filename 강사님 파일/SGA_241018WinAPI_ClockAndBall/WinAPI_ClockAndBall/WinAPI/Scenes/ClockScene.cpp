#include "Framework.h"
#include "ClockScene.h"

ClockScene::ClockScene()
{
    clock = new Clock();

}

ClockScene::~ClockScene()
{
}

void ClockScene::Update()
{
    clock->Update();
}

void ClockScene::Render(HDC hdc)
{
    clock->Render(hdc);
}
