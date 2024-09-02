#pragma once
#include <iostream>

class SampleCharacter
{
public:
    SampleCharacter();   // 생성자

    void Set(                 // 캐릭터 설정
        char*    name,        // 이 함수를 부를 때 필요한 매개변수들
        int      hitPoint,    // 각각의 의미는 아래 private에서...
        int      armor,
        int      sight,
        int      moveSpeed,
        int      costGold,
        int      costLumber,
        float    buildTime,
        int      baseDamage,
        int      range,
        int      piercing
    );

    void ShowMe();       // 캐릭터 출력

private:

    int id;              // ??? id?????

    char* name;          // 이름
    char sampleName[17] = "샘플 캐릭터";

    int hitPoint;        // HP
    int armor;           // 장갑 : 피해감소
    int sight;           // 시야범위
    int moveSpeed;       // 속력

    int costGold;        // 금 비용
    int costLumber;      // 목재 비용
    float buildTime;     // 징집에 필요한 시간

    int baseDamage;      // 기본 피해량
    int range;           // 공격 범위
    int piercing;        // 장갑관통 : 피해감소 상충량

};

