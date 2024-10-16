﻿//함수 작성과 사용

//함수 사용과제

// 슷자 두 개를 사용하는 사칙연산을 함수로 만들어주세요
// 그리고  main 에서 실행해주세요

// (옵션) 반환형이 있는 사칙연산 함수를 main 에서 출력하는 화면과
//			void 로 사칙연산 결과를 출력하는 함수를 실행하는 화면을
//			각각 만들어주세요(숫자  두개를 쓰는 매개변수는 같습니다.)

#include <iostream>

// 먼저, 함수를 만들거나 작성하려면 {}밖으로 나와야한다
// 함수 만들기 (자세한 사항은 main ()안에서 확인)

int FirstFuntion(); // 자료형 함수이름 () 작성후 , {}는 쓰지 않고 ;만 쓰기
					// 함수의 선언: 변수의 선언과 같다
					// 다시말해 이름으로 된 "이런 데이터가 있다" 고만 해두고
					// 실제 내용은 아직 아무것도 정하지 않는 것
					// 다만 , 이름이라도 있으면 컴퓨터는 "그런갑다" 라고 허용
					// 이후에 적당한 곳에서 함수의 내용을 다 적어주면 된다.

int ReturnCalc();
float ReturnFloat();
bool CheckItTrue();
char ShowLetter();
char ChangeThisToLetter(int code);
int AddAll(int x, int y, int z);
void PrintThis();


// 함수 작성의 기본 형태


//.... 는 밑에 있는 int main() {} 이게 바로 함수였다.

