#include "Knight.h"

void Knight::Print()
{
	List OP;

	set(50, 20, 20, 30, 10, 10);
	

	
	std::cout << "캐릭터의 직업은  " << OP.knight << "입니다." << std::endl;
	std::cout << "캐릭터의 사용 무기는 모든 검류 입니다." << std::endl;
	std::cout << "====================================================" << std::endl;
	std::cout << "캐릭터의 체력은 " << HP << "입니다." << std::endl;
	std::cout << "캐릭터의 마나는  " << MP << "입니다." << std::endl;
	std::cout << "캐릭터의 공격력은 " << ATK << "입니다." << std::endl;
	std::cout << "캐릭터의 방어력은 " << DEF << "입니다." << std::endl;
	std::cout << "캐릭터의 민첩함 및 이동속도는 " << AGI << "입니다." << std::endl;
	std::cout << "캐릭터의 지력은  " << INT << "입니다." << std::endl;
	std::cout << "====================================================" << std::endl;


}


void Knight::Knightskill1()
{
	std::cout << "스킬이름: 돌진베기" << std::endl;
	std::cout << "기사가 돌진하면서 검을 아래에서 위로 크게 베어올립니다." << std::endl;
	std::cout << "====================================================" << std::endl;
}
void Knight::Knightskill2()
{
	std::cout << "스킬이름: 검기" << std::endl;
	std::cout << "일정시간동안 기사의 기본공격에서 검기가 방출됩니다." << std::endl;
	std::cout << "====================================================" << std::endl;
}
void Knight::Knightskill3()
{
	std::cout << "스킬이름: 카운터" << std::endl;
	std::cout << "검으로 상대방을 막은뒤 즉시 공격합니다." << std::endl;
	std::cout << "====================================================" << std::endl;
}