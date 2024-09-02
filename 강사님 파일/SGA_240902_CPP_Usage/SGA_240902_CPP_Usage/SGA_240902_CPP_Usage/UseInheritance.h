#pragma once
#include "CharacterWarrior.h" // 전사 클래스
#include "CharacterHunter.h"  // 사냥꾼 클래스

// 부모 클래스 "캐릭터 메인"은 각 자식 클래스에 자동포함

class UseInheritance
{
public :
    void Run();

private:
    CharacterWarrior* warrior;
    CharacterHunter*  hunter;

};

