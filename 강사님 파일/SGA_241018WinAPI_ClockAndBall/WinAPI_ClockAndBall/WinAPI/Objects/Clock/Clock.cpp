#include "Framework.h"
#include "Clock.h"

Clock::Clock()
{
    position = { CENTER_X, CENTER_Y };

    lineHour = new Line();
    lineMinute = new Line();
    lineSecond = new Line();

    lineHour->pos = position;
    lineMinute->pos = position;
    lineSecond->pos = position;

    clockSize = 300.0f;
    background = new Circle(position, clockSize);

    // ù ��°�� �ð��� ���
    GetLocalTime(&st_time); // �����ϸ� �ð��� ���� ��, �Ű������� �޴� ������ ��ġ(������)�� ����

    // ���� 1�� �ʱ�ȭ (����, ������)
    angleHour = 0;
    angleMinute = 0;
    angleSecond = 0;

    endHour = { 0, 0 };
    endMinute = { 0, 0 };
    endSecond = { 0, 0 };

    // ������ ���, ������ �ð� ����
    GetTime();
}

Clock::~Clock()
{
}

void Clock::Update()
{
    GetTime(); // �Ž� ���� �ð��� ����
}

void Clock::Render(HDC hdc)
{

    // �ð� ��� = ���, ��ħ, ��ħ, ��ħ ������ �������ָ� �ȴ�

    background->Render(hdc);

    // �� ���̷� ���ڳ� ������ ������ ��ħ �ؿ� �׷�����

    lineHour->Render(hdc);
    lineMinute->Render(hdc);
    lineSecond->Render(hdc);

    // �� ���� ���ڳ� ������ ������ ��ħ ���� �׷�����

    wstring str = to_wstring(angleHour);
    TextOut(hdc, 0, 300, str.c_str(), str.length());

    str = to_wstring(st_time.wSecond);
    TextOut(hdc, 0, 320, str.c_str(), str.length());

}

void Clock::GetTime()
{
    // �ð��� �ٽ� ���, �̾ �� ħ�� ��ġ ���ϱ�

    GetLocalTime(&st_time); // �ð� ��Ȯ�� (�Ź� �ؾ� �Ǵϱ�)

    // ����ü �ȿ� �ִ� ��, �� �� ������ ������ ������ ���ϸ� �ȴ�

    // ���� ����, ȣ���� ����� ���� �غ�
    float pi = 3.14159f;    // ���⿡ ���ڸ� ���ϸ� �׿� �´� '��' ������ ���´�

    // ------------------------------------------------------------------------

    // �ð� ����
    angleHour = (pi * 2) * ((float)st_time.wHour / 12) - 0.5f * pi;
    // �� ������ 12�ð�
    // - 0.5pi = 90��
    // ** float���� ����ȯ�ؼ� ��� ������ ������ �߽��ϴ�. (10-18)

    /*
    
    // ��ħ�׸���
    endHour.x = cos(-angleHour) * lengthHour;       // -1�� ���ؼ� �ð� ���� ����������
    endHour.y = -sin(-angleHour) * lengthHour;
    lineHour->end = endHour + lineHour->pos;    // ��ħ�� ������ ��� ����� �̰�

    // �� ����
    angleMinute = (pi * 2) * ((float)st_time.wMinute / 60) - 0.5f * pi;
    // ��ħ�׸���
    endMinute.x = cos(-angleMinute) * lengthMinute;
    endMinute.y = -sin(-angleMinute) * lengthMinute;
    lineMinute->end = endMinute + lineMinute->pos;

    // �� ����
    angleSecond = (pi * 2) * ((float)st_time.wSecond / 60) - 0.5f * pi;
    // ��ħ�׸���
    endSecond.x = cos(-angleSecond) * lengthSecond;
    endSecond.y = -sin(-angleSecond) * lengthSecond;
    lineSecond->end = endSecond + lineSecond->pos;

    */

    //-------------------------------------------------------------------


    // * ��ȭ!!

    // ���� �ڵ�� �ð� �ٴ� ������ Į���� n��, n��, n�ʸ� �׷��ݴϴ�.
    // �׷��� ������ ��ħ, ��ħ�� ���� ��, ���� ������ ���� �޽��ϴ�.

    // �׷��Ƿ� �ش� ������ ��ħ, ��ħ���� ��� �����ؼ� �׷��ְ��� �մϴ�.
    
    // �׷��� ���ؼ��� ���� ���� ����� �Ǵ� ��ħ���� ���� ��,
    // ��ħ�� �����ϸ鼭 ��ħ��, �ٽ� ��ħ�� �����ϸ鼭 ��ħ�� ������ָ� �˴ϴ�.

    // �� ���� : ��ħ ����!
    angleSecond = (pi * 2) * ((float)st_time.wSecond / 60) - 0.5f * pi;
    
    // ��ħ�׸���
    endSecond.x = cos(-angleSecond) * lengthSecond;
    endSecond.y = -sin(-angleSecond) * lengthSecond;
    lineSecond->end = endSecond + lineSecond->pos;


    // �� ����
    angleMinute = (pi * 2) * ((float)st_time.wMinute / 60) - 0.5f * pi; // ���� ����
    angleMinute += angleSecond / 60; // ��ħ�� �� ������ ��ħ�� 1/60����

    // ��ħ�׸���
    endMinute.x = cos(-angleMinute) * lengthMinute;
    endMinute.y = -sin(-angleMinute) * lengthMinute;
    lineMinute->end = endMinute + lineMinute->pos;


    // �ð� ����
    angleHour = (pi * 2) * ((float)st_time.wHour / 12) - 0.5f * pi;
    // �� ������ 12�ð�. -0.5pi = 90��
    // ** float���� ����ȯ�ؼ� ��� ������ ������ �߽��ϴ�. (10-18)
    angleHour += angleMinute / 12; // ��ħ�� �� ������ ��ħ�� 1/12����


    // ��ħ�׸���
    endHour.x = cos(-angleHour) * lengthHour;       // -1�� ���ؼ� �ð� ���� ����������
    endHour.y = -sin(-angleHour) * lengthHour;
    lineHour->end = endHour + lineHour->pos;    // ��ħ�� ������ ��� ����� �̰�

    





}
