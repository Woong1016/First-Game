#pragma once

// ��� ��� �Լ� (����)
void ShowResult(int original, int opTerm, char opCode, int result);

// ������ ������ ����ϴ� �Լ��� �������
// * ���ǻ� ��� ������ �ۼ��մϴ�. (����x)

void AddPtr(int* baseTerm, int opTerm) // ���� ���� * : �޸� �ּ�
{
    int original = *baseTerm;       // ���� ���� Ȯ�ε� ������ ���ڸ� �ѹ� �� ���
                                    // (�� �̸� = �� ��ġ = ���� ���� = ���纻)
    *baseTerm = *baseTerm + opTerm; // ���� �̸��� ���� * : �ű� �ִ� ���� ��

    ShowResult(original, opTerm, '+', *baseTerm);
    // "���� �������� �纻��, ��������, �̷��� ����ߴ���, ���� �ٲ� ������ �Ǿ����"
}

void SubtractPtr(int* baseTerm, int opTerm)
{
    int original = *baseTerm;
    *baseTerm = *baseTerm - opTerm;
    ShowResult(original, opTerm, '-', *baseTerm);
}

void MultiplyPtr(int* baseTerm, int opTerm)
{
    int original = *baseTerm;
    *baseTerm = *baseTerm * opTerm;
    ShowResult(original, opTerm, '*', *baseTerm);
}

void DividePtr(int* baseTerm, int opTerm)
{
    int original = *baseTerm;
    int remains = 0; // ������
    if (opTerm != 0)
    {
        remains = *baseTerm % opTerm;
        *baseTerm = *baseTerm / opTerm;
    }
    else
    {
        std::cout << "0���� ���� �� �����ϴ�. ����� 0���� �����մϴ�." << std::endl;
        *baseTerm = 0;
    }
    ShowResult(original, opTerm, '/', *baseTerm);
    ShowResult(original, opTerm, '%', remains);
}

void ShowResult(int original, int opTerm, char opCode, int result)
{
    // �ٸ� �Լ����� ����� ����� ��¸� �ϴ� �Լ�
    // �޸𸮾� ��� �ִ� ���� Ȯ�θ� �Ǹ� �Ǵϱ� �����Ͱ� �ƴϾ �ȴ�

    std::cout << "------------------------" << std::endl;
    std::cout << opCode << " ���� ��� ���" << std::endl;
    std::cout << original << " " << opCode << " " << opTerm << " = " << result << std::endl;
    std::cout << "------------------------" << std::endl;
}

void HomeWorkSample()
{
    // ���� ���� : ������ ��Ģ���� ����� �� ����

    int hwFirst = 100;
    int hwSecond = 33;

    //hwFirst ���� ���� Ȯ��
    std::cout << "�׽�Ʈ ��� ���ڴ� " << hwFirst << std::endl;

    AddPtr(&hwFirst, hwSecond);     //���ϱ�
    MultiplyPtr(&hwFirst, hwSecond);//���ϱ�

    SubtractPtr(&hwFirst, hwSecond);//����
    DividePtr(&hwFirst, hwSecond);  //������

    // ���� �̸� �տ� & ������ : "�� �����Ͱ� ��ϵ� ��¥ �޸� �ּ� ��ġ"
    // ** �� ��° �Ű�����(������) : �� ���ڴ� �� �ٲ� �ȴ�.
    //                             ���⼭ �ʿ��� �� ���� ���� �� ��ü��.
    //                             �׷��Ƿ� ������ ������ �ƴϾ �ȴ�
    //                             (���� ������ �������� �ȴ�)

    // ����� �Լ��� ���� ����� ��� (hwFirst ���ڴ� �ٲ���°�?)
    std::cout << "�Լ� ���� ���� �� ���� ����� " << hwFirst << std::endl;
}