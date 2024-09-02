#pragma once
#include <iostream>

class SampleCharacter
{
public:
    SampleCharacter();   // ������

    void Set(                 // ĳ���� ����
        char*    name,        // �� �Լ��� �θ� �� �ʿ��� �Ű�������
        int      hitPoint,    // ������ �ǹ̴� �Ʒ� private����...
        int      armor,
        int      sight,
        int      moveSpeed,
        int      costGold,
        int      costLumber,
        float    buildTime,
        int      baseDamage,
        int      range,
        int      piercing
    );

    void ShowMe();       // ĳ���� ���

private:

    int id;              // ??? id?????

    char* name;          // �̸�
    char sampleName[17] = "���� ĳ����";

    int hitPoint;        // HP
    int armor;           // �尩 : ���ذ���
    int sight;           // �þ߹���
    int moveSpeed;       // �ӷ�

    int costGold;        // �� ���
    int costLumber;      // ���� ���
    float buildTime;     // ¡���� �ʿ��� �ð�

    int baseDamage;      // �⺻ ���ط�
    int range;           // ���� ����
    int piercing;        // �尩���� : ���ذ��� ���淮

};

