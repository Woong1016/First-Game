#pragma once
#include <iostream>

// 클래스 "인간" : 모든 인간의 기본 바탕 클래스

// 플밍 용어로는 "부모 클래스" (parent)

class Human
{

    // 여기서 인간의 특성을 표현

public: // 공개 코드

    // 예시용 변수, 함수 하나씩

    int age;        // 나이
    void Eat();     // 먹는 행동

private: // 비공개 코드

    float height;   // 키
    void Wash();    // 씻는 행동

    
    // 클래스 상속이 사용되는 시점에서 사용 가능한
    // 세 번째 접근 지정자가 존재한다

    // 바로 "부모 자식 클래스 사이에서는 같이 쓸 수 있는데"
    // "완전 밖에서는 쓸 수 없고 보이지 않는 데이터"
    // = 보호 데이터를 만드는 것.

protected: // pritvate, public에 이은 세 번째 접근 지정자
           // 보호 데이터를 의미한다.

    float weight;       // 체중
    void Workout();     // 헬스

    // 확인 : 클래스에는 private, public, protected 세 접근 지정자가 존재

    // 개방되는 정도는 public > protected > private 순

    // 혹은 질문과 답변을 사용해보면...

    //                1. 밖에서 쓸 수 있는가? // 2. 자식 클래스가 쓸 수 있는가?
    // private :         No                        No
    // protected :       No                        Yes
    // public :          Yes                       Yes

};

