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
		char tribe[20] = {"인간"};
		char woman[20] = {"여자"};
		char man[20] = { "남자" };
		char citizen[20] = { "시민" };
		char knight[20] = { "기사" };
		char thief[20] = { "도적" };
		char name1[20] = { "봉식이" };
		char name2[20] = { "춘담이" };
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

