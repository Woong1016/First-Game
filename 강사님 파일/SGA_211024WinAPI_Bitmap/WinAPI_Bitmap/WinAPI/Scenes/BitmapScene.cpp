#include "Framework.h"
#include "BitmapScene.h"

BitmapScene::BitmapScene()
{
    // 그림 그리기 순서

    // 0. 모니터가 아닌, 메모리 다른 곳에서 미리 그림을 준비할 장소 만들기
    //    = memory DC를 만들기

    // 그러기 위한 진짜 모니터 정보 따내기
    HDC hdc = GetDC(hWnd); // hWnd = 이 앱, 이 창
                           // GetDC = 매개변수로 받은 창에서 모니터 정보를 따내는 함수

    // 따낸 모니터 정보와 일치하는 메모리 속 가상 출력 도구 만들기
    memDC = CreateCompatibleDC(hdc); // CreateCompatibleDC : 지정된 정보와 호환되는
                                     // 복사된 메모리 영역 생성 함수

    // 따냈던 모니터 정보를 메모리에서 지우기 (성능 아끼기)
    ReleaseDC(hWnd, hdc); // "이 앱에서 방금 만든 정보를 그냥 안 쓰겠습니다"

    // -> 여기까지 오면 남는 건, 원래 모니터 정보를 복사한 memDC만 남는다

    // -----------------------------------------------------------------------

    // 1. 그림을 파일에서 읽어서 만든다

    dogBitmap = (HBITMAP)LoadImage(  // LoadImage : 파일에서 이미지 정보를 읽는 함수
        hInst,              // 현재 실행 중인 인스턴스 = 이 앱
        L"Textures/Dog.bmp",// 읽어들일 파일 이름 (경로명이 일치해야, 폴더명은 /로 구분)
        IMAGE_BITMAP,       // 이 파일이 어떤 이미지 파일인지 지정 (지금 경우는 "비트맵")
        0,                  // 읽기를 시작할 도트 좌표 X
        0,                  // 읽기를 시작할 도트 좌표 Y
        LR_LOADFROMFILE     // 파일을 저장소에서 직접 읽는 방식으로 지정
    ); // 그림 읽는 방식은 윈도우에서는 대체로 거의 공식화
    // LoadImage 함수는 이미지 포맷에 다양하게 대응 가능
    // -> 장점은 : 그림이면 다 읽어준다,
    //    단점은 : 읽은 다음에 어떤 포맷인지 사람이 지정을 해줘야 한다
    // 따라서, 다 읽고 형변환을 또 해줘야 한다

    // ----------------------------------------------------

    // 2. 다른 그림도 있으면 읽는다

    catBitmap = (HBITMAP)LoadImage(hInst, L"Textures/Cat.bmp", // 각자 자기 파일 이름에 주목
        IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

    // 3. 그림 사용은 출력은 렌더, 추가 연산이 필요하면 업데이트에서 진행하면 된다

    // ------------------------------------------------

    humanBitmap = (HBITMAP)LoadImage(hInst, L"Textures/Attack_1.bmp",
        IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

BitmapScene::~BitmapScene()
{
    // HBITMAP, HDC의 특성 : 윈도우에서 만들어줬고, 핸들링(이벤트 등록, 수행 대기) 기능이 포함
    //                       -> 포인터를 이 안에 포함했다는 이야기

    // 만들면 지워야 하는 대상이란 뜻 + 윈도우가 미리 만들어준 간편 함수가 같이 제공된단 뜻

    // 따라서, 윈도우 함수를 이용해서, 만들어둔 핸들러를 삭제
    DeleteDC(memDC);    // 출력 도구를 지우는 함수
    DeleteObject(dogBitmap);    // 출력 수단(기능)을 지우는 함수 (비트맵 핸들러 = 출력수단)
    DeleteObject(catBitmap);

}

void BitmapScene::Update()
{
}

void BitmapScene::Render(HDC hdc)
{

    // 그림 출력하기

    // 1. 윈도우가 그릴 장소와 수단을 선택하도록 지시하는 것부터
    //    -> MoveToEx 써서 좌표 지정하는 것과 비슷한 감각
    //      (HBrush, HPen 등을 써본 사람은 역시 비슷한 감각)

    SelectObject(memDC, dogBitmap); // SelectObject : 출력 장소, 수단 선택 함수
                                    // memDC : 그리려는 장소 (지금은 메모리 DC)
                                    // digBitmap : 그리려는 수단(혹은 대상, 지금은 개)

    // 2. 선택한 장소와 수단에 의한 결과를 모니터에 출력하면 된다

    BitBlt( // bitblt : 비트맵 블릿, 픽셀 그림 정보를 컴퓨터에 전해서 출력하는 함수
        hdc,        // 출력할 장소 (지금은 모니터)
        200,          // 출력을 시작할 좌표 x
        200,          // 출력을 시작할 좌표 y
        WIN_WIDTH,  // 출력을 끝낼 좌표 x (가능하면 여기까지 그리고, 모자라면 그림을 자른다)
        WIN_HEIGHT, // 출력을 끝낼 좌표 y
        memDC,      // 참조할 원본 장소 (아까 만들어서 개 그림을 만든, 메모리 DC)
        0,          // 참조를 시작할 좌표 x
        0,          // 참조를 시작할 좌표 y
        SRCCOPY     // SRCCOPY : "원본 이미지 정보 그대로 출력"
    );
    // 위 함수를 포함해서, blt 계열 함수에 좌표를 다르게 넣으면 그에 따라 출력 결과를
    // 조정할 수 있다.

    // BitBlt는 기본적인 출력에 쓰이고, 빠르다는 장점이 있는 반면
    // 복잡한 옵션 부여가 힘들다... 그러므로 다른 기능을 한번 더 알아보자

    // * 다른 그림을 그려보고 싶을 때는 윈도우에서 SelectObject 함수를 다시 수행시킨 다음
    //   다른 DC (있다면) 혹은 다른 그림, 다른 브러시 등을 선택해주면 된다

    SelectObject(memDC, catBitmap); // 메모리 DC에, 고양이 그림을 대기시킨다

    // 준비한 고양이 그림을 다른 옵션으로 출력

    StretchBlt( // 그림을 늘려서 (혹은 줄여서) 출력하는 블릿
        hdc,
        CENTER_X,   // 출력 위치 x
        0,          // 출력 위치 y
        -WIN_WIDTH / 2,  // 출력 종료...가 아닌, 출력 이미지 전체 크기 x
        WIN_HEIGHT / 2, // 출력 이미지 크기 y. 이 숫자가 바뀌면 이미지 크기가 달라진다
        memDC,
        0,            // 참조 원점 x. 여기가 달라지면 그림의 시작점이 달라진다
        220,          // 참조 원점 y
        WIN_WIDTH / 2,  // 참조의 크기 x. 위쪽 참조 원점을 기준으로 어디까지 참조할 것인가
        WIN_HEIGHT / 2, // 참조의 크기 y. 여기가 달라지면 그림이 잘린다
        SRCCOPY
    );
    // * 비트맵 크기를 줄이려면 줄일 수도 있다. 단 stretchBlt는 색깔 보정을 못 해서
    //   크기를 줄이면 화소가 깨지기도 한다.
    // * 크기가 직접 지정이 가능하면.... x나 y에 -가 들어가는 경우? 그림이 뒤집힌다


    SelectObject(memDC, humanBitmap);

    // 늘리기 (+자르기) 블릿으로 출력 (고양이 출력 복붙)
    // StretchBlt(
    //     hdc,
    //     CENTER_X, CENTER_Y,       
    //     WIN_WIDTH / 2, WIN_HEIGHT / 2,
    //     memDC,
    //     0, 0,
    //     WIN_WIDTH / 2, WIN_HEIGHT / 2,
    //     SRCCOPY
    // );

    // 늘리기 (+자르기) 블릿으로 출력 (좌표, 크기 직접 지정)
    // * 현재 로딩된 인간 그림 크기는 768 x 128
    //   128 x 128 크기가 1단위라고 치면 가로로 6개, 세로로 1개 작은 그림이 있는 것
    StretchBlt(
        hdc,
        CENTER_X, CENTER_Y,
        256, 256, // 그림을 참조해서 크기를 지정
        memDC,
        256, 0, // 어디서부터 참조할 것인가 -> 이어진 그림의 몇 번째를 출력할 것인가?
        128, 128, // 그림을 참조해서 크기를 지정
        SRCCOPY
    );
}
