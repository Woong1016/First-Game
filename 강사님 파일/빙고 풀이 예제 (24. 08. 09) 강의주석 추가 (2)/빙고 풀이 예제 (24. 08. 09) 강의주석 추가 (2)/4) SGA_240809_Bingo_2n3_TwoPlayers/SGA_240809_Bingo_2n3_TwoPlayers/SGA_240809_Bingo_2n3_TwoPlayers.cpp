// SGA_240809_Bingo_2n3_TwoPlayers.cpp

// 2단계 및 3단계 : 숫자로 칸을 지우고, 2인용으로 진행합니다.

#include <iostream>
#include "Header.h"

int main()
{
    // 함수를 활용하면 1인용이 2인용으로 바뀌어도
    // main() 쪽에서 수정이 적어서 편하다 : 함수의 효과

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

        // 2인용 수정사항
        GetInput(currentTurn); // 차례가 돌아온 플레이어를 기준으로 입력 진행
        
        //if (ValidateInput(input) == false) // 입력 검사 틀렸다 = 중복
        
        if (!ValidateInput(input)) // 윗줄과 똑같은 의미 (! 연산자)
        {
            std::cout << "이미 지운 숫자입니다. 다시 입력하세요." << std::endl;
            system("pause");
            continue; // 아래 코드는 무시하고 다시 진행 (차례 바꿈 없음)
        }

        ApplyInput();

        currentTurn = NextTurn(currentTurn); // 다음 차례를 계산해서 바꾸기

        // 테스트 전용 : 입력 기록을 보고 싶을 때
        TestOnly_ShowInputRecord();
    }

    ShowOutro();
}

void PrepareBoards()
{
    // 원시 데이터를 이번에는 두 사람 분량으로 만듭니다. 그냥 똑같아요.

    int value = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // 1~25 까지 들어가는 배열이 2개
            bingoBoard_playerOne[i][j] = ++value;
            bingoBoard_playerTwo[i][j] = value; // 여기선 ++가 없습니다.

            // 2인용에게도 ++value를 줬다면 1인용은 홀수만
            // 2인용은 짝수만 있는 이상한 빙고가 됐을 겁니다.
            
            // 그리고 중복방지 배열도 이 참에 모든 칸을 0으로 채워줍니다.

            // 1차원 배열에 값을 줘야 하므로 i와 j를 연산해서 1차원 순번을 구하기
            inputRecord[i * 5 + j] = 0; // value 대신 고정된 값 0
                                        // 여기에 0 외의 숫자가 들어가면
                                        // 해당 숫자는 입력한 적이 있는 겁니다.

            // i * 5 + j : i, j의 범위(0-0부터 4-4)를 5진법인 것처럼 계산.
            // j가 0~4까지 한 바퀴 돌 때마다 i가 0, 5, 10, 15, 20으로 바뀐다
            // -> 이런 계산을 사용해서도 0부터 24까지의 숫자를 만들 수 있다

            // -> 앞으로도 나오는 연산이므로 미리 보고 익숙해지자
        }
    }

    ShuffleNumbers();
}

void ShuffleNumbers()
{
    for (int i = 0; i < 1000; i++)
    {
        // 섞는 것도 두 사람 분량.

        // 일단 한 사람 섞어주고...

        int rand_X1 = rand() % 5;
        int rand_Y1 = rand() % 5;

        int rand_X2 = rand() % 5;
        int rand_Y2 = rand() % 5;

        int tmp = bingoBoard_playerOne[rand_Y1][rand_X1];
        bingoBoard_playerOne[rand_Y1][rand_X1] = bingoBoard_playerOne[rand_Y2][rand_X2];
        bingoBoard_playerOne[rand_Y2][rand_X2] = tmp;

        // 다음 사람 것도 섞어줍니다.

        rand_X1 = rand() % 5; // 랜덤 숫자를 새로 냅니다.
        rand_Y1 = rand() % 5; // 이미 만든 변수를 또 쓰는 거라 선언이 아닌 수정

        rand_X2 = rand() % 5;
        rand_Y2 = rand() % 5;

        tmp = bingoBoard_playerTwo[rand_Y1][rand_X1];
        bingoBoard_playerTwo[rand_Y1][rand_X1] = bingoBoard_playerTwo[rand_Y2][rand_X2];
        bingoBoard_playerTwo[rand_Y2][rand_X2] = tmp;
    }
}

