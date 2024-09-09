#pragma once
#include "Item.h"
#include "Inventory.h"

class Shop
{
public:

    Shop();
    ~Shop();

    void Run();                 // ���� ��� ����

private:
    void ShowDisplay();         // ������ ���
    void ShowInventory();       // �κ��丮 ���

    int GetInput();
    void Sort();

    // ���� �Լ� ����� �����ϴ� ��� ���忡�� �����ϴ�.
    void Buy(int index);        // ��� (�������� �κ��丮�� �̵�)
    void Sell(int index);       // �ȱ� (�κ��丮���� �������� �̵�)

private:

    Inventory* inventory; // �κ��丮 (�� ������) : �ٸ� Ŭ������ �ϳ� ��

    std::vector<Item*> display; // ���� ����
								// <>�ȿ� �  �ڷ����̶� �� �� �ִ�. �� ���� �ǹ̴�?????
								// <>�ȿ� ���� �� Ŭ������ OK��� ��
};

