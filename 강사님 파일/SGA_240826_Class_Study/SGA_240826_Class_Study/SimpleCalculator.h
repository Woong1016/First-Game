#pragma once
#include <iostream>

// 단순 계산기 클래스

class SimpleCalculator
{
public : // 이 아래 코드는 외부에 공개됩니다.
    // 이 클래스가 할 수 있는 것
    // : 이 클래스를 이용해 실제 데이터(=인스턴스=객체)를 만들었을 경우
    //   부른 장소(지금은 테스트 클래스나 main() 등)에서 시켜야 하는 것

    // = 기능들
    void InputNumber(); // 숫자 입력하기
    void SelectOps();   // 연산 선택하기

private: // 이 아래 코드는 보여주지 않습니다.

    // 계산기가 입력받은 숫자 그 자체
    // 그냥 입력 받았은 대로 계산만 잘 하면 좋은 것 아닐까요?
    int first;
    int second;

    int operation; // 연산

    // * 복습하는 경우 반짝 도전 : 아래 변수로 위 operation을 대체할 수 있을까요?
    char opCode; // 테스트용 변수

    // 계산기가 실제로 하는 계산
    // -> 사용자가 연산선택(cin)으로 시키면 main()에서 굳이 길게 안 적어도
    // 그냥 얘가 알아서 계산하면 좋겠다.....고 생각하고 작성합니다.

    int Add();
    int Subtract();
    int Multiply();
    int Divide();
    int Remains();
    
    // 그리고 숫자를 출력하는 기능
    // : 계산을 시켰으면 출력도 계산기가 알아서 하면 되지 않나?
    //   ......라고 생각해보고 작성합니다.

    void ShowResult();

    //연산자를 조건문에서 빨리 읽고 쓰기 위한 열거형
    enum OPCODE
    {
        ADD = 1,
        SUBTRACT,   // ADD가 1인데 아랫줄이라 자동으로 다음 숫자 2
        MULT,       // 3
        DIVIDE      // 4
    };
};

