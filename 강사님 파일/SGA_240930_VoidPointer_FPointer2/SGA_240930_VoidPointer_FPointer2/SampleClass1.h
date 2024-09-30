#pragma once
#include <functional>

class SampleClass1
{
public:
    SampleClass1();
    ~SampleClass1();

    void Function1();
    void Function2();

    void (*ptr)() = nullptr;  // 일반 포인터 문법을 사용할 경우
};

