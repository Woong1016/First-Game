#include "CharacterMain.h"

CharacterMain::CharacterMain() : level(1), hp(10)
{
    // ��� �̴ϼȶ������� ����ϴ� ���
}

CharacterMain::CharacterMain(int level, int hp)
{
    //���� �Ҵ��� ����ϴ� ���
    this->level = level;
    this->hp = hp;
}

CharacterMain::~CharacterMain()
{
}

void CharacterMain::Dance()
{
    std::cout << "ĳ���Ͱ� '/��'�� ����մϴ�!" << std::endl;
}

void CharacterMain::ShowCharacter()
{
    std::cout << level << std::endl;
    std::cout << hp << std::endl;
}
