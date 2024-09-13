#include "Homework.h"

Homework::Homework()
{
    // 강의 복습
    std::pair<int, std::string> word = {0, "사과"};
    dic.insert(word);

    word = { 1, "배" };
    dic.insert(word);

    word = { 2, "바나나" };
    dic.insert(word);

    // 생성자 활용
    // "자료 구조는, std::뒤 초록글씨는 클래스입니다." 기억하고 계시죠?
    // -> 그러므로 클래스의 생성자 문법을 시험해보면 과연 어떻게 될까요?
    // -> 개발자는 눈앞의 지식을 암기만 하지 않고, 도전과 시행착오를 해보는 것도 좋습니다.

    dic.insert(std::pair<int, std::string>(3, "딸기"));
    dic.insert(std::pair<int, std::string>(4, "포도"));
    dic.insert(std::pair<int, std::string>(5, "머루"));
}

Homework::~Homework()
{
}

void Homework::Run()
{
    int input = 0;                  // 숫자 입력 변수
    std::string inputSTR = "";      // 문자 입력 변수

    while (true)
    {
        system("cls");

        ShowAllWord();

        input = GetInput();

        if (input < 1 || input > 4)
        {
            std::cout << "잘못된 입력입니다." << std::endl;
            system("pause");
            continue;
        }

        if (input == 4)
        {
            std::cout << "과일 목록 관리를 마칩니다." << std::endl;
            break;
        }

        switch (input)
        {
        case 1: //단어 추가하기
            inputSTR = GetString();
            if (IsValid(inputSTR))      //목록에 중복이 있는지 확인
            {
                std::cout << "단어 " << inputSTR << "를 목록에 추가합니다." << std::endl;
                AddWord(inputSTR);
            }
            else
            {
                std::cout << "단어 " << inputSTR << "가 목록에 있습니다." << std::endl;
            }
            system("pause");
            break;

        case 2: //단어 지우기 (번호로 지정)
            input = GetNumber();
            RemoveIndex(input);
            std::cout << input << "번 단어를 목록에서 지웁니다." << std::endl;
            system("pause");
            break;

        case 3:
            inputSTR = GetString();
            RemoveWord(inputSTR);
            std::cout << "단어 " << inputSTR << "를 지웁니다." << std::endl;
            system("pause");
            break;
        }
    }

    
}

void Homework::ShowAllWord()
{
    // 맵의 []가 인덱스 연산자가 아니라면 반복문은 어떻게?
    // -> 반복자. "맵도 자료 구조입니다." 그러므로 반복자가 있습니다.

    std::cout << "과일 목록" << std::endl;

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

    std::cout << "행동을 입력해주세요." << std::endl;
    std::cout << "1. 단어 추가, 2. 번호로 삭제, ";
    std::cout << "3. 단어로 삭제, 4. 마치기" << std::endl;
    std::cout << "내 입력 : ";
    std::cin >> input;

    return input;
}

int Homework::GetNumber()
{
    int input;

    std::cout << "번호를 입력해주세요." << std::endl;
    std::cout << "내 입력 : ";
    std::cin >> input;

    return input;
}

std::string Homework::GetString()
{
    std::string str;

    std::cout << "단어를 입력해주세요." << std::endl;
    std::cout << "내 입력 : ";
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
    dic.erase(index);   // 맵에서 지우기 = [] 안에 들어갈 "키 값" 바로 주기
                        // 왜? 여긴 '메모리'나 '순번'의 판단이 없으니까
}

bool Homework::IsValid(std::string word)
{
    bool result = true;

    std::map<int, std::string>::iterator iter = dic.begin();
    for (; iter != dic.end(); iter++)
    {
        if (word.compare((*iter).second) == 0) // compare라는 함수 활용
        {
            result = false; // 중복을 확인 (자세한 이야기는 바로 밑에서)
            break;          // 중복 확인 후 반복문 중단
        }

        // * compare : string 기능의 부가 기본 함수 중 하나.
        // compare를 호출한 문자열과, 매개변수로 들어간 문자열을 서로 비교해서
        // 판별한 관계를 숫자로 반환한다.
        // 반환 결과가 1인 경우 : 호출한 문자열(여기서는 word)이 사전상 뒤에 있다
        // -1인 경우 : 호출한 문자열이 사전상 앞에 있다
        // 0인 경우 : 호출한 문자열과 매개변수가 완전히 일치한다
    }

    return result;
}

void Homework::RemoveWord(std::string word)
{
    // 단어를 직접 지우는 것도 어렵지 않습니다. 반복자와 반복문을 쓰면 돼요.
    // 바로 위 함수에서 중복 검사할 때처럼. 혹은.... 빙고에서 칸 지울 때처럼.

    std::map<int, std::string>::iterator iter = dic.begin();
    for (; iter != dic.end(); iter++)
    {
        if (word.compare((*iter).second) == 0) // 일치하는 단어가 있다면...
        {
            dic.erase((*iter).first);   // 그 단어의 key 값을 지우면 됩니다.

            break;  // 어차피 중복 검사 해가면서 단어 추가했으니 중복도 없을 거고
                    // 단어 지웠으니 굳이 연산을 더 하진 않아도 됩니다.
        }
        
    }
}
