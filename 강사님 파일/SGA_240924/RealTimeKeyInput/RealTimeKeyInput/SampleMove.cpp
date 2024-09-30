#include "SampleMove.h"
#include <Windows.h> // Sleep 함수 사용을 위해 필요

SampleMove::SampleMove()
{
    input = 0;
    Run();
}

SampleMove::~SampleMove()
{
}

void SampleMove::Run()
{
    while (true)
    {
        system("cls");

        Sleep(1); // _sleep(n) : 1000분의 n초만큼 연산을 지연시킵니다.
        // 시간을 일정하게 흐르게 하면서 자동으로 진행되는 프로그래밍을 할 때 씁니다.
        // 자동 일시 정지라고 생각해주시면 됩니다.
        // * <Windows.h> 기능 포함이 필요합니다.

        if (RealTimeKeyInput::KeyPressed()) // "키를 눌렀는가?"
        {
            Move(); // input 키를 받은 후 입력 처리 (플레이어 위치 이동)
        }

        ShowMap(); // 맵과 플레이어 위치 표시
    }
}

void SampleMove::Move()
{
    input = RealTimeKeyInput::ReadKeyPressed();

    switch (input)
    {

    case 97: // 97이 나온 경우 = a

        if (playerPosX > 0) playerPosX--;
        break;

    case 77: // (+224) 화살표 오른쪽
    case 100: // 100이 나온 경우 = d

        if (playerPosX < width) playerPosX++;
        break;

    case 80: // (+224) 화살표 아래
    case 115: // 115가 나온 경우 = s

        if (playerPosY < height) playerPosY++;
        break;

    case 72: // (+224) : 화살표 위
    case 119: // 119가 나온 경우 = w

        if (playerPosY > 0) playerPosY--;
        break;

    case 224:   // 화살표인 경우

        input = RealTimeKeyInput::ReadKeyPressed();
        switch (input)
        {
        case 72: //위

            if (playerPosY > 0) playerPosY--;
            break;

        case 75: //왼쪽

            if (playerPosX > 0) playerPosX--;
            break;

        case 77: //오른쪽

            if (playerPosX < width) playerPosX++;
            break;

        case 80: //아래

            if (playerPosY < height) playerPosY++;
            break;
        }
        break;
    }
}

void SampleMove::ShowMap()
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            if (x == playerPosX && y == playerPosY)
            {
                std::cout << " ★ ";
            }
            else std::cout << " 〓 ";
        }
        std::cout << std::endl;
    }
}