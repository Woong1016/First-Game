// SGA_240809_Bingo_1_Coord.cpp

// 1 단계 : 좌표 입력으로 빙고 칸 지워 보기

#include <iostream>
#include "Header.h" // 빙고에 사용할 변수, 함수, 기타 기능을 포함


int main()
{
    srand(GetTickCount64()); // 랜덤 시드

    PrepareBoards(); //보드 준비하기 (숫자 정하기 + 뒤섞기)

    ShowIntro(); // 빙고 시작을 보여주기

    while (true) // 이후 빙고 과정 반복
    {
        system("cls");

        //위 코드로 화면 지우기 실행.
        // -> system이라는 함수를 실행해서, 'cls'라는 단어를 넣은 것.
        // -> 옛날 운영체제에서 사용하던 화면 지우기 명령어를 사용한 것

        CountBingos(); // 가장 먼저 : 빙고 반복마다 현재 빙고가 몇 줄인지 보기
                       // (0줄이라도 좋다 -> 어차피 반복의 과정)

        ShowBingoBoards(); // 빙고판 출력

        ShowGameStatus();  // 게임의 상태도 출력 (현재 빙고 줄 수라든가)

        if (IsGameOver()) break; // 게임오버인가? 그러면 반복문 종료


        GetInput(); // 입력 받기

        ApplyInput(); // 입력을 게임에 적용하기

        // -> 게임에 입력이 적용되었으니, 다음 반복 수행 시에 칸이 지워질 것
    }

    // 반복문이 종료되면 = 게임이 끝나면 게임 종료를 알려준다

    ShowOutro();

    // 이로써 main() 함수 작성은 끝.
    // 구체적인 작업은 각 함수에서 적어주면 된다
}


// 빙고 함수 내용 작성 (이를 "정의"라고 한다)

void PrepareBoards()
{
    int value = 0; // 빙고 판 준비에만 쓰이는 지역 변수
                   // 지역 변수에서 연산을 하고, 전역 변수에 넣어주면
                   // 함수가 끝났을 때, value는 사라져도 전역 변수는 남는다

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            bingoBoard[i][j] = ++value;

            // ++, -- : 원래 이름은 증감 연산자 (+= : 누적 연산자)
            // 그런데 이 연산자가 변수 이름 앞에 오면 "전치 연산자"라고 불리고
            // 뒤에 붙으면 "후치 연산자"라고 불린다
            
            // ++가 변수 이름 앞에 올 때와 뒤에 올 때의 차이
            // (전치 연산자와 후치 연산자의 차이)

            // 먼저 알아둘 사실 (우리가 이미 아는 것)
            // 1. 컴퓨터는 개발자가 변수 이름을 적으면, 그에 맞는 값을 알아낸다
            // 2. 컴퓨터는 개발자가 연산자를 적으면, 변수를 연산한다
            // 3. () 같은 기호가 없으면, 컴퓨터는 왼쪽 연산자부터 계산한다

            // 연산자가 앞에 오면, 컴퓨터는 연산자부터 먼저 대기시킨다
            // ++value : 일단 뭐가 됐든 1 올린다 -> 그 대상이 value다, 하는 뜻
            // 그러므로 ++value라고 불린 대상은 불리자마자 1 올라가고 본다

            // -> 본래 value의 초기화 값은 0이었지만, 위의 할당 식을 적용하면
            //    배열의 값은 0부터 24까지가 아니라 1부터 25까지 올라간다.

            // 연산자가 뒤에 오면, 컴퓨터는 변수부터 읽고 연산을 한다
            // value++ : 일단 변수부터 읽은 다음 -> ++을 적용해서 1 올린다
            // 그러므로 value++라고 부르는 경우, 일단 불려온 뒤 왼쪽 연산자부터
            // (즉 할당 등의 연산자가 있다면 그것부터) 먼저 수행하고,
            // 그 다음에 비로소 1을 올림으로써 연산을 마무리한다.

            // -> 만약 위의 할당 식에서 value++라고 적었더라면
            //    배열의 값은 0부터 24까지 올라갔을 것.
        }
    }

    // 위 반복문을 반복하여 배열 0-0부터 4-4까지 칸의 값을
    // 1부터 25까지로 1차 준비한다.

    // 이렇게 가공되지 않은 최초의 데이터를 원시 자료, 혹은
    // 날것 그대로의 자료라고 한다. (raw data)

    // * 고든 램지가 방송에만 나오면 소리 지르는 그 raw가 맞는다


    // 뒤이어 숫자 뒤섞기를 이 안에서 실행한다 (준비의 과정이니까)

    ShuffleNumbers();
}

