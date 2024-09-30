#include "SampleClass1.h"
#include <iostream>

SampleClass1::SampleClass1()
{
	// 여기서 함수 포인터 적용해보기를 하면..

	//ptr = Function1; // 불가능
	//ptr = &SampleClass1::Function1; //불가능
	
	// 가능한 사례는 function2에서 확인

}

SampleClass1::~SampleClass1()
{
}

void SampleClass1::Function1()
{
    std::cout << "클래스 1, 함수 1" << std::endl;
}

void SampleClass1::Function2()
{
    std::cout << "클래스 1, 함수 2" << std::endl;
}
