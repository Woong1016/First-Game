#pragma once
#include <iostream>

class MyCharacterBase
{
    // �� Ŭ������ ���ǿ� ���� �ʽ��ϴ�.
    // �� Ŭ������ ���ǿ� ����� MyCharacterBase Ŭ������ �񱳿� �����Դϴ�.

public:
    MyCharacterBase();   // ������

    void Set(int hitPoint, int baseDamage); // ĳ���� ����
    void ShowMe();                          // ĳ���� ���

private:

    int id;              // ??? id?????

    int hitPoint;        // HP
    int baseDamage;      // �⺻ ���ط�
};



