#pragma once
#include "Baverage.h"
// 맥주 클라스
class Beer : public Baverage
{
public:
	Beer(int cost , std::string name ): Baverage (cost , name){}
	~Beer();

	void Drink()
	{
		// 함수 작성에 대한 해설은 coke 클래스에서 확인

		Baverage::Drink();
		std::cout << name << "을 마시자 기분이 좋아 춤을 춥니다." << std::endl;

	}

	void Color() 
	{
		// 가상 함수를 오버라이드 한다고 해서 지시가 반드시 필요한건 아니다.
		// virtual , override 생략 가능 (Coke 클래스에서 자세한 사항 참조)

		std::cout << name << "이 녀석은 달콤한 사과향이 나면서 황금빛이 돕니다." << std::endl;
	}
};

