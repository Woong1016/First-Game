#include "thief.h"

void Thief::Print()
{
	List OP;

	set(35, 25, 35, 15, 20, 10);



	std::cout << "ĳ������ ������  " << OP.thief << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ��� ����� �ܰ� �� �ϱ� �Դϴ�." << std::endl;
	std::cout << "====================================================" << std::endl;
	std::cout << "ĳ������ ü���� " << HP << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������  " << MP << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ���ݷ��� " << ATK << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������ " << DEF << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ��ø�� �� �̵��ӵ��� " << AGI << "�Դϴ�." << std::endl;
	std::cout << "ĳ������ ������  " << INT << "�Դϴ�." << std::endl;
	std::cout << "====================================================" << std::endl;


}



void Thief::Thiefskill1()
{
	std::cout << "��ų�̸�: �޼�" << std::endl;
	std::cout << "���� �޼Ҹ� ������ 6�� ����ѱ�ϴ�." << std::endl;
	std::cout << "====================================================" << std::endl;
}
void Thief::Thiefskill2()
{
	std::cout << "��ų�̸�: �ϱ���ô" << std::endl;
	std::cout << "�ڽ� ��ó ��� ������ �ϱ⸦ ��ô�� ���ظ� �����ϴ�." << std::endl;
	std::cout << "====================================================" << std::endl;
}
void Thief::Thiefskill3()
{
	std::cout << "��ų�̸�: ����" << std::endl;
	std::cout << "�����ð� ������ ���ظ� ���� Ȯ���� ���� �����մϴ�." << std::endl;
	std::cout << "====================================================" << std::endl;
}

