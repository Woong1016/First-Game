#pragma once
#include "Citizen.h" //시민 포함


class Woker :public Citizen // 노동자는 시민의 자식 클래스

{
public:

	int payment; //  봉급

	void Work(); // 일하기
	void GoDoctor(); // 병원가기" 그런데 부모 클래스와 철자가 같다.
						// -> 부모의 함수 기능이 이 함수에 덮어 씌인다.


	void Drive(); // 차 운전하기도 오버라이드 하기.

};

