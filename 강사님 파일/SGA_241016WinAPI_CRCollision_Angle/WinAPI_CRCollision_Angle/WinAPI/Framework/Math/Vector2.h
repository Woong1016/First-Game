#pragma once

struct Vector2  // 2���� ����
{
    // ���� : �����쿡�� ���ϴ� ���ʹ� �ڷ� ������ �ƴ϶� "������ ���� ����"
    //        �߰���б� ���п��� ���� �װ� �´´�.
    
    // 2���� ���� : ���ο� ���� (���̴� ����) ����

    // ����ü�� ���
    float x = 0.0f;     // ����
    float y = 0.0f;     // ����

    Vector2() = default;    // �⺻ ������
    Vector2(float x, float y) : x(x), y(y) {};  // �Ű������� ���� ��

    // ...����ü�ε�, �����ڶ��?
    // -> ����� ����ü�� Ŭ������ �� �� �ִ� �� �� �� �� �ִ�.
    //    �׳� ����ü�� ���� ����� �ַ� ������ �������� ���� �ͻ�

    // �Ʒ� �ڵ�� ������ �������̵��� �ϸ�,
    // +, -, * ���� �����ڿ� ���ο� �ǹ̸� �ο��Ѵ�
    // (����1) + (����2) ���� ����� �����ϰ� �Ѵٴ� ��

    // * �Ʒ� ������ ������ ������ ����� �ڵ�� ��Ÿ�� ��.
    //   ���� ��꿡 ���� �˾ƺ��� �ٽ� ���ƿͼ� ���캸��

    Vector2 operator+(const Vector2& value) const
    {
        return Vector2(x + value.x, y + value.y);
    }
    Vector2 operator-(const Vector2& value) const
    {
        return Vector2(x - value.x, y - value.y);
    }
    Vector2 operator*(const float& value) const
    {
        return Vector2(x * value, y * value);
    }
    Vector2 operator/(const float& value) const
    {
        return Vector2(x / value, y / value);
    }

    void operator+=(const Vector2& value)
    {
        x += value.x;
        y += value.y;
    }
    void operator-=(const Vector2& value)
    {
        x -= value.x;
        y -= value.y;
    }
    void operator*=(const float& value)
    {
        x *= value;
        y *= value;
    }
    void operator/=(const float& value)
    {
        x /= value;
        y /= value;
    }

    // �� ����(��ġ) ������ �Ÿ��� ã�Ƴ��� �Լ�
    float Length() const
    {
        return sqrt(x * x + y * y);
    }
};