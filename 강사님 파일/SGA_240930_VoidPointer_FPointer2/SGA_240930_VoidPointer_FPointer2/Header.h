#pragma once
#include <iostream>
#include <functional>

void (*fPtr1)();
std::function<void()> fPtr2;

void SampleFunction()
{
    std::cout << "�� �Լ��� ���� ������� ���� ���� �Լ��Դϴ�." << std::endl;
}