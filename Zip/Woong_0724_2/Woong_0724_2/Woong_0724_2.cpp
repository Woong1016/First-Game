﻿// Woong_0724_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// 실습 밎 과제

// 를 위해서 필요한 추가 기능 소개

#include <stdlib.h>// c++의 기본 기능 집합 " 표준 명령어 참조 구분" 이라고 한다
					// 명령어 집합을 " 라이브러리"  standard livrary 라고 한다.

#include <Windows.h>

// 실습 및 과제 본문 : 업앤다운 게임


// 1. 앱 사용자가 입력할 수 있는 숫자 하나를 변수로 만들어주세요 /클리어
//2. 랜덤으로 (위아래 소개 참조) 1부터 99까지의 숫자중 하나를 만들어주세요 /클리어
//3. 앱이 시작되면 사용자가 숫자를 입력했을때 랜덤 숫자와 비교되게 해주세요 / 클리어 
// 3-1 틀렸을 경우 , 사용자의 입력이 랜덤 숫자보다 큰지 작은지 출력해주세요 
// 4. 맞추면 앱이 끝납니다. 못맞추면 입력을 다시 받고 비교해주세요. / 클리어
// 5. 정답을 맞출때까지 계속되거나 맞추면 끝나는 반복문을 만들어주세요/ 클리어 
//6. 선택과제: 횟수 제한을 만들어주세요 n회 이내에 못맞추면 게임 오버입니다. / 클리어 
// 7. 정답을 맞출 수 있는 경우 , 정답을 반드시 맞출 수 있는 필승의 비법을 소개해주세요
// 그리고 비법이 있는 경우 해당 비법의 성공 조건도 확인해주세요

