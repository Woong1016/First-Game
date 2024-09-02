#include "MyCharacterBase.h"

MyCharacterBase::MyCharacterBase()
{
    hitPoint = 100;
    baseDamage = 10;
}

void MyCharacterBase::Set(int hitPoint, int baseDamage)
{
    this->hitPoint = hitPoint;
    this->baseDamage = baseDamage;
}

void MyCharacterBase::ShowMe()
{
    std::cout << hitPoint << std::endl;
    std::cout << baseDamage << std::endl;
}
