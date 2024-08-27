#include "SimpleCalculator.h"

void SimpleCalculator::InputNumber()
{
    std::cout << "----------------------------" << std::endl;
    std::cout << "단순 계산 기능을 실행합니다." << std::endl;
    std::cout << "숫자 둘을 차례로 입력해주세요." << std::endl;
    std::cout << "----------------------------" << std::endl;
    
    std::cout << "첫 번째 숫자 : ";
    std::cin >> first;
    
    std::cout << "두 번째 숫자 : ";
    std::cin >> second;
}

void SimpleCalculator::SelectOps()
{
    std::cout << "----------------------------" << std::endl;
    std::cout << "실행할 연산을 숫자로 선택해주세요." << std::endl;
    std::cout << "1 : 덧셈, 2 : 뺄셈, 3 : 곱셈, 4 : 나눗셈 " << std::endl;
    std::cout << "----------------------------" << std::endl;

    std::cout << "연산 코드 : ";
    std::cin >> operation;

    ShowResult(); // 입력 받았으면 기다릴 것 없이 그대로 결과까지 진행
}

int SimpleCalculator::Add()
{
    return first + second;
}

int SimpleCalculator::Subtract()
{
    return first - second;
}

int SimpleCalculator::Multiply()
{
    return first * second;
}

int SimpleCalculator::Divide()
{
    if (second == 0) return 0;
    else return first / second;
}

int SimpleCalculator::Remains()
{
    if (second == 0) return 0;
    else return first % second;
}

void SimpleCalculator::ShowResult()
{
    // 입력이 잘못되면 종료
    if (operation < 1 || operation > 4)
    {
        std::cout << "연산 선택 입력이 잘못되었습니다." << std::endl;
        return; // void에서만 가능한 '반환 결과 없는 return' : 함수 끝내버리기
    }

    int result = 0; // 결과 출력을 위한 지역 변수
    char opChar = ' '; // 연산자 텍스트 출력을 위한 문자 변수

    // 지역 변수에 연산 따라 결과 넣기

    switch (operation)
    {
    case ADD: // 열거형의 이름을 부른다 = 컴퓨터는 여기에 대응된 숫자로 이해한다
              // * 열거형에서 이름을 출력하면 숫자가 나오는 것으로 확인 가능

        result = Add(); // 덧셈 결과를 반환받아 저장
        opChar = '+';
        break;

    case SUBTRACT:
        result = Subtract();
        opChar = '-';
        break;

    case MULT:
        result = Multiply();
        opChar = '*';
        break;

    case DIVIDE:
        result = Divide();
        opChar = '/';
        break;
    }

    // 입력받은 결과와 문자를 출력....하기 전에 나눗셈만 따로 (연산항이 0인 경우)

    if (operation == DIVIDE && second == 0) // 하여간 이 숫자가 문제
    {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "0으로 나누기는 할 수 없습니다." << std::endl;
        std::cout << "계산에 무관하게 결과는 0입니다." << std::endl;
    }
    else
    {
        // 그리고 진짜로 출력
        // -> first도 second도... 다른 변수도 밖에서 안 보이는데?
        
        // : 안 보이는 건 first라는 데이터 그 자체뿐 (=접근권)
        //   해당 데이터를 출력하는 건 main()이 아니라, 이 함수, 다시 말해
        //   이 함수를 보유한 '단순 계산기 클래스' 본인(?)이다

        // 모니터에는 main이 아닌, 이 클래스가 실행한 연산의 결과가 나오는 것
        // -> 보는 사람 입장에선 아무튼 글자가 나오면 좋은 것

        std::cout << "-----------------------------" << std::endl;
        std::cout << first << " " << opChar << " " << second;
        std::cout << " = " << result << std::endl;

        if (operation == DIVIDE) // 나눗셈이라면 나머지도 계산하고 출력해보기
        {
            int remains = Remains();
            std::cout << "나머지는 " << remains << std::endl;
        }
    }

}
