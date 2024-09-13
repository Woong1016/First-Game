// SGA_240809_Bingo_4n5_VersusAI.cpp

// 4, 5단계 : 2인용을 기반으로 컴퓨터와 붙는 빙고
//           단계 적용은 헤더에서 확인해주세요.

// * 그런데 웬 AI? -> 비디오 게임의 AI는 현실에서와 의미가 다릅니다.

//   비디오 게임에서는 "프로그램 속에서 목적을 가지고 규칙적인 판단을 내리며
//   자신의 판단을 실행하는 가상의 주체"를 통칭해서 인공지능이라고 부릅니다.

//   목적을 가지고 : 의도와 목표가 뚜렷하다
//   규칙적인 판단 : 프로그래밍에 조건문을 사용했고, 예측이 가능하다 (중요)
//   실행한다 : 판단을 내린 바를 이루기 위해 직접 움직인다 (숫자든 캐릭터든)

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

        if (!ValidateInput(input))
        {
            std::cout << "이미 지운 숫자입니다. 다시 입력하세요." << std::endl;
            system("pause");
            continue;
        }

        ApplyInput(input); // 플레이어 입력에 의한 숫자 적용

        // 여기까지 플레이어 (1, 2인용과 같음)
        
        // --------------------
        // 지금부터 컴퓨터

        ComputerTurn(); // main()에서는 이거 하나면 끝

        // 컴퓨터 차례 진행 후, 다시 처음부터 반복
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
            bingoBoard_player[i][j] = ++value;
            bingoBoard_computer[i][j] = value;

            inputRecord[i * 5 + j] = 0;
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

        int tmp = bingoBoard_player[rand_Y1][rand_X1];
        bingoBoard_player[rand_Y1][rand_X1] = bingoBoard_player[rand_Y2][rand_X2];
        bingoBoard_player[rand_Y2][rand_X2] = tmp;

        rand_X1 = rand() % 5;
        rand_Y1 = rand() % 5;

        rand_X2 = rand() % 5;
        rand_Y2 = rand() % 5;

        tmp = bingoBoard_computer[rand_Y1][rand_X1];
        bingoBoard_computer[rand_Y1][rand_X1] = bingoBoard_computer[rand_Y2][rand_X2];
        bingoBoard_computer[rand_Y2][rand_X2] = tmp;
    }
}

void ShowBingoBoards()
{
    std::cout << "플레이어 빙고 판" << std::endl;
    std::cout << "-------------------" << std::endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (bingoBoard_player[i][j] < 1)
            {
                std::cout << "■" << "\t";
            }
            else std::cout << bingoBoard_player[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "-------------------" << std::endl;
    std::cout << "컴퓨터 빙고 판" << std::endl;
    std::cout << "-------------------" << std::endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (bingoBoard_computer[i][j] < 1)
            {
                std::cout << "■" << "\t";
            }
            else std::cout << bingoBoard_computer[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void GetInput()
{
    std::cout << "지우려는 숫자를 입력해주세요 :";
    std::cin >> input;
}

bool ValidateInput(int key)
{
    for (int i = 0; i < 25; i++)
    {
        if (key == inputRecord[i])
        {
            return false;
        }
    }

    for (int i = 0; i < 25; i++)
    {
        if (inputRecord[i] == 0)
        {
            inputRecord[i] = key;
            break;
        }
    }

    return true;
}

void ApplyInput(int key)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (key == bingoBoard_player[i][j])
            {
                bingoBoard_player[i][j] = -1;
            }

            if (key == bingoBoard_computer[i][j])
            {
                bingoBoard_computer[i][j] = -1;
            }
        }
    }
}

// -------여기서부터 컴퓨터 진행 관련 함수들

void ComputerTurn()
{
    // 컴퓨터 행동 수행
    switch (difficulty)
    {
    case 0:
        ComputerMove_Easy(); // 0 : 쉬움
        break;

    case 1:
        ComputerMove_Hard(); // 1 : 어려움
        break;
    }

    // 어떤 과정을 거쳤든, aiChoice에는 값이 들어가도록 할 것이다.
    // 그러므로 그 값을 보여주고, 빙고 판에서도 숫자 칸을 지운다

    std::cout << "컴퓨터가 숫자 " << aiChoice << "를 지웁니다." << std::endl;
    ApplyInput(aiChoice); // 컴퓨터가 찍은 숫자를 넣고 칸을 지운다

    system("pause"); // 플레이어가 과정을 볼 수 있게 일시정지
}