int main()
{
	// main () :  c++ 프로그램이 실행하면 반드시 자동으로 수행하는 시작이자 끝 행동
	//			시작과 동시에  main()이 시작되고 , main ()이 끝나면 앱이 끝난다.

	// 따라서 기본적으로 함수는 아래와 같은 기본 도식화 모양을 갖는다.

	// 자료형 함수이름() 
	//{
	// 수행할 행동(코드)
	//}

	//이와 같은 모양의 함수를 더 만들어서 써보는 것이 이번 과정의 목적


	// 이곳 main() 함수의 아래쪽 ({} 바깥 )영역에 함수를 더 만든 후
	// 다시 main ()에서 사용해보도록 하자 (함수 안에서 다른 만들어진 함수 사용가능_



	//--------------------------------------


	


	//-------------------------------------------------

	// () 괄호를 붙이는 이유 1. "호출"임을 알리기 위해서
	// 2. 그냥 호출이 아니라 "작업을 지시" 한다고 표시하기 위해
	// 3. ?????


	// 더불어 (꼭 그래야 되는 건 아니지만 )흔히 c++로 함수를 직접 만들때는
	// 함수 이름을 파스칼 방식으로 적는 경우가 많다
	//(대문자 시작, 소문자 위주, 2단어 이상이면 각 단어 첫 글자가 대문자)
	// 변수가 낙타 방식인 이유 중에는 함수 명명 방식과 안 헷갈리려고 하는 경우도

	//그리고 (다른 조치 없이) 작성만 한 함수를
	//(그것도 main() 뒤에 작성만 한) 함수를 실행하면 오류가 난다.

	//-------------------------------


	//이유 : 짧은 버전 "FirstFuntion 함수가 뭔지 아직 몰라서"
	//			긴버전 c++은 2회 로딩 1회 컴파일을 한다.
	//			그런데 컴파일 시점이 첫번째 로딩이다
	//			그래서 1회 로딩 시점에서 아직 모르는 지정이나 기능이 보이면
	//			실제로도 뒤에 정확히 적었더라도 "그런 건 모른다" 라고 판단한다.

	//			a=0; // 이 코드가 오류 나는 원리와 같다.

	//	해결책 : 1. 아예 작성을 main() 보다 위에 해버리기 (먼저 읽게 만들기)
	//			2. 작성은 main 보다 뒤에 하되, 이름만 슬쩍 가르쳐주기
	//				컴퓨터는 함수의 정확한 내용은 몰라도  일단 " 그런게 있는 갑다"
	//				라고는 생각해주게 된다.
	//				=> main() 함수의로 가서 , 함수의 이름을 만들어주면 된다.

	//===================================

	//함수 이름을 먼저 선언해주고, 다시 실행하면 그래도 오류가 난다.
	
	//함수를 만들 때는 자료형을 제시를 해주게 되는데
	// 그러면 함수가 끝날 때, 컴퓨터는 그 자료형으로 된 결과를 기대한다

	//따라서 모든 함수는 그 자료형에 맞는 결과, 다른 말로 반환(return)이
	// 필수가 된다.

	// 일단 int는 반환이 필수가 맞다.


	// main 그런데 main()은 왜?
	// 엄밀하게는 사실 return (수행을 못했던 코드 개수)라는 숨겨진 코드가 있다
	// 굳이 적을 필요가 없다(컴퓨터 입장에서 참고용으로만 쓰면 된다
	//(정상적으로 수행이 잘 됐다? 오류 개수 0, 안됐다? 중간에 터진다)
	//그렇게 해서 0이라는 값을 받았다고 해봤자 ... 이미 앱 끝났는데
	// 다만 사용자가 return 을 직접 작성하면 main 의 반환값도 만들 수는 있지만
	// 역시 의미가 없다. (main이 끝나면 앱도 끝나니까) : 자동작성


	// 밑에서 만든 함수는 여기서 이름을 부르면 실제 작업을 수행할 수 있다.
	// 이를 호출 , 혹은 실행이라고 한다

	

	//--------------------

	//그리고 함수의 수행 결과 , 반환값이 발생을 했다면?
	// 해당 반환 값도 하나의 데이터로 취급할 수 있다.

	 //수행 결과 반환값이 100인 함수가 있다면 , 그 100을 출력하거나 , 계산에 쓸 수 있다.

	FirstFuntion();// 함수를 실행할 때는 뒤에 ()를 붙인다.

	std::cout << FirstFuntion() << std::endl;

	int sum = FirstFuntion() + 200;

	std::cout << sum << std::endl;

	ReturnCalc();// 함수 실행만 
	std::cout << ReturnCalc() << std::endl;// 실행 후에  결과 출력까지
	// 두번째 줄에서 실행후 실행으로 나온 결과 까지 출력 되는 것을 볼 수 있다.
	// 이해함  return calc 를 하면 결과값 20000이 나옴

	//소수 함수 출력 
	std::cout << ReturnFloat()/2 << std::endl;

	// 불 함수 출력
	std::cout << CheckItTrue() << std::endl;

	// 문자 함수 출력 
	std::cout << ShowLetter() << std::endl;

	//문자 바꾸기 함수 실행 + 출력
	std::cout << ChangeThisToLetter(110) << std::endl;
	std::cout << ChangeThisToLetter(98) << std::endl;
	// 이해함 int code 는 매개변수이며 {} 안에서 마음대로 쓸 수 있는 변수느낌

	//매개변수가 여러 개인 함수 (실행만 해보기)
	AddAll(300, 500, 864); 
	// 리턴값이 안나오는 이유 std::cout <<AddAll()<<std::endl; 로 호출하지않아서



	// void 글자 출력함수 (호출만해보기)

	PrintThis();






}

int FirstFuntion()// 자료형 함수이름 () 형태
{
	//수행할 행동을 지시한다

	int a = 1;// 변수도 만들고
	int b = 2; // 다른 변수

	int add = a + b; 

	std::cout << "함수를 실행" << std::endl;
	std::cout << add << std::endl; //출력도 하고

	//아무튼 원래 우리가 해왔던 계산들은 다 함수로 만들 수 있다
	//-----
	
	//단 여기까지 적고 반환을 만들지 않으면 이 함수는 오류가 난다.

	// 다음 코드로 반환을 제시해야 한다.
	return  1;// 0이라는 숫자를 이 함수의 결과로 제시한다는 뜻(반환한다는) 뜻




}

// 다른 함수도 만들어보기 
int ReturnCalc() // 계산 후에 결과를 반환할 함수
{
	int c = 1000;
	int d = 200;

	int calc = c * d;

	// 츨력

	std::cout << c << "곱하기" << d<<calc << std::endl;
	return calc; // 변수도 데이터이므로 반환이 된다.



}

