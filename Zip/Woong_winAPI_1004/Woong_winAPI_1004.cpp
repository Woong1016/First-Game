// Woong_winAPI_1004.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

// 다른 말로 , 콘솔 앱의 main 함수에 해당하는 부분을 정의합니다.

#include "framework.h"
#include "Woong_winAPI_1004.h"

#define MAX_LOADSTRING 100	// 보라색 글자는 컴파일 시에 100으로 변환
							// 밑에 있는 배열은 szTitle[100]이나 다름없다

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스= 실행하면 나오는 윈도우입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 여기서 쓰인 HINSTANCE, WHCAR 모두 typedef 로 이름을 바꾼 재정의 자료형명

// HINSTANCE : 윈도우에서 벌어지는 일을 정보로 얻기 위한 클래스 (이해하고 쓰기만 하면 ok)
//	WCHAR : WCHAR.H로 추가한 char 자료형의 확장판. 2바이트 이상 문자 코드를 하나로 해석 가능
//				그 외에는 char와 비슷하다. 

// 그리고 위 자료형이 typedef 의 결과 , 그냥 보통 자료형인 것처럼
// winAPI에는 이름은 거창한데 실제로는 그냥 숫자, 그냥 문자인 데이터도 많다
//= 너무 어렵게 접근하지 않아도 된다! 

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
// = 윈도우가 존재하려면 아래 함수가 필요하다.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// 이쪽이 진짜 메인함수 (총 5개 함수)
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,			// 지금 만들 윈도우
                     _In_opt_ HINSTANCE hPrevInstance,	// (만약 있었다면 ) 참고할 이전 윈도우
                     _In_ LPWSTR    lpCmdLine,			// 실행 파일에 옵션 라인이 경우 데이터 전달
                     _In_ int       nCmdShow)			// 옵션 라인(옵션 인수가)이 있는가?
{												// 옵션 라인 (인수)은 또 뭔가?
												// 실행 파일 뒤에 붙여서 실행 속성을 변화시키는 것
													// 예: dir -w /p 에서 -w 혹은 /p



    UNREFERENCED_PARAMETER(hPrevInstance);		// 사전 정보가 있으면 참조
    UNREFERENCED_PARAMETER(lpCmdLine);			// 실행 옵션도 있으면 참조
												// (없으면 상관 없음)

    // 윈도우가 맨 처음 만들어지기 전부터 실행되어야 할 코드가 있다면 여기서 작성
	//... 하지만 게임 개발에선 안쓰인다. (혹은 쓰여야 할 경우 이미 작성된)
	//	부분을 가져와서 인용할 것)
	

    // 전역 문자열을 초기화합니다.
	//-> 전역 변수에 있던 문자열 (윈도우 이름등 ) 수정을 여기서 한다
	//		다른 말로 , 윈도우 이름을 정한다
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WOONGWINAPI1004, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다: = 윈도우 생성
    if (!InitInstance (hInstance, nCmdShow)) // 이게 윈도우 생성 함수 그자체
											// + 더불어서 결과가 성공인지 실패인지 
    {
        return FALSE;	// 윈도우가 안만들어지면 그냥 앱종료
    }


	// 윈도우가 만들어졌으면 후속 절차 만들기 

	// 앱이 OS와 통신하기 위한 준비를 하기 
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WOONGWINAPI1004));

    MSG msg; // OS로부터 받는 정보가 있으면 이쪽으로 받기 

	// OS로부터 정보를 받는다고?? - 여러가지를 받는다

	// 예: 키보드나 마우스 조작부터 , 소리, 버튼이 있으면 버튼 누르기, 클릭과 커서 위치까지
	//	갖가지 정보를 다 받는다. 


	//	여기까지 애플리케이션 초기화를 수행합니다 : => 이후 윈도우 실행 시작 ><

    // 기본 메시지 루프입니다: 위에서 받은 정보를 여기서 쓴다.
    while (GetMessage(&msg, nullptr, 0, 0))	// "정보" 즉 메시지가 존재한다면 
    {
		// 그 메시지가 준비된 규격에 맞추어 해석할 수도 있다면
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
			// 메시지를 처리한다
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
	//모든 앱이 끝나면 최종 정보를 다시 OS (컴퓨터)에 반환하고 윈도우를 닫는다


    return (int) msg.wParam;
	
	// 아주 간단히 말하면 :

	// 1. 사전 정보를 만든다
	// 2. 윈도우 바탕 판을 만든다
	// 3. 추가 정보를 위한 변수를 만든다. 
	// 4. 매시매초 추가 정보를받으면서 그떄그때 들어오는 신호를 처리한다.
	//		(-> 이게 우리가 보는 앱 실행의 99%)

	//5. 종료 신호가 오면 최종 결과를 컴퓨터에게 주고 앱을 마친다.

	//이 1~5 까지가 윈도우 앱의 구성, 혹은 바로 이 WinMain 함수의 구성

	///* 따라서 , 우리가 게임을 만든다고 하면....

	// 바로 위 순서 중 4번 항목에서 컴퓨터가 처리할 신호의 구분과,
	// 받아낸 신호로 무슨 연산을 할지 그걸 코딩으로 정하는 걸 가리킨다.
	//(winAPI의 경우는 그렇다.)
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;		// 윈도우 출력 스타일 
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WOONGWINAPI1004));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);		// 기본 배경색
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WOONGWINAPI1004);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	// 여기에 추가 정보가 있으면 추가 변수를 설정해줄 수도 있다.(예 : 제목, 구체적인 크기)

	
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
// 구체적으로 말하면 , 윈도우를 생성하는 함수 (위 함수도 참조하지만,)
// 이쪽이 더 직접적인 영향력을 끼치는 실질 함수
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)	// 반환형이 BOOL인 것 확인
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   // 윈도우의 모양 설정을 여기서 실질적으로 (혹은 최종적으로) 한다
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)	// 확인 : 만들어진 윈도우가 실제로 존재하는가? = 생성됐는가?
   {
      return FALSE;	// 안됐으면 실패로 반환 (그리고 WinMain에서 이 값을 받아 강종)
   }

   ShowWindow(hWnd, nCmdShow);	// 성공했으면 , 그 윈도우를 모니터에 띄우기
   UpdateWindow(hWnd);			// 업데이트 (뜻: 매시매초 윈도우 신호 받기) 시작
								//	정확히는 이 직후에는 업데이트 1회만 되지만
								// 이 업데이트 직후부터 본격 매시매초 신호받기가 시작


   return TRUE;		// 성공햇음을 반환하고 윈도우 생성 종료
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
// 
// 다른 말로 , 위에서 적은 "OS로부터 오는 각종 신호를 매시매초 처리한다"는 일을
//	이 함수에서 진행한다는 뜻
//
// 아래 있는 WM_로 시작하는 이름들 : OS가 앱에 주는 신호 명령의 종류
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다. (처음 시작할 때 , 혹은 코드가 직접)
//  WM_PAINT    - 주 창을 그립니다.(출력 신호가 왔을 떄 = 실질적인 '매시매초' 중 하나)
//				= WM_PAINT가 들어올떄마다 화면을 그려주면 일종의 잔상 효과로
//				 화면을 갱신하거나 심지어 움직이게 만들 수 있다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.	= 끝냅니다
//
//WINPROC : 윈도우 프로시저 , 윈도우 앱 진행 절차. 그게 이 함수의 이름
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// 들어온 메시지를 스위치 조건문으로 판독해서.... 
    switch (message)
    {
    case WM_COMMAND:
        {
			// 첫 실행, 혹은 코드에서 직접 지시했을 떄(메뉴라든가)

            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:	//대표적인 사례 : '종료 버튼 누를 때'
                DestroyWindow(hWnd);	// 앱 종료
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:	// 그리기 + 모니터에서의 화면 갱신
					// 사실상 되게 자주 반복되는 실질적인  '반복 신호' 중 하나
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
			// 다른 말로, 여기에 뭔가 적거나 .... 

			// ... 혹은 다른 클래스에서 화면을 그리는 기능을 준비한 후 여기서 부르면 
			//		화면이 바뀔 거라는 이야기!
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:		// 앱 종료 신호가 곧바로 들어온 경우
        PostQuitMessage(0);	// 역시 앱 종료
        break;
    default:
		// 미리 준비한 (판명한 ) 신호가 아니면 대기하면서 계속 해석(무슨 신호인지)
        return DefWindowProc(hWnd, message, wParam, lParam);
		//
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다. (= 메시지 판독 과정)
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
