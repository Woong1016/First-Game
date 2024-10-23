#include "Framework.h"
#include "AngleScene.h"

AngleScene::AngleScene()
{
    Vector2 start = { CENTER_X, CENTER_Y };

    line = new Line(start, mousePos); // ȭ�� �߰�����, ���콺 Ŀ������ ���� ��
}

AngleScene::~AngleScene()
{
}

void AngleScene::Update()
{
    // ���콺 Ŀ�� ��ġ�� �ٲ�ϱ� ��� ���� ���� �ٲ��
    // line->end = mousePos;

    // ���콺 Ŀ�� ��ġ�� ���󰡵�, ���̰� ��� �����ϰ�

    // 1. ���콺 Ŀ���� ���� ���� ���� + �߽ɿ��� ������ �Ÿ� (��ü ��ǥ)�� �ʿ�
    float x = mousePos.x - line->pos.x;
    float y = mousePos.y - line->pos.y;

    // ���� ���� ������ �̿��ؼ� ������ ���Ѵ�
    // -> ���Ǵ� �� : ź��Ʈ�� ������ (ź��Ʈ = ������ ���� ���� �� �ϳ��� ���� ���� ���)

    // angle = atan(-y / x);   // atan = a(��) + ź��Ʈ�� �����ϴ� �Լ�
                               // �� -y�ΰ�? : ������� y�� Ŀ���� ������ ���ϱ�
                               //  (���� ���� ��ǥ���� ����)

    angle = atan2(-y, x);   // x �� 0�� ��츦 ����ϱ� ���� ���� �Լ�

    // ������ ���ؼ�, �ٽ� ���� �׷��� �� ���� ���� ��ǥ�� ���Ѵ�
    // ��� : ������, ������ ����(���� ���� = �ﰢ���� ����) ��θ� �Ἥ
    //       ���� ���ο� x, ���ο� y�� ���ϴ� ��

    //float newX = cos(angle); // ������ ���� ������ '����'�� �˰� �ǰ�...
    float newX = cos(angle) * length; // ������ ���� ���̸� ���ؼ� ��μ� ���� ��ǥ ���
    float newY = -sin(angle) * length;  // -sin : Y ��ǥ ������

    Vector2 newEnd = { newX, newY };
    // line->end = newPos; // <-....��� ������? ���� �������� �ݿ� �� ��
    line->end = line->pos + newEnd; // ���� ���������� �ݿ��� ���� ���� ��ǥ�� �Ҵ�
}

void AngleScene::Render(HDC hdc)
{
    line->Render(hdc);
}