float ReturnFloat()
{
	int e = 200;
	float f = 300.0f;

	//return e; // 가능 ... 하지만 비추천
				// 이 경우 , 반환되면서 자동으로 소수로 취급된다.

	return f;// 가능하고 추천 (이유 : float 는 소수로 받으면 더욱  효율이 좋기때문에)



}

// 정말로 c++에 있는 모든 자료형 가능

bool CheckItTrue() // 사실인지 보기 (bool 변수)
{
	int number1 = 1000;
	int number2 = 200;

	// bool check  = number1 > number2; 숫자 1이 2보다 큰가?
	// return check;  이런식으로도 가능

	return number1 > number2;


}
// 형 변환도 적용 가능 (결국 연산이니까)
char ShowLetter()
{
	int ch = 99;
	return(char)ch; // 예상 c

}

// 그리고 여기서 /...

// 정해진대로만 연산하는게 아니라 사용자가 함수를 부를때 
// 무엇을 계산시킬 것인지 정하도록 만들기

// 매개변수 지정

char ChangeThisToLetter(int code)
{
	// () 안에 쓰인 int code : 매개변수
	// int : 매개변수의 자료형
	//code : ㄴ매개변수의 이름
	//이 것 이 {}안에서 code 라는 이름은
	// 나중에 사용자가 준비할 추가 준비물 (매개변수)임을 나타낸다
	// 당장은 이 code가 무슨 숫자인지 모른다
	// 나중에 실행할 때 이 code 가 무엇인지 사용자가 직접 지정해줘야한다.

	//그리고 이 매개변수로 받은 code를 형 변환 연산한다.

	std::cout << code << std::endl;
	//{}안이라면 매개변수도 그냥 변수처럼 평범하게 쓸 수 있다.
	return (char)code; // 그대로 반환



}
// 함수의 매개변수는 둘 이상을 지정할 수도 있다.

int AddAll(int x, int y, int z)
{
	int addall = x + y + z;// * c++은 대소문자가 서로 다른 글자로 취급
							// 그래서 addall과 Addall과는 서로 다른 글자

	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << z << std::endl;
	std::cout << addall << std::endl;

	return addall; // 왜 리턴값은 안나오지?
		
}

// 여기까지 익힌 후 함수의 마지막 사용지식

// void : c++의 첫 번째이자 마지막 자료형 의미는 "없음"
// 변수로 지정하면 그냥 데이터가 아니라 실체가 없는 추상적인 의미 ... 를 뜻하게 되고
// (사용이 지금 시점에서는 매우 까다롭다)
// 함수로 지정하면 "이 함수는 반환 데이터가 필요가 없다" 라는 뜻이 된다.
//따라서 return 자체는 슬 수 있지만 , 용도가 일반적인 반환의 목적이 아니다.
// 이 void는 반환 데이터가 무의미하고 , 대신 함수 자제가 실행되는 과정이
// 더 중요할때 함수의 반환 자료형으로 제시한다.


// void 함수의 예시
void PrintThis()// 이거 출력하세요
{
// 이 함수의 목적은 뭔가를 계산하는게 아니다 . 얻으려는 것도 아니다
// 오직 밑에 있는 글자를 출력하는 것 만이 목적(실행만 되면 나머지는 내 알바아님)

	std::cout << "여기까지가 함수를 사용하는 방법입니다."<<std::endl;
	std::cout << "고생하셨습니다.." << std::endl;
	std::cout << "빠이." << std::endl;
	//return 0;  // 반환 변수를 제시하면 오히려 문제

	// =------=--=-=-=-=-=-=-==============

	//  void에서 return을 사용하는 방법

	//함수에서 return 을 사용하면 컴퓨터는 그 밑의 코드는 더 계산하지 않는다
	// 반환을 한 시점에서 함수의 목적을 이루었다고 판단하니까.

	// void 함수는 그 특성을 써서 중간에 함수를 강제로 종료하려고 할 때
	//return 코드를 써서 함수를 도중에 멈춰버릴 수 있다.
	// 사실은 다른 자료형도 return 으로 함수를 중간에 멈추기 가능

	return;	// 변수 제시 없이 , 그냥 return 으로 쓰는건 가능

	std::cout << "끝" << std::endl;


}
