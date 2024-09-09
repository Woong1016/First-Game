#pragma once
#include "Item.h"
#include "Inventory.h"

class Shop
{
public:

    Shop();
    ~Shop();

    void Run();                 // 상점 기능 실행

private:
    void ShowDisplay();         // 진열장 출력
    void ShowInventory();       // 인벤토리 출력

    int GetInput();
    void Sort();

    // 이하 함수 명명은 실행하는 사람 입장에서 적습니다.
    void Buy(int index);        // 사기 (상점에서 인벤토리로 이동)
    void Sell(int index);       // 팔기 (인벤토리에서 상점으로 이동)

private:

    Inventory* inventory; // 인벤토리 (내 아이템) : 다른 클래스로 하나 더

    std::vector<Item*> display; // 상점 진열
								// <>안에 어떤  자료형이라도 들어갈 수 있다. 그 말의 의미는?????
								// <>안에 들어가는 게 클래스라도 OK라는 뜻
};

