#pragma once

#include <iostream>
class status
{

public:
	void set( int HP , int MP , int ATK, int DEF, int AGI, int INT); // ������ �ɷ�ġ 6�� �� �̸�
	

	int  print();

	//char* job,
private: // ���� �Է¹��� �Ű������� ���� ����� �׸� ����

	char* name;
	char* job;
		int HP;
		int MP;
		int ATK;
		int DEF;
		int AGI;
		int INT;

};