void ShowBingoBoards()
{
    // 2인용이니까 1인용보다는 보기 자세하게.

    std::cout << "1번 플레이어 빙고 판" << std::endl;
    std::cout << "-------------------" << std::endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (bingoBoard_playerOne[i][j] < 1)
            {
                std::cout << "■" << "\t";
            }
            else std::cout << bingoBoard_playerOne[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "-------------------" << std::endl;
    std::cout << "2번 플레이어 빙고 판" << std::endl;
    std::cout << "-------------------" << std::endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (bingoBoard_playerTwo[i][j] < 1)
            {
                std::cout << "■" << "\t";
            }
            else std::cout << bingoBoard_playerTwo[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void GetInput(int turn)
{
    // 사실 진짜 다른 건 없다 (어차피 입력은 키보드로 하고, 컴퓨터가 받는다)
    // (*치는 사람이 누군지 컴퓨터가 알 바도 아니다)
    // 그렇지만 중요한 건 화면에 누구의 차례인지 보는 사람이 알기 쉽게 해주는 것
    // -> 진짜 필요해서 넣은 기능이 아니라, 사람이 편하려고 넣는 것

    if (turn == 1) // 1번 차례
    {
        std::cout << "1번 플레이어 차례입니다." << std::endl;
    }
    else // 2번 차례
    {
        std::cout << "2번 플레이어 차례입니다." << std::endl;
    }

    std::cout << "지우려는 숫자를 입력해주세요 :";
    std::cin >> input;

    // 1단계에서는 만들고 안 쓰던 input 변수를 여기서 사용합니다.

    // * 이 함수의 논리적 진행에 매개변수는 사실 필요 없습니다.
    // currentTurn이 헤더에 있는 전역변수여도 돼요.
    // 그래도 이렇게 매개변수를 쓰는 이유는... 1. 그냥 복습,
    // 2. 이후, 이렇게 입력을 받는 함수가 다른 곳에서 쓰일 수도 있음에 대비,
    //    ...하기 위해서입니다.
}

// 입력이 중복인지 확인하는 변수 (적절성 인증 절차)
bool ValidateInput(int key)
{
    for (int i = 0; i < 25; i++) //입력 기록 배열 확인
    {
        if (key == inputRecord[i]) // 숫자가 입력된 적 있으면
        {
            // 결과는 실패 (중복이 걸렸으니까)

            return false; // 더 볼 것 없다. 당장 반환하고 중단
        }
    }

    // 위 반복문이 끝나서 여기까지 온 거면 인증은 성공
    // -> 이것도 결국은 완전탐색

    // 성공으로 함수를 마치기 전에, 이번 입력을 배열에 기록합니다.
    for (int i = 0; i < 25; i++)
    {
        if (inputRecord[i] == 0) // 제일 처음 보이는 빈 자리에
        {
            inputRecord[i] = key; // 입력을 기록하고, 다음 검사에 씁니다.
            break; // 반복문 중단 (25개 칸에 똑같은 숫자가 들어가는 것 방지)
        }
    }

    // 그리고 인증 성공 결과를 컴퓨터와 공유합니다 (반환하기)

    return true;
}

void ApplyInput()
{
    // * 숫자로 칸 지우기의 원리
    //   -> 그냥 반복문으로 칸을 모두 확인해서, 입력한 숫자면 지웁니다.
    //      넵, 그게 답니다. 결국, 빙고의 알고리즘은 곧 완전 탐색인 거죠.

    // 그리고 1인용이든 아니든 반복문은 한 번만 돌리면 충분합니다. 어차피...

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // ...숫자 칸 지우는 건 둘 다 해야 되거든요.

            // 1번 판을 조사해서 숫자가 맞으면 칸을 지웁니다. (여기서는 -1)
            if (input == bingoBoard_playerOne[i][j])
            {
                bingoBoard_playerOne[i][j] = -1;
            }

            // 2번 판도 지웁니다.
            if (input == bingoBoard_playerTwo[i][j])
            {
                bingoBoard_playerTwo[i][j] = -1;
            }
        }
    }
}

int NextTurn(int previuosTurn)
{
    int next = previuosTurn % 2; // 2인 경우 0로 바꾸기
    next += 1;                   // 2는 (0이 된 다음) 1로, 1은 2로
    return next;                 // 의도 표현을 위한 += 연산자 사용
}

void CountBingos()
{
    // 빙고 세기를 다른 함수로 쪼갰던 이유. 그리고 매개변수를 쓰는 이유
    // 플레이어마다 빙고를 셀 때 함수를 불러낸 다음
    // () 안에 빙고판을 인수로 주기만 하고, 결과를 더하면 되도록

    // 똑같은 식에, 인수만 다르게 넣어주면 두 사람의 빙고 줄 수를 알 수 있다.

    countBingo_playerOne = Count_Row(bingoBoard_playerOne)
                         + Count_Column(bingoBoard_playerOne)
                         + Count_Diagonal(bingoBoard_playerOne);

    countBingo_playerTwo = Count_Row(bingoBoard_playerTwo)
                         + Count_Column(bingoBoard_playerTwo)
                         + Count_Diagonal(bingoBoard_playerTwo);
}

int Count_Row(int board[5][5])
{
    // 1인용과 완전히 같은 코드.
    // 단, 보드 판이 헤더의 것이 아닌 매개변수로 받은 자료라는 점만 다르다

    int result = 0;

    for (int i = 0; i < 5; i++)
    {
        if ((board[i][0] == -1) && (board[i][1] == -1)
            && (board[i][2] == -1) && (board[i][3] == -1)
            && (board[i][4] == -1))
        {
            result++;
        }
    }

    return result;
}

int Count_Column(int board[5][5])
{
    int result = 0;

    for (int i = 0; i < 5; i++)
    {
        if ((board[0][i] == -1) && (board[1][i] == -1)
            && (board[2][i] == -1) && (board[3][i] == -1)
            && (board[4][i] == -1))
        {
            result++;
        }
    }

    return result;
}

int Count_Diagonal(int board[5][5])
{
    int result = 0;

    if ((board[0][0] == -1) && (board[1][1] == -1)
        && (board[2][2] == -1) && (board[3][3] == -1)
        && (board[4][4] == -1))
    {
        result++;
    }

    if ((board[4][0] == -1) && (board[3][1] == -1)
        && (board[2][2] == -1) && (board[1][3] == -1)
        && (board[0][4] == -1))
    {
        result++;
    }

    return result;
}

void ShowGameStatus()
{
    // 표시도 두 사람 분량으로 늘었을 뿐, 1인용과 동일
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "1번 참여자의 빙고 줄 수 : " << countBingo_playerOne << std::endl;
    std::cout << "2번 참여자의 빙고 줄 수 : " << countBingo_playerTwo << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

bool IsGameOver()
{
    // 조건이 두 사람 분량으로 늘었으므로 반영
    // 조건을 여기서 수정하면 main()에서 쓸 때는 수정이 필요 없다.
    return (countBingo_playerOne >= countToEnd ||
            countBingo_playerTwo >= countToEnd);
}

void ShowIntro()
{
    std::cout << "빙고 (2인용) 게임을 시작합니다." << std::endl;

    system("pause");
}

void ShowOutro()
{
    // 2인용은 1인용보다 결과 정보가 자세하다
    // 각 플레이어의 빙고 줄 수, 누가 이겼는가 등의 정보가 추가

    std::cout << "이로써 빙고 게임을 종료합니다." << std::endl;
    std::cout << std::endl;

    std::cout << "1번 참여자의 빙고 줄 수 : " << countBingo_playerOne << std::endl;
    std::cout << "2번 참여자의 빙고 줄 수 : " << countBingo_playerTwo << std::endl;
    std::cout << std::endl;

    if (countBingo_playerOne > countBingo_playerTwo) // 1번 승
    {
        std::cout << "1번 참여자가 이겼습니다." << std::endl;
    }
    else if (countBingo_playerOne < countBingo_playerTwo) // 2번 승
    {
        std::cout << "2번 참여자가 이겼습니다." << std::endl;
    }
    else // 동점. 비겼음
    {
        std::cout << "두 참여자의 점수가 같아 비겼습니다." << std::endl;
    }
    std::cout << std::endl;

    std::cout << "모두 고생하셨습니다!";
}

void TestOnly_ShowInputRecord()
{
    std::cout << "(테스트 전용) 지금까지의 입력 :";

    for (int i = 0; i < 25; i++)
    {
        if (inputRecord[i] > 0)
        {
            if (i > 0) std::cout << ",";
            std::cout << " " << inputRecord[i];
        }
    }

    std::cout << std::endl;

    system("pause");
}