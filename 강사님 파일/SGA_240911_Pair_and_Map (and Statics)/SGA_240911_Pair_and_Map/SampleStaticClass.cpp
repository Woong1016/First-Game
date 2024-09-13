#include "SampleStaticClass.h"

void SampleStaticClass::AddElementInt(std::list<int>* list, int index, int value)
{
    std::list<int>::iterator iter = list->begin();
    for (int i = 0; i < index; i++, iter++) {}
    list->emplace(iter, value);
}

void SampleStaticClass::RemoveElementInt(std::list<int>* list, int index)
{
    std::list<int>::iterator iter = list->begin();
    for (int i = 0; i < index; i++, iter++) {}
    list->erase(iter);
}
