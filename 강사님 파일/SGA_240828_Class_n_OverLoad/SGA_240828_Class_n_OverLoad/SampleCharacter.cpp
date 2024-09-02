#include "SampleCharacter.h"

SampleCharacter::SampleCharacter()
{
    // 클래스가 만들어질 때 기본적으로 만들어지는 캐릭터

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
    // 위에는 this를 안 쓰는데 여기선 쓰네??
    // : 위에도 사실 써도 됩니다. 그냥 생략한 겁니다.
    // this는 '같은 변수 이름이 있을 때 매개변수인지, 클래스 자체의 소속 변수인지
    // 둘을 구분하기 위해서' 쓰는 거예요.

    this->name = name;              // this : 장차 만들어질 인스턴스를 지칭하는
    this->hitPoint = hitPoint;      //        = 나를 가리키는 포인터
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
