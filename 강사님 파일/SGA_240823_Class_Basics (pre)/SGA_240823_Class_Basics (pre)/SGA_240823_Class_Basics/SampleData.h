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
	//"앞으로 앱 속에 "괴물"로 분류되는 존재가 있다면
	// 해당 존재는 아래와 같은 세부 정보를 갖는" 걸로 한다.


    const int* id;      // 도감 상의 id (항목 순서)
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

// 지난 시간에 진행했듯 위 괴물의 구조체를 자료형인 것처럼 사용하면
// 앱 안에서 실제 괴물 개체를 하나하나 구현할 수 있다
// 예: int a = 1, float f = 10.00f , 괴물 m = 어떤 괴물, 괴물 m2 = 저떤 괴물

// 그리고 개별 괴물에게 붙여줄 이름을 따로 작성한 후 (현재는 문자열의 수정이 안돼
//해당 문자열의 포인터를 (배열 이름을) 개별 괴물에게 준다

// 그 이름의 목록도 구조체
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

	//위 코드를 사용하려고 할 경우 , 얼핏 문제가 없어 보여도
	// 실제로는 빌드 즉시 (실행 즉시 ) 오류가 터진다

	//이유 : right라는 이름을 똑같이 사용한 다른 열거 데이터가 있어서 (중복)

	// 그런데, 이 상황에서 RIGHT라는 단어를 덮어놓고 못쓰면 안되는데?
	//-> 다른 경우에도 이렇게 동음이의어 등으로 꼭 필요해서
	// 절차가 겹치는 다른단어를 다른 열거형으로 만들어야 할 경우는
	// 그럼 어쩌지?

	// 이론적으로 매우 간단한 답이 있다.

	// '이 RIGHT와 저 RIGHT는 완전히 다르다' 라는걸 정해주면 된다.

	// 어떻게 하나요? ..... 여기서 c++ 이전의 프로그래밍은
	// 이 문제를 더는 해결 못한다. 왜? 

	// 이제부터는 C++로부터 시작한 고유한 기능을 하나씩 써야 할 차례

	// 자세한건 MAIN()에서 설명
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