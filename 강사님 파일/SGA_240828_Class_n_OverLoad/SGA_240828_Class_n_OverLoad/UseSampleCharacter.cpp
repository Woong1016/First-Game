#include "UseSampleCharacter.h"

UseSampleCharacter::UseSampleCharacter()
{
    // 인스턴스 생성 후 포인터에 주소 주기
    character1 = new SampleCharacter();
    character2 = new SampleCharacter();
    character3 = new SampleCharacter();

    // 캐릭터 1은 만들어진 샘플 캐릭터를 그대로 씁니다.
    // 캐릭터 2, 3은 스탯을 지정해주겠습니다.

    character2->Set(
        nameList.name2, 60, 2, 4,
        10, 600, 0, 60.0f, 6, 1, 3
    );

    character3->Set(
        nameList.name3, 50, 2, 9,
        10, 500, 50, 70.0f, 3, 5, 6
    );

    // 이렇게 세 캐릭터를 만든 다음 생성자를 종료합니다.
    // 이 클래스의 인스턴스가 만들어진다면, 그 안에는 이렇게 만들어진
    // 세 다른 캐릭터가 자동으로 들어갈 겁니다.
}

void UseSampleCharacter::PrintCharacters()
{
    //각 캐릭터를 따로 출력

    character1->ShowMe();

    character2->ShowMe();

    character3->ShowMe();
}
