#include "TestSimpleCalc.h"

void TestSimpleCalc::Run()
{
    calculcator.InputNumber(); // �Է� ��Ű��
    calculcator.SelectOps();   // ���� �����ϰ� ������ �ϱ�

    // �� �� ������ ������ "���� ����"�̶�� �ϳ��� �̸��� �ȴ�
}

void TestSimpleCalc::TwoInstances()
{
    calculcator.InputNumber(); // �Է��� ��Ű��...
    anotherInstance.InputNumber(); // ���� Ŭ������ �ٸ� �ν��Ͻ��� ����

    // �׸��� ���� ���� �Է��� �ٽ� ����

    calculcator.SelectOps(); // �����ϱ�
    anotherInstance.SelectOps(); // �� �����ϱ�

    // ���� �ν��Ͻ��� ������ �����Ͱ� �ƴϾ��ٸ�?
    // -> ���� �����Ϳ��ٸ� �� ��° �Է¿� ���� ����� �� �� ���� ��
    //    (int a = 0�̶�� �ϰ�, a = 100�̶�� �ϸ� a�� �����Ǵ� �Ͱ� ����)

    // ������ �ν��Ͻ��� ������ �����Ͷ��?
    // ������ ���� �Է� ����� ��� �ٸ��� ���� ���̴�
    // (int a = 0, int b = 1�̶�� �ϰ� a = 100 �̶�� �ص� b�� ��� 1�� �Ͱ� ����)
}
