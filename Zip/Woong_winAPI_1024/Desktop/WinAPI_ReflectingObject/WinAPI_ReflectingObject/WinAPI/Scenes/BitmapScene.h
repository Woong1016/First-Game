#pragma once
class BitmapScene : public Scene

{


	// 비트맵 씬 : 그림 출력용 클래스

public:
	BitmapScene();
	~BitmapScene();

	virtual void Update()override;
	virtual void Render(HDC hdc) override;




private:

	HBITMAP dogBitmap;	// HBITMAP : 비트맵 핸들러 = 이벤트 , 출력기능 등이 들어가 있다.
	HBITMAP catBitmap;	// 그림 정보도 같이 들어가 있다. 
	HBITMAP SkBitmap;

	//버퍼링에 대응해서 추가로 그림을 준비해둘 가상 출력도구가 하나 더 필요

	HDC memDC;	// 모니터 뒤에서 그림을 준비할 가짜 모니터 (메모리 내 관리소)

};

