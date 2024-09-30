#pragma once
#include "Baverage.h"

// 맥주 클래스

class Beer : public Baverage
{
public:

    // 자식 클래스 생성자 만들기 :
    // 가격과 이름을 받은 후 (여기서 가격, 이름 : 부모 클래스에게 필요한 것)
    // 멤버 이니셜라이저에서 부모의 생성자를 실행한다 (부모를 같이 생성)
    Beer(int cost, std::string name) : Baverage(cost, name) {}
    ~Beer() {}

    // 맥주를 마실 때 (작성까지 헤더에서 (비추천))
    void Drink()
    {
        // 함수 작성에 대한 해설은 Coke 클래스에서 확인

        Baverage::Drink(); // 부모로서 가진 기능을 먼저 써주고
        std::cout << name << "을 마시자 술기운이 올라옵니다." << std::endl;
    }

    void Color()
    {
        // 가상 함수를 오버라이드한다고 해서 지시가 반드시 필요한 건 아니다
        // virtual, override 생략 가능 (Coke 클래스에서 자세한 사항 참조)

        std::cout << name << "은 황금색입니다." << std::endl;
    }
};

