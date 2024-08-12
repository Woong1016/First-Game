#pragma once

#include <stdlib.h>
#include <Windows.h>

// 함수

void PrepareBoards();
void ShuffleNumbers();

void ShowBingoBoards();

void GetInput(int turn);     // 누구 입력인지 확인할 때 매개변수 사용
bool ValidateInput(int key); // validate : "입증, 인증" = 적절성 여부 확인
                             // 간단히 이 입력이 맞는지 아닌지 확인
                             // (범위 안인지, 중복은 아닌지)
void ApplyInput(); // 의외일지 아닐지, 칸 지우기는 누구 차례인지 몰라도 되네요.

int NextTurn(int previuosTurn);     // 플레이어 차례를 다른 쪽으로 교체

void CountBingos();

int Count_Row(int board[5][5]);     // 매개변수로 판을 주고 읽게 만들기
int Count_Column(int board[5][5]);
int Count_Diagonal(int board[5][5]);

void ShowGameStatus();

bool IsGameOver();

void ShowIntro();
void ShowOutro();

// 변수

// 플레이어 두 명에 맞추어 다른 빙고 판을 만든다
int bingoBoard_playerOne[5][5];
int bingoBoard_playerTwo[5][5];

int inputRecord[25]; // "입력 기록"이라는 이름의 배열을 준비
                     // 지운 숫자 또 지우기, 같은 실수가 있는지 확인할 때 사용

int currentTurn = 1; // 게임 차례. 각 플레이어 번호에 따라 1, 2 번갈아 사용

int input; // 입력

// x, y 변수 삭제. input에는 숫자를 입력하고 그 숫자의 칸을 지운다

// 빙고 줄 수도 두 사람에 맞추어서
int countBingo_playerOne = 0;
int countBingo_playerTwo = 0;

int countToEnd = 5;

// * 추가 테스트 전용. 입력 기록을 보고 싶다면
void TestOnly_ShowInputRecord();
