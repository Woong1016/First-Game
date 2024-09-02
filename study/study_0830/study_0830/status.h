#pragma once

#include <iostream>
class status
{

public:
	void set( int HP , int MP , int ATK, int DEF, int AGI, int INT); // 간단한 능력치 6개 및 이름
	

	int  print();

	//char* job,
private: // 값을 입력받은 매개변수에 값을 담아줄 그릇 제작

	char* name;
	char* job;
		int HP;
		int MP;
		int ATK;
		int DEF;
		int AGI;
		int INT;

};

