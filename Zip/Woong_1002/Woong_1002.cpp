

#include <iostream>

//오늘의 진도 : 전처리기와 매크로 (전처리 정의 지시)를 이용한 연산 코드의 단순화

//매크로 = 텍스트를 실행 파일 작성 단꼐에서 다른 글자로 바꿔주는 것

#define MY_MACRO "안녕하세요, 세상이여!"
//실제 코드에 MY_MACRO를 입력하면 _ 실행 파일 작성시 그 텍스트가 
//" 안녕하세요 , 세상이여!" 라는 글자로 바뀐다

// 그렇다면 ... 이렇게 글자를 바꾸는 것을 통해서
// 연산이나 (연산코드) 함수 호출 등을 만들어 볼 수도 있지 않을까?

//그게 바로 매크로를 이용한 연산 수행, 이름하여 "매크로 함수"

//매크로를 통해서 사칙연산 만들어보기

#define ADD(x,y) x+y
//1. ADD라는 매크로를 발견하면, 뒤에 ()가 있는지 보고
//2. ()가 있으면 그 안에 있는 , 쉼표로 구분된 데이터를 각각 X,Y인걸로 친다
//3. 그 x,y를 포함하는 텍스트를 'x'+'y'로 바꿔준다
//4. 결과적으로 , x+y의 연산을 실행파일이 수행하게끔 한다

//같은 방법으로 빼기, 곱하기 , 나누기도 매크로 함수로 만들기
#define MINUS(x,y)x-y
#define	MULT(x,y)x*y
#define DIVIDE(x,y)x/y

// 이 매크로를 main에서 사용하면 마치 x-y x*y x/y 인 것처럼 연산 수행



int main()
{
    // 매크로로 바뀐 연산을 직접 써보기

	int a = 10;
	int b = 3;

	//먼저 매크로가 없는 보통의 연산

	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a * b << std::endl;
	std::cout << a / b << std::endl;


	//매크로를 써서 연산을 확인

	std::cout << ADD(a, b) << std::endl; // ADD()사이 x,y 자리에 a,b 대입
	std::cout << MINUS(a, b) << std::endl;
	std::cout << MULT(a, b) << std::endl;
	std::cout << DIVIDE(a, b) << std::endl; //결과 확인: 똑같다 문제 없음


	// 즉 매크로를 통해서 정의된 텍스트를 넣더라도 실제 실행 때는
	// 이미 텍스트가 바뀌어 있기 때문에 똑같은 연산을 수행할 수가 있다.

}

