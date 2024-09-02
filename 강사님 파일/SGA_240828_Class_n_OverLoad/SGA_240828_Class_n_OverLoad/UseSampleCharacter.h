#pragma once
#include "SampleCharacter.h" // 이 클래스는 샘플 캐릭터 데이터를 따로 씁니다.

class UseSampleCharacter
{
public:

    UseSampleCharacter();                // 생성자
    void PrintCharacters();              // 출력

private:

    SampleCharacter* character1; // 클래스의 인스턴스....의 포인터
    SampleCharacter* character2;
    SampleCharacter* character3;

    // 샘플 캐릭터용 이름 목록
    struct NameList
    {
        char name1[17] = "농부";
        char name2[17] = "보병";
        char name3[17] = "엘프 유격병";
    };
    NameList nameList; // .....을 실제로 만든 것
};

