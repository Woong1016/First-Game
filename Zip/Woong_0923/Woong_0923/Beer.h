#pragma once
#include "Baverage.h"
// ���� Ŭ��
class Beer : public Baverage
{
public:
	Beer(int cost , std::string name ): Baverage (cost , name){}
	~Beer();

	void Drink()
	{
		// �Լ� �ۼ��� ���� �ؼ��� coke Ŭ�������� Ȯ��

		Baverage::Drink();
		std::cout << name << "�� ������ ����� ���� ���� ��ϴ�." << std::endl;

	}

	void Color() 
	{
		// ���� �Լ��� �������̵� �Ѵٰ� �ؼ� ���ð� �ݵ�� �ʿ��Ѱ� �ƴϴ�.
		// virtual , override ���� ���� (Coke Ŭ�������� �ڼ��� ���� ����)

		std::cout << name << "�� �༮�� ������ ������� ���鼭 Ȳ�ݺ��� ���ϴ�." << std::endl;
	}
};

