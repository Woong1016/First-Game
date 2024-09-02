#pragma once
#include <iostream>

class MyCharacterBase
{
    // 이 클래스는 강의에 쓰지 않습니다.
    // 이 클래스는 강의에 사용한 MyCharacterBase 클래스의 비교용 원본입니다.

public:
    MyCharacterBase();   // 생성자

    void Set(int hitPoint, int baseDamage); // 캐릭터 설정
    void ShowMe();                          // 캐릭터 출력

private:

    int id;              // ??? id?????

    int hitPoint;        // HP
    int baseDamage;      // 기본 피해량
};



