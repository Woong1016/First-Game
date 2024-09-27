#pragma once
#include "SampleSingleton.h"

//싱글턴 클래스를 써보기 위한 시험용 클래스

class SampleSingletonTest
{

public:

    // 값 정하기 (싱글턴 속 data 수정)
    void SetValue(int value);

    // 값 구하기 (싱글턴 속 data 호출)
    int GetValue();

};

