#pragma once

// ���⼭ ��ǻ�ʹ� 2������ �ΰ������� ����մϴ�.

// '����' �ܰ� (���� 4�ܰ�) : ��ǻ�ʹ� �ڱ� ���ʿ� ���� ���ڸ� �������� ���մϴ�.
//                           ���� �·��� ĭ�� ��ġ, � �¿�˴ϴ�.
//                           ��, �� ��쿡�� �ߺ� �Է��� ���� �ʽ��ϴ�. (�������)

// '�����' �ܰ� (���� 5�ܰ�) : ��ǻ�ʹ� �ڱ� ���ʿ� �ڱ� ���� ���� ���մϴ�.
//                            ��� ����� ���� ������ �� ��, Ȥ�� �ߺ��� ����
//                            ����� �غ��� ��ġ�� ���� �����ؼ� ����ϴ�.

#include <stdlib.h>
#include <Windows.h>

// �Լ�

void PrepareBoards();
void ShuffleNumbers();

void ShowBingoBoards();

void GetInput(); // �Ű����� "����"�� ���� �ʿ� �����ϴ�. ��ǻ�� �ൿ�� �ڵ��̴ϱ�.
bool ValidateInput(int key);
void ApplyInput(int key); // ��� �� ���ʿ� ���ڸ� �� �� ����!
                          // �÷��̾� �� ��, ��ǻ�Ͱ� �� ��.

void ComputerTurn(); // ��ǻ���� ���ʴ� ������ ��������

void ComputerMove_Easy(); // ���� �ܰ� ���� ����
void ComputerMove_Hard(); // ����� �ܰ� ���� ����

void CountBingos();

int Count_Row(int board[5][5]);
int Count_Column(int board[5][5]);
int Count_Diagonal(int board[5][5]);

void ShowGameStatus();

bool IsGameOver();

void ShowIntro();
void ShowOutro();

// ����

// �÷��̾�� ��ǻ���� ������
int bingoBoard_player[5][5];
int bingoBoard_computer[5][5];

int inputRecord[25];

int input;    // �� �Է� = �� ����
int aiChoice; // "��ǻ���� ������..."

// * �÷��̾� �Է� �Ŀ� �ݵ�� ��ǻ�Ͱ� ���ڸ� ���Ƿ�
// �⺻������ input�� �ٽ� �ᵵ �½��ϴٸ�
// ��ǻ�Ͱ� ĭ�� ���� �� ��, ���������� �����Ϸ���
// ������ �̸��� ���� ������ �ִ� �͵� �����ϴ�.

// �׸��� ���ο� �迭 �ۼ� (�����ǰ� �Ȱ��� ũ���)
int aiAssessment[5][5]; // ai �������� ���� ������ ��
                        // ai �������� �� ĭ�� ���� ��,
                        // ��� ĭ�� ���� �·��� ���ٰ� ����������
                        // �ڷ�� ��Ȯ�� ����� ���� ��.

// ��? (assessment)
// -> ��ü�� ���� �������� �Ǵ� �ٰſ� ����� ���մϴ�.
//    '���ڸ� ���� ���� ��'�� ������ �����ϴ� ��ü���,
//    '�ǿ��� ��� ���� ���� �ɱ�'�� �����ϴ� ����
//    �ٷ� ���� �ǹ�. �� ��ǻ�͵� �̱�� ���� �־�����
//    �����ϰ�, ����� ����ϱ� ���� ������ ������ִ� ��.

int countBingo_player = 0;
int countBingo_computer = 0;

int countToEnd = 5;

// ���̵��� �÷��̾ ������ �� �ֵ��� �ϴ� ����
int difficulty; // 0 : ����, 1 : �����