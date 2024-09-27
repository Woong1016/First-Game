#pragma once
#include "Singleton.h" // 새로 만든 템플릿 싱글턴 포함
class SampleData : public Singleton<SampleData>
							// 템플릿싱글턴 클래스를 상속받음 =
							// 나 자신의 싱글턴으로만 존재 가능한 클래스

{				
	SampleData(); // 생성자에 매개변수 있으면 힘듬
					// -> 싱글턴 (부모클래스) 에 없으므로
	~SampleData();

	int GetData(int index)
	{
		return myData[index];
	}

	void SetData(int index, int value) 
	{
		myData[index] = value;
	}

private:
	
	int myData[10]; // 정수 10개





};

