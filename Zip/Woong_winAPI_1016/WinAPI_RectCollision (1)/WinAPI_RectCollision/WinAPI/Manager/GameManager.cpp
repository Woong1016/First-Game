#include "Framework.h"

#include "Scenes/TutorialScene.h"
#include "Scenes/AngleScene.h"

GameManager* GameManager::instance = nullptr;

// ���ӸŴ����� �����ϸ�....

GameManager::GameManager()    
{    
    scene = new TutorialScene(); // 0. ���� ����� �����Ѵ�.
	scene = new AngleScene(); // ���ο� ���� ������ �ٲپ� �����(o)
								// ������ ���� scene �����ϱ�
								// �Ʒ��� �ڵ�� �ٲ� �ʿ� ����! 
}

GameManager::~GameManager()
{
    delete scene;               // ���ӸŴ����� ������ ���� (�����͸�) �����

    Timer::Delete();
    Keyboard::Delete();
}

void GameManager::Init(HWND hWnd) // 1. ���� �Ŵ����� ���������� �����ϸ�
{
    // ȭ���� �غ��Ѵ�

    this->hWnd = hWnd;
    hdc = GetDC(hWnd);

    hBackDC = CreateCompatibleDC(hdc);
    hBackBitmap = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);
    SelectObject(hBackDC, hBackBitmap);

    // ȭ�� �غ� ��

    Timer::Get();       // Ÿ�̸� ����
    Keyboard::Get();    // Ű���� �Է� �޴� ��� ����
}

void GameManager::Update()
{
    // ������Ʈ : ���ӿ��� �Ͼ�� �ϵ��� ���ΰ�ħ
    // -> �Ž�, ����, �ż��� ���� �� �� ������ �����ؼ�
    //    ��ȭ�� ����� ��� ���ӿ� �ݿ��ϴ� ������ �Ѵ�
    //    �� : Ű���尡 ������ �����ϰų�, ���콺�� �����̸� ��ġ�� ����ϰų�
    //    �����ϸ� �ڵ����� �ִϸ��̼��� ����ǰų�....(�� ���ο��� �׸��� �ٲ�ϱ�)

    // �׷��Ƿ� ������ ������Ʈ�Ǵ� ���̿�...

    Timer::Get()->Update();     //Ÿ�̸Ӱ� ������Ʈ�Ǿ�� �Ѵٸ� ���� ����
    Keyboard::Get()->Update();  //Ű���尡 ���ȴ��� ���ø� ����

    scene->Update();            // �׸��� "��"�� ��ȭ�� ����� ��� �ݿ��ϵ��� �غ�
                                // �׷��� �� �� Update �Լ����� ���� �ڵ带 �־��µ�
                                // ����Ǹ� �״�� �����Ϳ� �ݿ��ȴ�
}

void GameManager::Render()
{
    // ȭ�� ǥ��

    // PatBlt : �ٸ� ������ ȭ�� �����͸� ����� �Լ�
    // -> �� �Լ��� ���������ν�, ������ ��ҿ� �׸��� �̸� �׷��д�
    // hBackDC : �����δ� ���� �ʴ�, ������� ȭ�� ������
    PatBlt(hBackDC, 0, 0, WIN_WIDTH, WIN_HEIGHT, WHITENESS);

    //InvalidateRect(hWnd, nullptr, false); // ȭ�� ��ȿȭ(���� ���� ǥ�� ����) -> �� ��

    // �̸� �׷��� �׸� ��ġ�� �ٽ� ���� ������ �������

    scene->Render(hBackDC); // ������ ���� ��ȭ�� �ݿ�

    Timer::Get()->Render(hBackDC);

    // BitBlt : ȭ������ �غ�� �����Ͱ� ���� ���, ��� ������ �����ؼ� ǥ���ϴ� �Լ�
    // -> �̸� ������ �����͸� ���� ����ͷ� �Űܼ� ������
    BitBlt(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT,
        hBackDC, 0, 0, SRCCOPY);

    // ��, ȭ���� ���� ���� �׸��� ���� �ƴ϶�,
    // ���� ���� �׷��� �Ǵ� ȭ�� �����͸� �̸� ������ ���� (�ٸ� ������)
    // �� �����͸� ����Ϳ� ������ ȭ���� ǥ���Ѵ�

    // �̷� ����� ���۸��̶�� �Ѵ�
}
