#include "SampleMove.h"
#include <Windows.h> // Sleep �Լ� ����� ���� �ʿ�

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

        Sleep(1); // _sleep(n) : 1000���� n�ʸ�ŭ ������ ������ŵ�ϴ�.
        // �ð��� �����ϰ� �帣�� �ϸ鼭 �ڵ����� ����Ǵ� ���α׷����� �� �� ���ϴ�.
        // �ڵ� �Ͻ� ������� �������ֽø� �˴ϴ�.
        // * <Windows.h> ��� ������ �ʿ��մϴ�.

        if (RealTimeKeyInput::KeyPressed()) // "Ű�� �����°�?"
        {
            Move(); // input Ű�� ���� �� �Է� ó�� (�÷��̾� ��ġ �̵�)
        }

        ShowMap(); // �ʰ� �÷��̾� ��ġ ǥ��
    }
}

void SampleMove::Move()
{
    input = RealTimeKeyInput::ReadKeyPressed();

    switch (input)
    {

    case 97: // 97�� ���� ��� = a

        if (playerPosX > 0) playerPosX--;
        break;

    case 77: // (+224) ȭ��ǥ ������
    case 100: // 100�� ���� ��� = d

        if (playerPosX < width) playerPosX++;
        break;

    case 80: // (+224) ȭ��ǥ �Ʒ�
    case 115: // 115�� ���� ��� = s

        if (playerPosY < height) playerPosY++;
        break;

    case 72: // (+224) : ȭ��ǥ ��
    case 119: // 119�� ���� ��� = w

        if (playerPosY > 0) playerPosY--;
        break;

    case 224:   // ȭ��ǥ�� ���

        input = RealTimeKeyInput::ReadKeyPressed();
        switch (input)
        {
        case 72: //��

            if (playerPosY > 0) playerPosY--;
            break;

        case 75: //����

            if (playerPosX > 0) playerPosX--;
            break;

        case 77: //������

            if (playerPosX < width) playerPosX++;
            break;

        case 80: //�Ʒ�

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
                std::cout << " �� ";
            }
            else std::cout << " �� ";
        }
        std::cout << std::endl;
    }
}