// 예를 들면 ~~~ 하면 무조건 찾는다!. ~~~ 하려면 n 번 실패를 해야된다.
int main()
{

	// 과제 참조용 기능소개
	// 
	srand(GetTickCount64()); // 정식 명칭 : 랜덤 시드 생성
								// 뜻은 랜덤 숫자를 만들기 위한 기준자료 만들기
								// 
	int randomNumber = rand();	// 약 -33000부터 33000까지 숫자를 랜덤 절대값으로
								// 정하는 기능
								// 
								// 결과적으로 약 0~33000까지 숫자가 마음대로 나온다.
								// rnad 뒤에 괄호 필수

	int twodigits = rand() % 100; //  100으로 나눈 나머지 = 100 미만의 숫자들


	//int n = rand () % x라고 하면 , n은 0부터 x-1 까지의 숫자 중에서 아무거나 정해진다
	// // 단 srnad가 먼저 실행되어야함
	// 
	// 위에서 만든 두자리 숫자 확인 출력
	std::cout << twodigits << std::endl;

	// d





	// 본문 시작

// 반복문 
	// 조건문을 활용해서 한 조건이 맞는동안 (참인동안)
	// 작은 {}로 제시한 영역 내의 코드를 계속해서 순환 수행하는 코드

	// 기본 작성 형태

	int sample = 0;

	for (int i = 0; i < 10; i++)// 반복의 규칙 
	{
		sample = sample + 1; // 샘플을 1 올리고
		std::cout << sample << std::endl;// 출력

	}
	// 반복문의 첫 번째 형태  'for 문' 

	// for 문 : 제시한 조건식에 의해 정해진 횟수 동안 반복하는 반복문

	// for 문의 구성과 (+ " 제시한 조건식이라는 건 뭔가?")
	// for : 명령어 (if ,else 등과 같은 종류 )
	//(괄호 직후에 나오는 첫 번째 식 (위 예시의 경우, 'int i = 0')
	//-> for 문이 처음 시작할 때 설정되는 상황 (조건식의 시작)
	// -> "지금부터 i라는 이름의 숫자가 0이라고 칩시다."

	//  두 번째 식 ('i < 10)
	// for 문이 돌기 위한 조건 (조건식의 제시 , 반복의 조건)
	// "지금 설정한 i가 10 보다 작은 한, 다음의 {}를  계속 반복해주세요


	// 세번째 식(i++
	// {} 코드가 한번 수행될 때마다 자동으로 같이 계산해줘야 하는 코드
	// 다른말로 "변화"
	// {} 안의 코드가 끝날때마다 i를 1씩 올려주세요

	// 위의 반복문의 해석
	//i라는 새로운 숫자가 하나 더 있다고 치고 , 0이라고 정합시다
	// sample을 1 올려서 출력하고 나면 , i도 1 올립시다.
	//i가 10 보다 작으면 했던대로 한번 더 하고 , 10 이 되면 그만합시다.

	// =-------------------------------------------------

	//for 문의 도식화

	// for (시작 상황; 반복을 위한 조건 ; 변화)
	//{
		//수행코드
	//}


	// ======================================================

	// for 문의 다른 예시 하나 더

	for (int i = 0; i < 10; i++)
	{
		//int i = 0 ; for 문에서 가장 자주 사용할 시작 상황
		// i <- 그냥 그렇게 붙인 숫자 이름의 유래는 iterator(순찰자, "반복하는 사람", 프로그래밍에서는 '반복자')
		//

		//그리고 이 int i 의 다른 특징은 ... 이것도 변수라는 것
		// -> 그말은, 호출할 수가 있다는 뜻.

		std::cout << i << std::endl;
		// 그리고 이 i의 특성을 응용한 계산도 가능
		int n = 4;
		int result = i * n;

		std::cout << i << "X"<<n << "=" << result<< std::endl;
		//cout 뒤에 << 를 반복하면 계속 다른 숫자나 글자 출력가능


		// 여기서 n의 숫자를 바꿔주면 구구단의 n단 출력가능!
	}

	// 이렇게 조건을 제시해서,조건이 맞는동안 반복하는 것이 for 문
	//-> 이런 반복문은 언제 사용하는가?
	//===========================================================

	//for문과 같이 사용하는 또 다른 하나의 반복문

	//while 문

	int order = 0;
	int hour = 0;
	while (order < 12)
	{
		std::cout << "지금은 ..." << hour << "시입니다." << std::endl;
		//hour 1 올리기
		hour++;
		// order 1 올리기
		order++;
	}

	// 위 반복문의 구성요소

	// While : 명령어

	// () 안의 조건 : while 문이 반복되기 위한 조건.

	//				이 조건이 참이면 다음의 {} 는 계속 반복된다.

	// {}: 수행할 코드


	//while (조건)
	//{
	// 수행할 코드
	// 
	// }
	//
	//=================================================================

	//두가지 반복문이 있는데, 각각 장단점이 있어서 둘다 자주 쓰인다.

	//for문 : 다소 구성이 복잡 . 글자도 많다.
	//		한번 조건을 정하면 최대 횟수를 바꿀 수 없다.
	//		그대신 몇번을 반복할지 예상이 정확히 가능하다. (알기 쉽다.)
	//		통제도 쉽고, 조건을 잘정하면 오류의 위험도 적다

	// while 문 : 외우기 쉽다, 생긴게 간단하다
	//				특수한 조건을 더 달지 않으면 * 무한히 돌릴 수 있다.
	//				그 때문에 언제 반복문이 멈춰야 하는지를 코드로 정확히 정해야 하고
	//				그걸 {} 안에서 다 처리해줘야 한다. (결과적으로 헷갈리기도 쉽다)
	//				특히 무한히 도는 while 문을 통제하지 못하면 오류의 원흉이 되기도 한다.
	//

	// -> 위 while 문 사례에서 사용한 order++의 존재이유가 무한 루프를 멈추기 위함
	// -> order 를 언젠가 12보다 크게 해서 order <12라는 조건을 깨도록 하기 위해

	//while 문 한번 더 써보기 
	int row = 0;// 행

	while (row <10)
	{

		for (int colum = 0; colum < 10; colum++)
		{
			std::cout << "*";
		}
		//std::cout << std::endl;	// 줄바꾸기
		std::cout << "\n";
		// \ 뒤에 붙는 글자 :특수 문자 따라오는 글자에 따라 특수한 표시를 한다.
		// \n 의 경우 의미는 개행(endl과) 같다 \t 의 경우 의미는 글의 폭맞춤(탭키)
		row++;
	}
	//이렇게 코드를 쓰면 사각형 출력가능


	//===================================================


	// 반복문의 통제(추가 조건을 제시하는 방법)

	// 반복문이 수행되는 중에 특수한 이유가 있을 경우(= 조건문 쓴다)
	// 원래 작성된 것과 다르게 동작하도록 만드는 것

	// 1. 반복문의 중단

	//while 구구단

	int o = 5;
	bool go = true; // 그냥 갑니다.

	int toNine = 1; // 1부터 9까지 곱할 숫자

	while (go == true) // <- 어지간하면 그냥 무한반복하라는 지시
						 
	{
		//go == true 를 줄여서 그냥 true 라고만 하기도 한다
		// 그러면 ... 이대로는 반복문이 끝날 수가 없다.

		int result = o * toNine; // n단 곱하기 1~9까지

		std::cout << result << std::endl;

		toNine++;// 곱할 숫자 1 올리기

		// 반복문 수행조건이 go 이기 때문에 이대로는 다른 숫자를 올려도
		// go의 값은 바뀌지 않는다 (따로 작성하지 않는한)
		// 따라서 무한루프의 위험성이 있다.

		// 이때 그래도 바뀌는 toNine 변수의 값을 보고
		// 이 숫자가 10에 다다르면 while 문을 강제 종료하기로 한다

		if (toNine > 9)// 조건 확인 후
		{
			break; // break : 지금 수행중인 {} 안의 코드를 당장 중단하라는 지시
					// 만약 if 문 안이면 바로 바깥의 {}까지 포함한다.
					// (if 문은 break를 할지 안할지 판단하는 것 뿐입니다.)

			// toNine 이 10에 다다르면 if 는 물론 이 밖의 while 문까지 모두 중단
			// 하고 그 다음으로 진행된다.
		}

		// 확인용 출력 1
		std::cout << "구구단 계속 진행합니다" << std::endl;

	}

	// 여기가 break; 실행후에 컴퓨터가 작업을 수행할 위치
	// 이 다음부터 다시 실행
	// 
	// 
	//출력 2
	std::cout << "구구단 끝났습니다." << std::endl;

	// -> 이렇게 break 를 사용하면 코드 수행을 중단할 수 있다.
	// 반복문만이 아니라 다른 상황에서도 다 쓸 수 있다. (조건문이든, 다른 어디든)
	// 그래서 switch에서도 break 를 쓸 수 있었던 것
	

	// ====================================================================

	//2. 반복문의 초기화(쉽게 풀어서 이해하면 무시 후 다시 한번 속행)

	// 사용 예시

	for (int i = 0; i < 30; i++)
	{
		// 숫자를 그냥 출력하기 전에 한가지 조건울 확인
		// 해당 조건에 해당하면 "속행"을 하기로 한다

		int a = i % 10; // 10으로 나눈 나머지 == 1의 자리 숫자
		int b = a % 3; // a를 3으로 나눈 나머지 . 이게 0이면 i는 1의 자리가 3,6,9

		if(a != 0  && b== 0)
		{
			std::cout << "짝 " << std::endl;
			continue; // 속행을 지시하는 명령어
						// 정확한 뜻은 " 지금 코드는 그냥 무시하고 다시 처음부터"
						// 단 , for 문 규칙에 있는 i++ 코드는 {} 코드가 아니어서 제외
						// == continue 가 있어도 i는 올라간다.
		}

		//continue 가 실행되면 아래 코드는 실행되지 않고 
		// 위 if 문이 참이 아니면 아래 코드가 실행
			

		//i 숫자 출력
		std::cout << i << std::endl;

		// 이 방법으로 369 제작 가능

		
	}

}
