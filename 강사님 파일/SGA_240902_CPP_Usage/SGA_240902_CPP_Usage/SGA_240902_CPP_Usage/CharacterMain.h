#pragma once
#include <iostream>

// �θ� Ŭ���� : ĳ����

class CharacterMain
{
public:

    CharacterMain();    //������
    CharacterMain(int level, int hp);

    ~CharacterMain();   //�Ҹ���

    void Dance();       // /��

protected: // �ܺ� �����, �ڽĿ��� ����

    int level;
    int hp;
        
    void ShowCharacter();
};

