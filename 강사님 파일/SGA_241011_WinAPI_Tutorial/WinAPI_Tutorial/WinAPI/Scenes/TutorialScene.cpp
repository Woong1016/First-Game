#include "Framework.h"
#include "TutorialScene.h"

//. ���� �����ϸ� .....

TutorialScene::TutorialScene()
{
    count = 0;  //. �����ڿ��� ù ���� ���� ��Ȳ�� ���ϰ� *(������ �ʱ�ȭ)

	rectsize = {100,100}; // ����ü �����͸� {}�� �ۼ�����!

	rect = new Rect(mousePos, rectsize); // ���콺 ��ġ�� ������


}

TutorialScene::~TutorialScene()
{
	// ������ (Ȥ�� �� ����) ���� �� ���� �ִ� �ڵ带 �����ϰ�
}

void TutorialScene::Update()
{
	//. �� �����ֿ� ���� �ִ� �ڵ带 ��� �����ؼ�
	// . �ش�Ǵ� ������ �߻��ϸ� ���� �����ϰ�...
	//
    //if (GetAsyncKeyState(VK_RETURN))		//.GetAsyncKeyState : Ű�� ��ȭ ���� �Լ�
											//. = Ű�� ������ true , ���� true, ������ �־ �� true
    //if (Keyboard::Get()->Down(VK_RETURN))	// Ű���� Ŭ������ ����� �Ἥ , Down = Ű�� ó�� �������� true
    if (KEY_DOWN(VK_RETURN)) // ���� �Ȱ���, ��, ��ũ�θ� ���� framework.h���� Ȯ�� ����
 
		
		count++;
	VK_LBUTTON; //. ����: ���콺�� ���� ��ư �ƴ�. �������� ��Ŭ����
				// ���̰� �ִ°�? �������� ��Ŭ���� ���콺�� "����" ��ư�� ���ϴ� ��
				// ���콺�� ���� ��ư�� ��ġ�� �ٽ� �������� �������� �ٲ� ���� �ִ�.
				// (���ټ�, Ȥ�� ���콺 ����)

	//. �μ��� �� VK_RETURN: �����쿡�� ������ ���� Ű�ڵ� (VK)��, ����Ű�� �ش��ϴ�

	// . ���콺 ��ġ�� �ٲ�� �簢�� ��ġ�� �ٲ��
	rect->Pos() = mousePos; // �簢�� ��ġ = 
}


void TutorialScene::Render(HDC hdc)
{

	//. �� ������Ʈ �Լ��� ����� ���� �ִ� �ڵ�� ǥ���Ѵ�!
	//. �װ��� ���� ���ư��� ����
	//wstring : string�� Ȯ����. ���� ������ ���� ����Ʈ ���� �ڵ忡 ���� ����
	//			�ٸ����� .... �ѱ� ǥ�� ����.
	//			�� ,"" ���� ���� �빮�� L�� �ٿ���� �Ѵ�.

	//to_wstring : �����쿡�� �־��� �Լ�, �����͸� ���ڷ� �ٲ��ش�.

    wstring str = L"Cursor X : " + to_wstring(mousePos.x) + L" | Y : " + to_wstring(mousePos.y);
    TextOut(hdc, 0, 100, str.c_str(), (int)str.length());

    str = L"���� Ű�� ���� Ƚ�� : " + to_wstring(count);		// count ���
    TextOut(hdc, 0, 120, str.c_str(), (int)str.length());	// 



	// ǥ�� �ǽ� : ���콺 Ŀ�� ���� �簢�� �׸���

	Rectangle(hdc, mousePos.x + 100, mousePos.y + 100, mousePos.x - 100, mousePos.y - 100);

	//���� �� �ڵ� ���, ���� ������� rect���� ���� �Լ� ȣ�⸸

	rect->Render(hdc); // ����Ϳ� �簢���� Render�϶� ��
}
