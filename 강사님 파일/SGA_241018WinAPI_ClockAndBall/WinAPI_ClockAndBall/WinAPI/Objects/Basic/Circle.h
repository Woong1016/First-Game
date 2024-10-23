#pragma once

class Circle : public GameObject
{
public:
    //������ / �Ҹ���
    Circle() = default; // "�⺻ c++ Ŭ���� �����ڸ� ���ڴ�"
    Circle(Vector2 pos, float radius);  // ��ġ�� ���������� �����

    // ���ӿ�����Ʈ���� ��ӹ��� �������̽�

    virtual void Render(HDC hdc) override; // ���

    //�浹
    virtual bool IsCollision(const Vector2& point) const override; // ���� ��ĥ ���
    virtual bool IsCollision(const Rect* rect) const override;  // �簢���� ��ĥ ���
    virtual bool IsCollision(const Circle* circle) const override;  // ���� ������ ��ĥ ���

    float GetRadius() const { return radius; }   // ����
    float& SetRadius() { return radius; }        // ����

public:

    float radius = 0.0f;    // ������

};

