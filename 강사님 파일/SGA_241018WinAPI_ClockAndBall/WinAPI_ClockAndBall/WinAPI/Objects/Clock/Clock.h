#pragma once

class Clock
{
public:
    Clock();
    ~Clock();

    void Update();  // ����
    void Render(HDC hdc);   // ��� (+ ��� �׸� ���ΰ�?)


private:

    // �� �� �� : ��ħ, ��ħ, ��ħ
    Line* lineHour;
    Line* lineMinute;
    Line* lineSecond;

    // �� ħ�� ����
    float lengthHour = 100;
    float lengthMinute = 200;
    float lengthSecond = 150;

    // �ð谡 �־�� �ϴ� ��, ���� ������
    Vector2 position;

    // �ð� ���� ��
    Circle* background;

    // �ð��� ũ��, ������
    float clockSize;

    // ���� �߿��� �� : �ð� ����
    SYSTEMTIME st_time; // �ð� ����ü

    void GetTime();  // �ð��� ��� �ð� ���� ���ϱ�

    // ħ�� ����, ���� ����
    float angleHour;
    float angleMinute;
    float angleSecond;
    Vector2 endHour;    // ���� ����
    Vector2 endMinute;
    Vector2 endSecond;

};

