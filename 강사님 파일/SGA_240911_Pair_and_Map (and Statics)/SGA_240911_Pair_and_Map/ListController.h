#pragma once
#include <list>

class ListController
{
public:

    void AddElementInt(std::list<int>* list, int index, int value);
    void RemoveElementInt(std::list<int>* list, int index);

};

