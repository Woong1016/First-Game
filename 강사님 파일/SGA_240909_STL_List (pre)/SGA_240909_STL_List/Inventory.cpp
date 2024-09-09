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
        std::cout << "�� ����ǰ�� �����ϴ�." << std::endl;
        return;

        // ��Ʈ : size ��ſ� empty�� �Ẹ����!
    }

    for (int i = 0; i < inventory.size(); ++i)
    {
        std::cout << i + 1 << ". "; // ��� �� ��ȣ
        
        inventory[i]->Print(); // ������ ���
        
        std::cout << std::endl;	// �� �ٲ�
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


				// ���� �� ��Ʈ�� ����� ����� ��� �Ʒ� �Լ��� ��밡��
			

                std::swap(inventory[j], inventory[j + 1]);
				//swap: �迭 Ȥ�� ���Ϳ��� �Լ��� �� �Ű����� ����
							// ���� ����� ���� �¹ٲ۴�
            }
        }
    }

}
