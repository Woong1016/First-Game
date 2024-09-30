#pragma once
#include <iostream>
#include "RealTimeKeyInput.h"

class SampleMove
{
public :
    SampleMove();
    ~SampleMove();

private:
    void Run();

    void Move();
    void ShowMap();

    int input;

    int playerPosX = 0; // 플레이어 위치
    int playerPosY = 0;

    int width = 20;     // 맵 화면의 가로
    int height = 12;    // 맵 화면의 세로
};

