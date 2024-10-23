#include "Framework.h"

SpawnObject::SpawnObject()
{
    isActive = false;
}

SpawnObject::~SpawnObject()
{
    Destroy();
}

void SpawnObject::Update()
{
    if (!isActive) return;

    //playTime += DELTA;
    //
    //if (playTime >= lifeTime)
    //    Destroy();
}

void SpawnObject::Render(HDC hdc)
{
    if (!isActive) return;

    SelectObject(hdc, hBrush);
    // SelectObject : hBrush �귯�ø� �����ϴ� �Լ�
    // �̰� ������ ���ְ� ����, �� ������ ��ü�� �׸���
    // ��μ� �����ϱ� ���� �����ߴ� �귯�� ������ ���� ��ü�� �׷����� �ȴ�
    // = �귯�ô� ����ٰ� ���� �ƴϰ�, ���ñ��� �ؾ� ���� �׸��Ⱑ ����ȴ�

    Rect::Render(hdc);
}

void SpawnObject::Spawn()
{
    if (isActive) return;

    isActive = true;

    // ���� ���� ���� ������ ���ؼ� ��ġ, ũ�⸦ �ٲٰ� �� ���� ��Ÿ����
    // ���⼭ ���� Random : rand() �Լ��� �� �� ���� ���� ���� �����ӿ�ũ �Լ�

    lifeTime = Random(MIN_LIFE_TIME, MAX_LIFE_TIME);
    playTime = 0.0f;
    
    size.x = Random(MIN_SIZE, MAX_SIZE);
    size.y = Random(MIN_SIZE, MAX_SIZE);

    pos.x = Random(size.x * 0.5f, WIN_WIDTH - size.x * 0.5f);
    pos.y = Random(size.y * 0.5f, WIN_HEIGHT - size.y * 0.5f);

    int r = Random(0, 255);
    int g = Random(0, 255);
    int b = Random(0, 255);

    hBrush = CreateSolidBrush(RGB(r, g, b));
    // �귯�ÿ� ���� ����ڰ� ���ø� ȣ���ϴ� �ڵ�
    // CreateSolidBrush : ���� ������ �غ��ϴ� �Լ�.
    // �Ű������� �����찡 �̸� ���� ���� �̸�, Ȥ�� RGB ��ũ��
    // ���⼭�� RGB ��ũ�ΰ� ������

    // �̷��� �귯�ð� ��������� ����, �ٽ� ���� �ڵ忡�� ���õ� �Ŀ�
    // �������� ȿ���� ������ �ȴ� (Render �Լ����� ���)
}

void SpawnObject::Destroy()
{
    if (hBrush == nullptr)
        return;

    isActive = false;

    DeleteObject(hBrush);
}
