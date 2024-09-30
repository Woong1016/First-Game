#pragma once
#include <iostream>
#include <functional>

void (*fPtr1)();
std::function<void()> fPtr2;

void SampleFunction()
{
    std::cout << "이 함수는 전역 헤더에서 만든 전역 함수입니다." << std::endl;
}