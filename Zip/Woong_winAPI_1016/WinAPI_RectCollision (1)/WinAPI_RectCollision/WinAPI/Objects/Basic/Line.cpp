#include "Framework.h"
#include "Line.h"

Line::Line(Vector2 start, Vector2 end)
	:GameObject(start), end(end)
{
	//���� ��ü�μ��� ��ġ = ���������� ����
	// ������ ���� ����

}

void Line::Render(HDC hdc)
{
	// ���⼭ ���� ��� moveto , lineto ���

	Moveto(hdc)
}


// �浹�� ��� ����(��� false)
bool Line::IsCollision(const Vector2& point) const
{
	return false;
}

bool Line::IsCollision(const Rect* rect) const
{
	return false;
}

bool Line::IsCollision(const Circle* circle) const
{
	return false;
}