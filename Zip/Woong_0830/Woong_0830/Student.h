#pragma once
#include "Citizen.h"// 시민 클래스 포함하기
					// (시민 안에 있는 인간도 자동 포함하기)


class Student : public Citizen //public 부모상속: 반쯤 공식이라고 쳐도 ok



{
public : 

	bool inCourse; // 지정된 과정을 따르는 중인가?
	void GoAcadamy(); 

	void GoDoctorAsCitizen();


	// privat , protected 는 이제 안써도 될 듯






};

