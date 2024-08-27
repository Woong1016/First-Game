#pragma once

// 단순 계산기 클래스...를 써보는 클래스
// = 클래스를 사용하는 클래스

#include "SimpleCalculator.h" // 그래서 계산기 클래스 사용
                              // 먼저 계산기부터 보고 옵시다.

class TestSimpleCalc
{
public:
    void Run(); // 계산기 실행

    // 클래스와 '인스턴스'가 서로 다르다는 것, 혹은
    // 같은 클래스(≒자료형)에서도 다른 개체가 나온다는 것을 확인하려면
    void TwoInstances();

private:

    SimpleCalculator calculcator; // 계산기

    // 제 2의 인스턴스 테스트용
    SimpleCalculator anotherInstance; // 또 다른 인스턴스

    // -> 이렇게 인스턴스를 준비해두면
    //    -> 이 클래스의(테스트) 인스턴스가 만들어질 때,
    //       -> 여기 있는 계산기의 인스턴스도 같이 만들어지는 것
};

