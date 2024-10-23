#pragma once
// pragma once : #로 시작하는 코드 중복 시 한 번만 계산
// -> 같은 기능을 여러 번 포함해야 할 때 필수
//    (그냥 .h 파일이면 의례상 넣어두는 편이 좋을 정도)

#include <iostream> // 입출력 기본 기능 (cout 때문에 필요)

// 샘플 데이터

// 구조체 작성 후 밑에 열거형을 같이 작성합니다.

//--------------------------------------------------

// 구조체 : 어떤 게임의 캐릭터 데이터를 내가 묘사한다면

struct Monster          // 괴물
{
    const int* id;      // 도감 상의 id
    const int* subId; // id가 같은 특이 개체가 있다면 사용

    char* name;         // 이름

    int typeCode1;      // 유형1
    int typeCode2;      // 유형2
    int typeCode3;      // 유형3
    int typeCode4;      // 유형4

    float sexRatio;     // 성별비율
    int hatchCount;     // 부화에 걸리는 필드 이동 횟수 (걸음 혹은 맵 전환)

    float hpMax;        // 최대 체력
    float hpCurrent;    // 현재 체력
    float attack;       // 공격력
    float defence;      // 방어력
    float exAttack;     // 특수 공격력
    float exDefence;    // 특수 방어력
    float speed;        // 빠르기
    float totalStats;   // 종합 능력치 (종족치)

    // 그 외 필요한 데이터가 있지만 생략합니다.

    // 아래 데이터의 용도는 다른 사람들에게 밝히지 않습니다.
    int _var0000;
    int _var0001;

    // 0000 : id, 0001 : 서브id
};

struct MonsterNames     // 괴물의 이름 목록
{
    // * 특수한 상황! : 여기의 데이터는 나중에
    // 바뀔 수도 없고 (중요한 기초 데이터),
    // 바꿀 수도 없으므로 (상수 포인터)
    // 여기서 그냥 변수 값을 할당합니다.

    char name_sample[17] = "한글이름 8자까지";

    char name_001[17] = "나오하";
    char name_004[17] = "뜨아거";
    char name_007[17] = "꾸왁스";
    char name_024[17] = "빠르모트";
    char name_037[17] = "비비용";
    char name_074[17] = "피카츄";
    char name_099[17] = "찌르호크";
    char name_125[17] = "대왕끼리동";
};

// 구조체 출력

void PrintMonster(Monster monster) // 구조체 형식을 매개변수로
{
    std::cout << "---------------------------------" << std::endl;
   
    std::cout << *monster.id << std::endl;  // 포인터는 역참조
    std::cout << *monster.subId << std::endl;

    std::cout << monster.name << std::endl; // * 문자열은 예외!

    std::cout << monster.typeCode1 << std::endl;
    std::cout << monster.typeCode2 << std::endl;
    std::cout << monster.typeCode3 << std::endl;
    std::cout << monster.typeCode4 << std::endl;

    std::cout << monster.sexRatio << std::endl;
    std::cout << monster.hatchCount << std::endl;

    std::cout << monster.hpMax << std::endl;
    std::cout << monster.hpCurrent << std::endl;
    std::cout << monster.attack << std::endl;
    std::cout << monster.defence << std::endl;
    std::cout << monster.exAttack << std::endl;
    std::cout << monster.exDefence << std::endl;
    std::cout << monster.speed << std::endl;
    std::cout << monster.totalStats << std::endl;

    std::cout << "---------------------------------" << std::endl;
}

// 열거형 샘플

enum DIRECTION      // 방향을 나타내는 열거형
{
    FORWARD,        // 앞
    BACK,           // 뒤
    RIGHT,          // 오른쪽
    LEFT,           // 왼쪽
    UPWARD,         // 위
    DOWNWARD,       // 아래
};

enum CHECKANSWER    // 답변에 대한 정오를 확인하는 열거형
{
    //RIGHT,          // 맞았다
    //WRONG,          // 틀렸다

    // ... ?? 이게 왜 주석이지? 무슨 문제 있나요?
};

// 열거형 출력

void TestEnum()
{
    // 방향 열거형 출력 시작
    std::cout << "---------------------------------" << std::endl;
    std::cout << "방향 열거형 코드 목록" << std::endl;

    std::cout << "전 : " << FORWARD << std::endl;
    std::cout << "후 : " << BACK << std::endl;
    std::cout << "우 : " << RIGHT << std::endl;
    std::cout << "좌 : " << LEFT << std::endl;
    std::cout << "상 : " << UPWARD << std::endl;
    std::cout << "하 : " << DOWNWARD << std::endl;

    std::cout << "---------------------------------" << std::endl;
}