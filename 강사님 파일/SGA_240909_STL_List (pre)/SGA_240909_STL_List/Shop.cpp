#include "Shop.h"

Shop::Shop()
{
    inventory = new Inventory(); // 인벤토리 생성

    // 아이템을 포인터로 생성
    // 이유 : 포인터를 통해 동일한 아이템 데이터를 사용하기 위해
    // ( * 포인터가 없을 때, 데이터를 매개변수 등에 넣으면 어땠는지 기억합시다)
    Item* shortSword = new Item(0, "짧은 칼", 100);
    Item* armingSword = new Item(1, "군장용 칼", 300);
    Item* cutlass = new Item(2, "커틀라스", 350);
    Item* scimitar = new Item(3, "시미터", 400);
    Item* longsword = new Item(4, "긴 칼", 1500);
    Item* zweihander = new Item(5, "양손용 칼", 1800);
    Item* knife = new Item(6, "나이프", 50);

    // 벡터에 만든 아이템 하나씩 추가하기
    display.push_back(shortSword);
    display.push_back(armingSword);
    display.push_back(cutlass);
    display.push_back(scimitar);
    display.push_back(longsword);
    display.push_back(zweihander);
    display.push_back(knife);
}

Shop::~Shop()
{
}

void Shop::Run()
{
    int input = 0;

    while (true)
    {
        system("cls");

        std::cout << "상점의 아이템" << std::endl;
        ShowDisplay();  // 상점 아이템 출력

        std::cout << std::endl;

        std::cout << "내 아이템" << std::endl;
        ShowInventory();    //내 아이템 출력

        std::cout << std::endl;

        std::cout << "행동 선택하기 : ";
        std::cout << "1. 사기, 2. 팔기, 3. 끝내기" << std::endl;
        std::cout << "내 입력 : ";
        
        input = GetInput(); //입력은 함수를 통해 "입력을 받는다"는 것을 명시

        // 나쁜 입력 걸러내기
        if (input < 1 || input > 3)
        {
            std::cout << "잘못된 선택입니다." << std::endl;
            system("pause");
            continue;
        }

        //상점 마치기
        if (input == 3)
        {
            std::cout << "상점 기능을 마칩니다." << std::endl;
            break;
        }

        // 입력이 1이냐 2냐에 따른 기능 정하기
        switch (input)
        {
        case 1:

            //살 물건이 없는 경우
            if (display.size() < 1)
            {
                std::cout << "상점에 물건이 떨어졌습니다." << std::endl;
                break;
            }

            // 입력 이어서 받기
            std::cout << "사려는 물건의 번호를 입력하세요 : ";
            input = GetInput();

            std::cout << std::endl;

            //잘못된 조작 거르기
            if (input < 1 || input > display.size()) // 소지품 범위 이탈
            {
                std::cout << "잘못된 선택입니다." << std::endl;
            }
            else
            {
            // 힌트 : 앱에 예산 요소가 있다면 먼저 소지금 검사를 해야 할 겁니다.
            // 한번 예산을 부여해서 범위 안에서 사고 팔 수 있게 해봅시다.

                int index = input - 1;

                std::cout << display[index]->GetName();
                std::cout << " 아이템을 구매합니다." << std::endl;

                Buy(index);
            }

            break;

        case 2:

            if (inventory->IsEmpty()) // 소지품이 하나도 없는 경우
            {
                std::cout << "소지품이 없습니다." << std::endl;
                break;
            }

            std::cout << "팔려는 물건의 번호를 입력하세요 : ";
            input = GetInput();

            std::cout << std::endl;

            if (input < 1 || input > inventory->Size())
            {
                std::cout << "잘못된 선택입니다." << std::endl;
            }
            else
            {
                int index = input - 1;

                std::cout << inventory->GetName(index);
                std::cout << " 아이템을 판매합니다." << std::endl;

                Sell(index);

                // 힌트 : 플레이어에게 돈이 있다면 여기서 수입이 생길 겁니다.
            }
        
            break;
        }

        system("pause");
    }
}

void Shop::ShowDisplay()
{
    if (display.size() < 1)
    {
        std::cout << "상점에 아이템이 없습니다." << std::endl;
        return;
    }

    // 힌트 : size 대신에 empty도 써보세요!

    for (int i = 0; i < display.size(); ++i)
    {
        std::cout << i + 1 << ". ";

        display[i]->Print();

        std::cout << std::endl;
    }
}

void Shop::ShowInventory()
{
    inventory->ShowInventory();
}

int Shop::GetInput()
{
    int input;
    std::cin >> input;
    return input;
}

void Shop::Sort()
{
    for (int i = 0; i < display.size(); ++i)
    {
        for (int j = 0; j < (display.size() - 1 - i); ++j)
        {
            if (display[j]->GetID() > display[j + 1]->GetID())
            {
                //Item* tmp = display[j];
                //display[j] = display[j + 1];
                //display[j + 1] = tmp;

                std::swap(display[j], display[j + 1]);
            }
        }
    }
}

void Shop::Buy(int index)
{
    // (플레이어가) 사기
    inventory->AddItem(display[index]); // 인벤토리에 넣기
    display.erase(display.begin() + index); // 상점에서 빼기

    // 벡터 정렬은 인벤토리에서 알아서 하도록
}

void Shop::Sell(int index)
{
    display.push_back(inventory->GetItem(index)); // 상점에 팔기
    inventory->RemoveItem(index); // 인벤토리에서 빼기

    Sort(); // 상점에 들어온 아이템 정렬하기
}