void ShuffleNumbers()
{
    for (int i = 0; i < 1000; i++)
    {
        int rand_X1 = rand() % 5; // 바꿀 원본 XY 좌표
        int rand_Y1 = rand() % 5;

        int rand_X2 = rand() % 5; // 바꿀 대상 XY 좌표
        int rand_Y2 = rand() % 5;
        
        // 서로 자리 맞바꾸기
        int tmp = bingoBoard[rand_Y1][rand_X1];
        bingoBoard[rand_Y1][rand_X1] = bingoBoard[rand_Y2][rand_X2];
        bingoBoard[rand_Y2][rand_X2] = tmp;

        // 위 과정을 1000번 반복
    }
}

void ShowBingoBoards()
{
    //출력하기
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (bingoBoard[i][j] < 1)
            {
                // 빙고판에 있으면 안 되는 수가 있다 = 입력으로 지웠다
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

    // 일단은 입력을 받아두고, 적용은 다음 함수로 역할 전달

    // cin은 input아니라 어떤 변수라도 입력을 넣으면 바꿀 수 있다
    // -> 쓰고 나니까 input 변수가 ....쓸 데가 없네요...?
    //    그래도 일단 남겨는 두겠습니다.
}

void ApplyInput()
{
    // 받은 입력을 여기서 적용
    if (x < 1 || x > 5 || y < 1 || y > 5)
    {
        std::cout << "입력 범위를 벗어났습니다.";
        system("pause"); // 일시정지 (입력 오류 확인용)
    }
    else bingoBoard[y - 1][x - 1] = -1; // 여기는 -1 아니어도 됨

    // 1. 변수에 -1 연산을 한 다음, [] 안에 넣어서 순번으로 사용
    // 2. 값은 -1 말고 다른 숫자도 좋다. 아무튼 "1부터 25" 범위만 아니면 된다
    //    다만 -1 값은 게임에서 공통적으로 "없음"을 나타낼 때 자주 쓰기에 선택.
}

void CountBingos()
{
    // 빙고 줄 수 = 가로 줄 수 + 세로 줄 수 + 대각선 줄 수
    countBingo = Count_Row() + Count_Column() + Count_Diagonal();
}

int Count_Row()
{
    int result = 0; // 0부터 시작하는 가로 줄 세기 (셀 때마다 리셋)

    for (int i = 0; i < 5; i++)
    {
        if ((bingoBoard[i][0] == -1) && (bingoBoard[i][1] == -1)
            && (bingoBoard[i][2] == -1) && (bingoBoard[i][3] == -1)
            && (bingoBoard[i][4] == -1)) // ; 없는 줄바꿈은 한 줄로 친다
        {
            // 세로 순번이 똑같은 가로 0, 1, 2, 3, 4순번 칸이 모두 -1이면
            // 이 가로 줄은 모두 지워진 한 줄이다
            result++;
        }

        // -> 무식하지만, 확실한 방법. 그리고 가장 변형하기도 좋다.
        
        // 이렇게 가능한 모든 경우의 수를 무식하게 하나하나 따져 가면서
        // 이 경우가 맞느냐 아니냐를 일일이 판단해가는 것을...

        // -> "완전 탐색"이라고 한다.

        // 응용 : 값이 빙고판을 벗어난 경우, 더할수록 더 극단적인 값이 될 것
        // (* 0을 5번 더해도 0. -1이나 26 같은 숫자는 더할수록 범위 초과)

        //if (bingoBoard[i][0] + bingoBoard[i][1] + bingoBoard[i][2]
        //    + bingoBoard[i][3] + bingoBoard[i][4] == -5) // -1 x 5
        //{
        //    result++
        //}
    }

    return result;
}

int Count_Column()
{
    int result = 0; // 세로 결과 0부터 세기

    for (int i = 0; i < 5; i++)
    {
        // 가로와 같다. 같은 가로 순번에서, 모든 세로 칸.
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

    //가로 세로 순번이 같은 칸들 = 왼쪽 위에서 오른쪽 밑으로
    if ((bingoBoard[0][0] == -1) && (bingoBoard[1][1] == -1)
        && (bingoBoard[2][2] == -1) && (bingoBoard[3][3] == -1)
        && (bingoBoard[4][4] == -1))
    {
        result++;
    }

    //가로 세로 순번이 거꾸로 = 오른쪽 위에서 왼쪽 밑으로
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