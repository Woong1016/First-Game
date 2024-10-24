﻿// WinAPI.cpp : 애플리케이션에 대한 진입점을 정의합니다.

// ---------------------------------------------------------------------

// 이번 과제 : 아날로그 탁상 시계 만들기

// 초침, 분침, 시침이 있는 아날로그 탁상 시계를 만들어주세요.

// 시침은 12시간마다, 분침은 1시간마다, 초침은 1분마다 한 바퀴 돕니다.

// (쉬움) -> 시침, 분침에 각각 분, 초 반영 안 해도 됩니다.

// (본격) -> 시침, 분침에 각각 분과 초가 반영되도록 한번 해봅시다.
//          (예 : 12시 30분이면 시침은 12와 1 사이에 있어야 합니다.)

// (어려움) -> 시계 위에 숫자, 혹은... 눈금도 그려봅시다

// 시계 모양은 마음대로 해주세요.

// * 렌더 팁 : 언제나 더 밑에 있는 표시 코드가 더 위에 그려집니다.
//             (작은 그림 밑에 큰 그림 코드를 넣으면 작은 그림은 안 보입니다! 주의)


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
