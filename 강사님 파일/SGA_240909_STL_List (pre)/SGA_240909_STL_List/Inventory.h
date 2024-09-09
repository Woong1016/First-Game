#pragma once
#include <vector>
#include "Item.h"

class Inventory
{
public:

    Inventory();
    ~Inventory();

    void AddItem(Item* item);
    void RemoveItem(int index);

    void ShowInventory();

    //�ܺ�����
    std::string GetName(int index) { return inventory[index]->GetName(); }
    Item* GetItem(int index) { return inventory[index]; }
    
    int Size() { return inventory.size(); }
    bool IsEmpty() { return (inventory.size() < 1); }
							// inventory .empty() �� ������ size ()�� ���� ����

private:

    void Sort();

    std::vector<Item*> inventory; // �� ������ ����

    // * Item�� �����ʹ� ���������, Ŭ���� �ȿ��� Item �����ʹ� ���� �ʽ��ϴ�.
    // �������� �������� ������ �̴ϴ�. �� Ŭ������ �����������.

    //-----------------------------------------
    // ���غ��� : ���� �Լ��� ������ ����Ѵٸ�?
    void AddItem(Item item) {}			// ������ �ƴ� ������?
    std::vector<Item*> inventoryData;
};

