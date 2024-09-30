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

    int playerPosX = 0; // �÷��̾� ��ġ
    int playerPosY = 0;

    int width = 20;     // �� ȭ���� ����
    int height = 12;    // �� ȭ���� ����
};

