#pragma once
class BitmapScene : public Scene

{


	// ��Ʈ�� �� : �׸� ��¿� Ŭ����

public:
	BitmapScene();
	~BitmapScene();

	virtual void Update()override;
	virtual void Render(HDC hdc) override;




private:

	HBITMAP dogBitmap;	// HBITMAP : ��Ʈ�� �ڵ鷯 = �̺�Ʈ , ��±�� ���� �� �ִ�.
	HBITMAP catBitmap;	// �׸� ������ ���� �� �ִ�. 
	HBITMAP SkBitmap;

	//���۸��� �����ؼ� �߰��� �׸��� �غ��ص� ���� ��µ����� �ϳ� �� �ʿ�

	HDC memDC;	// ����� �ڿ��� �׸��� �غ��� ��¥ ����� (�޸� �� ������)

};

