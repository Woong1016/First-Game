#include "Framework.h"

#include "Scenes/TutorialScene.h"
#include "Scenes/AngleScene.h"

GameManager* GameManager::instance = nullptr;

// 게임매니저를 실행하면....

GameManager::GameManager()    
{    
    scene = new TutorialScene(); // 0. 씬을 만들고 실행한다.
	scene = new AngleScene(); // 새로운 씬이 있으면 바꾸어 만든다(o)
								// 어차피 같은 scene 변수니까
								// 아래쪽 코드는 바꿀 필요 없음! 
}

GameManager::~GameManager()
{
    delete scene;               // 게임매니저가 끝나면 씬도 (포인터를) 지운다

    Timer::Delete();
    Keyboard::Delete();
}

void GameManager::Init(HWND hWnd) // 1. 게임 매니저가 본격적으로 시작하면
{
    // 화면을 준비한다

    this->hWnd = hWnd;
    hdc = GetDC(hWnd);

    hBackDC = CreateCompatibleDC(hdc);
    hBackBitmap = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);
    SelectObject(hBackDC, hBackBitmap);

    // 화면 준비 끝

    Timer::Get();       // 타이머 시작
    Keyboard::Get();    // 키보드 입력 받는 기능 시작
}

void GameManager::Update()
{
    // 업데이트 : 게임에서 일어나는 일들을 새로고침
    // -> 매시, 매초, 매순간 게임 앱 속 정보를 감시해서
    //    변화가 생기면 즉시 게임에 반영하는 역할을 한다
    //    예 : 키보드가 눌리면 감지하거나, 마우스가 움직이면 위치를 기록하거나
    //    응용하면 자동으로 애니메이션이 재생되거나....(앱 내부에서 그림이 바뀌니까)

    // 그러므로 게임이 업데이트되는 사이에...

    Timer::Get()->Update();     //타이머가 업데이트되어야 한다면 역시 수행
    Keyboard::Get()->Update();  //키보드가 눌렸는지 감시를 수행

    scene->Update();            // 그리고 "씬"도 변화가 생기면 즉시 반영하도록 준비
                                // 그래서 씬 속 Update 함수에서 뭔가 코드를 넣었는데
                                // 수행되면 그대로 데이터에 반영된다
}

void GameManager::Render()
{
    // 화면 표시

    // PatBlt : 다른 곳에서 화면 데이터를 만드는 함수
    // -> 이 함수를 수행함으로써, 가상의 장소에 그림을 미리 그려둔다
    // hBackDC : 실제로는 쓰지 않는, 상관없는 화면 데이터
    PatBlt(hBackDC, 0, 0, WIN_WIDTH, WIN_HEIGHT, WHITENESS);

    //InvalidateRect(hWnd, nullptr, false); // 화면 무효화(맞지 않은 표시 삭제) -> 안 씀

    // 미리 그려둔 그림 위치에 다시 씬의 내용을 덧씌운다

    scene->Render(hBackDC); // 씬에서 생긴 변화도 반영

    Timer::Get()->Render(hBackDC);

    // BitBlt : 화면으로 준비된 데이터가 있을 경우, 출력 도구에 전달해서 표시하는 함수
    // -> 미리 만들어둔 데이터를 실제 모니터로 옮겨서 덮어씌운다
    BitBlt(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT,
        hBackDC, 0, 0, SRCCOPY);

    // 즉, 화면을 지운 다음 그리는 것이 아니라,
    // 다음 순간 그려야 되는 화면 데이터를 미리 만들어둔 다음 (다른 곳에서)
    // 그 데이터를 모니터에 씌워서 화면을 표시한다

    // 이런 기법을 버퍼링이라고 한다
}
