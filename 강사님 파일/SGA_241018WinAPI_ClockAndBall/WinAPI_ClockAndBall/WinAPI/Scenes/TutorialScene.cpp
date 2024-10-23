#include "Framework.h"
#include "TutorialScene.h"

// 씬을 시작하면.....

TutorialScene::TutorialScene()
{
    count = 0; // 생성자에서 첫 씬의 시작 상황을 정하고 (데이터 초기화)

    rectSize = { 100, 100 }; // 구조체 데이터를 {}로 작성 가능!
    
    Vector2 zero = { 0, 0 };

    rect = new Rect(zero, rectSize);    // 마우스 위치와 위에서 정한 사각형 크기로 생성

    sceneRectSize = { 200, 200 }; // 씬 속 사각형
    sceneRectPosition = { CENTER_X, CENTER_X };

    rectOnScene = new Rect(sceneRectPosition, sceneRectSize); // 네모 생성

    //원을 만들어서 마우스 커서에 대입
    radius = 100;
    circle = new Circle(mousePos, radius);

    // 씬 속 원은 위에서 만든 변수 재활용
    circleOnScene = new Circle(sceneRectPosition, radius);
}

TutorialScene::~TutorialScene()
{
    // 게임이 (혹은 이 씬이) 끝날 때 여기 있는 코드를 수행하고
}

void TutorialScene::Update()
{
    // 씬 실행 중에 여기 있는 코드를 계속 감시해서
    // 해당되는 연산이 발생하면 전부 수행하고....

    //if (GetAsyncKeyState(VK_RETURN)) // GetAsyncKeyState : 키값 변화 감지 함수. 어떤 식이든 키 값에 변화만 생기면 true
                                     // = 키를 눌러도 true, 떼도 true, 누르고 있어도 다 true
    //if (Keyboard::Get()->Down(VK_RETURN)) // 키보드 클래스의 기능을 써서, Down = 키를 처음 누를 때만 true
    if (KEY_DOWN(VK_RETURN))                // 위와 똑같다. 단, 매크로를 쓴 것. framework.h 파일에서 확인 가능
        count++;

    VK_LBUTTON; // 주의 : 마우스의 왼쪽 버튼 아님. 윈도우의 좌클릭임.
                // 차이가 있는가? 윈도우의 좌클릭은 마우스의 "결정" 버튼을 뜻하는 것
                // 마우스의 결정 버튼의 위치는 다시 윈도우의 설정에서 바꿀 수가 있다
                // (접근성, 혹은 마우스 설정)

    // 인수로 들어간 VK_RETURN : 윈도우에서 지정한 가상 키코드(VK) 중, 엔터키에 해당하는 매크로
    // VK_로 타자를 쳐보면 다른 매크로 키 코드를 확인 가능


    // 마우스 위치가 바뀌면 사각형 위치가 바뀌도록
    // rect->Pos() = mousePos; // 사각형 위치 = 마우스 위치
    
    // 마우스 위치가 바뀌면 원의 위치가 바뀌도록
    circle->Pos() = mousePos;


    // 두 사각형의 충돌 여부를 판단하는 함수를 써서, 충돌 조건문 만들기
    if (rect->IsCollision(rectOnScene)) // 마우스 사각형과 씬 속 사각형이 부딪치면
    {
        // 씬 속 사각형을 지우기!!

        // 방법 1. 사각형의 크기를 0으로 만들기
        // rectOnScene->SetSize() = { 0, 0 };  // 일부 게임에서 쓰는 방법

        // 방법 2. 사각형을 아예 연산에서 제외
        rectOnScene->Active() = false;    //활성화 값을 거짓으로
    }

    // 원끼리 충돌하면 일어나는 일
    if (circle->IsCollision(circleOnScene))
    {
        circleOnScene->Active() = false;    // 씬 속 원 지우기
        //circle->Active() = false;           // 마우스 원 지우기 생략
    }


    // 필드에 있는 원과 사각형이 서로 닿으면....
    //if (circle->IsCollision(rectOnScene)) // 원 입장에서 판단
    if (rectOnScene->IsCollision(circle))   // 사각형 입장에서 판단
    {
        //rectOnScene->Active() = false;  // 사각형과
        //circle->Active() = false;       // 원이 지워지게
    }


    // 싱글턴 (직사각형 랜덤 생성하는 기능) 한번 써보기
    SpawnManager::Get()->Update();  // 이거만 호출해도 이 안에서 마우스 입력 받음
                                    // 이 함수의 실행 결과는 다시 Render 함수에서 호출

}

void TutorialScene::Render(HDC hdc)
{
    // 위 업데이트 함수의 결과를 여기 있는 코드로 표시한다!
    // 그것이 씬이 돌아가는 구조

    // wstring : string의 확장판. 여러 국가의 복수 바이트 문자 코드에 대응 가능
    //           다른 말로.... 한글 표시 가능.
    //           단, "" 쓰기 전에 대문자 L을 먼저 붙여줘야 한다.

    // to_wstring : 윈도우에서 주어진 함수. 데이터를 문자로 바꿔준다

    wstring str = L"Cursor X : " + to_wstring(mousePos.x) + L" | Y : " + to_wstring(mousePos.y);
    TextOut(hdc, 0, 100, str.c_str(), (int)str.length());

    str = L"엔터 키를 누른 횟수 : " + to_wstring(count); // count 사용
    TextOut(hdc, 0, 120, str.c_str(), (int)str.length());

    // 표시 실습 : 마우스 커서 따라 사각형 그리기
    // Rectangle(hdc, mousePos.x - 100, mousePos.y - 100, mousePos.x + 100, mousePos.y + 100);

    // 윗줄 긴 코드 대신, 이제 만들어진 rect에서 간편 함수 호출만
    //rect->Render(hdc);  // '모니터에 사각형을 Render하라' 끝
    rectOnScene->Render(hdc);

    // 싱글턴으로 만든 사각형 출력
    //SpawnManager::Get()->Render(hdc);

    circle->Render(hdc); // 원 출력
    //circleOnScene->Render(hdc);
}
