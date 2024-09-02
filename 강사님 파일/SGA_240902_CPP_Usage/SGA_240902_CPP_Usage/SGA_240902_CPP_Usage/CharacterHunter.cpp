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
    //ĳ���� ���� ǥ�ô� ����
    std::cout << "���� : ��ɲ�" << std::endl;
    std::cout << "���� : " << level << std::endl;
    std::cout << "�ִ� ü�� : " << hp << std::endl;
    std::cout << "���� : " << focus << std::endl;
}

void CharacterHunter::HuntersMark()
{
    std::cout << "��ɲ��� ��ɲ��� ¡ǥ�� ����ϴ�!" << std::endl;
}
