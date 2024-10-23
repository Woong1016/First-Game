   #include "Framework.h"
#include "AngleScene.h"

AngleScene::AngleScene()
{
	Vector2 start = { CENTER_X,CENTER_Y };


	line = new Line(start, mousePos); // ȭ�� �߰����� ���콺 Ŀ������ ���� ��
}

AngleScene::~AngleScene()
{
}

void AngleScene::Update()
{

	// ���콺 Ŀ�� ��ġ�� �ٲ�ϱ� ��� ���� ���� �ٲ��

	// ���콺 Ŀ�� ��ġ�� ���󰡵� ���̰� ��� �����ϰ�

	// 1. ���콺 Ŀ���� ���μ��� ������ + �߽ɿ��� ������ �Ÿ� (��ü ��ǥ)�� �ʿ�

	float x = mousePos.x = line->pos.x;
	float y = mousePos.y = line->pos.y;

	//���� ���� ������ �̿��ؼ� ������ ���Ѵ�.

	// ���Ǵ� �� : ź��Ʈ�� ������ (ź��Ʈ= ������ ���� ���� �� �ϳ��� ���� ���� ���)]

	//angle = atan(-y / x); // atan = a(��)+ ź��Ʈ�� �����ϴ� �Լ�
							// �� -y�ΰ�?: ������� y�� Ŀ���� ������ ���ϱ�(���� ���� ��ǥ���� ����)



	angle = atan2(-y, x); // x�� 0�� ��츦 ����ϱ� ���Ѿ��� �Լ�

	// ������ ���ؼ� , �ٽ� ���� �׷��� �� ���� ���� ��ǥ�� ���Ѵ�.
	// ���: ������ ������ ���� (���� ����= �ﰢ���� ����) ��带 �Ἥ
		// ���� ���ο� x, ���ο� y�� ���ϴ� ��

	//float newX = cos(angle); // ������ ���� ������ ������ �˰� �ǰ�
	float newX = cos(angle) * length; // ������ ���� ���̸� ���ؼ� ��μ� ���� ��ǥ ���
	float newY = cos(angle) * length;

	
}

void AngleScene::Render(HDC hdc)
{
}
