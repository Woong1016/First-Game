#include "Framework.h"
#include "Ball.h"

Ball::Ball(Vector2 pos, float radius):
    Circle(pos, radius)
{
    // �ӷ°�, ������, ���� ��ġ ���ϱ�

    pos = { CENTER_X, CENTER_Y };   // �߰��� ����

    speed = 200.0f;  // �ӷ�

    angle = 0;      // ����
}

Ball::~Ball()
{
}

void Ball::Update()
{
    // ������ ������, ������ �ٲ��
    if (KEY_PRESS(VK_LEFT)) // ���� �Է� ��
        angle += 5 * DELTA;
    if (KEY_PRESS(VK_RIGHT)) // ������ �Է� ��
        angle -= 5 * DELTA;


    // ��ġ �ٲٱ�: ������ �ݿ��ؼ�

    Vector2 next;
    next.x = cos(angle) * speed * DELTA;
    next.y = -sin(angle) * speed * DELTA;

    // ���⼭ DELTA : �ð��� ��ȭ�� ��Ÿ���� ��Ī��
    //                �뷫 0.0n �̸��� ���� ��Ÿ���� ��찡 ����
    //                ���ŵ� ������ ��ȭ���� �޶����� ������
    //                ��������� ������ �󵵸� �����ϰ� �������ִ� ȿ���� �ִ�

    // ������ ���� ��ġ�� �ݿ�
    this->pos = this->pos + next;

    if (this->pos.x >= 1200.0f)
    {
        this->pos.x = 1200.0f;
    }

    else if (this->pos.x <= 80.0f)
    {
        this->pos.x = 80.0f;
    }

    else if (this->pos.y <= 72.0f)
    {
        this->pos.y = 72.0f;
    }

    else if (this->pos.y >= 640.0f)
    {
        this->pos.y = 640.0f;
    }
    



}

void Ball::Render(HDC hdc)
{





    Circle::Render(hdc);     // �ڱ� �ڽ� ��� (�����μ�!)
}
