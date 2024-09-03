#include "CharacterWarrior.h"

/*
CharacterWarrior::CharacterWarrior() : level(10), hp(1000), rage(100)
{
    // -> 멤버 이니셜라이저가 안 된다!!

    // 왜? 멤버 이니셜라이저를 사용하는 주체가 자식 클래스가 아니라서.
    // 이니셜라이저의 실행 시점 : 클래스가 객체로서 생성되는 바로 그 순간
    //                          (이 시점에 인스턴스가 아직 없다는 이야기)
    // -> 멤버 이니셜라이저의 실행 주체는 바로 "이 생성자를 불러온 곳" = 외부

    // 그러므로 (다른 방법을 못 찾았다면) 직접 변수 할당
    level = 10;
    hp = 1000;
    rage = 100;
}
*/

// 그렇다면 멤버 이니셜라이저를 상속 관계의 자식 클래스에서는 아예 못 쓰는가?
// 그건 아니다

// 자식 클래스가 부모 클래스를 포함해 멤버 이니셜라이저를 쓰는 방법은...

// 자식 클래스에서 부모 클래스의 생성자를 같이 써주는 것!
// 왜? 자식은 부모의 모든 것을 지금 물려받은 상태니까!

// 부모 생성자를 활용한 진짜 멤버 이니셜라이저 활용 생성자

CharacterWarrior::CharacterWarrior() : CharacterMain(10, 200),
                                       rage(100)
{
    // 부모의 생성자를 멤버 이니셜라이저 실행 장소에 같이 표기
    // -> 먼저 부모를 만들고, 해당 부모의 연장으로써 다시 자기 자신을 생성
}

CharacterWarrior::CharacterWarrior(int level, int hp) : CharacterMain(level, hp)
{
    // 위 방법으로 자식 생성자에서 받은 인수를 부모 생성자에게 그대로 전달 가능

    this->rage = 300;

    // 이렇게 부모 클래스를 자식 클래스에서 언급함으로써 부모 클래스에 있었던
    // 데이터를 활용할 수 있다.

    // 그리고... 이렇게 부모 클래스를 활용하는 방법은 생성자만이 아니다
    // (아래 ShowCharacter 함수 참조)
}

CharacterWarrior::CharacterWarrior(int level, int hp, int rage)
{
    this->level = level;
    this->hp = hp;
    this->rage = rage;
}

CharacterWarrior::~CharacterWarrior()
{
}

void CharacterWarrior::ShowCharacter()
{
    //캐릭터 최종 표시는 상세히
    //std::cout << "직업 : 전사" << std::endl;
    //std::cout << "레벨 : " << level << std::endl;
    //std::cout << "최대 체력 : " << hp << std::endl;
    //std::cout << "분노 : " << rage << std::endl;

    // 추가 활용

    // 위의 출력 코드는 부모 클래스의 기능을 완전히 꺼뜨리고
    // 자식 클래스만의 독자적인 출력을 한 것.

    // 반면 함수 활용에서도 생성자처럼 부모 쪽에서 먼저 코드 활용을 하고
    // 그 다음에 자식 클래스만의 고유한 코드를 이어서 쓰고 싶을 수도 있다

    // (사실 코드 활용 면에서는 그 쪽이 더 합리적)

    // 이 때 부모 클래스의 데이터를 쓰려면.... "클래스명::" 문법을 활용하면 된다

    CharacterMain::ShowCharacter(); // 부모 클래스로서 가진 동명의 함수 사용
                                    // "클래스명::" 문법은 함수 작성에만 쓰는 게 x

    // 부모 클래스 함수 사용에 이어서 자식만의 함수 작성도

    std::cout << "직업 : 전사" << std::endl;       // 자식 클래스만 있는 정보
    std::cout << "분노 : " << rage << std::endl;   // 자식 클래스만 있는 정보2

    // 이렇게 자식 클래스가 상속 관계에 있는 부모 클래스의 이름을 쓰면
    // 부모 클래스의 기능을 빌려쓸 수도 있다

    // + 클래스명 문법의 활용 : "클래스명::"이라고 호출하면
    //                         해당 클래스...라는 범위의 코드를 빌려쓸 수 있다!
}

void CharacterWarrior::GiganticStrike()
{
    std::cout << "전사가 거인의 강타를 시전합니다!" << std::endl;
}
