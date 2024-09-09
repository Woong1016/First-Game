#pragma once
#include <iostream>
#include <string>

class Item
{   
public:

    Item(int _id, std::string _name, int _cost);
    ~Item();

    void Print();
    int GetID() { return id; }

    // 외부정보 (겟터)
    std::string GetName() { return name; }

private:

    int id;
    std::string name;

    int cost;

};

