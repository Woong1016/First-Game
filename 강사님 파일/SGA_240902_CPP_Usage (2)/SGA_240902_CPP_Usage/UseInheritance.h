#pragma once
#include "CharacterWarrior.h" // ���� Ŭ����
#include "CharacterHunter.h"  // ��ɲ� Ŭ����

// �θ� Ŭ���� "ĳ���� ����"�� �� �ڽ� Ŭ������ �ڵ�����

class UseInheritance
{
public :
    void Run();

private:
    CharacterWarrior* warrior;
    CharacterHunter*  hunter;

};

