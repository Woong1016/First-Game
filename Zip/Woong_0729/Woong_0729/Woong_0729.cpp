﻿
#include <iostream>



//과제


// 2차원 배열을 좌표로 사용하는 방법

//1. 오늘 진행한 코드의 아래쪽 '1단계' 까지 이해할 수 있도록합시다.

// (옵션)system 이라고 적혔던 코드도 확인해봅시다.(cls, pause, 2줄 확인하자)

//2. 아래 '2단계'를 직접 코드로 만들어봅시다.

//2단계 : 2-1 : 코드 확인을 통해서 '위, 아래, 왼쪽, 오른쪽 으로 삼기에 
//		좋은 코드가 있는지 살펴봅시다(대표 예 : w,a,s,d)

//2-2 : 해당 코드의 문자 코드를 _getch로 확인합시다.
//2-3 : 위, 아래 , 왼쪽, 오른쪽 으로 의미를 부여한 키를 누르면
// 그에따라 x,y 변수의 값이 달라지도록 합시다.

// 2단계 목표: "위, 아래, 왼쪽 , 오른쪽으로 내가 의미를 부여한 키를 누르면 
//				배열 two 안에서 별표가 움직이도록 해봅시다.

//3단계 (옵션): 아래 3단계도 도전해봅시다

//3-1 :키보드의 글자 수는 소문자, 대문자, 특수문자 등을 합쳤을때
// 256자를 넘어갑니다. 참고로 이는... c에서 다루는 숫자의 최소 취급단위를 넘어갑니다.
// 따라서 특정한 키를 누르면 입력이 제대로 되지 않거나
// 다른 키를 눌렀는데 같은 결과가 나올 수도 있습니다.
//(이유 : 컴퓨터의 구조가 8개의 신호 단위로 구성되는데)
// 컴퓨터는 0과1로 연산을 하므로 2의 8제곱까지가 컴퓨터의 최소 연산 범위

//		다시말해 .. "257번째 이후의 문자가 혹시 눌리면 어떻게 될까?
//		를 생각해보거나 (다음 시간 풀이) 혹은 예습해주세요

//3-2 : (위와 별개) 별표가 배열의 특정 위치에 있을때 
//		범위를 벗어나지 않게 해주세요

//	3-3 : 별표가 배열의 한 좌표에 있을 때 , 숫자 키를 누르면 
//			배열 값이 그 숫자로 바뀌게 해주세요

