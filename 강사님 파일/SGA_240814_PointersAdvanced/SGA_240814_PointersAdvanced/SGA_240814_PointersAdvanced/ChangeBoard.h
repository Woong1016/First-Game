#pragma once


// 2차원 배열 : 아래처럼 선언할 수도 있어요.
int board[5][5] =
{                           // 큰 배열 {} 속에 다시 작은 배열 {}
    { 11, 12, 13, 14, 15 }, // 이 작은 배열 하나가 [0][0]부터 [0][4]까지입니다.
    { 21, 22, 23, 24, 25 }, // [1][0]부터 [1][4]까지
    { 31, 32, 33, 34, 35 }, // [2][0]부터 [2][4]까지
    { 41, 42, 43, 44, 45 }, // [3][0]부터 [3][4]까지
    { 51, 52, 53, 54, 55 }, // [4][0]부터 [4][4]까지
};

// 배열 바꾸기... 그런데 매개변수를 재료로 쓰는.
void ChangeArrayBatchTo(int from[5][5], int targetValue)
{
    // from 배열의 모든 칸의 값을 targetValue로 바꿔버리기
    // * batch : 더미, 덩어리. 플밍에서는 "한 번에 계산하기(일괄처리)"를 지칭

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            from[i][j] = targetValue;
        }
    }
}

void ShowArrayValue(int target[5][5])
{
    std::cout << "배열을 출력합니다." << std::endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << target[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void TestArrayArguments()
{
    // argument : 인수 (매개변수로 정의된 자리에 실제로 넣은 데이터)

    ShowArrayValue(board); // 원래 보드의 값

    ChangeArrayBatchTo(board, 7); // 보드의 모든 칸을 7로 교체

    ShowArrayValue(board); // 다시 출력해서 보기
}