#include "Shop.h"

Shop::Shop()
{
    inventory = new Inventory(); // �κ��丮 ����

    // �������� �����ͷ� ����
    // ���� : �����͸� ���� ������ ������ �����͸� ����ϱ� ����
    // ( * �����Ͱ� ���� ��, �����͸� �Ű����� � ������ ����� ����սô�)
    Item* shortSword = new Item(0, "ª�� Į", 100);
    Item* armingSword = new Item(1, "����� Į", 300);
    Item* cutlass = new Item(2, "ĿƲ��", 350);
    Item* scimitar = new Item(3, "�ù���", 400);
    Item* longsword = new Item(4, "�� Į", 1500);
    Item* zweihander = new Item(5, "��տ� Į", 1800);
    Item* knife = new Item(6, "������", 50);

    // ���Ϳ� ���� ������ �ϳ��� �߰��ϱ�
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

        std::cout << "������ ������" << std::endl;
        ShowDisplay();  // ���� ������ ���

        std::cout << std::endl;

        std::cout << "�� ������" << std::endl;
        ShowInventory();    //�� ������ ���

        std::cout << std::endl;

        std::cout << "�ൿ �����ϱ� : ";
        std::cout << "1. ���, 2. �ȱ�, 3. ������" << std::endl;
        std::cout << "�� �Է� : ";
        
        input = GetInput(); //�Է��� �Լ��� ���� "�Է��� �޴´�"�� ���� ���

        // ���� �Է� �ɷ�����
        if (input < 1 || input > 3)
        {
            std::cout << "�߸��� �����Դϴ�." << std::endl;
            system("pause");
            continue;
        }

        //���� ��ġ��
        if (input == 3)
        {
            std::cout << "���� ����� ��Ĩ�ϴ�." << std::endl;
            break;
        }

        // �Է��� 1�̳� 2�Ŀ� ���� ��� ���ϱ�
        switch (input)
        {
        case 1:

            //�� ������ ���� ���
            if (display.size() < 1)
            {
                std::cout << "������ ������ ���������ϴ�." << std::endl;
                break;
            }

            // �Է� �̾ �ޱ�
            std::cout << "����� ������ ��ȣ�� �Է��ϼ��� : ";
            input = GetInput();

            std::cout << std::endl;

            //�߸��� ���� �Ÿ���
            if (input < 1 || input > display.size()) // ����ǰ ���� ��Ż
            {
                std::cout << "�߸��� �����Դϴ�." << std::endl;
            }
            else
            {
            // ��Ʈ : �ۿ� ���� ��Ұ� �ִٸ� ���� ������ �˻縦 �ؾ� �� �̴ϴ�.
            // �ѹ� ������ �ο��ؼ� ���� �ȿ��� ��� �� �� �ְ� �غ��ô�.

                int index = input - 1;

                std::cout << display[index]->GetName();
                std::cout << " �������� �����մϴ�." << std::endl;

                Buy(index);
            }

            break;

        case 2:

            if (inventory->IsEmpty()) // ����ǰ�� �ϳ��� ���� ���
            {
                std::cout << "����ǰ�� �����ϴ�." << std::endl;
                break;
            }

            std::cout << "�ȷ��� ������ ��ȣ�� �Է��ϼ��� : ";
            input = GetInput();

            std::cout << std::endl;

            if (input < 1 || input > inventory->Size())
            {
                std::cout << "�߸��� �����Դϴ�." << std::endl;
            }
            else
            {
                int index = input - 1;

                std::cout << inventory->GetName(index);
                std::cout << " �������� �Ǹ��մϴ�." << std::endl;

                Sell(index);

                // ��Ʈ : �÷��̾�� ���� �ִٸ� ���⼭ ������ ���� �̴ϴ�.
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
        std::cout << "������ �������� �����ϴ�." << std::endl;
        return;
    }

    // ��Ʈ : size ��ſ� empty�� �Ẹ����!

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
    // (�÷��̾) ���
    inventory->AddItem(display[index]); // �κ��丮�� �ֱ�
    display.erase(display.begin() + index); // �������� ����

    // ���� ������ �κ��丮���� �˾Ƽ� �ϵ���
}

void Shop::Sell(int index)
{
    display.push_back(inventory->GetItem(index)); // ������ �ȱ�
    inventory->RemoveItem(index); // �κ��丮���� ����

    Sort(); // ������ ���� ������ �����ϱ�
}
