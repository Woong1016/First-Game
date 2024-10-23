// WinAPI.cpp : 애플리케이션에 대한 진입점을 정의합니다.

// ---------------------------------------------------------------------

// 주말의 과제 : 공 가두기, 반사하기 + 응용

// 1. 공 가두기 (쉬움)

// 공이 창 밖으로 나가지 않게 해주세요.

// 2. 공 튕기기 (보통)

// 공이 창 끝에 닿으면 (윈도우 밖으로 좀 비져나가는 건 OK)
// 오던 반대 방향으로 튕겨나가게 해주세요.

// 즉 반사가 구현되어야 합니다!

// 3. 다른 물체와의 반사 (어려움)

// 공이 창만 아니라, 다른 물체, 특히 사각형에 부딪치면
// 그 때도 반사가 되도록 해주세요.

// 4. 그리고 3.까지 가능하면.....

// 공이 사각형과 부딪쳤는데, 공도 반사되면서, 사각형도 사라진다면??

// -> 그게 바로 고전 게임 '운석 쏘기'입니다. 그리고...
//    여기 나오는 사각형이 되게 많고 규칙적으로 늘어서 있다면?
//    그게 바로 벽돌 깨기입니다.


// ---------------------------------------------------------------------

#include "framework.h"
#include "WinAPI.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
Vector2 mousePos = {};                          // 마우스 위치 기록용 변수

WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPI, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINAPI);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   //WCHAR : WIDE Char(2Byte)
   WCHAR title[] = L"Tutorial";

   RECT size = { 0, 0, WIN_WIDTH, WIN_HEIGHT };

   AdjustWindowRect(&size, WS_OVERLAPPEDWINDOW, false);

   HWND hWnd = CreateWindowW(szWindowClass, title, WS_OVERLAPPEDWINDOW,
       CW_USEDEFAULT, 0,//창 위치
       size.right - size.left,
       size.bottom - size.top,//창 크기
       nullptr, nullptr, hInstance, nullptr);

   SetMenu(hWnd, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:

        GameManager::Get()->Init(hWnd); // 윈도우 생성 시, "게임매니저"라는 것을 만든다
        SetTimer(hWnd, 0, 10, nullptr); // 윈도우 기능 "타이머 세팅" 수행
                                        // 정해진 초마다 (현재 100분의 1초) 앱이
                                        // 타이머 신호를 따로 하나 더 받는다 (WM_TIMER)
        
        break;
    case WM_COMMAND://메뉴관련 메시지
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;    
    case WM_PAINT://화면이 처음 생성 될 때나 가려졌다가 다시 그릴경우
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);            

            EndPaint(hWnd, &ps);
        }
        break;    
    case WM_MOUSEMOVE:  // 마우스가 움직이면
    {
        // 마우스 위치 기록 (자료형과 구조는 Vector2 클래스에서 확인)
        mousePos.x = (float)LOWORD(lParam);
        mousePos.y = (float)HIWORD(lParam);
    }
        break;    
    case WM_TIMER:  // 타이머 신호가 들어오면 ( = 100분의 1초마다)
        GameManager::Get()->Update();   // 게임매니저에서 Update와...
        GameManager::Get()->Render();   // Render 함수를 실행
        break;
    case WM_DESTROY://창이 닫힐 때
        KillTimer(hWnd, 0);             // 타이머 종료
        GameManager::Delete();          // 게임매니저 "삭제" 함수 실행
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
