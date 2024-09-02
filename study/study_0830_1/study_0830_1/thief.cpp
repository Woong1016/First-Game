#include "thief.h"

void Thief::Print()
{
	List OP;

	set(35, 25, 35, 15, 20, 10);



	std::cout << "캐릭터의 직업은  " << OP.thief << "입니다." << std::endl;
	std::cout << "캐릭터의 사용 무기는 단검 및 암기 입니다." << std::endl;
	std::cout << "====================================================" << std::endl;
	std::cout << "캐릭터의 체력은 " << HP << "입니다." << std::endl;
	std::cout << "캐릭터의 마나는  " << MP << "입니다." << std::endl;
	std::cout << "캐릭터의 공격력은 " << ATK << "입니다." << std::endl;
	std::cout << "캐릭터의 방어력은 " << DEF << "입니다." << std::endl;
	std::cout << "캐릭터의 민첩함 및 이동속도는 " << AGI << "입니다." << std::endl;
	std::cout << "캐릭터의 지력은  " << INT << "입니다." << std::endl;
	std::cout << "====================================================" << std::endl;


}



void Thief::Thiefskill1()
{
	std::cout << "스킬이름: 급소" << std::endl;
	std::cout << "적의 급소를 빠르게 6번 베어넘깁니다." << std::endl;
	std::cout << "====================================================" << std::endl;
}
void Thief::Thiefskill2()
{
	std::cout << "스킬이름: 암기투척" << std::endl;
	std::cout << "자신 근처 모든 적에게 암기를 투척해 피해를 입힙니다." << std::endl;
	std::cout << "====================================================" << std::endl;
}
void Thief::Thiefskill3()
{
	std::cout << "스킬이름: 은신" << std::endl;
	std::cout << "일정시간 적에게 피해를 받을 확률이 대폭 감소합니다." << std::endl;
	std::cout << "====================================================" << std::endl;
}

