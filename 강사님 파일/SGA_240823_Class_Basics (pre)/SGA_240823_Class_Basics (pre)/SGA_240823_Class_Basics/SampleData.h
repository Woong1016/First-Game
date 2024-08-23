#pragma once
// pragma once : #�� �����ϴ� �ڵ� �ߺ� �� �� ���� ���
// -> ���� ����� ���� �� �����ؾ� �� �� �ʼ�
//    (�׳� .h �����̸� �Ƿʻ� �־�δ� ���� ���� ����)

#include <iostream> // ����� �⺻ ��� (cout ������ �ʿ�)

// ���� ������

// ����ü �ۼ� �� �ؿ� �������� ���� �ۼ��մϴ�.

//--------------------------------------------------

// ����ü : � ������ ĳ���� �����͸� ���� �����Ѵٸ�

struct Monster          // ����
{
	//"������ �� �ӿ� "����"�� �з��Ǵ� ���簡 �ִٸ�
	// �ش� ����� �Ʒ��� ���� ���� ������ ����" �ɷ� �Ѵ�.


    const int* id;      // ���� ���� id (�׸� ����)
    const int* subId; // id�� ���� Ư�� ��ü�� �ִٸ� ���

    char* name;         // �̸�

    int typeCode1;      // ����1
    int typeCode2;      // ����2
    int typeCode3;      // ����3
    int typeCode4;      // ����4

    float sexRatio;     // ��������
    int hatchCount;     // ��ȭ�� �ɸ��� �ʵ� �̵� Ƚ�� (���� Ȥ�� �� ��ȯ)

    float hpMax;        // �ִ� ü��
    float hpCurrent;    // ���� ü��
    float attack;       // ���ݷ�
    float defence;      // ����
    float exAttack;     // Ư�� ���ݷ�
    float exDefence;    // Ư�� ����
    float speed;        // ������
    float totalStats;   // ���� �ɷ�ġ (����ġ)

    // �� �� �ʿ��� �����Ͱ� ������ �����մϴ�.

    // �Ʒ� �������� �뵵�� �ٸ� ����鿡�� ������ �ʽ��ϴ�.
    int _var0000;
    int _var0001;

    // 0000 : id, 0001 : ����id
};

// ���� �ð��� �����ߵ� �� ������ ����ü�� �ڷ����� ��ó�� ����ϸ�
// �� �ȿ��� ���� ���� ��ü�� �ϳ��ϳ� ������ �� �ִ�
// ��: int a = 1, float f = 10.00f , ���� m = � ����, ���� m2 = ���� ����

// �׸��� ���� �������� �ٿ��� �̸��� ���� �ۼ��� �� (����� ���ڿ��� ������ �ȵ�
//�ش� ���ڿ��� �����͸� (�迭 �̸���) ���� �������� �ش�

// �� �̸��� ��ϵ� ����ü
struct MonsterNames     // ������ �̸� ���
{
    // * Ư���� ��Ȳ! : ������ �����ʹ� ���߿�
    // �ٲ� ���� ���� (�߿��� ���� ������),
    // �ٲ� ���� �����Ƿ� (��� ������)
    // ���⼭ �׳� ���� ���� �Ҵ��մϴ�.

    char name_sample[17] = "�ѱ��̸� 8�ڱ���";

    char name_001[17] = "������";
    char name_004[17] = "�߾ư�";
    char name_007[17] = "�ٿν�";
    char name_024[17] = "������Ʈ";
    char name_037[17] = "����";
    char name_074[17] = "��ī��";
    char name_099[17] = "�ȣũ";
    char name_125[17] = "��ճ�����";
};

// ����ü ���

void PrintMonster(Monster monster) // ����ü ������ �Ű�������
{
    std::cout << "---------------------------------" << std::endl;
   
    std::cout << *monster.id << std::endl;  // �����ʹ� ������
    std::cout << *monster.subId << std::endl;

    std::cout << monster.name << std::endl; // * ���ڿ��� ����!

    std::cout << monster.typeCode1 << std::endl;
    std::cout << monster.typeCode2 << std::endl;
    std::cout << monster.typeCode3 << std::endl;
    std::cout << monster.typeCode4 << std::endl;

    std::cout << monster.sexRatio << std::endl;
    std::cout << monster.hatchCount << std::endl;

    std::cout << monster.hpMax << std::endl;
    std::cout << monster.hpCurrent << std::endl;
    std::cout << monster.attack << std::endl;
    std::cout << monster.defence << std::endl;
    std::cout << monster.exAttack << std::endl;
    std::cout << monster.exDefence << std::endl;
    std::cout << monster.speed << std::endl;
    std::cout << monster.totalStats << std::endl;

    std::cout << "---------------------------------" << std::endl;
}

// ������ ����

enum DIRECTION      // ������ ��Ÿ���� ������
{
    FORWARD,        // ��
    BACK,           // ��
    RIGHT,          // ������
    LEFT,           // ����
    UPWARD,         // ��
    DOWNWARD,       // �Ʒ�
};

enum CHECKANSWER    // �亯�� ���� ������ Ȯ���ϴ� ������
{
    //RIGHT,          // �¾Ҵ�
    //WRONG,          // Ʋ�ȴ�

    // ... ?? �̰� �� �ּ�����? ���� ���� �ֳ���?

	//�� �ڵ带 ����Ϸ��� �� ��� , ���� ������ ���� ������
	// �����δ� ���� ��� (���� ��� ) ������ ������

	//���� : right��� �̸��� �Ȱ��� ����� �ٸ� ���� �����Ͱ� �־ (�ߺ�)

	// �׷���, �� ��Ȳ���� RIGHT��� �ܾ ������� ������ �ȵǴµ�?
	//-> �ٸ� ��쿡�� �̷��� �������Ǿ� ������ �� �ʿ��ؼ�
	// ������ ��ġ�� �ٸ��ܾ �ٸ� ���������� ������ �� ����
	// �׷� ��¼��?

	// �̷������� �ſ� ������ ���� �ִ�.

	// '�� RIGHT�� �� RIGHT�� ������ �ٸ���' ��°� �����ָ� �ȴ�.

	// ��� �ϳ���? ..... ���⼭ c++ ������ ���α׷�����
	// �� ������ ���� �ذ� ���Ѵ�. ��? 

	// �������ʹ� C++�κ��� ������ ������ ����� �ϳ��� ��� �� ����

	// �ڼ��Ѱ� MAIN()���� ����
};

// ������ ���

void TestEnum()
{
    // ���� ������ ��� ����
    std::cout << "---------------------------------" << std::endl;
    std::cout << "���� ������ �ڵ� ���" << std::endl;

    std::cout << "�� : " << FORWARD << std::endl;
    std::cout << "�� : " << BACK << std::endl;
    std::cout << "�� : " << RIGHT << std::endl;
    std::cout << "�� : " << LEFT << std::endl;
    std::cout << "�� : " << UPWARD << std::endl;
    std::cout << "�� : " << DOWNWARD << std::endl;

    std::cout << "---------------------------------" << std::endl;
}