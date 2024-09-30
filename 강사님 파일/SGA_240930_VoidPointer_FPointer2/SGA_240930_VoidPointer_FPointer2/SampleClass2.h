#pragma once
#include <functional>

class SampleClass2
{
public:
    SampleClass2();
    ~SampleClass2();

    void Function1();
    void Function2();

    std::function<void()> ptr = nullptr; // c++ 함수 기능을 사용할 경우
};

