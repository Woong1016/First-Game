#include "UseInheritance.h"

void UseInheritance::Run()
{
    // 인스턴스(의 포인터) 생성 후 할당
    warrior = new CharacterWarrior();
    hunter = new CharacterHunter();

    // 전사 데이터 써보기
    warrior->Dance();         // 부모 클래스의 함수 사용
    warrior->ShowCharacter(); // 스테이터스 출력
    warrior->GiganticStrike(); // 거인의 강타 사용

    //사냥꾼 데이터 써보기
    hunter->Dance();
    hunter->ShowCharacter();
    hunter->HuntersMark(); // 사냥꾼의 징표 사용

    // 이로써 같은 부모 클래스, 다른 자식 클래스의 관계를 활용하면
    // 공통 기능은 부모 클래스를 통해 작성하고 (중복 작성을 줄이기)
    // 각 직업 전용 기능 (전사에게만, 사냥꾼에게만 있어야 하는 데이터) 등은
    // 자식 클래스에 따로 적어서 개성을 부여할 수 있다!

	// 부모 클래스를 자식에서 활용하는 예시

	CharacterWarrior* warrior2 = new CharacterWarrior(60, 30000);

	warrior2->ShowCharacter();
}
