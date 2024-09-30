#include "SampleClass2.h"
#include <iostream>

SampleClass2::SampleClass2()
{   

	//std::function<> 포인터에 함수를 넣을 경우

	// 자기 클래스의 멤버 변수에 함수 위치를 넣을 때도
	// 함수 위치를 가리킬 때는 여전히 클래스명을 포함해야 한다
	// = 클래스명 자체가 함수 이름에 포함되어 있고 , 
	// 이 자체가 추가 규격이라고 해석하는 편이 좋다

	ptr = std::bind(&SampleClass2::Function2, this);
	// this : 이 클래스에서 만들어질 ㅡ 인스턴스 = 나 자신을 가리키는 포인터
	// *이 this 자리에 다른 클래스 멤버 변수가 들어간다면
	// 해당 객체의 인스턴스나 위치를 나타낼 변수를 넣어주면 된다.

	// 이 클래스의 ptr을 메인 함수에서 써보면 호출 가능 여부를 알 수 있다.
}

SampleClass2::~SampleClass2()
{
}

void SampleClass2::Function1()
{
    std::cout << "클래스 2, 함수 1" << std::endl;
}

void SampleClass2::Function2()
{
    std::cout << "클래스 2, 함수 2" << std::endl;
}
