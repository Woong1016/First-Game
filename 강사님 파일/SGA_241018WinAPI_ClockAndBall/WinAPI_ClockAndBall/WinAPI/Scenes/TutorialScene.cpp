#include "Framework.h"
#include "TutorialScene.h"

// ���� �����ϸ�.....

TutorialScene::TutorialScene()
{
    count = 0; // �����ڿ��� ù ���� ���� ��Ȳ�� ���ϰ� (������ �ʱ�ȭ)

    rectSize = { 100, 100 }; // ����ü �����͸� {}�� �ۼ� ����!
    
    Vector2 zero = { 0, 0 };

    rect = new Rect(zero, rectSize);    // ���콺 ��ġ�� ������ ���� �簢�� ũ��� ����

    sceneRectSize = { 200, 200 }; // �� �� �簢��
    sceneRectPosition = { CENTER_X, CENTER_X };

    rectOnScene = new Rect(sceneRectPosition, sceneRectSize); // �׸� ����

    //���� ���� ���콺 Ŀ���� ����
    radius = 100;
    circle = new Circle(mousePos, radius);

    // �� �� ���� ������ ���� ���� ��Ȱ��
    circleOnScene = new Circle(sceneRectPosition, radius);
}

TutorialScene::~TutorialScene()
{
    // ������ (Ȥ�� �� ����) ���� �� ���� �ִ� �ڵ带 �����ϰ�
}

void TutorialScene::Update()
{
    // �� ���� �߿� ���� �ִ� �ڵ带 ��� �����ؼ�
    // �ش�Ǵ� ������ �߻��ϸ� ���� �����ϰ�....

    //if (GetAsyncKeyState(VK_RETURN)) // GetAsyncKeyState : Ű�� ��ȭ ���� �Լ�. � ���̵� Ű ���� ��ȭ�� ����� true
                                     // = Ű�� ������ true, ���� true, ������ �־ �� true
    //if (Keyboard::Get()->Down(VK_RETURN)) // Ű���� Ŭ������ ����� �Ἥ, Down = Ű�� ó�� ���� ���� true
    if (KEY_DOWN(VK_RETURN))                // ���� �Ȱ���. ��, ��ũ�θ� �� ��. framework.h ���Ͽ��� Ȯ�� ����
        count++;

    VK_LBUTTON; // ���� : ���콺�� ���� ��ư �ƴ�. �������� ��Ŭ����.
                // ���̰� �ִ°�? �������� ��Ŭ���� ���콺�� "����" ��ư�� ���ϴ� ��
                // ���콺�� ���� ��ư�� ��ġ�� �ٽ� �������� �������� �ٲ� ���� �ִ�
                // (���ټ�, Ȥ�� ���콺 ����)

    // �μ��� �� VK_RETURN : �����쿡�� ������ ���� Ű�ڵ�(VK) ��, ����Ű�� �ش��ϴ� ��ũ��
    // VK_�� Ÿ�ڸ� �ĺ��� �ٸ� ��ũ�� Ű �ڵ带 Ȯ�� ����


    // ���콺 ��ġ�� �ٲ�� �簢�� ��ġ�� �ٲ��
    // rect->Pos() = mousePos; // �簢�� ��ġ = ���콺 ��ġ
    
    // ���콺 ��ġ�� �ٲ�� ���� ��ġ�� �ٲ��
    circle->Pos() = mousePos;


    // �� �簢���� �浹 ���θ� �Ǵ��ϴ� �Լ��� �Ἥ, �浹 ���ǹ� �����
    if (rect->IsCollision(rectOnScene)) // ���콺 �簢���� �� �� �簢���� �ε�ġ��
    {
        // �� �� �簢���� �����!!

        // ��� 1. �簢���� ũ�⸦ 0���� �����
        // rectOnScene->SetSize() = { 0, 0 };  // �Ϻ� ���ӿ��� ���� ���

        // ��� 2. �簢���� �ƿ� ���꿡�� ����
        rectOnScene->Active() = false;    //Ȱ��ȭ ���� ��������
    }

    // ������ �浹�ϸ� �Ͼ�� ��
    if (circle->IsCollision(circleOnScene))
    {
        circleOnScene->Active() = false;    // �� �� �� �����
        //circle->Active() = false;           // ���콺 �� ����� ����
    }


    // �ʵ忡 �ִ� ���� �簢���� ���� ������....
    //if (circle->IsCollision(rectOnScene)) // �� ���忡�� �Ǵ�
    if (rectOnScene->IsCollision(circle))   // �簢�� ���忡�� �Ǵ�
    {
        //rectOnScene->Active() = false;  // �簢����
        //circle->Active() = false;       // ���� ��������
    }


    // �̱��� (���簢�� ���� �����ϴ� ���) �ѹ� �Ẹ��
    SpawnManager::Get()->Update();  // �̰Ÿ� ȣ���ص� �� �ȿ��� ���콺 �Է� ����
                                    // �� �Լ��� ���� ����� �ٽ� Render �Լ����� ȣ��

}

void TutorialScene::Render(HDC hdc)
{
    // �� ������Ʈ �Լ��� ����� ���� �ִ� �ڵ�� ǥ���Ѵ�!
    // �װ��� ���� ���ư��� ����

    // wstring : string�� Ȯ����. ���� ������ ���� ����Ʈ ���� �ڵ忡 ���� ����
    //           �ٸ� ����.... �ѱ� ǥ�� ����.
    //           ��, "" ���� ���� �빮�� L�� ���� �ٿ���� �Ѵ�.

    // to_wstring : �����쿡�� �־��� �Լ�. �����͸� ���ڷ� �ٲ��ش�

    wstring str = L"Cursor X : " + to_wstring(mousePos.x) + L" | Y : " + to_wstring(mousePos.y);
    TextOut(hdc, 0, 100, str.c_str(), (int)str.length());

    str = L"���� Ű�� ���� Ƚ�� : " + to_wstring(count); // count ���
    TextOut(hdc, 0, 120, str.c_str(), (int)str.length());

    // ǥ�� �ǽ� : ���콺 Ŀ�� ���� �簢�� �׸���
    // Rectangle(hdc, mousePos.x - 100, mousePos.y - 100, mousePos.x + 100, mousePos.y + 100);

    // ���� �� �ڵ� ���, ���� ������� rect���� ���� �Լ� ȣ�⸸
    //rect->Render(hdc);  // '����Ϳ� �簢���� Render�϶�' ��
    rectOnScene->Render(hdc);

    // �̱������� ���� �簢�� ���
    //SpawnManager::Get()->Render(hdc);

    circle->Render(hdc); // �� ���
    //circleOnScene->Render(hdc);
}
