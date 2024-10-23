#include "Framework.h"

SpawnObject::SpawnObject()
{
    isActive = false;
}

SpawnObject::~SpawnObject()
{
    Destroy();
}

void SpawnObject::Update()
{
    if (!isActive) return;

    //playTime += DELTA;
    //
    //if (playTime >= lifeTime)
    //    Destroy();
}

void SpawnObject::Render(HDC hdc)
{
    if (!isActive) return;

    SelectObject(hdc, hBrush);
    // SelectObject : hBrush 브러시를 선택하는 함수
    // 이걸 선택을 해주고 나서, 그 다음에 물체를 그리면
    // 비로소 선택하기 전에 설정했던 브러시 정보에 따라 물체가 그려지게 된다
    // = 브러시는 만든다고 끝이 아니고, 선택까지 해야 최종 그리기가 수행된다

    Rect::Render(hdc);
}

void SpawnObject::Spawn()
{
    if (isActive) return;

    isActive = true;

    // 랜덤 값에 의해 변수를 정해서 위치, 크기를 바꾸게 한 다음 나타낸다
    // 여기서 사용된 Random : rand() 함수를 좀 더 쉽게 쓰게 만든 프레임워크 함수

    lifeTime = Random(MIN_LIFE_TIME, MAX_LIFE_TIME);
    playTime = 0.0f;
    
    size.x = Random(MIN_SIZE, MAX_SIZE);
    size.y = Random(MIN_SIZE, MAX_SIZE);

    pos.x = Random(size.x * 0.5f, WIN_WIDTH - size.x * 0.5f);
    pos.y = Random(size.y * 0.5f, WIN_HEIGHT - size.y * 0.5f);

    int r = Random(0, 255);
    int g = Random(0, 255);
    int b = Random(0, 255);

    hBrush = CreateSolidBrush(RGB(r, g, b));
    // 브러시에 대해 사용자가 지시를 호출하는 코드
    // CreateSolidBrush : 단일 색상을 준비하는 함수.
    // 매개변수는 윈도우가 미리 정한 색상 이름, 혹은 RGB 매크로
    // 여기서는 RGB 매크로가 쓰였다

    // 이렇게 브러시가 만들어지고 나면, 다시 나중 코드에서 선택된 후에
    // 실질적인 효력이 나오게 된다 (Render 함수에서 상술)
}

void SpawnObject::Destroy()
{
    if (hBrush == nullptr)
        return;

    isActive = false;

    DeleteObject(hBrush);
}
