#include "Framework.h"

// Timer Ŭ������ ������
Timer::Timer()
{
    // CPU�� 1�� ������ �������� ��ȯ�ϴ� �Լ� (��, CPU Ŭ�� �ֱ⸦ ����)
    QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency);

    // ���� ������ CPU �������� ��ȯ�ϴ� �Լ� (���� �ð��� Ÿ�ӽ������� ����)
    QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);

    // �������� ���� �ð��� �� ������ ��ȯ�ϴ� ������ ���
    timeScale = 1.0f / (float)periodFrequency;
}

Timer::~Timer()
{
    // �Ҹ���: ����� �ƹ� �۾��� ���� ����
}

// �� �����Ӹ��� ȣ��Ǵ� �Լ��� �ð��� ������
void Timer::Update()
{
    // ���� �ð��� CPU �������� ��ȯ��
    QueryPerformanceCounter((LARGE_INTEGER*)&curTime);

    // ���� �����Ӱ� ���� ������ ������ �ð�(��)�� �����
    elapsedTime = (float)(curTime - lastTime) * timeScale;

    // ���� �ð��� ���� ������ ��꿡 ����ϱ� ���� ������
    lastTime = curTime;

    // ������ ī��Ʈ�� ������Ŵ
    frameCount++;

    // 1�� ���� �ð��� ��� �ð��� ����
    oneSecCount += elapsedTime;

    // 1�ʰ� ����ϸ� FPS�� ����ϰ� �ʱ�ȭ��
    if (oneSecCount >= 1.0f)
    {
        // �ʴ� ������ ��(FPS)�� ������
        frameRate = frameCount;

        // ������ ī��Ʈ�� 0���� �ʱ�ȭ��
        frameCount = 0;

        // 1�� ���� �ð��� �ʱ�ȭ��
        oneSecCount = 0.0f;
    }
}

// FPS�� Delta Time(��� �ð�)�� ȭ�鿡 ����ϴ� �Լ�
void Timer::Render(HDC hdc)
{
    // FPS�� ����ϱ� ���� ���ڿ��� ������
    wstring str = L"FPS : " + to_wstring(frameRate);

    // ȭ���� (0, 0) ��ǥ�� FPS�� �����
    TextOut(hdc, 0, 0, str.c_str(), (int)str.length());

    // ��� �ð��� ����ϱ� ���� ���ڿ��� ������
    str = L"Delta : " + to_wstring(elapsedTime);

    // ȭ���� (0, 20) ��ǥ�� Delta Time�� �����
    TextOut(hdc, 0, 20, str.c_str(), (int)str.length());
}
