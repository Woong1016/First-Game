#pragma once
#include "SampleCharacter.h" // �� Ŭ������ ���� ĳ���� �����͸� ���� ���ϴ�.

class UseSampleCharacter
{
public:

    UseSampleCharacter();                // ������
    void PrintCharacters();              // ���

private:

    SampleCharacter* character1; // Ŭ������ �ν��Ͻ�....�� ������
    SampleCharacter* character2;
    SampleCharacter* character3;

    // ���� ĳ���Ϳ� �̸� ���
    struct NameList
    {
        char name1[17] = "���";
        char name2[17] = "����";
        char name3[17] = "���� ���ݺ�";
    };
    NameList nameList; // .....�� ������ ���� ��
};

