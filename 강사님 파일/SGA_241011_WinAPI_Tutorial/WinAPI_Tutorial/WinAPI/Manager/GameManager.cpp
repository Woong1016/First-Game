#include "Framework.h"

#include "Scenes/TutorialScene.h"

GameManager* GameManager::instance = nullptr;


//. ���ӸŴ����� �����ϸ�
GameManager::GameManager()    
{    
    scene = new TutorialScene();		// ���� ����� �����Ѵ�.
}

GameManager::~GameManager()
{
    delete scene;			//. ���ӸŴ����� ������ ���� (�����͸�) �����.

    Timer::Delete();
    Keyboard::Delete();
}


void GameManager::Init(HWND hWnd)	// ���ӸŴ����� ���������� �����ϸ�


{

	//. ȭ���� �غ��Ѵ�.
    this->hWnd = hWnd;
    hdc = GetDC(hWnd);

    hBackDC = CreateCompatibleDC(hdc);
    hBackBitmap = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);
    SelectObject(hBackDC, hBackBitmap);    

	//. ȭ�� �غ� ��

    Timer::Get();		//. Ÿ�̸ӽ���
	
    Keyboard::Get();	// Ű���� �Է¹޴� ��� ����.
}

void GameManager::Update()
{
	//. ������Ʈ : ���ӿ��� �Ͼ�� �ϵ��� ���ΰ�ħ
	//-> �Ž� , ����, �ż��� ���� �� �� ������ �����ؼ�
	//. ��ȭ�� ����� ��� ���ӿ� �ݿ��ϴ� ������ �Ѵ�.
	// ��: Ű���尡 ������ �����ϰų�, ���콺�� �����̸� ��ġ�� ����ϰų�
	//. �����ϸ� �ڵ����� �ִϸ��̼��� ����ǰų�,,, (�� ���ο��� �׸��� �ٲ�ų�)

	

	// �׷��Ƿ� ������ ������Ʈ �Ǵ� ���̿�...
    Timer::Get()->Update(); //. Ÿ�̸Ӱ� ������Ʈ �Ǿ�� �Ѵٸ� ���� ����
    Keyboard::Get()->Update();	//. Ű���尡 ���ȴ��� ���ø� ����

    scene->Update(); //. �׸��� ���� ��ȭ�� ����� ��� �ݿ��ϵ��� �غ�
}					// �׷���  �� �� Update �Լ����� ���� �ڵ带 �־��µ�
					// ����Ǹ� �״�� �����Ϳ� �ݿ��ȴ�.

void GameManager::Render()
{
	//, ȭ�� ǥ��

	//PatBlt : �ٸ� ������ ȭ�� �����͸� ����� �Լ�
	// -> �� �Լ��� ���������ν� , ������ ��ҿ� �׸��� �̸� �׷��д�.
	//hBackDC : �����δ� ���� �ʴ� ������� ȭ�� ������
    PatBlt(hBackDC, 0, 0, WIN_WIDTH, WIN_HEIGHT, WHITENESS);

    //InvalidateRect(hWnd, nullptr, false); // ȭ�� ��ȿȭ(���� ���� ǥ�� ����) -> ���� �Ⱦ�

	// �̸� �׷��� �׸� ��ġ�� �ٽ� ���� ������ �������. 
    scene->Render(hBackDC);

    Timer::Get()->Render(hBackDC); //. ������ ���� ��ȭ�� �ݿ�
			
	// ���� ���� �ʴ´ٸ� ����Ƿ����� ���� �����״�.  ����߰���?^^

	//BitBlt : ȭ������ �غ�� �����Ͱ� ���� ���, ��� ������ �����ؼ� ǥ���ϴ� �Լ�
	//�̸� ������ �����͸� ���� ����ͷ� �Űܼ� ������. 
    BitBlt(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT,
        hBackDC, 0, 0, SRCCOPY);

	//�� , ȭ���� ���� ���� �׸��� ���� �ƴ϶�. 
	// ���� ���� �׷��� �Ǵ� ȭ�� �����͸� �̸� ������ ���� (�ٸ� ������)
	// �� �����͸� ����Ϳ� ������ ȭ���� ǥ���Ѵ�.

	//�̷� ����� ���۸��̶�� �Ѵ�. 
}
