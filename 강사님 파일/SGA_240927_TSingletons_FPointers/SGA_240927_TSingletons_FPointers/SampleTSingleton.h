#pragma once
#include "Singleton.h"

// ���ø� �̱��� �Ẹ��

class SampleTSingleton : public Singleton<SampleTSingleton>
    // �̱��� Ŭ������ ��ӹ��� ��, ���ø����� �ڱ� Ŭ���� �̸��� ����
    // -> �� Ŭ������ �̸��� �̱������� ����� ��𼭵� ȣ���� �� �ִ�
    //    ������ �����ͷ� ���� �� �ִ�.
{
public:

    SampleTSingleton();     // ���ø� �̱����� �����ڿ� �Ű����� x
    ~SampleTSingleton();

    int data[10];               // <- ������

    // * �ζ��� �Լ� ����
    inline int Add(int x, int y) { return x + y; }
    // �̰� �ٸ� ������ �����ϸ� Add�� �ƴ� �ؽ�Ʈ�� �ٲ��


};

