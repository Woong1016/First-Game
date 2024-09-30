#include "SampleClass2.h"
#include <iostream>

SampleClass2::SampleClass2()
{   

	//std::function<> �����Ϳ� �Լ��� ���� ���

	// �ڱ� Ŭ������ ��� ������ �Լ� ��ġ�� ���� ����
	// �Լ� ��ġ�� ����ų ���� ������ Ŭ�������� �����ؾ� �Ѵ�
	// = Ŭ������ ��ü�� �Լ� �̸��� ���ԵǾ� �ְ� , 
	// �� ��ü�� �߰� �԰��̶�� �ؼ��ϴ� ���� ����

	ptr = std::bind(&SampleClass2::Function2, this);
	// this : �� Ŭ�������� ������� �� �ν��Ͻ� = �� �ڽ��� ����Ű�� ������
	// *�� this �ڸ��� �ٸ� Ŭ���� ��� ������ ���ٸ�
	// �ش� ��ü�� �ν��Ͻ��� ��ġ�� ��Ÿ�� ������ �־��ָ� �ȴ�.

	// �� Ŭ������ ptr�� ���� �Լ����� �Ẹ�� ȣ�� ���� ���θ� �� �� �ִ�.
}

SampleClass2::~SampleClass2()
{
}

void SampleClass2::Function1()
{
    std::cout << "Ŭ���� 2, �Լ� 1" << std::endl;
}

void SampleClass2::Function2()
{
    std::cout << "Ŭ���� 2, �Լ� 2" << std::endl;
}
