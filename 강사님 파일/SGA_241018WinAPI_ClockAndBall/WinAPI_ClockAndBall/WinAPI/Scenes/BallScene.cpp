#include "Framework.h"
#include "BallScene.h"

BallScene::BallScene()
{
    
    Vector2 origin = { CENTER_X, CENTER_Y };

    ball = new Ball(origin, 75);


 


}

BallScene::~BallScene()
{
    // �Ҹ꿡�� ������ �Ǵ� ��
    // -> �� ���� ������ = �� �ȿ� �ִ� �����ʹ� �� �̻� �� ����

    // �׷��Ƿ�
    delete ball; // �� �޸𸮸� ��ǻ�Ͱ� ����� �ᵵ �ȴٰ� �������ش�

    // -> �׷��� ���߿� ���� ���� ���ӿ����� ��ǻ�Ͱ� �ӵ��� ������ �� �ִ�!

}

void BallScene::Update()
{

    ball->Update();
}

void BallScene::Render(HDC hdc)
{
    
    ball->Render(hdc);

}
    
