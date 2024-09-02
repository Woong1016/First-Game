#include "status.h"

void status::set(int HP, int MP, int ATK, int DEF, int AGI, int INT)
{
	
	this->HP = HP;
	this->MP = MP;
	this->ATK = ATK;
	this->DEF = DEF;
	this->AGI = AGI;
	this->INT = INT;
}

//, char* job
int status::print()
{

	
	std::cout << "====================================================" << std::endl;
	std::cout << "캐릭터의 스테이터스" << std::endl;
	std::cout << "캐릭터의 체력은 " << HP << "입니다." << std::endl;
	std::cout << "캐릭터의 마나는  " << MP << "입니다." << std::endl;
	std::cout << "캐릭터의 공격력은 " << ATK << "입니다." << std::endl;
	std::cout << "캐릭터의 방어력은 " << DEF << "입니다." << std::endl;
	std::cout << "캐릭터의 민첩함 및 이동속도는 " << AGI << "입니다." << std::endl;
	std::cout << "캐릭터의 지력은  " << INT << "입니다." << std::endl;
	std::cout << "====================================================" << std::endl;


	return 0;
}
