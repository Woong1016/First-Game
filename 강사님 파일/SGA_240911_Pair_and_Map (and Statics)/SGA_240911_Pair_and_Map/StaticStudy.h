#pragma once
#include <iostream> // 출력용

static int a = 0;
// int a = 0; // 이건 원래도 안 되고

// 이렇게 전역변수로 쓰고 있을 때는 어차피 최상위 우선순위라 잘 모른다

void DynamicVarTest() // 동적 변수 시험하기
{
    int num = 0; // 변수 선언

    for (int i = 0; i < 10; ++i) // 10번 반복하는 동안
    {
        num++; // 숫자 1씩 올리기
        std::cout << num << std::endl; // 숫자 출력
    }
    // 숫자 출력을 다 하면 절취선
    std::cout << "*************************" << std::endl;
}

void StaticVarTest() // 정적 변수 시험하기
{
    static int num = 0; // 정적 변수 선언

    for (int i = 0; i < 10; ++i) // 10번 반복하는 동안
    {
        num++; // 숫자 1씩 올리기
        std::cout << num << std::endl; // 숫자 출력
    }
    // 숫자 출력을 다 하면 절취선
    std::cout << "*************************" << std::endl;
}

// static의 응용 (함수 혹은 클래스에 적용할 경우)

// 클래스가 정적 선언의 대상인 경우
static class StaticClass {}; //딱히 내용은 없고, 그냥 이런 선언 자체가 중요

//class SampleA // 평범한 클래스의...
//{
//public:
//    int value;
//    static void Print() { std::cout << "Wa!" << std::endl; } // 정적 함수
//};
//
//class SampleB
//{
//public:
//    static SampleA data; // 평범한 클래스의 정적 인스턴스 만들기
//};