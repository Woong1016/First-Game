#include "Item.h"

Item::Item(int _id, std::string _name, int _cost) :
    id(_id), name(_name), cost(_cost)
{
}

Item::~Item()
{
}

void Item::Print()
{
    std::cout << "ID : " << id << " / ";

    std::cout << "�̸� : " << name << " / ";

    std::cout << "���� : " << cost;
}
