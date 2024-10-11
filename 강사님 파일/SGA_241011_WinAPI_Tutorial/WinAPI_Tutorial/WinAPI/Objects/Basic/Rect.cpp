#include "Framework.h"

Rect::Rect(Vector2 pos, Vector2 size)
    : GameObject(pos), size(size)
{
}

Rect::Rect(float left, float top, float right, float bottom)
{
    pos.x = (left + right) * 0.5f;
    pos.y = (top + bottom) * 0.5f;

    size.x = abs(right - left);
    size.y = abs(bottom - top);
}


//�簢������ Render �Լ��� ȣ���ϸ� �Ʒ� �ڵ天��� ȭ�鿡 �����Եȴ�.
void Rect::Render(HDC hdc)	// isActive������ �����̸� : �׳� ����������
{
    if (!isActive)
        return;

	//��ġ ����, ��ġ���� ũ��(�� ��)��ŭ �����¿� ��ġ�� ���� �����
	// �̾ ���簢���� �׸���.
    int left = (int)(pos.x - size.x * 0.5f);
    int right = (int)(pos.x + size.x * 0.5f);
    int top = (int)(pos.y - size.y * 0.5f);
    int bottom = (int)(pos.y + size.y * 0.5f);

	//Rectangle �Լ� ����
    Rectangle(hdc, left, top, right, bottom);
}

bool Rect::IsCollision(const Vector2& point) const
{
    if (!isActive)
        return false;

    if (point.x > Left() && point.x < Right())
    {
        if (point.y > Top() && point.y < Bottom())
            return true;
    }

    return false;
}

bool Rect::IsCollision(const Rect* rect) const
{
    if (!isActive) return false;
    if (!rect->isActive) return false;

    if (rect->Left() < Right() && rect->Right() > Left())
    {
        if (rect->Top() < Bottom() && rect->Bottom() > Top())
        {
            return true;
        }
    }

    return false;
}

bool Rect::IsCollision(const Circle* circle) const
{
    return false;
}
