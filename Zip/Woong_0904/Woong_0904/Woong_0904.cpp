

#include <iostream>


// C++의 STL중 흔히 쓰는 기능들 특집의 첫번째

// STL: standard templeate libary의 줄임말 뜻은 표준 지시의 원형
//		프로그래밍 언어에서 대체로 필요한 기능이 무엇인지 합의해둔 구성을 말함

// 그리고 STL에 따라 C++이 사용자 지원용으로 만든 라이브러리가 c++StlL

//-> 자유 문자열 , 자료 구조(크기를 바꿀 수 있는 배열 비슷한 것들 데이터 집합)
//_수학기능 os기능을 끌어다 쓰기, 프로그래밍 자체의 확장(변형)등을 포함


//기본적인 건 stdlib.h 안에 들어잇는데 , 그 박에 몇가지 추가 STL헤더가 존재

// 그리고 오늘 첫 순서로 우리가 STL의 한가지로 불러올 대상은

// 문자열, 정확히는 '마음대로 바꿀 수 있는 문자열'(용어로는 string 스트링 , 또는 대본대사)

// 먼저 스트링 기능 사용하기

#include <string>	 // string.h의 신버전 (이전 강의 주석을정정)

//=> string 역시 c++ STL 의 일부분


//옵션) 원하시면 using으로 std::생략해도 된다.
int main()
{
	std::string stringData; // 문자열 ST:문자열
							// std::strin ;: 문자열의 저장 출력 수정등을
							// 담당하는 자료형 겸  클래스



	// 앞으로 C++의 STL기능을 사용하면 그 중에 상당수가ㅓ 이렇게
	//std 네임스페이스 속, 내부에 복잡한 기능을 숨긴 클래스의 형태로
	// 쓰는 경우가 있을것 사전에 include등의 준비완료

	//STL 문자열을 어떻게 쓸 수 있는지 확인
	//1. 만든 문자열을 나중에 수정하기

	stringData = "안녕", "박진웅입니다."; // 변수처럼 수정하면 OK
	std::cout << stringData << std::endl;

	stringData = "감사합니다."; // 수정한 변수 또 수정하기
	
	std::cout << stringData << std::endl;

	// 이것 만으로도 앞으로문자 출력은 string 가지고 하면 되겠네? 맞습니다!


	//다만 char* 등 기본적인 C++기능도 미리 알아두어야 윈도우 플밍에서
	// 사용하는 함수 구성등에 적응이 가능해서 기본단계가 필요했다.

	//2. 문자열 입력받기

	std::cin >> stringData;
	std::cout << stringData << std::endl;

	std::cin >> stringData;
	std::cout << stringData << std::endl;


	// 즉 일반 변수를 다루듯이 string 은 얼마든지 재수정 가능하다.!!!!!!!

	//다만 cin으로 입력을 하면 띄어쓰기를 할경우 문자가 잘린다


	//다만 cin 으로 입력을 하면 띄어쓰기를 할 경우 문자가 잘린다.
	//이유: 띄어쓰기가 여기서 철자 ㅡ 혹은 항 등을 구분하는 연산 기능이 있어서

	// 이런 경우는 어떻게 하는가 ? -> string 이 클래스를 겸하는 점을 이용

	// string 혹은 std:: , 혹은 string 으로 만들어진 변수 안을 각각 들여다보면
	// 이 과정에서 :: 혹은 , 연산자 사용) 그 안에도 함수들이 있음이 보인다
	// 이번 경우는 std:: 안에 있ㄴs getline gkatn tkdyd

	std::getline(std::cin, stringData ); // getline 함수:
										// cin으로 입력을 받아서
										// stringData 안에 데이터를 다 넣는다
										// 엔터 누르기 전까지 유효
	// 아래 콛를 실험할 때는 위의 cin 코드를 주석으로 만들면 좋습니다.
	std::cout << stringData << std::endl; 

	// 3. 변수 사이의 (일부 )연산

	// 이 연산은 영어일때 더 좋습니다. ㅉ(2바이트 문자 코드가 있으면 안좋음)

	std::string compare = "Banana ";// string 비교초기화도 가능
			
	//string 
											 
											 
											 //문자열이 갈 수록 "큰 변수로 친다

	stringData = " Text";

	bool compareResult = (stringData > compare);//string 끼리 비교 연산 가능	

	std::cout << compareResult << std::endl; // 둘중 어느쪽 문자열이 더 긴가에 따라
												//bool 변수가 달라진다.

	//4. 변수 사이의 (일부) 연산 2탄


	std::string sumText = compare + stringData;

	std::cout << sumText << std::endl;

	sumText += compare; // 누적 연산 가능)

	std::cout << sumText << std::endl;


	// 단 뺄셈은 안된다 (곱셈과 나눗셈은 저도 몰라용)

	//sumText = stringData - compare; // 성립하지 않음(오류)
									// 문자열을 "빼기"를 하려면
									// 먼저 컴퓨터가 문자열의 구성을 해석해야 하는데
									// 빼려는 문자가 원본에 있던가? 있다면 어디인가?
									//C++은 컴퓨터가 그런 과정을 안거쳐요


	//


	// 1,2,3,4를 모두 종합하면

	//std::string 은 매우 다루기 쉬운 문자열이라는 것!
	//그냥 초기화하고, 할당하고 , 수정하고 , 마음대로 바꿔도 되는 편한 변수!

	// 지금부터는 필요하면 이쪽도 자유롭게 쓰도록 합시다.

	//졸려졸려졸려졸려졸려졸려졸려조렬조ㅑㄹ져져려져졸려졸려졸려졸렺졸려졸려졸려졸려졸려ㅕ
	//담배최고

	//힘내세요.. 저 무서워요 인정


	//===========================================================================


	//5. string 의 클래스로서의 함수

	// 사용법: 만든 변수 뒤에 . 연산자를 붙이면 된다.

	//stringData.

	// 전부는 아니고 자ㄱ주 쓰게 될 string 함수

	std::string text = "Text to test"; // 새 원본 텍스트

	// 5-1 append 추가 : 문자열을 추가

	text.append("안녕하세요!"); // 매개변수에 원하는 텍스트 추가하기

	std::cout << text << std::endl;

	// 5-2 erase (삭제) :  문자열을 삭제

	//						위에 적었든 , c++은 컴퓨터가 문자열을 해독하지 않는다
	//						- 얀산이 안됐듯이 , 여기서 "단어"는 못지운다
	// 그 대신///

	text.erase(4, 5);

	std::cout << text << std::endl; // 지우기 시작할 자리와 , 몇 글자를 지울지를 지정가능
									// text.erase(n,m)이라고 하면 n은 지우기시작할 위치
									// m은 지울 글자 개수를나타낸다


	// 5-3 length : 문자열의 길이

	int length = text.length();


	std::cout << length << std::endl;

	//5-4 push_back: 문자열 추가 기능의 다른 형태
	//				단, 1글자만 가능

	text.push_back('A'); // 칼같이 1글자만 추가할때 가끔사용
	std::cout << text << std::endl;

	//5-5. pop_back : 문자열 삭제의 다른 형태
	//					단, 맨 마지막 글자 하나만 가능(위치, 길이 지정불가)
	text.pop_back();
	std::cout << text << std::endl;

	//5-6 . empty : bool 변수 , 이 문자열이 비어 있는지 아닌지 판별
	
	std::string emptyText; // 텅빈 텍스트

	bool isEmpty = text.empty();
	bool isEmpty2 = emptyText.empty();

	std::cout << isEmpty << std::endl;
	std::cout << isEmpty2 << std::endl;

	// 입력을 잘 받았는지, 데이터가 있기는 한지 등을 확인할 때 유용

	//5-7 clear : 문자열 초기화

	text.clear(); // 그냥 부르면 바로 문자열초기화 (내용 다 삭제)

	std::cout << text << std::endl;

	isEmpty = text.empty();				// 컴퓨터 입장에서 비었는지도 확인
	std::cout << isEmpty << std::endl;


	// 이 일곱가지 외에도 다른 함수들이 더 많이 있고
	// 보통은 단순수정 정도로 (수정 가능한 문자열처럼) 써도 문제가 없다.

	// -> 다만 string 으로 만들어진 변수가 엄연히 인스턴스로서
	// 다른편의 함수들이 존재한다는 것만은 알아두어야 한다.

	//=========================================================


	//STL은 현재 여러 기능이 있지만 , 기능의 사용상 형태가 비슷하다면
	// (이를테면 " 늘렸다 줄였다 하는 행동이 있다" 든가 편집이 가능하다든가
	// 대체로 비슷한 이름의 함수를 지어주는 경향이 있다

	// 따라서 오늘 바로 이 함수들을 외우기 보다, 꾸준히 천천히 계속 

	// 함수의 존재를눈에 익혀두는 것이 낫다

	// +함수만 그런것이 아니라, c와 c++에서는 현재 기준으로
	// 대부분의 내부 기능 사이에서도  호환성이 높아진 상태

	// 예 : 우리가 클래스의 기능으로서 알아왔던 함수 작성, 접근 지정자 , 상속...
	//		/....등이 사실은 구조체에서도 사용이 가능하다.

	//struct 를 사용에서 함수를 불러오기?

	//따라서 무조건 코딩을 외우기보다 " 이런 형태에서 이런 코딩이 되더라" 위주로
	// 실습으로 익혀두면 나중에 나름대로의 응용 형태 역시 만들 수가 있다.

}

// iiii ===== ///// :::: iiiiii ===== ///// :::: 

// 동해물과 백두산이 마르고 닳도록 하느님이 보우하사 우리나라만세
// 무궁화 삼천리 화려강산 대한사람 대한으로 길이 보전하세