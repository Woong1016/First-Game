#pragma once


// 헤더 = 전역 변수의 자리

// 구조체 작성

struct Champion
{
	int hitPoint; // hp , 체력
	float hitPointRestore; // 체력 재생
	float atk;	// 공격력
	float atkSpeed;	// 공격 속도
	float def;		// 방어력
	float res; // 마법 저항력
	int range; // 사거리
	float moveSpeed; // 이동속도



};



enum  AGEGROUP
{

	INFANT,
	TODDLER,
	YOUNGSTER,
	JUNIOR,
	YOUNGADULT,
	ADULT,
	MIDDLE,
	SENIOR,
	SILVER,
	OLD,



};