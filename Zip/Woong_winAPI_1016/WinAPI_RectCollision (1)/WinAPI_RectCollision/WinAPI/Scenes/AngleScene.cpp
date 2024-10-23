   #include "Framework.h"
#include "AngleScene.h"

AngleScene::AngleScene()
{
	Vector2 start = { CENTER_X,CENTER_Y };


	line = new Line(start, mousePos); // 화면 중간에서 마우스 커서까지 가는 선
}

AngleScene::~AngleScene()
{
}

void AngleScene::Update()
{

	// 마우스 커서 위치가 바뀌니까 계속 선의 끝이 바뀌게

	// 마우스 커서 위치를 따라가되 길이가 계속 일정하게

	// 1. 마우스 커서의 가로세로 정보가 + 중심에서 떨어진 거리 (전체 좌표)가 필요

	float x = mousePos.x = line->pos.x;
	float y = mousePos.y = line->pos.y;

	//가로 세로 정보를 이용해서 각도를 구한다.

	// 사용되는 식 : 탄젠트의 역방향 (탄젠트= 각도와 가로 세로 중 하나가 있을 때의 계산)]

	//angle = atan(-y / x); // atan = a(역)+ 탄젠트를 수행하는 함수
							// 왜 -y인가?: 윈도우는 y가 커지면 밑으로 가니까(본래 수학 좌표에선 위로)



	angle = atan2(-y, x); // x가 0인 경우를 대비하기 위한안전 함수

	// 각도를 통해서 , 다시 새로 그려야 할 선의 종점 좌표를 구한다.
	// 방법: 각도와 정해진 길이 (선의 길이= 삼각형의 빗변) 모드를 써서
		// 각각 새로운 x, 새로운 y를 구하는 것

	//float newX = cos(angle); // 각도에 의한 가로의 비율을 알게 되고
	float newX = cos(angle) * length; // 비율에 선의 길이를 곱해서 비로소 최종 좌표 얻기
	float newY = cos(angle) * length;

	
}

void AngleScene::Render(HDC hdc)
{
}
