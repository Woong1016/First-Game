#pragma once

class BitmapScene : public Scene
{
public:

    // ��Ʈ�� �� : �׸� ��¿� Ŭ����

    BitmapScene();
    ~BitmapScene();

    virtual void Update() override;
    virtual void Render(HDC hdc) override;

private:

    // �׸��� �׸��� ���� �ʿ��� �����͵�

    // �׸� ������ ��ü
    HBITMAP dogBitmap;  // HBITMAP : ��Ʈ�� �ڵ鷯 = �̺�Ʈ, ��±�� ���� �� �ִ�
    HBITMAP catBitmap;  // �׸� ������ ���� �� �ִ�

    HBITMAP humanBitmap;

    // ���۸��� �����ؼ� �߰��� �׸��� �غ��ص� ���� ��� ������ �ϳ� �� �ʿ�
    HDC memDC;          // ����� �ڿ��� �׸��� �غ��� ��¥ ����� (=�޸� �� ������)

};

