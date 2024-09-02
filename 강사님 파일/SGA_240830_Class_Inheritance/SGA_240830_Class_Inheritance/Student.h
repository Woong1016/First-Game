#pragma once

#include "Citizen.h" // 시민 클래스 포함하기
                     // (시민 안에 있는 인간도 자동 포함하기)

class Student : public Citizen // public 부모 상속 : 반쯤 공식이라고 쳐도 OK
{

public:

    bool inCourse;  // 지정된 과정을 따르는 중인가?
    void GoAcademy(); // 학원 가기

    void GoDoctorAsCitizen(); // 부모 클래스 기능 쓰기

    // private, protected는 이제 안 써도 될듯
};

