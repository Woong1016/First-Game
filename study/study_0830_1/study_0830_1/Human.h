#pragma once
#include <iostream>
class Human
{
public:
	int set(int HP, int MP, int ATK, int DEF, int AGI, int INT);
	void Print();
	void PrintKnight();
	void PrintThief();

	struct List
	{
		int age;
		int birthday;
		char tribe[20] = {"�ΰ�"};
		char woman[20] = {"����"};
		char man[20] = { "����" };
		char citizen[20] = { "�ù�" };
		char knight[20] = { "���" };
		char thief[20] = { "����" };
		char name1[20] = { "������" };
		char name2[20] = { "�����" };
		char* name3;

	};
	
	List list;

protected:

	int HP;
	int MP;
	int ATK;
	int DEF;
	int AGI;
	int INT;


};

