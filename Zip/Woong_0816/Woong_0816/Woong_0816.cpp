﻿

#include <iostream>

int main()
{
   
	// 지난 시간까지 포인터를 알아보았다

	// 그리고 포인터가 메모리 그 자체에 접근을 하는 수단임을 알았다.

	// 여기서 느낄 수 있는 포인터의 의미란?? :통제 , 관리 , 권한 ,사람의 자유


	// 이렇게 대단한 포인터 의 연산자 가  왜 다음언어들에서 안보일까?
	// 심지어 포인터의 개념은 지금도 쓰고 있는데?

	//예 : C# 언어에서 변수의 이름은 그 자체가 포인터를 겸한다

	//1. 편하려고 (너무 당연한 이유)
	//2. 자유의 대가가 너무 커서

	// 포인터가 어려워서도 문제지만, 한번 익숙해지면 너무 편해져서 문제이기도 하다

	// 많은 C, C++ 개발자들은 포인터를 너무 많이 써서 망하기도한다. ㄹㅇ?

	// 그 때문에 이 후 언어에서는 연산자를 생략해서 포인터의 용법을 일부 제한했고

	// .. 그와 동시에 c에서는 한가지 대응 수단을 더 만들었다.

	// 권환 회수 , 제한 , 억제 ... 오늘은 바로 이 "억제"에 대해서 알아보자


	// ===========================================================


	// 오늘의 대상 : (정)"상수" (constant value)

	// 변수가 '이름을 받고 , 그 이름으로 부여된 메모리 위치 내에서 수정 가능한 자료'

	//.. 라면 ' 이름을 받고 , 그 이름으로 부여된 메모리 위치 내에서 수정 가능한 자료 라면

	// 상수는 주어진 순간ㅂ터 수정이 불가능한 자료 (혹은 수정하는 의미가 없는 자료)
	// 를 뜻한다.

	// 상수의 작성 방법 (가장 흔한 방법)

	int a = 0; // 이건 변수

	const int  con = 100; // 자료형 앞에 const 추가 : 이것이 상수


	// 상수의 사용 방법(역시 가장 흔한 방법)

	std::cout << con << std::endl; // 출력 가능


	int b = 3;

	std::cout << con + b << std::endl; // 연산 가능 (연산에 호출 가능)
	std::cout << con - b << std::endl;
	
	a = con + b; // 연산 결과를 다른 곳에 저장도 가능


	//con = a + b; // 이건 불가능 // 연산을 어떻게 하든 결과를 자기가 수정해서 할당하는 것 불가

	//con = 10000; // 단순 수정도 불가능

	// 요약하면 만들어지고 나면 쓸 수는 있다. 하지만 바뀔 수는 없다.

	// 이것이 상수


	// 상수의 억제 능력을 보여주는 다른 예 

	//const float fcon; // 소수 상수 선언 (const + float도 가능 )

	//fcon = 1000; // 이 줄도 오류 , 윗줄도 오류


	// 한번 만들면 다시는 못 바꾸므로 , " 값이 없는 상태에서의 선언 " 조차 불가능

	// 따라서 상수는 선언 불가능 => 만들거면 값까지 다 포함한 초기화 생성만 가능


	// 이렇게 상수를 선언을 해주면 변수, 특히 포인터를 (일반도 사실 마찬가지)
	// 사람이 잘못 수정해서 오류를 일으키는 경우를 막아줄 수 있다.

	// 다른말로 상수는 필요에 따라 사람이 스스로에게 부여한 "구속"이다

	// ==========================================


	// 그러면 상수를 실제로 활용하는 경우가 있는가?

	// 게임에서의 활용 예시 : 1. 온라인 게임의 플레이어 id 

	// 2. 격투 (혹은 moba) 게임에서 특정 버전의 등장 인물 수

	// 3. 최대 인벤토리 칸 , 배열의 (혹은 지도의 ) 한계 크기


	// 이렇게 실제로도 이후에 개발자, 혹은 외부의 해커가 핵 사용자가 함부로 바꾸면 안되는 

	// 이런 자료들이 있다면개발자는 const 를 변수 작성 앞에 붙여서

	// 데이터를 지켜줄 수 있다.


	//----------------------------------------------------------------------------------


	// const의 실용 응용 : char 의 포인터와 같이 썼을 떄

	char c = 'a'; // 문자 변수
	char* cPtr = &c; // 문자 포인터

				// 그런데 포인터 = 배열


	// 문자 포인터는 , 그러니까 "문자의 나열"


	//문자의 나열을 적절하게 구성하면 ? 문장과 단어

	// 그런데 "그냥" 배열을 포인터로만 선언하면 ? 배열의 크기를 모른다

	// 문장의 길이도, 글자수도 확실치 않아서 아무렇게나 출력하다가 오류를 낸다

	// 그게 바로 우리가 char* 를 쓰거나 출력했을 때 봤던 오류 메시지의 정체

	// 이 오류를 막고 , 배열의 크기를 고정하느데 const가 도움이 된다.

	// 만들어지는 순간에 포인터의 내용이 무엇인지 완전 고정을 시켜줘서 
	// 배열의 크기 (어디까지 출력하고 어디까지 사용할지 ) 지정도 해준다.

	// 예

	const char* Ccon = "오늘 저녁은 제육이다."; // 문자에 포인터와 상수를 같이 써주면
	// 제육 최고

	std::cout << Ccon << std::endl;

	// 이렇게 만들면 c++에서 문자의 나열 , 즉 문장과 단어를 표현할 수 있다.

	// 단 지금 단계에서는 아직 수정은불가 (const니까)

	//-------------------------------------------------------

	// 포인터에서 파생하는 "배열을 통한 문자열"

	//const의 역할이 "크기의 고정" 이라는 점을 이용했을 때...
	// 그럼 처음부터 배열의 크기를 정확히 지정하면 , 그 안에서도 
	// 문자를 문장으로 늘릴 수 있었는가?


	// 확인

	//char word[8] = "computer"; // <- 오류 남
	char word2[9] = "computer"; // 오류 안남
	//word[9] = "computers"; // 이따구로 하면 안됨
	//출력
	//std::cout << word << std::endl;//변수 작성 시점에서 이미 문제
	std::cout << word2 << std::endl;// 문제없음


	// 1. 배열의 크기를 정확히 지정하면 확실히 문자를 늘릴 수 잇다.

	// 2. 그런데 글자 수만큼 배열 크기를 주면 오류가 난다!(중요)
	// 이유 : 배열의 크기를 지정하는데에 " 배열의 포인터로서의 기능" 이 쓰여서

	// (그냥 숫자만 갖추면 되는 숫자 배열과 달리 , 문자열은 마지막에 )
	// "여기가 끝이다" 는 의미를 갖는 특수 문자를 추가로 배정한다.


	// 문자를 배열로 쓸 떄는 내가 쓰려는 글자 수보다 +1만큼 늘려서 만들 것

	//3. 여기서 다시 또 알 수 있는 것

	//word2 = "computers"; // 이거 안되네?

	// 그리고 보면 아까 "배열의 크기가 고정됨으로써" 문자 출력 오류가 안난다고...


	// 다시 말해서 여기서 " 배열의 이름" 이 갖는 또 다른 의미를 알 수 있다.

	//배열의 이름은 = const의 역할을 어느정도 겸한다. (상수다.)






	// (짜투리 상식) 상수에도 종류가 있다.

	// 위에서 우리가 살펴본 상수는 " 기호에 의한 상수" 라고 한다

	// (symbolic constants)

	// -> 원래는 상수가 아니었을 수도 있는데 (int a = 0 )

	//  선언 기호에 의해 (const int a = 0 ) 상수로 쓰이게 됐단 뜻



	// 다른 상수는 " 말 그대로  상수" 라고 한다. 이름이 이따구지만 이게 맞다

	// 원문은 literal constants  역시 발음을 그대로 써서 리터럴 상수라고도 한다.

	//

	6; // 여기서 6은 데이터 하지만 자료형 없음, 이름 없음 =변수 아님

		// 왜 오류가 안ㄴ나나? 컴퓨터가 알아보니까

		// 컴퓨터가 본 이 1이라는 숫자는 해석이 더 필요없는 그냥 우리가 아는 그 1
		// 이게 바로 "말 그대로의 상수"


	// 굳이 이름을 더 붙이지 않아도 다 아는 현실의 데이터 그 자체가 리터럴  상수의 정체

	2; // 마찬가지

	true; // 마찬가지

	'a'; // 역시 마찬가지

	//애초에 문제가 없었기 때문에 위 '상수'들을 std::cout 으로 출력이 가능했다.

	// 그리고 이게 "상수"로 구분되는 이유도 명백하다.

	//6 = 2; // 이게 말이 안되는 것과 같다. 

	// 따라서 우리가 보통 상수라고 언급하면 대부분은 기호로 된 상수(심볼릭)를 지칭
	
	//화이팅하세유 

	// 커피라도 사오시지//...


	// ---------------------------------------------














}	
