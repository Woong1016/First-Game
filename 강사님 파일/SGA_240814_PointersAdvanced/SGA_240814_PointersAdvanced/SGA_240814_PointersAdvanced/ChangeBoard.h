#pragma once


// 2���� �迭 : �Ʒ�ó�� ������ ���� �־��.
int board[5][5] =
{                           // ū �迭 {} �ӿ� �ٽ� ���� �迭 {}
    { 11, 12, 13, 14, 15 }, // �� ���� �迭 �ϳ��� [0][0]���� [0][4]�����Դϴ�.
    { 21, 22, 23, 24, 25 }, // [1][0]���� [1][4]����
    { 31, 32, 33, 34, 35 }, // [2][0]���� [2][4]����
    { 41, 42, 43, 44, 45 }, // [3][0]���� [3][4]����
    { 51, 52, 53, 54, 55 }, // [4][0]���� [4][4]����
};

// �迭 �ٲٱ�... �׷��� �Ű������� ���� ����.
void ChangeArrayBatchTo(int from[5][5], int targetValue)
{
    // from �迭�� ��� ĭ�� ���� targetValue�� �ٲ������
    // * batch : ����, ���. �ùֿ����� "�� ���� ����ϱ�(�ϰ�ó��)"�� ��Ī

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
    std::cout << "�迭�� ����մϴ�." << std::endl;

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
    // argument : �μ� (�Ű������� ���ǵ� �ڸ��� ������ ���� ������)

    ShowArrayValue(board); // ���� ������ ��

    ChangeArrayBatchTo(board, 7); // ������ ��� ĭ�� 7�� ��ü

    ShowArrayValue(board); // �ٽ� ����ؼ� ����
}