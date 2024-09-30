#pragma once
#include "Baverage.h"

// ���� Ŭ����

class Beer : public Baverage
{
public:

    // �ڽ� Ŭ���� ������ ����� :
    // ���ݰ� �̸��� ���� �� (���⼭ ����, �̸� : �θ� Ŭ�������� �ʿ��� ��)
    // ��� �̴ϼȶ��������� �θ��� �����ڸ� �����Ѵ� (�θ� ���� ����)
    Beer(int cost, std::string name) : Baverage(cost, name) {}
    ~Beer() {}

    // ���ָ� ���� �� (�ۼ����� ������� (����õ))
    void Drink()
    {
        // �Լ� �ۼ��� ���� �ؼ��� Coke Ŭ�������� Ȯ��

        Baverage::Drink(); // �θ�μ� ���� ����� ���� ���ְ�
        std::cout << name << "�� ������ ������� �ö�ɴϴ�." << std::endl;
    }

    void Color()
    {
        // ���� �Լ��� �������̵��Ѵٰ� �ؼ� ���ð� �ݵ�� �ʿ��� �� �ƴϴ�
        // virtual, override ���� ���� (Coke Ŭ�������� �ڼ��� ���� ����)

        std::cout << name << "�� Ȳ�ݻ��Դϴ�." << std::endl;
    }
};

