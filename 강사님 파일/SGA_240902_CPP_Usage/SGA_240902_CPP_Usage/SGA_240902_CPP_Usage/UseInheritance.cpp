#include "UseInheritance.h"

void UseInheritance::Run()
{
    // �ν��Ͻ�(�� ������) ���� �� �Ҵ�
    warrior = new CharacterWarrior();
    hunter = new CharacterHunter();

    // ���� ������ �Ẹ��
    warrior->Dance();         // �θ� Ŭ������ �Լ� ���
    warrior->ShowCharacter(); // �������ͽ� ���
    warrior->GiganticStrike(); // ������ ��Ÿ ���

    //��ɲ� ������ �Ẹ��
    hunter->Dance();
    hunter->ShowCharacter();
    hunter->HuntersMark(); // ��ɲ��� ¡ǥ ���

    // �̷ν� ���� �θ� Ŭ����, �ٸ� �ڽ� Ŭ������ ���踦 Ȱ���ϸ�
    // ���� ����� �θ� Ŭ������ ���� �ۼ��ϰ� (�ߺ� �ۼ��� ���̱�)
    // �� ���� ���� ��� (���翡�Ը�, ��ɲۿ��Ը� �־�� �ϴ� ������) ����
    // �ڽ� Ŭ������ ���� ��� ������ �ο��� �� �ִ�!

	// �θ� Ŭ������ �ڽĿ��� Ȱ���ϴ� ����

	CharacterWarrior* warrior2 = new CharacterWarrior(60, 30000);

	warrior2->ShowCharacter();
}
