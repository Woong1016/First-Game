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

// �簢������ Render �Լ��� ȣ���ϸ� �Ʒ� �ڵ��� ȭ�鿡 ������ �ȴ�
void Rect::Render(HDC hdc)
{
    //if (!isActive) // isActive ������ �����̸� : �׳� �׸��� ����
       // return;

    //��ġ ����, ��ġ���� ũ��(�� ��)��ŭ �����¿� ��ġ�� ���� �����
    //�̾ ���簢���� �׸���
    int left = (int)(pos.x - size.x * 2.3f);
    int right = (int)(pos.x + size.x * 2.3f);
    int top = (int)(pos.y - size.y * 1.5f);
    int bottom = (int)(pos.y + size.y * 1.5f);

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

    // �簢���� �浹 ���� : ���� ��ġ���� ���ΰ� ������ ħ���ߴµ�
    // (�ٸ� ����, "�� ������ �� �����ʺ��� �� ����")
    // ���ÿ� ���� ���迡���� ���ΰ� ������ ħ���ߴ�...�� �浹�� �� ��Ȳ

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
    // �簢���� ���� �浹

    // 1. �簢���� ��� ���� �������� �� ���� ������ ���� ������
    //    ���� �������� �簢���� ���μ��� ũ�⸦ �������� �Ǵ�

    // 2. ���� ���� ���̸�, �簢���� �� �������� ���� �߽ɰ��� �Ÿ���
    //    ���� �������� ���ؼ� �Ǵ�
    // ---------------------------------------------------

    // 1. ��Ȱ��ȭ �� ���� �� ��
    if (!isActive) return false;
    if (!circle->isActive) return false;

    // 2. ���� ���� �Ǻ� �� ��
    if (circle->pos.x > Left() && circle->pos.x < Right() || //���� �߽��� �簢�� ���� ��, Ȥ��
        circle->pos.y > Top() && circle->pos.y < Bottom())  // ���� �߽��� �簢�� ���� ��
    {
        // �� ���� �� �ϳ��� �����ص� ���� ���� ������ ���� ��

        // �� �� : �簢���� ���μ��� ũ��(�� ��)�� ���� ������ ��

        Vector2 size(circle->GetRadius() * 2, circle->GetRadius() * 2);
        // x2�� �� ��� ���� ���δ� ū �簢���� ���� ��¥ ��� ����
        // -> ��¥ ���? : ���� 4���� ��� �ʿ� ������� ���� ������ ������ ���� ����
        
        // ���� ���μ��� ũ�⸦ ��Ÿ���� ���� ����
        Rect tempSize(circle->pos, size);   // ���� ��ġ, ���� 'ũ��'

        //�� �簢���� ������� '����'�� �浹�ϴ��� ����
        // = ���� �������� �簢�� ������ �������� ����

        if (IsCollision(&tempSize)) // ���� �־��� �簢�� �浹 �Լ� �̿�
            return true;

        else return false;  // �浹�� �� ������ �׳� ��
    }

    // * ���⼭ ���� �߽� �Ÿ����� �ٽ� �������� ��� �����¿� ��ǥ
        //   + �簢������ �̾����� ���� ���� ��� Ȥ�� �� �浹....�� ����

        // -> ���� �ۼ��� ����� �ļ�����, �ڵ��� ���� ���ٴ� ���� ����
        // -> ���� ���߿��� ���̴� ��Ʈ�ڽ��� ����

        // ���� ���� ���������� �� �ڵ忡�� �浹 ���ΰ� ������ ��� ��, �Լ� ����
        // -> ������� �ڵ尡 ����, ���� ���� ���� �ۿ� �ִٴ� ��

        // 2. ���� ���� ���� �ۿ� �ִ� ���

        // �簢���� �� ������ ��ġ Ȯ��
        // Vector2 edge1, edge2, edge3, edge4; // <- �ۼ� ����

    Vector2 edge[4]; // <- �̰͵� ����
    edge[0] = { Left(), Top() };    // �»�
    edge[1] = { Left(), Bottom() };    // ����
    edge[2] = { Right(), Top() };    // ���
    edge[3] = { Right(), Bottom() };    // ����

    //for (int i = 0; i < 4; ++i)
    //{
    //    if (circle->IsCollision(edge[i])) return true;
    //    // ���浹 Ȯ�� ��, �浹�� ������ �´ٰ� ��ȯ�ϰ� ����
    //}

    // ���⼭ ���ο� ���� �߰�
    for (Vector2 point : edge) // ���� �ݺ����� ����� �Ȱ���
    {
        if (circle->IsCollision(point)) return true;
    }

    // for (�ڷ��� name : array) ����
    // -> array��� �迭�� �����ϴ� ���Ҹ� �ӽ÷� name�̶�� ����� ��,
    //    �迭 �ӿ� �ִ� ��� ����, �� name�� ��� ���ư��鼭 �˻��Ѵ�
    //    ��, �迭�� ũ�Ⱑ ��Ȯ�� ���� ���� �˾Ƽ� �迭�� �ݺ��Ѵ�

    // �̰��� for each �ڵ��� �Ѵ�
    // -> �ӵ��� ���� ��, �迭�� � ���Ұ� �ִ���, �ڷ����� ��Ȯ�� �˾ƾ� �Ѵ�
    //    �׷��� �ܼ� �ܰ質 ���� �ܰ迡���� �׷��� ��ȣ������ �ʰ�
    //    �ٸ� ��API, DX �ܰ迡���� ��� ���� ���̹Ƿ� �� ���� �����غ��ô�.

    // ������� ������ ������ ���� �浹���� ���� ��
    return false;
}
