﻿// WinAPI.cpp : 애플리케이션에 대한 진입점을 정의합니다.

// 오늘의 과제 : 스프라이트 자유 출력 도전

// 1. 오늘 진행했던 방법을 따라 스프라이트 시트 사이트에 가서,
//    원하는 스프라이트 시트를 받아봅시다. (여기 있는 파일을 써도 되고,
//    주소는 추가로 카페에 같이 올리겠습니다. 다른 사이트여도 됩니다.)

// 2. 해당 스프라이트 시트를 찾아서... 가로 세로 배치에 따라
//    순번을 부여하고, 해당 순번을 입력하면 그에 맞는 잘린 그림이
//    나오도록 하는 기능을 함수로 만들어봅시다. (순번이 아니라 좌표여도 됩니다.)

// -> 스프라이트에서 나오는 여러 캐릭터 동작 중 하나만 출력되고,
//    순번(혹은 좌표)을 다르렉 입력하면 화면에 다른 동작이 나오도록 합시다

#include "framework.h"
#include "WinAPI.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HWND hWnd;
HINSTANCE hInst;                                // 현재 인스턴스입니다.
Vector2 mousePos = {};

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

    MSG msg = {};

    
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            GameManager::Get()->Update();
            GameManager::Get()->Render();
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

   hWnd = CreateWindowW(szWindowClass, title, WS_OVERLAPPEDWINDOW,
       WIN_START_X, WIN_START_Y,//창 위치
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
    case WM_MOUSEMOVE:
    {
        mousePos.x = (float)LOWORD(lParam);
        mousePos.y = (float)HIWORD(lParam);
    }
        break;        
    case WM_DESTROY://창이 닫힐 때        
        GameManager::Delete();
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