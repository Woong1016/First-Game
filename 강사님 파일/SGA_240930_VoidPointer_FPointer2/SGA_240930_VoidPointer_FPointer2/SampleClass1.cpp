#include "SampleClass1.h"
#include <iostream>

SampleClass1::SampleClass1()
{
	// ���⼭ �Լ� ������ �����غ��⸦ �ϸ�..

	//ptr = Function1; // �Ұ���
	//ptr = &SampleClass1::Function1; //�Ұ���
	
	// ������ ��ʴ� function2���� Ȯ��

}

SampleClass1::~SampleClass1()
{
}

void SampleClass1::Function1()
{
    std::cout << "Ŭ���� 1, �Լ� 1" << std::endl;
}

void SampleClass1::Function2()
{
    std::cout << "Ŭ���� 1, �Լ� 2" << std::endl;
}
