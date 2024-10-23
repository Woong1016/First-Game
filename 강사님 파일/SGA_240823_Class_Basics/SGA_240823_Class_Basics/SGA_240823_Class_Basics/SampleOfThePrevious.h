#pragma once

// 복습 겸 배경 확인을 위한 샘플

#include "SampleData.h" // 샘플 데이터 사용

// 팁 : 헤더에서 다른 헤더를 포함해도 됩니다.
// -> 먼저 샘플 데이터 헤더를 읽고, 여기로 돌아옵시다.

// 샘플 함수에서 쓰기 위한 전역 변수로서
// "괴물의 이름 목록" 데이터를 생성

MonsterNames monsterNameList; // 구조체(자료형 집합)를 실제 변수로

// 샘플 함수

// * 환기 : .h 파일에 함수를 모두 작성하는 것은 권장 사항이 아닙니다.
// 지금은 main()이 있는 파일의 가독성을 위해 여기서 몰아 쓰는 것뿐이에요.

void TwoMonsters()
{
    // 같은 구조체를 가지는 두 실제 '등장인물' 구현

    Monster pikachu;        // 전기 쥐
    Monster pawmot;         // 전기 쥐

    // 전기 쥐와 전기 쥐의 각 세부 항목에 값을 할당
    // Q : 전기 쥐와 전기 쥐의 차이가 뭔가요? A : 저도 모르겠습니다.

    // 아무튼 전기 쥐
    pikachu._var0000 = 74;  // 도감 번호 74
    pikachu._var0001 = 7;   // 이 쥐는 세부항목 8번째인 특수 개체.
                            // 빨간 모자를 머리에 쓰고 있지요.

    pikachu.name = monsterNameList.name_074; // 포인터 할당

    // * 이렇게 메모리 참조의 대상을 지정함으로써
    //   c++ 기본 기능으로도 변수의 문자 내용을 바꿔줄 수 있습니다.

    pikachu.id = &pikachu._var0000;
    pikachu.subId = &pikachu._var0001;
    pikachu.sexRatio = 0.5f;    // 부화 시 50%로 수컷, 50%로 암컷
    pikachu.hatchCount = 10;    // 알이었을 경우 부화 후 10걸음째 부화

    pikachu.typeCode1 = 4;      // '전기 타입'입니다.
    pikachu.typeCode2 = -1;     // 다른 유형 없는 단일타입 괴물입니다.
    pikachu.typeCode3 = -1;
    pikachu.typeCode4 = -1;

    pikachu.hpMax = 35;
    pikachu.hpCurrent = 35;     // 부상이 없습니다.
    pikachu.attack = 55;
    pikachu.defence = 40;
    pikachu.exAttack = 50;
    pikachu.exDefence = 50;
    pikachu.speed = 90;
    pikachu.totalStats = 320;   // 유전시 빠른 계산에 쓰이며,
                                // 레벨업을 해서 다른 스탯이 바뀌어도
                                // 종족치 값은 여기서 보존됩니다.

    // 그리고 전기 쥐
    pawmot._var0000 = 24;  // 도감 번호 24
    pawmot._var0001 = 1;   // 목록 세부 2번째, 암컷 개체입니다.

    pawmot.name = monsterNameList.name_024; // 이름 할당

    pawmot.id = &pawmot._var0000;
    pawmot.subId = &pawmot._var0001;
    pawmot.sexRatio = 0.5f;
    pawmot.hatchCount = 15;

    pawmot.typeCode1 = 4;      // '전기 타입'입니다.
    pawmot.typeCode2 = 11;     // '격투 타입'을 겸합니다.
    pawmot.typeCode3 = -1;
    pawmot.typeCode4 = -1;

    pawmot.hpMax = 70;
    pawmot.hpCurrent = 60;     // 진화 전에 좀 싸웠습니다.
    pawmot.attack = 115;
    pawmot.defence = 70;
    pawmot.exAttack = 70;
    pawmot.exDefence = 60;
    pawmot.speed = 105;
    pawmot.totalStats = 490;

    // 두 괴물에 대한 데이터 출력 (샘플데이터에 만들어둔 함수)

    PrintMonster(pikachu); // 피카츄 출력
    PrintMonster(pawmot);  // 빠르모트 출력

    std::cout << "두 포켓몬스터 출력을 마칩니다." << std::endl;
}