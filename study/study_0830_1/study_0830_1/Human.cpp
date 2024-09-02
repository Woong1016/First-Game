#include "Human.h"

int Human::set(int HP, int MP, int ATK, int DEF, int AGI, int INT)
{
	this->HP = HP;
	this->MP = MP;
	this->ATK = ATK;
	this->DEF = DEF;
	this->AGI = AGI;
	this->INT = INT;

	return 0;
}

void Human::Print()
{
	List OP;
	
	set(10, 10, 10, 10, 10, 10);
	OP.age = 24;
	OP.birthday = 20011016;
	
	
	std::cout << "캐릭터의 종족은  " << OP.tribe << "입니다." << std::endl;
	std::cout << "캐릭터의 직업은  " << OP.citizen << "입니다." << std::endl;
	std::cout << "캐릭터의 성별은  " << OP.man << "입니다." << std::endl;
	std::cout << "캐릭터의 나이는 " << OP.age << "입니다." << std::endl;
	std::cout << "캐릭터의 생일은  " << OP.birthday << "입니다." << std::endl;
	std::cout << "====================================================" << std::endl;
	std::cout << "캐릭터의 체력은 " << HP << "입니다." << std::endl;
	std::cout << "캐릭터의 마나는  " << MP << "입니다." << std::endl;
	std::cout << "캐릭터의 공격력은 " << ATK << "입니다." << std::endl;
	std::cout << "캐릭터의 방어력은 " << DEF << "입니다." << std::endl;
	std::cout << "캐릭터의 민첩함 및 이동속도는 " << AGI << "입니다." << std::endl;
	std::cout << "캐릭터의 지력은  " << INT << "입니다." << std::endl;
	std::cout << "====================================================" << std::endl;


	
}

void Human::PrintKnight()
{
	List OP;
	OP.age = 32;
	OP.birthday = 0325;
	std::cout << "캐릭터의 종족은  " << OP.tribe << "입니다." << std::endl;
	std::cout << "캐릭터의 성별은  " << OP.man << "입니다." << std::endl;
	std::cout << "캐릭터의 나이는 " << OP.age << "입니다." << std::endl;
	std::cout << "캐릭터의 생일은  " << OP.birthday << "입니다." << std::endl;

}

void Human::PrintThief()
{
	List OP;
	OP.age = 25;
	OP.birthday = 1225;
	std::cout << "캐릭터의 종족은  " << OP.tribe << "입니다." << std::endl;
	std::cout << "캐릭터의 성별은  " << OP.woman << "입니다." << std::endl;
	std::cout << "캐릭터의 나이는 " << OP.age << "입니다." << std::endl;
	std::cout << "캐릭터의 생일은  " << OP.birthday << "입니다." << std::endl;

	
}