// 난이도별 컴퓨터가 진행하는 함수

// 쉬운 경우는 아래
void ComputerMove_Easy()
{
    while (true) // "될 때까지 반복하는 반복문"
    {
        // 목적 : 중복 없는 컴퓨터 다음 랜덤 값 찾기 (1~25 사이)

        aiChoice = rand() % 25; // 0 ~ 24
        aiChoice++;             // +1

        if (ValidateInput(aiChoice)) break;
        
        // 컴퓨터가 고른 값이 중복이 아니면 종료
        // 중복이면 중복 아닐 때까지 무한 반복
    }
}

// 컴퓨터 (어려움) 진행은 길어서 파일 밑에 따로 적겠습니다. 길어요.
//------여기서부터는 2인용과 비슷------

void CountBingos()
{
    countBingo_player = Count_Row(bingoBoard_player)
                      + Count_Column(bingoBoard_player)
                      + Count_Diagonal(bingoBoard_player);

    countBingo_computer = Count_Row(bingoBoard_computer)
                        + Count_Column(bingoBoard_computer)
                        + Count_Diagonal(bingoBoard_computer);
}

int Count_Row(int board[5][5])
{
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
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "플레이어의 빙고 줄 수 : " << countBingo_player << std::endl;
    std::cout << "컴퓨터의 빙고 줄 수 : " << countBingo_computer << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

bool IsGameOver()
{
    return (countBingo_player >= countToEnd ||
        countBingo_computer >= countToEnd);
}

void ShowIntro()
{
    std::cout << "빙고 (컴퓨터 대전) 게임을 시작합니다." << std::endl;
    std::cout << std::endl;

    std::cout << "원하시는 난이도에 해당하는 숫자를 입력해주세요." << std::endl;
    std::cout << "<< 1 : 쉬움 ｜ 2 : 어려움 >>" << std::endl;
    std::cout << std::endl;

    std::cout << "내 선택 : ";
    std::cin >> difficulty;
    
    // 당연한 이야기지만 꼭 input이 아니라도 입력으로 수정할 수 있습니다.
    
    // 실제 난이도 변수는 0이 쉬움, 1이 어려움이므로
    difficulty--; // 입력에서 1 낮추기

    system("pause");
}

void ShowOutro()
{
    std::cout << "이로써 빙고 게임을 종료합니다." << std::endl;
    std::cout << std::endl;

    std::cout << "플레이어의 빙고 줄 수 : " << countBingo_player << std::endl;
    std::cout << "컴퓨터의 빙고 줄 수 : " << countBingo_computer << std::endl;
    std::cout << std::endl;

    if (countBingo_player > countBingo_computer)
    {
        std::cout << "플레이어가 이겼습니다." << std::endl;
    }
    else if (countBingo_player < countBingo_computer)
    {
        std::cout << "컴퓨터가 이겼습니다." << std::endl;
    }
    else
    {
        std::cout << "점수가 같아 비겼습니다." << std::endl;
    }
    std::cout << std::endl;

    std::cout << "모두 고생하셨습니다!";
}

// -------컴퓨터 (어려움) 진행 함수


void ComputerMove_Hard()
{
    // 다음 변수 준비

    int value = 0;          // 가중치 (weight value)
    int highestValue = 0;   // 가중치 중에 제일 높은 가중치

    // 원리

    // 1. 가로, 세로, 대각선 줄마다 "지금 줄에서 몇 칸이 지워졌는지" 확인
    
    // 2. 해당 줄에 속한 칸에 "가중치"를 부여 (위의 value 변수)
    // 3. 중복되는 가중치는 각 칸에 모두 부여
    //    (예 : 0-0 좌표는 가로 1행, 세로 1열, 대각선이 갖는 가중치 모두 합산)
    
    // 4. 합산된 가중치 중에서 가장 높은 칸을 선택 (위의 highestValue 변수)
    
    // 5. 가장 높은 가중치를 가진 칸이 여러 곳이면, 랜덤이 아닌 위치지향으로 선택
    //    (비슷한 위치에 있는 곳을 의도적으로 계속 골라 중복이 터지기 쉽게 함)
    //    (** 마침 반복문이 왼쪽 위부터 오른쪽 아래로 돌므로 자연스럽게 지향 발생)
    
    // 6. 해당 칸을 아직 안 지웠으면 지우고, 지웠으면 다음 높은 가중치 칸 선택

    //----본 계산 시작

    // 평가용 판 (가중치 기록판)에 부여한 숫자를 0으로 초기화
    // (계산할 때마다 0에서부터 다시 가중치 계산)
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            aiAssessment[i][j] = 0;
        }
    }

    //가로줄 가중치 탐색
    for (int i = 0; i < 5; ++i)
    {
        value = 0; // 가중치도 계산할 때마다 0으로 초기화

        for (int j = 0; j < 5; ++j)
        {
            if (bingoBoard_computer[i][j] == -1) // 지워진 칸이면
            {
                value++; // 가중치 +1
            }
        }
        // 가로줄 탐색이 끝날 때마다 계산된 가중치를
        // i(y) 좌표를 공유하는 모든 칸에 부여
        aiAssessment[i][0] += value; // 중복 합산을 위한 += 연산
        aiAssessment[i][1] += value;
        aiAssessment[i][2] += value;
        aiAssessment[i][3] += value;
        aiAssessment[i][4] += value;
    }

    // 세로줄 탐색
    for (int i = 0; i < 5; ++i)
    {
        value = 0;

        for (int j = 0; j < 5; ++j)
        {
            // 아래 조건에서 [j][i] 순서에 주목
            // -> i(x) 좌표를 공유하는 j(y) 좌표 찾기가 목적
            if (bingoBoard_computer[j][i] == -1)
            {
                value++;
            }
        }
        // 역시 계산한 가중치를 세로줄 모든 칸에 부여
        // : i(x) 좌표가 같은 모든 칸에 += 연산
        aiAssessment[0][i] += value;
        aiAssessment[1][i] += value;
        aiAssessment[2][i] += value;
        aiAssessment[3][i] += value;
        aiAssessment[4][i] += value;
    }

    //대각선 검사 1
    value = 0;
    for (int i = 0; i < 5; ++i) // 5번 반복해서
    {
        // 가로 세로 좌표가 i로 같다 = 왼쪽 위부터 오른쪽 아래
        if (bingoBoard_computer[i][i] == -1)
        {
            value++;
        }
    }
    // 가로 세로가 같은 모든 칸에 가중치
    aiAssessment[0][0] += value;
    aiAssessment[1][1] += value;
    aiAssessment[2][2] += value;
    aiAssessment[3][3] += value;
    aiAssessment[4][4] += value;

    //대각선 검사 2
    value = 0;
    for (int i = 0; i < 5; ++i)
    {
        // 가로 순서가 뒤에서 세었을 때 세로와 같다
        // = 오른쪽 위부터 왼쪽 아래
        if (bingoBoard_computer[i][(4 - i)] == -1)
        {
            value++;
        }
    }
    // 가로 세로를 더해서 4가 되는 모든 칸에 가중치
    aiAssessment[0][4] += value;
    aiAssessment[1][3] += value;
    aiAssessment[2][2] += value;
    aiAssessment[3][1] += value;
    aiAssessment[4][0] += value;

    // 여기까지 연산하면 빙고판을 AI 시점에서 보았을 때,
    // "어디를 찍어야 빙고가 빨리 나올까"에 대한 참고자료가 나온다
    // -> 무조건 숫자 높은 칸을 찍는 것이 유리하다
    //    (이미 지워진 칸이 많은 줄에 속해 있으므로)

    // 그러므로 평가표에서 가장 가중치가 높은 칸을 찾는다

    // 좌표를 기록하기 위한 x, y 변수
    int x = 0;
    int y = 0;

    //평가표 돌려보기
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (aiAssessment[i][j] > highestValue && // 가중치 갱신
                bingoBoard_computer[i][j] != -1) // 아직 안 지운 칸
            {
                highestValue = aiAssessment[i][j]; // 기록 갱신
                x = j; // 최대 가중치가 있는 칸의 x, y 정보 기록하기
                y = i;
            }
        }
    }
    // 반복문이 끝나면 컴퓨터에게 다음 자료가 준비된다
    // 1. 현재 내 승산 (얼마나 칸이 몰려서 지워져 있는가)
    // 2. 그 승산이 제일 높은 칸의 위치 (다음 번엔 어디를 찍을까)

    // 그리고 3. 그 위치에 실제로 적혀 있는 빙고판 속 숫자
    // 그 숫자를 x, y 좌표로 찍어주면 된다

    aiChoice = bingoBoard_computer[y][x];

    // 해당 위치의 숫자를 찾아서 iaChoice로 정해주면 된다
}