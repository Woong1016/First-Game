#pragma once
#include "CharacterMain.h"

// ���� ĳ���� : �ڽ� Ŭ����
// -> �⺻ ĳ���Ϳ� ���� "����"�� ������ �߰��� �ο��� ���

class CharacterWarrior : public CharacterMain
{
public: // ���� ����

    CharacterWarrior();
    CharacterWarrior(int level, int hp); // ���� 2��¥�� ������
    CharacterWarrior(int level, int hp, int rage);

    ~CharacterWarrior();

    void ShowCharacter();   // ĳ���� ���̱�
                            // (�θ𿡰� ���� �Լ� ���� = �Լ� �������̵�)

    void GiganticStrike();  // ������ ��Ÿ

private: // ������ �����

    int rage;               // ������ �ڿ��� '�г�'�� ��Ī
};

