#include "SampleSingletonTest.h"

void SampleSingletonTest::SetValue(int value)
{
    //�޾ƿ� �Ű������� �̱��� �����Ϳ� �״�� �ֱ�
    SampleSingleton::Get()->data = value;
}

int SampleSingletonTest::GetValue()
{
    return SampleSingleton::Get()->data;
}
