#pragma once
#include <functional>

class SampleClass1
{
public:
    SampleClass1();
    ~SampleClass1();

    void Function1();
    void Function2();

    void (*ptr)() = nullptr;  // �Ϲ� ������ ������ ����� ���
};

