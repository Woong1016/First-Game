#pragma once

#include <stdlib.h>
#include <Windows.h>

// �Լ�

void PrepareBoards();
void ShuffleNumbers();

void ShowBingoBoards();

void GetInput(int turn);     // ���� �Է����� Ȯ���� �� �Ű����� ���
bool ValidateInput(int key); // validate : "����, ����" = ������ ���� Ȯ��
                             // ������ �� �Է��� �´��� �ƴ��� Ȯ��
                             // (���� ������, �ߺ��� �ƴ���)
void ApplyInput(); // �ǿ����� �ƴ���, ĭ ������ ���� �������� ���� �ǳ׿�.

int NextTurn(int previuosTurn);     // �÷��̾� ���ʸ� �ٸ� ������ ��ü

void CountBingos();

int Count_Row(int board[5][5]);     // �Ű������� ���� �ְ� �а� �����
int Count_Column(int board[5][5]);
int Count_Diagonal(int board[5][5]);

void ShowGameStatus();

bool IsGameOver();

void ShowIntro();
void ShowOutro();

// ����

// �÷��̾� �� �� ���߾� �ٸ� ���� ���� �����
int bingoBoard_playerOne[5][5];
int bingoBoard_playerTwo[5][5];

int inputRecord[25]; // "�Է� ���"�̶�� �̸��� �迭�� �غ�
                     // ���� ���� �� �����, ���� �Ǽ��� �ִ��� Ȯ���� �� ���

int currentTurn = 1; // ���� ����. �� �÷��̾� ��ȣ�� ���� 1, 2 ������ ���

int input; // �Է�

// x, y ���� ����. input���� ���ڸ� �Է��ϰ� �� ������ ĭ�� �����

// ���� �� ���� �� ����� ���߾
int countBingo_playerOne = 0;
int countBingo_playerTwo = 0;

int countToEnd = 5;

// * �߰� �׽�Ʈ ����. �Է� ����� ���� �ʹٸ�
void TestOnly_ShowInputRecord();
