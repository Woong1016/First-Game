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
	std::cout << "ĳ������ �������ͽ�" << std::endl;
	std::cout << "ĳ������ ü���� " << HP << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������  " << MP << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ���ݷ��� " << ATK << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������ " << DEF << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ��ø�� �� �̵��ӵ��� " << AGI << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������  " << INT << "�Դϴ�." << std::endl;
	std::cout << "====================================================" << std::endl;


	return 0;
}
