#pragma once
#include "CharacterMain.h"

// 사냥꾼 캐릭터 : 자식 클래스
// -> 기본 캐릭터에 더해 "사냥꾼"의 직업을 추가로 부여한 결과

class CharacterHunter : public CharacterMain
{
public: // 완전 공개

    CharacterHunter();
    CharacterHunter(int level, int hp, int focus);

    ~CharacterHunter();

    void ShowCharacter();   // 캐릭터 보이기
                            // (부모에게 같은 함수 있음 = 함수 오버라이드)

    void HuntersMark();     // 사냥꾼의 징표

private: // 완전한 비공개

    int focus;              // 사냥꾼의 자원은 '집중'으로 지칭

};

