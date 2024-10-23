#include "Framework.h"

#include "Scenes/CollisionScene.h"
#include "Scenes/BallScene.h"
#include "Scenes/BrickScene.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()    
{    
    Init();

    //scene = new CollisionScene();
    // scene = new BallScene();
    scene = new BrickScene();
}

GameManager::~GameManager()
{
    delete scene;

    Timer::Delete();
    Keyboard::Delete();
}

void GameManager::Init()
{
    hdc = GetDC(hWnd);

    hBackDC = CreateCompatibleDC(hdc);
    hBackBitmap = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);
    SelectObject(hBackDC, hBackBitmap);    

    Timer::Get();
    Keyboard::Get();
}

void GameManager::Update()
{
    Timer::Get()->Update();
    Keyboard::Get()->Update();

    scene->Update();
}

void GameManager::Render()
{
    PatBlt(hBackDC, 0, 0, WIN_WIDTH, WIN_HEIGHT, WHITENESS);

    GetLocalTime(&st);
    wstring strr = to_wstring(st.wHour);
    TextOut(hdc, 0, 250, strr.c_str(), strr.length());

    //InvalidateRect(hWnd, nullptr, false);
    scene->Render(hBackDC);

    Timer::Get()->Render(hBackDC);

    BitBlt(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT,
        hBackDC, 0, 0, SRCCOPY);
}
