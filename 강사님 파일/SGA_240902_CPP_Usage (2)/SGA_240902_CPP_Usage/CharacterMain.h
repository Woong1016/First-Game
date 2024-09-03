#pragma once
#include <iostream>

// 부모 클래스 : 캐릭터

class CharacterMain
{
public:

    CharacterMain();    //생성자
    CharacterMain(int level, int hp);

    ~CharacterMain();   //소멸자

    void Dance();       // /춤

protected: // 외부 비공개, 자식에겐 공개

    int level;
    int hp;
        
    void ShowCharacter();
};

