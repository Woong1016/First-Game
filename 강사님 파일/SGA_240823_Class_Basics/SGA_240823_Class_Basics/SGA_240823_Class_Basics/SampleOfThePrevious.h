#pragma once

// ���� �� ��� Ȯ���� ���� ����

#include "SampleData.h" // ���� ������ ���

// �� : ������� �ٸ� ����� �����ص� �˴ϴ�.
// -> ���� ���� ������ ����� �а�, ����� ���ƿɽô�.

// ���� �Լ����� ���� ���� ���� �����μ�
// "������ �̸� ���" �����͸� ����

MonsterNames monsterNameList; // ����ü(�ڷ��� ����)�� ���� ������

// ���� �Լ�

// * ȯ�� : .h ���Ͽ� �Լ��� ��� �ۼ��ϴ� ���� ���� ������ �ƴմϴ�.
// ������ main()�� �ִ� ������ �������� ���� ���⼭ ���� ���� �ͻ��̿���.

void TwoMonsters()
{
    // ���� ����ü�� ������ �� ���� '�����ι�' ����

    Monster pikachu;        // ���� ��
    Monster pawmot;         // ���� ��

    // ���� ��� ���� ���� �� ���� �׸� ���� �Ҵ�
    // Q : ���� ��� ���� ���� ���̰� ������? A : ���� �𸣰ڽ��ϴ�.

    // �ƹ�ư ���� ��
    pikachu._var0000 = 74;  // ���� ��ȣ 74
    pikachu._var0001 = 7;   // �� ��� �����׸� 8��°�� Ư�� ��ü.
                            // ���� ���ڸ� �Ӹ��� ���� ������.

    pikachu.name = monsterNameList.name_074; // ������ �Ҵ�

    // * �̷��� �޸� ������ ����� ���������ν�
    //   c++ �⺻ ������ε� ������ ���� ������ �ٲ��� �� �ֽ��ϴ�.

    pikachu.id = &pikachu._var0000;
    pikachu.subId = &pikachu._var0001;
    pikachu.sexRatio = 0.5f;    // ��ȭ �� 50%�� ����, 50%�� ����
    pikachu.hatchCount = 10;    // ���̾��� ��� ��ȭ �� 10����° ��ȭ

    pikachu.typeCode1 = 4;      // '���� Ÿ��'�Դϴ�.
    pikachu.typeCode2 = -1;     // �ٸ� ���� ���� ����Ÿ�� �����Դϴ�.
    pikachu.typeCode3 = -1;
    pikachu.typeCode4 = -1;

    pikachu.hpMax = 35;
    pikachu.hpCurrent = 35;     // �λ��� �����ϴ�.
    pikachu.attack = 55;
    pikachu.defence = 40;
    pikachu.exAttack = 50;
    pikachu.exDefence = 50;
    pikachu.speed = 90;
    pikachu.totalStats = 320;   // ������ ���� ��꿡 ���̸�,
                                // �������� �ؼ� �ٸ� ������ �ٲ�
                                // ����ġ ���� ���⼭ �����˴ϴ�.

    // �׸��� ���� ��
    pawmot._var0000 = 24;  // ���� ��ȣ 24
    pawmot._var0001 = 1;   // ��� ���� 2��°, ���� ��ü�Դϴ�.

    pawmot.name = monsterNameList.name_024; // �̸� �Ҵ�

    pawmot.id = &pawmot._var0000;
    pawmot.subId = &pawmot._var0001;
    pawmot.sexRatio = 0.5f;
    pawmot.hatchCount = 15;

    pawmot.typeCode1 = 4;      // '���� Ÿ��'�Դϴ�.
    pawmot.typeCode2 = 11;     // '���� Ÿ��'�� ���մϴ�.
    pawmot.typeCode3 = -1;
    pawmot.typeCode4 = -1;

    pawmot.hpMax = 70;
    pawmot.hpCurrent = 60;     // ��ȭ ���� �� �ο����ϴ�.
    pawmot.attack = 115;
    pawmot.defence = 70;
    pawmot.exAttack = 70;
    pawmot.exDefence = 60;
    pawmot.speed = 105;
    pawmot.totalStats = 490;

    // �� ������ ���� ������ ��� (���õ����Ϳ� ������ �Լ�)

    PrintMonster(pikachu); // ��ī�� ���
    PrintMonster(pawmot);  // ������Ʈ ���

    std::cout << "�� ���ϸ��� ����� ��Ĩ�ϴ�." << std::endl;
}