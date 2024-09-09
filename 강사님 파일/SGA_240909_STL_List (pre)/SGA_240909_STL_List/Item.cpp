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

    std::cout << "이름 : " << name << " / ";

    std::cout << "가격 : " << cost;
}
