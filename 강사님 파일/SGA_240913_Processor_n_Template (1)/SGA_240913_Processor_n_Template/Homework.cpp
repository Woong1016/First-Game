#include "Homework.h"

Homework::Homework()
{
    // ���� ����
    std::pair<int, std::string> word = {0, "���"};
    dic.insert(word);

    word = { 1, "��" };
    dic.insert(word);

    word = { 2, "�ٳ���" };
    dic.insert(word);

    // ������ Ȱ��
    // "�ڷ� ������, std::�� �ʷϱ۾��� Ŭ�����Դϴ�." ����ϰ� �����?
    // -> �׷��Ƿ� Ŭ������ ������ ������ �����غ��� ���� ��� �ɱ��?
    // -> �����ڴ� ������ ������ �ϱ⸸ ���� �ʰ�, ������ ���������� �غ��� �͵� �����ϴ�.

    dic.insert(std::pair<int, std::string>(3, "����"));
    dic.insert(std::pair<int, std::string>(4, "����"));
    dic.insert(std::pair<int, std::string>(5, "�ӷ�"));
}

Homework::~Homework()
{
}

void Homework::Run()
{
    int input = 0;                  // ���� �Է� ����
    std::string inputSTR = "";      // ���� �Է� ����

    while (true)
    {
        system("cls");

        ShowAllWord();

        input = GetInput();

        if (input < 1 || input > 4)
        {
            std::cout << "�߸��� �Է��Դϴ�." << std::endl;
            system("pause");
            continue;
        }

        if (input == 4)
        {
            std::cout << "���� ��� ������ ��Ĩ�ϴ�." << std::endl;
            break;
        }

        switch (input)
        {
        case 1: //�ܾ� �߰��ϱ�
            inputSTR = GetString();
            if (IsValid(inputSTR))      //��Ͽ� �ߺ��� �ִ��� Ȯ��
            {
                std::cout << "�ܾ� " << inputSTR << "�� ��Ͽ� �߰��մϴ�." << std::endl;
                AddWord(inputSTR);
            }
            else
            {
                std::cout << "�ܾ� " << inputSTR << "�� ��Ͽ� �ֽ��ϴ�." << std::endl;
            }
            system("pause");
            break;

        case 2: //�ܾ� ����� (��ȣ�� ����)
            input = GetNumber();
            RemoveIndex(input);
            std::cout << input << "�� �ܾ ��Ͽ��� ����ϴ�." << std::endl;
            system("pause");
            break;

        case 3:
            inputSTR = GetString();
            RemoveWord(inputSTR);
            std::cout << "�ܾ� " << inputSTR << "�� ����ϴ�." << std::endl;
            system("pause");
            break;
        }
    }

    
}

void Homework::ShowAllWord()
{
    // ���� []�� �ε��� �����ڰ� �ƴ϶�� �ݺ����� ���?
    // -> �ݺ���. "�ʵ� �ڷ� �����Դϴ�." �׷��Ƿ� �ݺ��ڰ� �ֽ��ϴ�.

    std::cout << "���� ���" << std::endl;

    std::map<int, std::string>::iterator iter = dic.begin();
    for (; iter != dic.end(); iter++)
    {
        std::cout << (*iter).first << " : ";
        std::cout << (*iter).second << std::endl;
    }
}

int Homework::GetInput()
{
    int input;

    std::cout << "�ൿ�� �Է����ּ���." << std::endl;
    std::cout << "1. �ܾ� �߰�, 2. ��ȣ�� ����, ";
    std::cout << "3. �ܾ�� ����, 4. ��ġ��" << std::endl;
    std::cout << "�� �Է� : ";
    std::cin >> input;

    return input;
}

int Homework::GetNumber()
{
    int input;

    std::cout << "��ȣ�� �Է����ּ���." << std::endl;
    std::cout << "�� �Է� : ";
    std::cin >> input;

    return input;
}

std::string Homework::GetString()
{
    std::string str;

    std::cout << "�ܾ �Է����ּ���." << std::endl;
    std::cout << "�� �Է� : ";
    std::cin >> str;

    return str;
}

void Homework::AddWord(std::string word)
{
    int nextIndex = dic.size();
    dic.insert(std::pair<int, std::string>(nextIndex, word));
}

void Homework::RemoveIndex(int index)
{
    dic.erase(index);   // �ʿ��� ����� = [] �ȿ� �� "Ű ��" �ٷ� �ֱ�
                        // ��? ���� '�޸�'�� '����'�� �Ǵ��� �����ϱ�
}

bool Homework::IsValid(std::string word)
{
    bool result = true;

    std::map<int, std::string>::iterator iter = dic.begin();
    for (; iter != dic.end(); iter++)
    {
        if (word.compare((*iter).second) == 0) // compare��� �Լ� Ȱ��
        {
            result = false; // �ߺ��� Ȯ�� (�ڼ��� �̾߱�� �ٷ� �ؿ���)
            break;          // �ߺ� Ȯ�� �� �ݺ��� �ߴ�
        }

        // * compare : string ����� �ΰ� �⺻ �Լ� �� �ϳ�.
        // compare�� ȣ���� ���ڿ���, �Ű������� �� ���ڿ��� ���� ���ؼ�
        // �Ǻ��� ���踦 ���ڷ� ��ȯ�Ѵ�.
        // ��ȯ ����� 1�� ��� : ȣ���� ���ڿ�(���⼭�� word)�� ������ �ڿ� �ִ�
        // -1�� ��� : ȣ���� ���ڿ��� ������ �տ� �ִ�
        // 0�� ��� : ȣ���� ���ڿ��� �Ű������� ������ ��ġ�Ѵ�
    }

    return result;
}

void Homework::RemoveWord(std::string word)
{
    // �ܾ ���� ����� �͵� ����� �ʽ��ϴ�. �ݺ��ڿ� �ݺ����� ���� �ſ�.
    // �ٷ� �� �Լ����� �ߺ� �˻��� ��ó��. Ȥ��.... ������ ĭ ���� ��ó��.

    std::map<int, std::string>::iterator iter = dic.begin();
    for (; iter != dic.end(); iter++)
    {
        if (word.compare((*iter).second) == 0) // ��ġ�ϴ� �ܾ �ִٸ�...
        {
            dic.erase((*iter).first);   // �� �ܾ��� key ���� ����� �˴ϴ�.

            break;  // ������ �ߺ� �˻� �ذ��鼭 �ܾ� �߰������� �ߺ��� ���� �Ű�
                    // �ܾ� �������� ���� ������ �� ���� �ʾƵ� �˴ϴ�.
        }
        
    }
}
