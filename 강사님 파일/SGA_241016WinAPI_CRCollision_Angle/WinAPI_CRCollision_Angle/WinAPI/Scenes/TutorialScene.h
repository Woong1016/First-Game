#pragma once

// 튜터리얼 씬 : 씬을 상속한, 그리고 우리가 실제로 코딩을 할,
//              실질적인 첫 화면

#include "Objects/Basic/Rect.h" // 폴더명 -> 파일명 순으로 적기
                                // 폴더명은 / 로 구분 가능

#include "Objects/Basic/Circle.h" // 원 써보기

class TutorialScene : public Scene
{
public:
    TutorialScene();    // 생성자 (시작)
    ~TutorialScene();   // 소멸자 (끝)

    virtual void Update() override; // 새로고침
    virtual void Render(HDC hdc) override;  //화면표시

private:
    
    int count; // 씬 내부에서 사용할 변수

    //새로 만든 변수들
    Rect* rect; // 사각형 객체 변수 (포인터 인스턴스)
    Vector2 rectSize; // 사각형의 크기

    Rect* rectOnScene; // 씬 속 사각형
    Vector2 sceneRectSize; // 씬 속 사각형 크기
    Vector2 sceneRectPosition;

    // 원 써보기
    Circle* circle;
    float radius;

    Circle* circleOnScene;
};