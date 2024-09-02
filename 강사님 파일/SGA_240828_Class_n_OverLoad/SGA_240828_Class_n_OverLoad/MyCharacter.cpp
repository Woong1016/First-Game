#include "MyCharacter.h"

MyCharacter::MyCharacter() : id(0) // : 다음 부분이 변수 초기화 (멤버 이니셜라이징)
{
    // id가 상수로 지정되고, 초기값이 없으면 여기서 오류 확인 가능
    // 이유 : {}가 실행되면 이미 늦었기 때문 (상수 선언 후, 값이 없는 상태)

    // 해결 방법? 컴퓨터가 함수를 이해하는 형태 + 생성자의 실행 시점에 힌트
    // 컴퓨터가 함수의 구분을 하는 시점 = 파일을 읽을 때
    // 생성자의 실행 시점 = 최초로 클래스가 만들어질 때
    // -> 둘 다, 프로그래밍을 확정하기 "이전" (심지어 하나는 다 읽기도 전)
    
    // -> "늦기 전에 값을 정해주면 되겠네?" = {} 나오기 전에 코딩하면 되겠네?

    // c++에서 함수의 이름을 확정하고 = () 이후
    // 함수의 실행을 시작하기 전에 = {} 이전에 변수를 미리 할당해두는 방법 지원

    // = 변수 초기화 수단 (혹은 발음대로 '멤버 이니셜라이저' member initializer)
    //   ...작성법은 위 참조

    hitPoint = 100;
    baseDamage = 10;
}

// 오버로드를 통한 생성자 작성
MyCharacter::MyCharacter(int hp, int dmg) : id(0)
                                       // : 표시 = '멤버 이니셜라이저 실행'
                                       // () 밖 변수 이름 : 멤버 변수
                                       // () 안 데이터 : 초기 값
{
    hitPoint = hp;  // 매개변수를 그대로 사용
    baseDamage = dmg;
}

// 멤버 이니셜라이저 응용 : 모든 멤버 변수 써보기, 매개변수 써보기
MyCharacter::MyCharacter(int id, int hp, int dmg) : id (id),
                                                    hitPoint (hp),
                                                    baseDamage(dmg)
    // : 표시 = 이니셜라이징 시작
    // 왼쪽의, () 밖 이름 : 멤버 변수를 의미
    // 오른쪽의, () 속 데이터 : 초기 값. 함수의 매개변수여도 OK
{
    // 변수를 모두 이니셜라이저로 초기화해서 이 안에는 이제 코드가 필요없다
}

MyCharacter::~MyCharacter()
{
    std::cout << "이 캐릭터는 지워졌습니다." << std::endl;

    // 소멸자의 사용은 main에서 알아보기
}

void MyCharacter::Set(int hitPoint, int baseDamage)
{
    this->hitPoint = hitPoint;
    this->baseDamage = baseDamage;
}

// 위 Set 함수와 이름 철자가 같은, 그러나 매개변수가 다른 것들
void MyCharacter::Set(float hitPoint, float baseDamage)
{
    // float 변수를 int 변수에 할당하는 과정이므로
    // (이대로도 계산이 사실 되지만) 형변환을 해두면 더 확실하다
    this->hitPoint = (int) hitPoint; // (자료형) : 형변환. 기억합시다.
    this->baseDamage = (int) baseDamage;

    // 서로 다른 함수로 실행하고 있음을 출력으로 나타내기
    std::cout << "이 함수는 소수를 받아 실행했습니다." << std::endl;
}

void MyCharacter::Set(int hitPoint)
{
    this->hitPoint = hitPoint;
    this->baseDamage = 99999; // 고정값

    std::cout << "이 함수는 매개변수를 하나만 받았습니다." << std::endl;
}

void MyCharacter::Set()
{
    this->hitPoint = 1000;
    this->baseDamage = 2000;

    std::cout << "이 함수는 매개변수 없이 실행했습니다." << std::endl;
}

void MyCharacter::ShowMe()
{
    std::cout << hitPoint << std::endl;
    std::cout << baseDamage << std::endl;
}

void MyCharacter::ShowMe(bool showID)
{
    if (showID) // 매개변수로 받은 값이 참이면
        std::cout << id << std::endl;

    //나머지 정보는 그대로
    std::cout << hitPoint << std::endl;
    std::cout << baseDamage << std::endl;
}