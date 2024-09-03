#pragma once
#include "CharacterMain.h"

// 전사 캐릭터 : 자식 클래스
// -> 기본 캐릭터에 더해 "전사"의 직업을 추가로 부여한 결과

class CharacterWarrior : public CharacterMain
{
public: // 완전 공개

    CharacterWarrior();
    CharacterWarrior(int level, int hp); // 정수 2개짜리 생성자
    CharacterWarrior(int level, int hp, int rage);

    ~CharacterWarrior();

    void ShowCharacter();   // 캐릭터 보이기
                            // (부모에게 같은 함수 있음 = 함수 오버라이드)

    void GiganticStrike();  // 거인의 강타

private: // 완전한 비공개

    int rage;               // 전사의 자원은 '분노'로 지칭
};

