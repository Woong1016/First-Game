#pragma once
#include <iostream>
// Ŭ���� "�ΰ�" : ��� �ΰ��� �⺻ ���� Ŭ����

// �ù� ���δ� " �θ� Ŭ����" (parent)


class Human
{
	// ���⼭ �ΰ��� Ư���� ǥ��


public:	// ����
	// ���ÿ� ���� , �Լ� �ϳ���


	int age;	// ����
	void Eat();	// �Դ� �ൿ


private: // �����

	float height;  // Ű
	void Wash();	// �Ĵ� �ൿ


	// Ŭ���� ����� ���Ǵ� �������� ��� ������

	// ����° ���� �����ڰ� �����Ѵ�

	// �ٷ� " �θ� �ڽ� Ŭ���� ���̿����� ���� �� �� �ִµ�"
	// "���� �ۿ����� �� �� ���� ������ �ʴ� ������"
	//= ��ȣ �����͸� ����� ��/

protected : // private , public �� ���� ����° ���� ������
			// ��ȣ �����͸� �ǹ��Ѵ�

	float weight;

	void Workout();

	// Ȯ�� : Ŭ�������� private , public , protected �� ���� �����ڰ� ����

	// ����Ǵ� ������ public > protected > private ��

	// Ȥ�� ������ �亯�� ����غ��� ...

	//			 1. �ۿ��� �� �� �ִ°�? // 2. �ڽ� Ŭ������ �� �� �ִ°�?
	//private :       No							No
	//protected:      no							Yes
	//public			yes							yes




};

