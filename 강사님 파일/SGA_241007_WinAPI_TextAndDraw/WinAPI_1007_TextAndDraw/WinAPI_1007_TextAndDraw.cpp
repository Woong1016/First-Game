// WinAPI_1007_TextAndDraw.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

// 오늘의 과제 : winAPI로 그림 그려보기

// 글자, 자유 직선, 직사각형, 타원을 사용해서....

// 무엇이든 좋습니다. 여러분이 좋아하는 그림을 하나 그려보세요.

// * InvalidateRect 함수는 과제에서 빼셔도 됩니다.

// * (도전 과제) 예습과 자습을 해보실 분은 HDC 브러시에 대해서도 한번 알아봅시다.
//              게임 개발에는 필요가 없지만, 그림은 예쁘게 그릴 수 있습니다.



#include "framework.h"
#include "WinAPI_1007_TextAndDraw.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

float mouseX;   //마우스 커서 가로 위치
float mouseY;   //마우스 커서 세로 위치

// * 나중에는 이 둘을 묶어서 적절한 구조체를 만들 예정...이지만 시간상 기본 변수 2개



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
    LoadStringW(hInstance, IDC_WINAPI1007TEXTANDDRAW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    //전역변수 초기화
    mouseX = 0; // 나중에는 더 적절한 곳에서 초기화할 테지만 지금은 여기서...
    mouseY = 0;

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI1007TEXTANDDRAW));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI1007TEXTANDDRAW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINAPI1007TEXTANDDRAW);
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

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
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
    case WM_PAINT:  // 화면 표시 메시지. OS가 자동으로 호출 수행한다
        {
            // 그래서 여기에 코드를 적으면 자동으로 화면으로 처리된다

            PAINTSTRUCT ps;                  // 화면 정보를 담은 구조체
                                             // 기본 정보는 만들어질 때 결정
                                             // 있는 그대로 써도 괜찮다

            HDC hdc = BeginPaint(hWnd, &ps); // HDC : 출력 매체 관리 데이터
                                             // handler of 'Device Context'
                                             // 출력매체 혹은 "디바이스 컨텍스트"
                                             // = 다양한 출력 도구를 OS가 관리하기 위해
                                             // 하나의 통칭으로 편의상 지칭하는 것
                                             // 우리한테는 "모니터"쯤으로 이해하면 된다

            // 어쨌든, 이렇게 출력 도구에 대한 데이터를 미리 준비해서
            // "그릭 준비 (Begin Paint)" 절차를 시작한다 (이때 인수가 hWnd, &ps)
            // hWnd : 이 화면을 그려낼 영역 = 앱이 실행된 윈도우

            // 그리고 지금 이 줄부터 코드를 작성해서, 화면에 영향을 끼치면
            // 그 결과가 화면에 그림으로서 나타나게 된다 (혹은 문자나...)
            //-------------------------------------------------------------------

            // 맨 처음보다 더 먼저, 혹은 모든 작성이 끝난 후에....

            // "용도가 끝난 화면을 폐기하는" = 화면 갱신 코드

            InvalidateRect(hWnd, NULL, false);
            // InvalidateRect : 그리기 정보가 바뀔 경우 기존 화면을 폐기하는 함수
            // 매개변수 hWnd : 화면을 갱신할 윈도우
            // NULL : 화면을 갱신할 넓이 혹은 그 위치를 나타내는 사각형 정보
            //        지정이 없으면 전 윈도우 크기를 대상으로 한다
            // true / false : 기존 화면을 완전히 지울 것인지 말 것인지

            //---------------------------------------------------------------

            // 맨 처음 그려볼 것 : 'Hello world!'

            // std::cout <- 이 코드는 winAPI 환경에선 더 이상 안 쓴다
            // printf_s  <- 마찬가지로 안 쓴다

            // winAPI에서 문자 출력 수단 : TextOut...라는 함수

          // TextOut( hdc,                   // 어느 출력 위치에?
          //          200,                   // 가로 어디에? (x 좌표)
          //          100,                   // 세로 어디에? (y 좌표)
          //          L"Hello world!",       // 무슨 글자를?
          //          12                     // 몇 글자나?
          // );                              // ....출력할 것인가?

            //다른 글자도 가능
            //TextOut(hdc, 300, 250, L"안녕하세요!", 12);
            // 마지막 글자 수 인수가 문자 개수와 안 맞으면 빈 칸만큼 이상한 기호 출현
            // 또한 윈도우 문자 설정에 따라, 한글을 적어도 1글자로 취급되거나
            // 2바이트 이상 문자를 출력할 때 크기가 늘어나서 출력되거나 둘 중 하나
            // 이유 : 현재 API가 WChar라는 복합 문자 코드 데이터를 쓰고 있기 때문
            
            // 여기까지 글자 출력 방법

            //-----------------------------------------------------------------

            // 도형 그리기

            // winAPI에서 기본 도형 그리기는 크게 3가지 원형을 사용한다
            // (원형 이상 단계에서는 더 많은 기능이 있지만, 원형은 3가지)

            // 1. 자유 직선 그리기 (잘 안 씀. 자유로움)

            // 자유 직선은 두 함수의 조합으로 만든다

            // 첫 번째 : "그리기 초점 옮기기"

            // MoveToEx : '컴퓨터의 초점' 이동하기
            MoveToEx(hdc,600, 150, NULL);
            // 각각 출력위치, 가로 지정위치, 세로 지정위치, 추가 요청

            // 두 번째 : "직선 그리기"

            LineTo(hdc, 600, 600);  // 초점을 옮기면서, 궤적을 그리는 코드
            // 따라서.....
            // MoveToEx 함수로 컴퓨터가 먼저 500, 50 위치에 초점을 옮기고
            // (이 때는 아무 것도 안 그려짐)
            // 이어지는 LineTo 함수로 해당 선의 끝점이 정해진다

            // ----------------------------------------------------------

            // 2. 직사각형(과 정사각형) 그리기

            // winAPI에서 직사각형은 약간 까다롭다

            // 작성 방법

           //Rectangle(hdc,  // 출력 위치
           //          200,  // 왼쪽 변의 (기준으로부터의) 거리
           //          200,  // 위쪽 변의 거리
           //          500,  // 오른쪽 변
           //          500); // 아래쪽

            // 그런데 왜 직사각형인가?
            // 1. 윈도우에선 가로 세로끼리 길이가 같으면 빨라진다
            //    (그러므로 보통 직사각형 아니면 정사각형이면 생성이 빠른데)
            // 2. 직사각형은 정사각형을 포함하니까 명명을 직사각형이라고

            // 마찬가지로 winAPI에서는 동그라미도 "타원(ellipse)"

            // ------------------------------------------------------------

            //3. 타원

           // Ellipse(hdc, 500, 500, 250, 250);

            // * 비슷한 위치에 다른 글자나 도형이 다시 출력될 경우
            //   다른 말로 윗줄 코드에 의해 그려진 글자나 도형이
            //   아랫줄 코드에 의해 다시 덮어씌워질 경우,
            //   먼저 그려진 글자, 도형은 가려져서 보이지 않게 된다

            // -----------------------------------------------------------

            // (도전과제) 휴일 중에 시간 남는 분들은 개인 자습
            // : "브러시"에 대해서 (선 굵기, 색 칠하기 등)

            // -----------------------------------------------------------

            // 이렇게 윈도우에 도형을 그릴 수가 있다면
            // 이걸 윈도우 실행 중 상황 변화에 맞추어서 다르게 바꿀 수도 있을까?

            // -> 윈도우는 그림, 실시간 등으로 사용이 표현되니까

            // 답은 '가능하다'이다

            // -> 윈도우에서 실행 중 마우스 커서 위치에 그림 다시 그리기

            // * 준비물 : 전역변수 (소수) 2개, 이 전역변수에 마우스 위치 담기
            //   -> 전역변수 자리에 만든 후, 값을 할당하고 돌아온다

            // 위에서 만든 mouseX, mouseY를 사용해서 도형이 그려질 위치 지정
           //Rectangle(hdc,
           //    mouseX - 100,
           //    mouseY - 100,
           //    mouseX + 100,
           //    mouseY + 100);
            // 커서 기준으로 사방으로 위치를 재조정한 사각형 그리기

            // 이후 (아무 준비 없이) 실행하면 0, 0 위치에 사각형이 그려진다
            // -> 전역변수는 실제로 잘 동작했다
            // -> 그리고 0, 0 위치는 왼쪽 위다 (원점)
            // -> 그런데 사각형은 마우스 커서를 따라가지 않는다!!

            // 이상의 사실을 확인할 수 있다

            // 이유 : 그려진 화면에 대한 지시가 코드에 없었기 때문 (정보 폐기만 있음)

            // 따라서, 화면에서 정보가 바뀜에 대한 화면 갱신 코드를 추가해줘야 한다

            // 그 함수가 InvalidateRect() <- 여기 말고, WM_PAINT 위에 작성

            //-------------------------------------------------------------------
            // 그리기가 다 끝난 후, End Paint 절차를 통해서 화면 그리기 작업에 동원한
            // 데이터의 메모리 점유를 해제해준다 (안 하면 작업 수행 시마다 메모리 점유↑)
            // 다시 그리기가 시작되어야 하면 위에 있는 Begin Paint부터 재시작...!
            EndPaint(hWnd, &ps);
        }
        break;

    case WM_MOUSEMOVE:  // OS에서 감지한 메시지 내용이 마우스 이동에 대한 것일 때

        // 메시지에서 같이 들어온 매개변수 두 개가 마우스 가로, 세로 위치
        // -> 그 데이터를 준비해둔 전역변수에 넣으면 된다

        mouseX = (float)LOWORD(lParam);
        mouseY = (float)HIWORD(lParam);

        // lParam : 마우스 정보가 들어가 있는 큰 매개변수 단위. 긴 패러미터.
        // LOWORD : 긴 패러미터 중에서 먼저 들어온 정보
        // HIWORD :           "       뒤에 들어온 정보
        // * 두 정보 값이 더블(배정밀도)이므로 형변환을 직접 해서 오차 감소 의도

        break;

    case WM_DESTROY:
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
