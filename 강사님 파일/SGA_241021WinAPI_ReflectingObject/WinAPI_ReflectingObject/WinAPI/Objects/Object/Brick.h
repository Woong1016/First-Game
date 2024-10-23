#pragma once

class Brick : public Rect
{
public:

    Brick(Vector2 pos, Vector2 size);
    ~Brick();

    void Update();
    void Reflect(Vector2 overlapSize); // �ݻ� �� ������ �Լ�

private:

    // ������ "������"�� �ʿ��� ��

    bool isMovable; // �����̱� �� �ǰ�?
    
    float angle;    // ������ �ʿ�
    float speed;    // �ӷµ� �ʼ�

    Vector2 direction;  // ���� ����
    
};

