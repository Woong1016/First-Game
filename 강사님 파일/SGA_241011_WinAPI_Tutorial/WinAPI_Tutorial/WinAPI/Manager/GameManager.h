#pragma once

// 게임매니저 싱글턴, 단 하나뿐인 게임관리 클래스!

class GameManager : public Singleton<GameManager>
{
private:
    friend class Singleton;

    GameManager(); 
    ~GameManager();

public:
    void Init(HWND hWnd);  // 실질적인시작 생성자
							// (어차피 싱글턴으로 하나만 있고)
							 // (호출과 동시에 객체가 만들어지므로)

	//WndProc에서 봤던 두 함수
    void Update();				// 업데이트: 게임속 정보 새로고침
    void Render();				// 렌더 : 화면 표시 담당

    HWND GetHWND() { return hWnd; }	// 호출하면 윈도우 정보가 공유 

private:
    static GameManager* instance;

    Scene* scene;		// "씬" 
						// 게임 매니저가 게임을 관리한다면
						// 지금 이 "씬"이 바로
						// 게임속 장면과 그 순간 , 다시말해
						// "지금 내가 보는 윈도우 그 자체"를
						// 정의한다!
						// 다른말로, 이 "씬"이 곧
						// 내 눈에 보이는 게임이다.

						// 그래서 , 이 "씬"이...
						// 우리가 실질적으로 코딩하는 무대.

    HWND hWnd = nullptr;
    HDC hdc = nullptr;

    HDC hBackDC = nullptr;
    HBITMAP hBackBitmap = nullptr;
};