#include "MyCharacter.h"

MyCharacter::MyCharacter() : id(0) // : ���� �κ��� ���� �ʱ�ȭ (��� �̴ϼȶ���¡)
{
    // id�� ����� �����ǰ�, �ʱⰪ�� ������ ���⼭ ���� Ȯ�� ����
    // ���� : {}�� ����Ǹ� �̹� �ʾ��� ���� (��� ���� ��, ���� ���� ����)

    // �ذ� ���? ��ǻ�Ͱ� �Լ��� �����ϴ� ���� + �������� ���� ������ ��Ʈ
    // ��ǻ�Ͱ� �Լ��� ������ �ϴ� ���� = ������ ���� ��
    // �������� ���� ���� = ���ʷ� Ŭ������ ������� ��
    // -> �� ��, ���α׷����� Ȯ���ϱ� "����" (������ �ϳ��� �� �б⵵ ��)
    
    // -> "�ʱ� ���� ���� �����ָ� �ǰڳ�?" = {} ������ ���� �ڵ��ϸ� �ǰڳ�?

    // c++���� �Լ��� �̸��� Ȯ���ϰ� = () ����
    // �Լ��� ������ �����ϱ� ���� = {} ������ ������ �̸� �Ҵ��صδ� ��� ����

    // = ���� �ʱ�ȭ ���� (Ȥ�� ������� '��� �̴ϼȶ�����' member initializer)
    //   ...�ۼ����� �� ����

    hitPoint = 100;
    baseDamage = 10;
}

// �����ε带 ���� ������ �ۼ�
MyCharacter::MyCharacter(int hp, int dmg) : id(0)
                                       // : ǥ�� = '��� �̴ϼȶ����� ����'
                                       // () �� ���� �̸� : ��� ����
                                       // () �� ������ : �ʱ� ��
{
    hitPoint = hp;  // �Ű������� �״�� ���
    baseDamage = dmg;
}

// ��� �̴ϼȶ����� ���� : ��� ��� ���� �Ẹ��, �Ű����� �Ẹ��
MyCharacter::MyCharacter(int id, int hp, int dmg) : id (id),
                                                    hitPoint (hp),
                                                    baseDamage(dmg)
    // : ǥ�� = �̴ϼȶ���¡ ����
    // ������, () �� �̸� : ��� ������ �ǹ�
    // ��������, () �� ������ : �ʱ� ��. �Լ��� �Ű��������� OK
{
    // ������ ��� �̴ϼȶ������� �ʱ�ȭ�ؼ� �� �ȿ��� ���� �ڵ尡 �ʿ����
}

MyCharacter::~MyCharacter()
{
    std::cout << "�� ĳ���ʹ� ���������ϴ�." << std::endl;

    // �Ҹ����� ����� main���� �˾ƺ���
}

void MyCharacter::Set(int hitPoint, int baseDamage)
{
    this->hitPoint = hitPoint;
    this->baseDamage = baseDamage;
}

// �� Set �Լ��� �̸� ö�ڰ� ����, �׷��� �Ű������� �ٸ� �͵�
void MyCharacter::Set(float hitPoint, float baseDamage)
{
    // float ������ int ������ �Ҵ��ϴ� �����̹Ƿ�
    // (�̴�ε� ����� ��� ������) ����ȯ�� �صθ� �� Ȯ���ϴ�
    this->hitPoint = (int) hitPoint; // (�ڷ���) : ����ȯ. ����սô�.
    this->baseDamage = (int) baseDamage;

    // ���� �ٸ� �Լ��� �����ϰ� ������ ������� ��Ÿ����
    std::cout << "�� �Լ��� �Ҽ��� �޾� �����߽��ϴ�." << std::endl;
}

void MyCharacter::Set(int hitPoint)
{
    this->hitPoint = hitPoint;
    this->baseDamage = 99999; // ������

    std::cout << "�� �Լ��� �Ű������� �ϳ��� �޾ҽ��ϴ�." << std::endl;
}

void MyCharacter::Set()
{
    this->hitPoint = 1000;
    this->baseDamage = 2000;

    std::cout << "�� �Լ��� �Ű����� ���� �����߽��ϴ�." << std::endl;
}

void MyCharacter::ShowMe()
{
    std::cout << hitPoint << std::endl;
    std::cout << baseDamage << std::endl;
}

void MyCharacter::ShowMe(bool showID)
{
    if (showID) // �Ű������� ���� ���� ���̸�
        std::cout << id << std::endl;

    //������ ������ �״��
    std::cout << hitPoint << std::endl;
    std::cout << baseDamage << std::endl;
}