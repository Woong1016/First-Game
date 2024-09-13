#pragma once
#include <list>

class SampleStaticClass
{
public:

    static void AddElementInt(std::list<int>* list, int index, int value);
    static void RemoveElementInt(std::list<int>* list, int index);
};

