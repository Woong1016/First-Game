#include "TestSimpleCalc.h"

void TestSimpleCalc::Run()
{
    calculcator.InputNumber(); // 입력 시키기
    calculcator.SelectOps();   // 연산 선택하고 계산까지 하기

    // 이 두 동작을 묶으면 "계산기 실행"이라는 하나의 이름이 된다
}

void TestSimpleCalc::TwoInstances()
{
    calculcator.InputNumber(); // 입력을 시키고...
    anotherInstance.InputNumber(); // 같은 클래스의 다른 인스턴스도 실행

    // 그리고 각각 받은 입력을 다시 연산

    calculcator.SelectOps(); // 연산하기
    anotherInstance.SelectOps(); // 또 연산하기

    // 만약 인스턴스가 독립된 데이터가 아니었다면?
    // -> 같은 데이터였다면 두 번째 입력에 의한 결과가 두 번 나올 것
    //    (int a = 0이라고 하고, a = 100이라고 하면 a가 수정되는 것과 같다)

    // 하지만 인스턴스가 독립된 데이터라면?
    // 각각의 연산 입력 결과가 모두 다르게 나올 것이다
    // (int a = 0, int b = 1이라고 하고 a = 100 이라고 해도 b는 계속 1인 것과 같다)
}
