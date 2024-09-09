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

    //외부정보
    std::string GetName(int index) { return inventory[index]->GetName(); }
    Item* GetItem(int index) { return inventory[index]; }
    
    int Size() { return inventory.size(); }
    bool IsEmpty() { return (inventory.size() < 1); }
							// inventory .empty() 도 좋지만 size ()가 좀더 엄밀

private:

    void Sort();

    std::vector<Item*> inventory; // 내 아이템 벡터

    // * Item의 데이터는 사용하지만, 클래스 안에서 Item 데이터는 쓰지 않습니다.
    // 아이템은 상점에서 생성할 겁니다. 이 클래스도 마찬가지고요.

    //-----------------------------------------
    // 비교해보기 : 이쪽 함수와 변수를 사용한다면?
    void AddItem(Item item) {}			// 포인터 아닌 데이터?
    std::vector<Item*> inventoryData;
};

