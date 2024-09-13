#pragma once

// 팁 : #include 코드도 헤더에서 적은 후,
// 그 헤더를 main()이 있는 cpp에서 포함하면
// 모든 기능을 한 번에 포함할 수 있습니다.

#include <stdlib.h>
#include <Windows.h>

//----------------------------------

// 빙고에 사용할 기능=함수들

void PrepareBoards();   // 빙고 판 준비하기
void ShuffleNumbers();  // 판 위의 숫자 뒤섞기

void ShowBingoBoards(); // 빙고 판 출력하기

void GetInput();        // 입력 받기
void ApplyInput();      // 입력에 따라 칸 지우기

void CountBingos();     // 빙고 줄을 세어 아래 변수에 적용하기
int Count_Row();        // 부분 줄 세기 : 가로
int Count_Column();     // 부분 줄 세기 : 세로
int Count_Diagonal();   // 부분 줄 세기 : 대각선

void ShowGameStatus();  // 현재 게임의 상태 보여주기

bool IsGameOver();      // 게임이 끝났는지 확인하기

void ShowIntro();       // 게임 시작 알리기
void ShowOutro();       // 게임 종료 알리기

// 빙고에 사용할 자료=변수들

int bingoBoard[5][5];   // 빙고 판. 크기는 5x5

int input;              // 플레이어가 입력할 변수

int x;                  // x, y 좌표.
int y;

int countBingo = 0;     // 빙고 줄 수 (최초 값은 0)
int countToEnd = 5;     // 게임을 마치기 위한 빙고 줄 수. 기본값 5