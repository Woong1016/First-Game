#include "Knight.h"

void Knight::Print()
{
	List OP;

	set(50, 20, 20, 30, 10, 10);
	

	
	std::cout << "ĳ������ ������  " << OP.knight << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ��� ����� ��� �˷� �Դϴ�." << std::endl;
	std::cout << "====================================================" << std::endl;
	std::cout << "ĳ������ ü���� " << HP << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������  " << MP << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ���ݷ��� " << ATK << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������ " << DEF << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ��ø�� �� �̵��ӵ��� " << AGI << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������  " << INT << "�Դϴ�." << std::endl;
	std::cout << "====================================================" << std::endl;


}


void Knight::Knightskill1()
{
	std::cout << "��ų�̸�: ��������" << std::endl;
	std::cout << "��簡 �����ϸ鼭 ���� �Ʒ����� ���� ũ�� ����ø��ϴ�." << std::endl;
	std::cout << "====================================================" << std::endl;
}
void Knight::Knightskill2()
{
	std::cout << "��ų�̸�: �˱�" << std::endl;
	std::cout << "�����ð����� ����� �⺻���ݿ��� �˱Ⱑ ����˴ϴ�." << std::endl;
	std::cout << "====================================================" << std::endl;
}
void Knight::Knightskill3()
{
	std::cout << "��ų�̸�: ī����" << std::endl;
	std::cout << "������ ������ ������ ��� �����մϴ�." << std::endl;
	std::cout << "====================================================" << std::endl;
}