// Woong_0724_1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	// 참조만 하는 파일

	 // 이전지시문

	int number = 1;
	int count = 1;

start: // "이정표" 가야되는곳

	number = number * 2;
	count++;// 횟수를 1 올린다 (증감 연산자 사용
	//* 연산자는 과제 복습을 봐주세요

	std::cout << number << std::endl;

	// 현재 count 가 몇인지 확인하고 , 숫자에 따라 다른 곳으로 컴퓨터의 
	// 수행 지점을 옮긴다

	if (count < 10)goto start;//if 응용 작성법:
	else goto end;// if 뒤에 수행할 코드가 한줄밖에 없을 때는 {} 생략 가능

	//위 조건문의 뜻 : count가 5 가 아직 못됐으면 start 대목으로 다시보낸다
	// 아니면 end 가 있는 곳으로 보낸다
	// 그러면 start 갔을 때는 다시 거기서부터 차례로 코드를 수행하므로
	// 결과적으로는 같은 코드를 또 수행하는 결과
	//


end:; // 가야 되는 곳 2
}