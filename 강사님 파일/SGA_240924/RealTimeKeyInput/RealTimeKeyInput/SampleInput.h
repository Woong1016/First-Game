#pragma once
#include <iostream>
#include "RealTimeKeyInput.h"

class SampleInput
{
public:
    SampleInput();
    ~SampleInput();

private:
    void Run();

    int number;
    int input;
};

