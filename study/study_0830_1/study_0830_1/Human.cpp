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
	
	
	std::cout << "ĳ������ ������  " << OP.tribe << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������  " << OP.citizen << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������  " << OP.man << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ���̴� " << OP.age << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������  " << OP.birthday << "�Դϴ�." << std::endl;
	std::cout << "====================================================" << std::endl;
	std::cout << "ĳ������ ü���� " << HP << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������  " << MP << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ���ݷ��� " << ATK << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������ " << DEF << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ��ø�� �� �̵��ӵ��� " << AGI << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������  " << INT << "�Դϴ�." << std::endl;
	std::cout << "====================================================" << std::endl;


	
}

void Human::PrintKnight()
{
	List OP;
	OP.age = 32;
	OP.birthday = 0325;
	std::cout << "ĳ������ ������  " << OP.tribe << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������  " << OP.man << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ���̴� " << OP.age << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������  " << OP.birthday << "�Դϴ�." << std::endl;

}

void Human::PrintThief()
{
	List OP;
	OP.age = 25;
	OP.birthday = 1225;
	std::cout << "ĳ������ ������  " << OP.tribe << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������  " << OP.woman << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ���̴� " << OP.age << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������  " << OP.birthday << "�Դϴ�." << std::endl;

	
}


