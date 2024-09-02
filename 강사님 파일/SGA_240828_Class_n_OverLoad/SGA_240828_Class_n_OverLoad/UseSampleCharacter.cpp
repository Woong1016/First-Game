#include "UseSampleCharacter.h"

UseSampleCharacter::UseSampleCharacter()
{
    // �ν��Ͻ� ���� �� �����Ϳ� �ּ� �ֱ�
    character1 = new SampleCharacter();
    character2 = new SampleCharacter();
    character3 = new SampleCharacter();

    // ĳ���� 1�� ������� ���� ĳ���͸� �״�� ���ϴ�.
    // ĳ���� 2, 3�� ������ �������ְڽ��ϴ�.

    character2->Set(
        nameList.name2, 60, 2, 4,
        10, 600, 0, 60.0f, 6, 1, 3
    );

    character3->Set(
        nameList.name3, 50, 2, 9,
        10, 500, 50, 70.0f, 3, 5, 6
    );

    // �̷��� �� ĳ���͸� ���� ���� �����ڸ� �����մϴ�.
    // �� Ŭ������ �ν��Ͻ��� ��������ٸ�, �� �ȿ��� �̷��� �������
    // �� �ٸ� ĳ���Ͱ� �ڵ����� �� �̴ϴ�.
}

void UseSampleCharacter::PrintCharacters()
{
    //�� ĳ���͸� ���� ���

    character1->ShowMe();

    character2->ShowMe();

    character3->ShowMe();
}
