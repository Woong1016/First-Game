#include "SampleSingletonTest.h"

void SampleSingletonTest::SetValue(int value)
{
    //받아온 매개변수를 싱글턴 데이터에 그대로 넣기
    SampleSingleton::Get()->data = value;
}

int SampleSingletonTest::GetValue()
{
    return SampleSingleton::Get()->data;
}
