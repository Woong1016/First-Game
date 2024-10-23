#pragma once

// ���ӿ�����Ʈ v2
// ���������ڸ� public����
// �浹 ���� (������Ʈ �浹�� ���� ��Ī����, ��ü�� �浹�� ���� ���)

class Rect;
class Circle;

class GameObject
{
public:
    GameObject() = default;
    GameObject(Vector2 pos) : pos(pos) {}
    ~GameObject() = default;

    virtual void Update() {}
    virtual void Render(HDC hdc) = 0;

    virtual bool IsCollision(const GameObject* object);

    virtual bool IsCollision(const Vector2& point) const = 0;
    virtual bool IsRectCollision(const Rect* rect) const = 0;
    virtual bool IsCircleCollision(const Circle* circle) const = 0;

    // ��Ʈ �浹 2�� : �浹 ���� ũ�⸦ �߰� ��� (��Ʈ Ŭ�������� Ȯ��)
    // �Ű��������� IN, OUT�� �ڵ�� �ǹ̰� ���� ���� ���� ��ũ��
    // = ��� ����� ������ų�, �� ��ũ�ΰ� "�ִٴ�" ��Ǹ����� �ڵ尡 �޶����� �� �� ���� ��ũ��
    //   (���� ��쿡�� ����. IN : ���� �Ű������� ��. OUT : �Լ� ����� ���⿡�� ����ȴ� ��)
    virtual bool IsRectCollision(IN const Rect* rect, OUT Vector2* overlapSize) const { return false; }

public:
    string tag;                 // "�±�" = �з����̶�� ���� �߰�
    bool isActive = true;
    Vector2 pos;
};