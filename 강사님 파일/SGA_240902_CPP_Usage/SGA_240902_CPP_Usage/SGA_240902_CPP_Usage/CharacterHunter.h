#pragma once
#include "CharacterMain.h"

// ��ɲ� ĳ���� : �ڽ� Ŭ����
// -> �⺻ ĳ���Ϳ� ���� "��ɲ�"�� ������ �߰��� �ο��� ���

class CharacterHunter : public CharacterMain
{
public: // ���� ����

    CharacterHunter();
    CharacterHunter(int level, int hp, int focus);

    ~CharacterHunter();

    void ShowCharacter();   // ĳ���� ���̱�
                            // (�θ𿡰� ���� �Լ� ���� = �Լ� �������̵�)

    void HuntersMark();     // ��ɲ��� ¡ǥ

private: // ������ �����

    int focus;              // ��ɲ��� �ڿ��� '����'���� ��Ī

};

