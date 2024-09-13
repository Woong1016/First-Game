#include "ListController.h"

void ListController::AddElementInt(std::list<int>* list, int index, int value)
{
    // main 밑에 있던 전역 함수와 같다.
    // 차이는 매개변수를 포인터로 받아서 직접 수정한다는 것뿐

    std::list<int>::iterator iter = list->begin(); // 포인터이므로 -> 연산자

    for (int i = 0; i < index; i++)
    {
        iter++;
    }

    list->emplace(iter, value);
    //list->insert(iter, value);
}

void ListController::RemoveElementInt(std::list<int>* list, int index)
{
    std::list<int>::iterator iter = list->begin();
    for (int i = 0; i < index; i++, iter++) {}

    list->erase(iter);
}
