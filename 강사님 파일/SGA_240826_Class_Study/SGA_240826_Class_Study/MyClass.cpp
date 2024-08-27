#include "MyClass.h"

void MyClass::Set_X(int x)
{
    // 함수의 목적 : 클래스 속 x를 매개변수 x로 설정하기. 오직 그거 하나

    this->x = x; // 왼쪽의 'this->' : "이 클래스의 변수, 멤버"라는 뜻
                 // 오른쪽의 그냥 x : 딱히 지칭이 없으면 매개변수라는 뜻
}

// {} 속 코드가 너무 짧으면 그냥 이렇게 한 줄로 작성해도 OK
// 그리고 이 정도로 짧은 함수는 종종 헤더 내에서 그냥 다 작성하기도...
void MyClass::Set_Y(int y) { this->y = y; }
void MyClass::Set_Z(int z) { this->z = z; }

int MyClass::Get_X()
{
    return x; // () 안에 헷갈리는 다른 이름이 없어서 this-> 없어도 됨
              // return x; 만으로도 자동으로 클래스 속 x가 반환
}

int MyClass::Get_Y() { return y; }
int MyClass::Get_Z() { return z; }
