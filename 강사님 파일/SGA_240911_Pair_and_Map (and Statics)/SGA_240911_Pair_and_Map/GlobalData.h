#pragma once
#include <list>

// 오랜만에 쓰는 전역 변수와 함수 선언

std::list<int> homeworkList;
//std::list<int> gnyangList;

// 함수 선언 (정의는 main 아래서 확인)
void Homework();

void ReadyList();
void ShowList();

//과제 대상 (리스트 중간 추가 삭제)
void AddIntToList(int index, int value);
void RemoveIntFromList(int index);