#include "Framework.h"
#include "Circle.h"

Circle::Circle(Vector2 pos, float radius)
    : GameObject(pos) // �����ڴ� �θ� Ŭ���� ����� �ͺ���
    , radius(radius)  // �׸��� ������ �����ϱ�
{
    // �����ϸ� �� ������ ���������
}

void Circle::Render(HDC hdc)
{
    // �� ��� �Լ�

    if (!isActive) return;  // ��Ȱ��ȭ �� ������� ����

    int left = (int)(pos.x - radius);   // "���� �߽ɿ��� �������� �Ÿ��� ��� ����"
    int right = (int)(pos.x + radius);
    int top = (int)(pos.y - radius);
    int bottom = (int)(pos.y + radius);

    // �� ������ 'Ÿ��'�� ����� �ȴ� (�߽ɿ��� ������ �Ÿ��� �Ȱ��� Ÿ�� = ��)
    Ellipse(hdc, left, top, right, bottom);
}

// ���� �浹 (���� �ٸ� �׸����� ��ħ) ����

bool Circle::IsCollision(const Vector2& point) const
{
    if (!isActive) return false; // ��Ȱ��ȭ �� ���� ���� ("�浹 �ƴ�")

    // �� �浹 : ���� ���� �߽� �� �Ÿ��� ���, ���̰� �������� ���ؼ� ���
    
    //float x = pos.x - point.x;  // pos�� �� �����̸� -�� ���������� ������
    //float y = pos.y - point.y;  // ������ ������ �Ŵϱ� (- x - = +)
    //
    //float distance = sqrt(x * x + y * y);   //sqrt : ������(��Ʈ) ���ϱ�

    // �� ���� �̸� �ٸ� ���� �غ��ص״ٰ� ȣ���ص� �ȴ�
    // * ���� �����ӿ�ũ���� ����� ����� �ִ�
    float distance = (point - pos).Length();
    // * �� ����(Vector2)�� +, - ����� �����ϴ�
    //   ������ ���� : ��ġ�� ��� �Ÿ� ����, �̵��� ��� ������ ����� ���� ũ��
    // * ����� ���� ���ʹ� = . �����ڷ� ���� �Լ� ȣ���� �����ϴ�

    // ã�Ƴ� �Ÿ��� ���������� ª���� : �� ��� �ֵ� �и� ��輱 �ȿ� �ִ� ��
    return distance <= radius;

}

bool Circle::IsCollision(const Rect* rect) const
{
  // ���� �簢���� �浹... 

	//... �� ���� �ڵ尡 �簢���� �� ���� ������?
	// �׷� �� ���忡�� �� �Ϸ� ������ �� ���� ��� ����ϴ°�?

	// �׳� �簢������ �� �Ѱܵ� ���� ������?

	return rect->IsCollision(this); // ����ض�! «ó��
}

bool Circle::IsCollision(const Circle* circle) const
{
    if (!isActive) return false;            // ��Ȱ��ȭ �� ���� ����
    if (!circle->isActive) return false;    // �Ű����� Ȱ��ȭ�� ���캸��

    // ���� ���� �浹�ϴ� ���� �Ǵ��ϴ� ����?
    // = �� ���� �߽��� �Ÿ��� ���� �ȴ�.
    // �� �Ÿ��� �� ���� ������ �պ��� ª���� �浹

    float distance = (circle->pos - pos).Length();

    return distance < (radius + circle->radius);
}
