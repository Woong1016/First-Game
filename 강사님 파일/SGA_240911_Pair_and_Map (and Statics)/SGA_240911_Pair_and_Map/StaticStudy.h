#pragma once
#include <iostream> // ��¿�

static int a = 0;
// int a = 0; // �̰� ������ �� �ǰ�

// �̷��� ���������� ���� ���� ���� ������ �ֻ��� �켱������ �� �𸥴�

void DynamicVarTest() // ���� ���� �����ϱ�
{
    int num = 0; // ���� ����

    for (int i = 0; i < 10; ++i) // 10�� �ݺ��ϴ� ����
    {
        num++; // ���� 1�� �ø���
        std::cout << num << std::endl; // ���� ���
    }
    // ���� ����� �� �ϸ� ���뼱
    std::cout << "*************************" << std::endl;
}

void StaticVarTest() // ���� ���� �����ϱ�
{
    static int num = 0; // ���� ���� ����

    for (int i = 0; i < 10; ++i) // 10�� �ݺ��ϴ� ����
    {
        num++; // ���� 1�� �ø���
        std::cout << num << std::endl; // ���� ���
    }
    // ���� ����� �� �ϸ� ���뼱
    std::cout << "*************************" << std::endl;
}

// static�� ���� (�Լ� Ȥ�� Ŭ������ ������ ���)

// Ŭ������ ���� ������ ����� ���
static class StaticClass {}; //���� ������ ����, �׳� �̷� ���� ��ü�� �߿�

//class SampleA // ����� Ŭ������...
//{
//public:
//    int value;
//    static void Print() { std::cout << "Wa!" << std::endl; } // ���� �Լ�
//};
//
//class SampleB
//{
//public:
//    static SampleA data; // ����� Ŭ������ ���� �ν��Ͻ� �����
//};