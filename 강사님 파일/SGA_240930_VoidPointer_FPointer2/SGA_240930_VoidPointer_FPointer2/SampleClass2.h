#pragma once
#include <functional>

class SampleClass2
{
public:
    SampleClass2();
    ~SampleClass2();

    void Function1();
    void Function2();

    std::function<void()> ptr = nullptr; // c++ �Լ� ����� ����� ���
};

