#include "Framework.h"
#include "Ball.h"

Ball::Ball(Vector2 pos, float radius):
    Circle(pos, radius)
{
    // �ӷ°�, ������, ���� ��ġ ���ϱ�

    pos = { CENTER_X, CENTER_Y };   // �߰��� ����

    speed = 50.0f;  // �ӷ�

    //angle = 0;      // ����
    //angle = GameMath::Random(-1.0f, 1.0f);
    angle = Random(-1.0f, 1.0f); // ���ٰ� ���� (using namespace GameMath �����)

    // �ӷ¿��� ������ ã�Ƴ���
    float x = cos(angle) * speed;
    float y = -sin(angle) * speed;
    direction = { x, y };
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

    //Vector2 next;                           // ������ ���� ���������...
    //next.x = cos(angle) * speed * DELTA;    // �ð��� �ð���� �ɸ���
    //next.y = -sin(angle) * speed * DELTA;   // �����⵵ -> �׷��� ��� ������ �°�

    // ���⼭ DELTA : �ð��� ��ȭ�� ��Ÿ���� ��Ī��
    //                �뷫 0.0n �̸��� ���� ��Ÿ���� ��찡 ����
    //                ���ŵ� ������ ��ȭ���� �޶����� ������
    //                ��������� ������ �󵵸� �����ϰ� �������ִ� ȿ���� �ִ�

    // ������ ���� ��ġ�� �ݿ�
    // this->pos = this->pos + next;

    // -------------------------------------------------------------

    // v2 : �� ���α�. ���� �� '���� ����'�� â�� ������ ƨ���

    // -> if��

    if ((this->pos.x - radius) < 0) // ���� ���� ������ â�� ���ʺ��� �۴� = �� �Ѿ���
    {
        // �� ���� �ٲٱ� : ���� ���� ������ �ݴ��
        // direction.x = direction.x * -1; // ���� ������
        direction.x *= -1;              // ���� �ڵ�

        // ���� ���� ���⿡�� ������ ã�Ƴ� �� ������ ������ �͵� ���� (���ư��� ���)
        // 1. next.x, next.y ���ϱ�
        // 2. angle = -atan(-x, y) <-
        // 3. next �� ���ϱ�...... ���ŷӱ� �ѵ� ���ϱ� ���Ѵ�
    }
    if ((this->pos.y - radius) < 0) // â�� ���ʰ� ��
    {
        direction.y *= -1;
    }
    if ((this->pos.x + radius) > WIN_WIDTH) // ���� �������� â �����ʺ��� ũ�� = �� �Ѿ���
    {
        direction.x *= -1;
    }
    if ((this->pos.y + radius) > WIN_HEIGHT) // ���� �Ʒ����� â �Ʒ����� ũ��
    {
        direction.y *= -1;
    }

    // v2 : ���⿡ ���߾ ���� ��ġ�� ����
    this->pos = this->pos + direction * DELTA;
}