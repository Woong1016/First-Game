#pragma once
#include <list>

// �������� ���� ���� ������ �Լ� ����

std::list<int> homeworkList;
//std::list<int> gnyangList;

// �Լ� ���� (���Ǵ� main �Ʒ��� Ȯ��)
void Homework();

void ReadyList();
void ShowList();

//���� ��� (����Ʈ �߰� �߰� ����)
void AddIntToList(int index, int value);
void RemoveIntFromList(int index);