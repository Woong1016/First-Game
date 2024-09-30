#pragma once
#include "Singleton.h"

// 템플릿 싱글턴 써보기

class SampleTSingleton : public Singleton<SampleTSingleton>
    // 싱글턴 클래스를 상속받은 후, 템플릿으로 자기 클래스 이름을 지정
    // -> 내 클래스의 이름을 싱글턴으로 만들어 어디서든 호출할 수 있는
    //    유일한 데이터로 만들 수 있다.
{
public:

    SampleTSingleton();     // 템플릿 싱글턴은 생성자에 매개변수 x
    ~SampleTSingleton();

    int data[10];               // <- 데이터

    // * 인라인 함수 예시
    inline int Add(int x, int y) { return x + y; }
    // 이걸 다른 곳에서 실행하면 Add가 아닌 텍스트가 바뀐다


};

