#include "ListController.h"

void ListController::AddElementInt(std::list<int>* list, int index, int value)
{
    // main �ؿ� �ִ� ���� �Լ��� ����.
    // ���̴� �Ű������� �����ͷ� �޾Ƽ� ���� �����Ѵٴ� �ͻ�

    std::list<int>::iterator iter = list->begin(); // �������̹Ƿ� -> ������

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
