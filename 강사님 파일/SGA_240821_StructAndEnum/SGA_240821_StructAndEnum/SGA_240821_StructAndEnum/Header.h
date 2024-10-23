#pragma once

// 헤더 = 전역 변수의 자리


// 구조체 작성

struct Champion
{
    int hitPoint;          // hp, 체력
    float hitPointRestore; // 체력 재생
    float atk;             // 공격력 (attack)
    float atkSpeed;        // 공격 속도
    float def;             // 방어력 (defense)
    float res;             // 마법 저항력 (resist)
    int range;             // 사거리
    float moveSpeed;       // 이동 속도
};


// 열거형 작성

enum AGEGROUP
{
    INFANT,
    TODDLER,
    YOUNGSTER,
    JUNIOR,
    YOUNGADULT,
    ADULT,
    MIDDLE,
    SENIOR,
    SILVER,
    OLD,
};