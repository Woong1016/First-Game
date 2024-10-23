#include "Framework.h"

bool GameObject::IsCollision(const GameObject* object)
{
    // �Ű������� ���� ��� ��ü�� Circle�� ����ȯ �õ��غ���

    const Circle* circle = dynamic_cast<const Circle*>(object);

    if (circle != nullptr)  // ����ȯ�� ������ = ���̸�
        return IsCircleCollision(circle);   // �� �浹

    const Rect* rect = dynamic_cast<const Rect*>(object);

    if (rect != nullptr) //�簢�� ����ȯ�� �Ǹ� = �簢��
        return IsRectCollision(rect);   // �簢�� �浹

    // �������� �� / �簢�� / Ȥ�� �ٸ� ������� �浹 ���� �õ�

    return false;
}
