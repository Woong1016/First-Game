#include "Inventory.h"

Inventory::Inventory()
{
    inventory.clear();
}

Inventory::~Inventory()
{
}

void Inventory::AddItem(Item* item)
{
    inventory.push_back(item);
    Sort();
}

void Inventory::RemoveItem(int index)
{
    inventory.erase(inventory.begin() + index);
}

void Inventory::ShowInventory()
{
    if (inventory.size() < 1)
    {
        std::cout << "내 소지품이 없습니다." << std::endl;
        return;

        // 힌트 : size 대신에 empty도 써보세요!
    }

    for (int i = 0; i < inventory.size(); ++i)
    {
        std::cout << i + 1 << ". "; // 목록 내 번호
        
        inventory[i]->Print(); // 아이템 출력
        
        std::cout << std::endl;	// 줄 바꿈
    }
}

void Inventory::Sort()
{
    for (int i = 0; i < inventory.size(); ++i)
    {
        for (int j = 0; j < (inventory.size() - 1 - i); ++j)
        {
            if (inventory[j]->GetID() > inventory[j + 1]->GetID())
            {
                //Item* tmp = inventory[j];
                //inventory[j] = inventory[j + 1];
                //inventory[j + 1] = tmp;


				// 벡터 및 스트링 기능을 사용할 경우 아래 함수를 사용가능
			

                std::swap(inventory[j], inventory[j + 1]);
				//swap: 배열 혹은 벡터에서 함수로 준 매개변수 둘의
							// 순번 기록을 서로 맞바꾼다
            }
        }
    }

}
