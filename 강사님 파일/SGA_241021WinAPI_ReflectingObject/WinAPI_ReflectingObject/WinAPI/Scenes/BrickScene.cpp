#include "Framework.h"
#include "BrickScene.h"

BrickScene::BrickScene()
{
    bricks.resize(brickAmount); // resize : ���� �Լ�. �뷮 Ȯ�� �� �⺻�� ����
                                // * �̸� �뷮 Ȯ���� �صּ� �Ź� ���Ͱ� �����̴�
                                //   ���� �ð��� ���� �� �ִ�.

    for (int i = 0; i < brickAmount; ++i) // ���� ������ŭ �ݺ�
    {
        // ���� ��ġ
        Vector2 position = { (float)Random(250, WIN_WIDTH - 250), (float)Random(250, WIN_HEIGHT - 250) };

        // ���� ũ��
        float edge = Random(100, 200);
        Vector2 size = { edge, edge }; // ���� ���� ���� ���ο� �Ȱ��� �༭ ���簢������
        
        bricks[i] = new Brick(position, size); // ���� ����
    }
}

BrickScene::~BrickScene()
{
    // �����͵� ����
    for (int i = 0; i < bricks.size(); ++i)
    {
        delete bricks[i];
    }
}

void BrickScene::Update()
{
    for (int i = 0; i < bricks.size(); ++i)
    {
        bricks[i]->Update();
    }

    // �ݻ� �Ǵ�!
    for (int i = 0; i < bricks.size(); ++i)
    {
        for (int j = 0; j < bricks.size(); ++j)
        {
            // i�� j�� ���� �����ϰ� (continue)
            if (i == j) continue;

            // �� ������ �ε�ġ�� �� ���� ��� �ݻ�

            Vector2 overlap = {};   // �浹 ���� �ӽ� ����

            if (bricks[i]->IsRectCollision(bricks[j], &overlap))
            {
                bricks[i]->Reflect(overlap);
                // ������ ��� ������ �������� ���̶� i, j�� ���� �ݻ��� �ʿ�� ����
            }
        }
    }
}

void BrickScene::Render(HDC hdc)
{
    for (int i = 0; i < bricks.size(); ++i)
    {
        bricks[i]->Render(hdc);
    }
}
