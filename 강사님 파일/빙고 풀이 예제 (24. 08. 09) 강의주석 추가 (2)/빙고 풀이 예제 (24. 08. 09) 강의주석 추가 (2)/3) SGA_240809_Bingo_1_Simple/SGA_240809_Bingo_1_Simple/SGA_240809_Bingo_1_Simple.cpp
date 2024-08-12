// SGA_240809_Bingo_1_Simple.cpp

#include <iostream>

// 랜덤용 기능 포함하기
#include <stdlib.h>
#include <Windows.h>

int main()
{
    // 변수 만들기
    int bingoBoard[5][5];

    int input;

    int x;
    int y;

    int countBingo = 0;
    int countToEnd = 5;

    // 빙고판 최초 준비
    {
        int value = 0; // {} 속 {}에서만 쓰이는 지역 변수
        
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                bingoBoard[i][j] = ++value;
                
                // 전치 연산자 = 1부터 올리고, 그 다음에 할당.
                // (자세한 설명은 원본 _Coord 파일을 봐주세요)
            }
        }
    }

    // 빙고 판 섞기
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
    
    // 게임 시작 안내
    std::cout << "빙고 게임을 시작합니다." << std::endl;
    system("pause");

    // 반복문 (게임 반복)
    while (true)
    {
        system("cls");

        // 입력을 받기 전에, 일단 빙고 개수부터 세어보기
        // (반복시마다 수행 : 빙고가 조건 수를 충족하면 종료)
        
        countBingo = 0; // 일단 초기화 진행 (0에서부터 다시 세어보기)

        //가로 세기
        for (int i = 0; i < 5; i++)
        {
            if ((bingoBoard[i][0] == -1) && (bingoBoard[i][1] == -1)
                && (bingoBoard[i][2] == -1) && (bingoBoard[i][3] == -1)
                && (bingoBoard[i][4] == -1))
            {
                countBingo++;
            }
        }

        //세로 세기
        for (int i = 0; i < 5; i++)
        {
            if ((bingoBoard[0][i] == -1) && (bingoBoard[1][i] == -1)
                && (bingoBoard[2][i] == -1) && (bingoBoard[3][i] == -1)
                && (bingoBoard[4][i] == -1))
            {
                countBingo++;
            }
        }

        //대각선 세기
        if ((bingoBoard[0][0] == -1) && (bingoBoard[1][1] == -1)
            && (bingoBoard[2][2] == -1) && (bingoBoard[3][3] == -1)
            && (bingoBoard[4][4] == -1))
        {
            countBingo++;
        }
        if ((bingoBoard[4][0] == -1) && (bingoBoard[3][1] == -1)
            && (bingoBoard[2][2] == -1) && (bingoBoard[1][3] == -1)
            && (bingoBoard[0][4] == -1))
        {
            countBingo++;
        }

        // 다 센 결과와 현재의 빙고 판을 출력하기
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

        // 빙고 줄 개수가 정해둔 숫자 이상이면 입력 받을 필요 없이 종료
        if (countBingo >= countToEnd) break;

        // 아직 종료가 안 됐으면 입력 받기 진행
        std::cout << "지우려는 가로 좌표 (1-5) :";
        std::cin >> x;

        std::cout << "지우려는 세로 좌표 (1-5) :";
        std::cin >> y;

        // 입력이 범위에 들어와 있으면 적용, 아니면 오류
        if (x < 1 || x > 5 || y < 1 || y > 5)
        {
            std::cout << "입력 범위를 벗어났습니다.";
            system("pause");
        }
        else bingoBoard[y - 1][x - 1] = -1;

        // 입력이 적용된 (칸이 지워진) 판은 다음 반복에서 출력
        // -> 이후 과정 반복
    }

    // 게임 종료 안내
    std::cout << "이로써 빙고 게임을 종료합니다." << std::endl;
    std::cout << "빙고 줄 수 : " << countBingo << std::endl;
    std::cout << std::endl;

    std::cout << "고생하셨습니다!";
}