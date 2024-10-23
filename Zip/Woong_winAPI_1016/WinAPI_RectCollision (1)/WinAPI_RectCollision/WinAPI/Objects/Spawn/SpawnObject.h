#pragma once

// ���簢���� �� �� ���� ����� ���� �غ��ߴ� Ŭ����
// �������� ���簢���� ����� �Ѹ���

class SpawnObject : public Rect
{
private:
    const float MIN_SIZE = 50.0f;
    const float MAX_SIZE = 200.0f;
    const float MIN_LIFE_TIME = 3;
    const float MAX_LIFE_TIME = 10;

public:
    SpawnObject();
    ~SpawnObject();

    void Update();
    void Render(HDC hdc);

    void Spawn();
    void Destroy();

private:    
    float lifeTime = 0;
    float playTime = 0;

    HBRUSH hBrush = nullptr;
    // HBursh : �귯�� �ڵ鷯. ���� ǥ��, ����, ��� ���� ����
    //          �ڵ鷯�� "�̺�Ʈ �Լ��� �̿��ؼ� Ư�� ���ø� ������ �����ϰ� ���� ���"
    //          ���⼭�� ����� ����Ű�� �ִٰ�, '����, ��Ÿ��, ��¹��' � ����
    //          �����ڰ� ���߿� ���� �ڵ带 �����ϸ� �׿� ���߾ ������ �����Ѵ�
};