#pragma once

class Ball : public Circle
{
    // �� = 2D �� ��

    // ������ �����ʹ� �θ� Ŭ���� �ؿ� �� �����ϱ�...

    // �� '��'�� ��ü�μ� �������� ���� ���� �����͸� �ø��غ���

public:
    Ball(Vector2 pos, float radius); // �����ڿ��� ��ġ�� �������� �ʼ�
    ~Ball();

    void Update();

private:

    // float pi = 3.14159; ���ʿ�
    
    float angle; // ����
    float speed; // �����δٰ� ġ��, �ӷ��� ���� ��

    // ���� ���� �� ���� ��ġ... �� ������ �߰� ������ ����
    // �ӷ��� �ƴϴ� (�ӷ¿��� �Ʒ� ������ ������ ��)

    Vector2 direction;  // "����"
};

