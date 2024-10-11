#pragma once


// 씬: 완전 추상 클래스 
//. 규칙만 존재하는 인터페이스
class Scene
{
public:

	//. 그러므로 이 씬을 상속받는 모든 클래스는...

    virtual void Update() = 0;	// 새로고침 기능이 있어야 하고
    virtual void Render(HDC hdc) = 0;	// 화면 표시 기능도 있어야 한다.
};