//c,c++ 을 명령어 입력 화면(콘솔)에서 사용할 때 유용한 확장기능
#include <conio.h>//콘솔
int main()
{
	// 복습

	int a[5] = { 1,2,3,4,5 }; // 자료형 배열이름[배열크기]= {초기값};

	int b[3];// 일단 만들고
		//b[3]={1,2,3}; 이렇게는 안돼

	b[0] = 1;// 대신 이렇게 할당 가능[0]은 배열의 순번. 배열은 0번째부터 센다
	b[1] = 2;
	b[2] = 3;// 크기가 n인 배열은 n-1이 마지막 순번

	//위 방법으로 배열을 할당, 수정 , 연산도 가능
	std::cout << b[0] << std::endl;

	//[]사이에 (크기 범위 안이기만 하면) 결국 숫자가 들어가는 것
	// -> 따라서 숫자를 의미하는 변수의 이름을 넣어도 똑같이 호출할 수 있다.

	int c = 2; // 정수 변수를 만들고
	std::cout << b[c] << std::endl;

	//=======================================================================================

	int tmp;

	tmp = _getch();

	std::cout << tmp << std::endl;
	std::cout << (char)tmp << std::endl;


	//본론 :다차원 배열 써보기

	//* 이론 설명등은 ppt를 기본적으로 참조해주세요

	// 2차원 배열 만들어보기

	// 기본형태

	int two[4][5];// 배열 선언

  //값 초기화
	int arr2[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	//-> 큰 배열 크기 x 작은배열 크기만큼 원소 초기화 가능(여기선 3x4)

	// 조금 더 명확한 형태로 초기화할 수도 있다.
	int arr2_1[2][3] = { {1,2,3}, {4,5,6} };
	//작은 배열을 각각 {} 로 다시 나누어서 구분하는 것도 가능

	//만든 2차원 배열을 사용해보기
	
	// 값 할당(및 수정)

	//2차원 배열도 그냥 배열과 마찬가지로, 반복문과 어울린다
	//단 , 2차원이므로 반복문도 두 번 겹쳐 사용할 뿐

	//위에서 만든 two 배열에 값을 넣어보기(5개짜리 작은 배열을 4개 묶은 것)
	// -> 반복문을 작성할 때는 큰 배열부터 작성
	for (int i = 0; i < 4; i++)
	{

		//그 안에 작은 배열을 넣기 : 큰배열 반복문 1회당 , 작은 배열이 처음부터 끝까지
		for (int j = 0; j < 5; j++)
		{

			//two[i][j]// 큰 배열의 i번째 작은 배열의 j번째 원소

			// 해당 값 수정
			two[i][j] = i + j;//0+0 부터 3+4까지 올라갈 것

			std::cout << arr2[i][j] << "\t";// \t : 특수 문자 중 하나. 용도는 "폭 맞춤(tab)"
		}
		// 작은 배열 한 주기가 끝날때마다 줄 바꿈
		std::cout << "\n"; //\n : 특수문자 "개행 ("줄바꿈")
		

	}

	// 원하는 자리의 배열 순번을 정확히 입력하면 해당 좌표의 자료도 불러올 수 있다.

	std::cout << "직접 숫자 불러와보기" << std::endl;
	int x;// x좌표
	int y;// y좌표

	//cin 사용시 배열내 원소 호출 *(참조용)
	//std::cout << "X 좌표";//입력받을 자리
	//std::cin >> x;	// 입력대상

	//std::cout << "Y 좌표"; // 입력받을 자리
	//std::cin >> y;// 입력대상

	//std::cout << "입력한 좌표의 숫자 : "; // 출력이 나오는 곳

	//std::cout << two[y][x];	// 축 순서를 반대로 할 것!


	// 조금 다른 배열 호출 방법

	// 좌표 초기화(0,0)

	x = 0;
	y = 0;

	//입력 전용 변수 하나 더 만들기

	int input;

	while (true)
	{
		system("cls"); // 화면을 모두 지우는 기능


		for (int i = 0; i < 4; i++)
		{

			
			for (int j = 0; j < 5; j++)
			{
				//two[i][j] = i + j;
				// 추가 조건: x,y로 지정된 좌표인 경우
				//해당 자리만 -1로 보이게 만들기

				if (j == x && i == y)// 각 i,j에 축 정보를 넣었는데 일치하면
									// 더불어 축 순서는 반대!

				{
					std::cout << "♠" << "\t";
				}
				else std::cout << arr2[i][j] << "\t";	// 아니면 숫자
			}
			
			std::cout << "\n"; 

		}

		//출력이 끝난 후, 일시 정지 겸 (일시 정지가 없으면 무한 실행할 테니까
		//키보드로 입력을 받아 , 문자 코드를 input에 넣도록 하기

		input = _getch();

		//_getch(); : c, c++ 에서 사용한 콘솔 환경에서 키 입력 대기겸,
		// 입력 받은 키의 문자 코드를 즉시 출력해내는 기능
		// 반응 속도가 빠르고 (키를 누르자마자 실행)
		//코드에 대응하는 문자를 찾기에도 좋다
		// 단, 이 기능 자체는 데이터를 저장하지 않기 때문에 (실행만 한다)
		// 실행 결과를 저장하기 위한 변수가 하나 더 필요하다(우리가 만든 input0)


		// 1단계 : input의 문자 코드와 대응하는 문자를 확인
		std::cout << input << std::endl;// 문자 코드
		std::cout << (char)input << std::endl;// 형 변환을 써서 코드를 다시 문자로 바꾼 것
												// 형 변환이 낯선 분들은 이참에 복습


		// 1단계를 위한추가 코드
		system("pause"); // 이 코드를 실행하면 앱이 일시정지를 한다




		// 그리고 2단계 /....
		//그리고 3단계......



		//는 과제 대상입니다.
	}


}
