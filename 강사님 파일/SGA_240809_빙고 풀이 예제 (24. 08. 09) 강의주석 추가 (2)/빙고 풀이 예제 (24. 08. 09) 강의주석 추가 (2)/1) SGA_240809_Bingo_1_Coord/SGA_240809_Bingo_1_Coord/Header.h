#pragma once

// �� : #include �ڵ嵵 ������� ���� ��,
// �� ����� main()�� �ִ� cpp���� �����ϸ�
// ��� ����� �� ���� ������ �� �ֽ��ϴ�.

#include <stdlib.h>
#include <Windows.h>

//----------------------------------

// ���� ����� ���=�Լ���

void PrepareBoards();   // ���� �� �غ��ϱ�
void ShuffleNumbers();  // �� ���� ���� �ڼ���

void ShowBingoBoards(); // ���� �� ����ϱ�

void GetInput();        // �Է� �ޱ�
void ApplyInput();      // �Է¿� ���� ĭ �����

void CountBingos();     // ���� ���� ���� �Ʒ� ������ �����ϱ�
int Count_Row();        // �κ� �� ���� : ����
int Count_Column();     // �κ� �� ���� : ����
int Count_Diagonal();   // �κ� �� ���� : �밢��

void ShowGameStatus();  // ���� ������ ���� �����ֱ�

bool IsGameOver();      // ������ �������� Ȯ���ϱ�

void ShowIntro();       // ���� ���� �˸���
void ShowOutro();       // ���� ���� �˸���

// ���� ����� �ڷ�=������

int bingoBoard[5][5];   // ���� ��. ũ��� 5x5

int input;              // �÷��̾ �Է��� ����

int x;                  // x, y ��ǥ.
int y;

int countBingo = 0;     // ���� �� �� (���� ���� 0)
int countToEnd = 5;     // ������ ��ġ�� ���� ���� �� ��. �⺻�� 5