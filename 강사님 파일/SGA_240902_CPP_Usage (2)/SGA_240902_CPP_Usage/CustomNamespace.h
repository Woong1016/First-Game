#pragma once

// �츮�� ���� ���ӽ����̽� ���

//���ӽ����̽� �ۼ�
namespace CustomNamespace1
{
    //���ӽ����̽� �ӿ� �Լ� �ۼ��ϱ�

    int Operation(int x, int y) // "���"�̶�� �̸��� �Լ�
    {
        return x + y;
    }

    // ���� �ۼ��� �Լ��� CustomNamespace1 �� �̸� �ӿ� ���Եȴ�

    // �ۼ��ϴ� �Լ��� �󸶵��� �߰� ���� (�� �ȿ����� �ߺ� ������ OK)

    int Mult(int x, int y)
    {
        return x * y;
    }

} // ; ���ʿ�

// �ٸ� �̸��� ���ӽ����̽� �ۼ�
namespace CustomNamespace2
{
    int Operation(int x, int y) // ���� �Ȱ��� �̸��� �Լ�
    {
        return x - y;
    }
}