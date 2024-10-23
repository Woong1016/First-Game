#pragma once

class Ball : public Circle
{
    // �� = 2D �� ��

    // ������ �����ʹ� �θ� Ŭ���� �ؿ� �� �����ϱ�...

    // �� '��'�� ��ü�μ� �������� ���� ���� �����͸� �ø��غ���

public:
    
    Ball* ball;
    Ball(Vector2 pos, float radius); // �����ڿ��� ��ġ�� �������� �ʼ�
    ~Ball();

    void Update();
    void Render(HDC hdc);

private:

    float pi = 3.14159;
    float angle; // ����

    float speed; // �����δٰ� ġ��, �ӷ��� ���� ��
};

