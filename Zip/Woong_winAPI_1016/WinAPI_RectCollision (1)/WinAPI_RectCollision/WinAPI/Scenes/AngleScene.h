#pragma once
class AngleScene : public Scene
{

public:
	AngleScene();    // 생성자 (시작)
	~AngleScene();   // 소멸자 (끝)

	virtual void Update() override; // 새로고침
	virtual void Render(HDC hdc) override;  //화면표시


private:
	//선을 전담해서 그려줄 기능

	Line* line; //선

	// 선에 길이를 정해주기 위한 추가 변수
	// 내가 가진 것: 선이 원래 찍히는 가로 , 세로 좌표 (마우스 커서)
	// 필요한 것 : 선에 정해져야 할 길이 , 그리고 각도

	float lenth = 300.0f; 
	float pi = 3.14159; // 파이
	float angle = pi * -0.25f;
};

