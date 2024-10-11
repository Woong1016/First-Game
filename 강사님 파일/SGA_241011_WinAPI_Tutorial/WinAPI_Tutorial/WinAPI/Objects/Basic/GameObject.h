#pragma once

// Ŭ���� ���� ����(Ŭ���� �̸��� ���͵� ��ǻ�Ͱ� �򰥸��� �ʰ�)
class Rect;		// ���� ������ Ŭ���� : ���簢��(Rectangle)
class Circle;	// ���� �ȸ��� Ŭ���� = ������ ���� Ŭ���� : ��

class GameObject
{
public:
    GameObject() = default;
    GameObject(Vector2 pos) : pos(pos) {}
    ~GameObject() = default;

	//���� ������Ʈ���� �ʼ��� ��: ������ "ǥ��"�� �����ؾ��Ѵ�.

    virtual void Render(HDC hdc) = 0;

	//�ϳ� �� "�浹"�� ������ �Ѵ�.
	//�浹 : �����Ͱ� ��Ÿ���� �׷����� ���� �������� �����ϴ� �Լ� �ڵ�
	//			�׼�,rpg, ������, �׿� ���� ���ӿ��� ������ �Ǵ��� �� ���

    virtual bool IsCollision(const Vector2& point) const = 0;
    virtual bool IsCollision(const Rect* rect) const = 0;
    virtual bool IsCollision(const Circle* circle) const = 0;

	// �� ���� ������Ʈ�� ��ġ�� ��Ÿ���� ���͵�
    Vector2& Pos() { return pos; }	// �ڷ��� + * : ������
    bool& Active() { return isActive; }	// �ڷ��� +& : �ش絥���� (��ü)
										// =���� ������ ���� �ƴϰ� ��Ȯ�� �� �����͸� ���ڴٴ� ��
										// �ؼ��ϱ� ���󼭴� ������ �� ��° �̸��� �����شٰ� �� �� �ִ�.
										// �ٸ� ���� , POS()�� �ҷ��� �����ϸ� pos�� �ٲ��.
protected:
    bool isActive = true;				// Active : Ȱ��ȭ ����
										// Ȱ��ȭ�� ������ �����ʹ� ���Ӽӿ� �־ 
										// ȭ�鿡 ������ �ʰ� �ϰų� , ������ ������� ���� ���� ���� �ִ�.		
										// �� : ������ ĳ���� �������ͽ�

    Vector2 pos;
};