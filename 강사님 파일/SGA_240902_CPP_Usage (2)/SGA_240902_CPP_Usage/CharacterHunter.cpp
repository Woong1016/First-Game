#include "CharacterHunter.h"

CharacterHunter::CharacterHunter()
{
    level = 15;
    hp = 800;
    focus = 100;
}

CharacterHunter::CharacterHunter(int level, int hp, int focus)
{
    this->level = level;
    this->hp = hp;
    this->focus = focus;
}

CharacterHunter::~CharacterHunter()
{

}

void CharacterHunter::ShowCharacter()
{
    //캐릭터 최종 표시는 상세히
    std::cout << "직업 : 사냥꾼" << std::endl;
    std::cout << "레벨 : " << level << std::endl;
    std::cout << "최대 체력 : " << hp << std::endl;
    std::cout << "집중 : " << focus << std::endl;
}

void CharacterHunter::HuntersMark()
{
    std::cout << "사냥꾼이 사냥꾼의 징표를 남깁니다!" << std::endl;
}
