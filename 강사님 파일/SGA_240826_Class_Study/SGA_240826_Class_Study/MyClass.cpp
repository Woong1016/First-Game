#include "MyClass.h"

void MyClass::Set_X(int x)
{
    // �Լ��� ���� : Ŭ���� �� x�� �Ű����� x�� �����ϱ�. ���� �װ� �ϳ�

    this->x = x; // ������ 'this->' : "�� Ŭ������ ����, ���"��� ��
                 // �������� �׳� x : ���� ��Ī�� ������ �Ű�������� ��
}

// {} �� �ڵ尡 �ʹ� ª���� �׳� �̷��� �� �ٷ� �ۼ��ص� OK
// �׸��� �� ������ ª�� �Լ��� ���� ��� ������ �׳� �� �ۼ��ϱ⵵...
void MyClass::Set_Y(int y) { this->y = y; }
void MyClass::Set_Z(int z) { this->z = z; }

int MyClass::Get_X()
{
    return x; // () �ȿ� �򰥸��� �ٸ� �̸��� ��� this-> ��� ��
              // return x; �����ε� �ڵ����� Ŭ���� �� x�� ��ȯ
}

int MyClass::Get_Y() { return y; }
int MyClass::Get_Z() { return z; }
