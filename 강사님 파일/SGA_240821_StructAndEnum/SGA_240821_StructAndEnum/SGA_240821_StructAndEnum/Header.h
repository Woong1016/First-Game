#pragma once

// ��� = ���� ������ �ڸ�


// ����ü �ۼ�

struct Champion
{
    int hitPoint;          // hp, ü��
    float hitPointRestore; // ü�� ���
    float atk;             // ���ݷ� (attack)
    float atkSpeed;        // ���� �ӵ�
    float def;             // ���� (defense)
    float res;             // ���� ���׷� (resist)
    int range;             // ��Ÿ�
    float moveSpeed;       // �̵� �ӵ�
};


// ������ �ۼ�

enum AGEGROUP
{
    INFANT,
    TODDLER,
    YOUNGSTER,
    JUNIOR,
    YOUNGADULT,
    ADULT,
    MIDDLE,
    SENIOR,
    SILVER,
    OLD,
};