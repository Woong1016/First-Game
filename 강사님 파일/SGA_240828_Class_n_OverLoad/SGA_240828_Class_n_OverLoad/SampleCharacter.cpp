#include "SampleCharacter.h"

SampleCharacter::SampleCharacter()
{
    // Ŭ������ ������� �� �⺻������ ��������� ĳ����

    name = sampleName;
    hitPoint = 10;
    armor = 0;
    sight = 10;
    moveSpeed = 5;
    costGold = 100;
    costLumber = 100;
    buildTime = 60.0f;
    baseDamage = 1;
    range = 1;
    piercing = 3;

}

void SampleCharacter::Set(char* name, int hitPoint, int armor, int sight,
    int moveSpeed, int costGold, int costLumber, float buildTime,
    int baseDamage, int range, int piercing)
{
    // ������ this�� �� ���µ� ���⼱ ����??
    // : ������ ��� �ᵵ �˴ϴ�. �׳� ������ �̴ϴ�.
    // this�� '���� ���� �̸��� ���� �� �Ű���������, Ŭ���� ��ü�� �Ҽ� ��������
    // ���� �����ϱ� ���ؼ�' ���� �ſ���.

    this->name = name;              // this : ���� ������� �ν��Ͻ��� ��Ī�ϴ�
    this->hitPoint = hitPoint;      //        = ���� ����Ű�� ������
    this->armor = armor;
    this->sight = sight;
    this->moveSpeed = moveSpeed;
    this->costGold = costGold;
    this->costLumber = costLumber;
    this->buildTime = buildTime;
    this->baseDamage = baseDamage;
    this->range = range;
    this->piercing = piercing;
}

void SampleCharacter::ShowMe()
{
    std::cout << name << std::endl;
    std::cout << hitPoint << std::endl;
    std::cout << armor << std::endl;
    std::cout << sight << std::endl;
    std::cout << moveSpeed << std::endl;
    std::cout << costGold << std::endl;
    std::cout << costLumber << std::endl;
    std::cout << buildTime << std::endl;
    std::cout << baseDamage << std::endl;
    std::cout << range << std::endl;
    std::cout << piercing << std::endl;
    std::cout << "----------------------" << std::endl;
}
