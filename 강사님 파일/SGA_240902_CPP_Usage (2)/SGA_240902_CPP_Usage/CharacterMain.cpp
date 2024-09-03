#include "CharacterMain.h"

CharacterMain::CharacterMain() : level(1), hp(10)
{
    // 멤버 이니셜라이저를 사용하는 경우
}

CharacterMain::CharacterMain(int level, int hp)
{
    //변수 할당을 사용하는 경우
    this->level = level;
    this->hp = hp;
}

CharacterMain::~CharacterMain()
{
}

void CharacterMain::Dance()
{
    std::cout << "캐릭터가 '/춤'을 사용합니다!" << std::endl;
}

void CharacterMain::ShowCharacter()
{
    std::cout << level << std::endl;
    std::cout << hp << std::endl;
}
