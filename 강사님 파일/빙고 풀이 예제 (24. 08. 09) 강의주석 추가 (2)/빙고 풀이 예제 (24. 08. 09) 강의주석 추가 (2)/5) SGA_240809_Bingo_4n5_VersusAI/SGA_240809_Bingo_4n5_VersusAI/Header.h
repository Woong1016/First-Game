#pragma once

// 여기서 컴퓨터는 2종류의 인공지능을 사용합니다.

// '쉬움' 단계 (과제 4단계) : 컴퓨터는 자기 차례에 지울 숫자를 랜덤으로 정합니다.
//                           따라서 승률은 칸의 배치, 운에 좌우됩니다.
//                           단, 이 경우에도 중복 입력은 하지 않습니다. (예측대상)

// '어려움' 단계 (과제 5단계) : 컴퓨터는 자기 차례에 자기 판을 보고 평가합니다.
//                            어디를 지우면 가장 빠르게 한 줄, 혹은 중복이 될지
//                            계산을 해보고 위치를 직접 지정해서 지웁니다.

#include <stdlib.h>
#include <Windows.h>

// 함수

void PrepareBoards();
void ShuffleNumbers();

void ShowBingoBoards();

void GetInput(); // 매개변수 "차례"는 이제 필요 없습니다. 컴퓨터 행동은 자동이니까.
bool ValidateInput(int key);
void ApplyInput(int key); // 대신 한 차례에 숫자를 두 번 넣죠!
                          // 플레이어 한 번, 컴퓨터가 한 번.

void ComputerTurn(); // 컴퓨터의 차례는 별도의 과정으로

void ComputerMove_Easy(); // 쉬운 단계 숫자 고르기
void ComputerMove_Hard(); // 어려운 단계 숫자 고르기

void CountBingos();

int Count_Row(int board[5][5]);
int Count_Column(int board[5][5]);
int Count_Diagonal(int board[5][5]);

void ShowGameStatus();

bool IsGameOver();

void ShowIntro();
void ShowOutro();

// 변수

// 플레이어와 컴퓨터의 빙고판
int bingoBoard_player[5][5];
int bingoBoard_computer[5][5];

int inputRecord[25];

int input;    // 내 입력 = 내 선택
int aiChoice; // "컴퓨터의 선택은..."

// * 플레이어 입력 후에 반드시 컴퓨터가 숫자를 고르므로
// 기본적으로 input을 다시 써도 맞습니다만
// 컴퓨터가 칸을 직접 고를 때, 직관적으로 이해하려면
// 별도의 이름을 가진 변수가 있는 것도 좋습니다.

// 그리고 새로운 배열 작성 (빙고판과 똑같은 크기로)
int aiAssessment[5][5]; // ai 시점에서 보는 빙고판 평가
                        // ai 시점에서 각 칸을 봤을 때,
                        // 어느 칸이 제일 승률이 높다고 생각할지를
                        // 자료로 정확히 만들어 놓은 것.

// 평가? (assessment)
// -> 실체에 대한 행위자의 판단 근거와 결론을 말합니다.
//    '숫자를 적은 빙고 판'이 실제로 존재하는 실체라면,
//    '판에서 어디를 찍어야 빙고가 될까'를 예측하는 것이
//    바로 평가의 의미. 즉 컴퓨터도 이기기 위해 애쓰도록
//    예측하고, 결과를 기록하기 위한 변수를 만들어주는 것.

int countBingo_player = 0;
int countBingo_computer = 0;

int countToEnd = 5;

// 난이도를 플레이어가 선택할 수 있도록 하는 변수
int difficulty; // 0 : 쉬움, 1 : 어려움