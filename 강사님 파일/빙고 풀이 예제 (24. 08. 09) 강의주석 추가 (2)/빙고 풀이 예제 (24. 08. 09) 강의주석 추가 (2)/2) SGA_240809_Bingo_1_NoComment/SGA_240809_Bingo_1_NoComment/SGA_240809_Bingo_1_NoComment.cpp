// SGA_240809_Bingo_1_NoComment.cpp

// SGA_240809_Bingo_1_Coord.cpp 파일을 주석 없이 적은 것
// -> 코드만 참조할 때 써보세요.

#include <iostream>
#include "Header.h"

int main()
{
    srand(GetTickCount64());

    PrepareBoards();

    ShowIntro();

    while (true)
    {
        system("cls");

        CountBingos();

        ShowBingoBoards();

        ShowGameStatus();

        if (IsGameOver()) break;

        GetInput();
        ApplyInput();
    }

    ShowOutro();

}

void PrepareBoards()
{
    int value = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            bingoBoard[i][j] = ++value;
        }
    }

    ShuffleNumbers();
}

void ShuffleNumbers()
{
    for (int i = 0; i < 1000; i++)
    {
        int rand_X1 = rand() % 5;
        int rand_Y1 = rand() % 5;

        int rand_X2 = rand() % 5;
        int rand_Y2 = rand() % 5;

        int tmp = bingoBoard[rand_Y1][rand_X1];
        bingoBoard[rand_Y1][rand_X1] = bingoBoard[rand_Y2][rand_X2];
        bingoBoard[rand_Y2][rand_X2] = tmp;
    }
}

void ShowBingoBoards()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (bingoBoard[i][j] < 1)
            {
                std::cout << "■" << "\t";
            }
            else std::cout << bingoBoard[i][j] << "\t";
        }
        std::cout << std::endl << std::endl;
    }
}

void GetInput()
{
    std::cout << "지우려는 가로 좌표 (1-5) :";
    std::cin >> x;

    std::cout << "지우려는 세로 좌표 (1-5) :";
    std::cin >> y;
}

void ApplyInput()
{
    if (x < 1 || x > 5 || y < 1 || y > 5)
    {
        std::cout << "입력 범위를 벗어났습니다.";
        system("pause");
    }
    else bingoBoard[y - 1][x - 1] = -1;
}

void CountBingos()
{
    countBingo = Count_Row() + Count_Column() + Count_Diagonal();
}

int Count_Row()
{
    int result = 0;

    for (int i = 0; i < 5; i++)
    {
        if ((bingoBoard[i][0] == -1) && (bingoBoard[i][1] == -1)
            && (bingoBoard[i][2] == -1) && (bingoBoard[i][3] == -1)
            && (bingoBoard[i][4] == -1))
        {
            result++;
        }
    }

    return result;
}

int Count_Column()
{
    int result = 0;

    for (int i = 0; i < 5; i++)
    {
        if ((bingoBoard[0][i] == -1) && (bingoBoard[1][i] == -1)
            && (bingoBoard[2][i] == -1) && (bingoBoard[3][i] == -1)
            && (bingoBoard[4][i] == -1))
        {
            result++;
        }
    }

    return result;
}

int Count_Diagonal()
{
    int result = 0;

    if ((bingoBoard[0][0] == -1) && (bingoBoard[1][1] == -1)
        && (bingoBoard[2][2] == -1) && (bingoBoard[3][3] == -1)
        && (bingoBoard[4][4] == -1))
    {
        result++;
    }

    if ((bingoBoard[4][0] == -1) && (bingoBoard[3][1] == -1)
        && (bingoBoard[2][2] == -1) && (bingoBoard[1][3] == -1)
        && (bingoBoard[0][4] == -1))
    {
        result++;
    }

    return result;
}

bool IsGameOver()
{
    return countBingo >= countToEnd;
}

void ShowIntro()
{
    std::cout << "빙고 게임을 시작합니다." << std::endl;

    system("pause");
}

void ShowOutro()
{
    std::cout << "이로써 빙고 게임을 종료합니다." << std::endl;
    std::cout << "빙고 줄 수 : " << countBingo << std::endl;
    std::cout << std::endl;

    std::cout << "고생하셨습니다!";
}

void ShowGameStatus()
{
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "현재 빙고 줄 수 : " << countBingo << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}