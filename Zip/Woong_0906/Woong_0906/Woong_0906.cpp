﻿

#include <iostream>
#include <vector>

// std 생략시

using namespace std;
int main()
{
	// STL의 자료구조 기능 중 하나인 벡터

	// 자료구조란: 여러 데이터를 분류하고 집합으로 만드는 기능 , 혹은 그 방법

	// 벡터 : 자료구조 중 , 배열과 유사한 기능을 하도록 만든 STL 자료 구조의 이름
	// 배열처럼 쓰되, 크기를 내가 마음대로 바꾸고 원소를 추가, 삭제할 수 있다.

	//1. 벡터를 쓰는 방법
	// 1. main() 위에 #include <vector> 추가

	//2. 벡터를 배열을 선언한다는 기분으로 선언하기

	//	(단, 문법은 고유한 방법을 사용한다.)

	

	// 정수의 벡터 선언
	std::vector<int> vec;

	// * vector : 벡터의 클래스를 의미 
	// vector 뒤의 <int > : " 어떤 자료형" 의 배열일지를 정하는 것
	//<int> 라고 하면 정수의 가변 배열, <float>이라고 하면 소수의 가변 배열

	// 소수 벡터 선언
	std::vector<float> vecFloat; 

	// 이후 자료형 ; 클래스 등에 <>를 넣어서 "어떤 자료형에 대한 사용인지"
	// 한번 더 지정을 해줘야 하는 경우가 생길 수도 있다.

	//std::vector vec; 이따구로 쓰면 오류남

	//이렇게 <> 를 써서 구체적인 자료형을 다시 지정을 해주는 코딩을 
	// "템플릿"이라고 한다. (템플릿에 대한 상세는 다시 다음 기회에 계속...)

	// *일단은 "벡터는 <> 포함 선언한다" 는 것까지만 익혀둡시다.

	// 3. 선언으로 만들어진, 아직 원소가 없는 벡터에 원소를 추가

	// 벡터에 원소를 추가하는 방법 : push_back 기능 사용 (string과 동일)
	// push_back : 마지막 원소 뒤에 새 원소 추가

	vec.push_back(10); // 정수 벡터에 10이라는 정수를 추가
	vec.push_back(1);	// 10 다음에 1 추가
	vec.push_back(2);	//	1 다음에 2 추가

	// 위 세줄을 수행함으로써 vec라는 벡터 (가변 배열)에 10,1,2 라는 숫자가
	// 차례로 들어갔다

	// 위 결과를 출력으로 확인

	for (int i = 0; i < 3; ++i)	// 결과 값 : 10, 1 ,2
	{

		std::cout << vec[i] << std::endl;
	}
	// 4. 한번 만들어진 벡터에서 원소를 삭제 

	// 원소를 삭제하는 방법 : pop_back (string 과 마찬가지)
	// 맨 뒤에 있는 원소1개를 삭제

	vec.pop_back(); // 맨 마지막에 있었던 2라는 숫자를 지우기

	for (int i = 0; i < 2; ++i)	// 오류가 나는 것을 확인
								// 원소가 삭제 됨으로써 줄어든 만큼의 길이를 반영해야함
								//3 =X, 2 =O
	{

		std::cout << vec[i] << std::endl;
	}


	//여기까지 벡터의 기본 사용 방법

	//===========================================================

	//5분 간단 실습 : 1.0부터 9.0부터까지의 소수를 vecFloat에 넣어서 출력하기




	//for (float i = 1; i < 9; i++)		// 집가서 해결하기
	//{
	//	vec.push_back(i);
	//	
	//}

	//for (float i = 1; i < 9; i++)
	//{
	//	std::cout << vecFloat[i] << std::endl;

	//}
	//

	//for (float i = 0; i < 4; i++)
	//{
	//	vec.pop_back();
	//	
	//}
	//for (float i = 0; i < 5; i++)
	//{
	//	std::cout << vecFloat[i] << std::endl;

	//}

	// 벡터의 좀 더 복잡한 사용 방법

	// 벡터에서 원소 추가 삭제 방법은 알았는데, 이거 다 마지막 순서에만 먹히네
	
	// 중간도 추가하고 삭제하면 얼마나 좋을까
	// = string에  erase가 있었는데 써볼까?

	// 벡터에 erase 시도해보기


	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);	// 먼저 원소 좀 더 추가하기

	//erase 호출
	//vec.erase(3); //오류발생

	// 이유 : vec가 단순 자료형이 아닌 클래스라서 
	//		=> 여기서 "몇번째" 라고만 했을 떄, 일반 배열처럼 메모리 위치를
	//			자동으로 짐작할 수가 없다.

	//			현재 벡터 내의 진자 데이터가 어디에 있는지, 어떻게 있는지
	//			매번 별도의 포인터 기능을 써서 알아내야 한다.

	// 그리고 벡터에서"원소의 메모리 위치" 를 전문적으로 찾는 전용 포인터 존재

	//이 포인터를 iterator라고 한다 (우리말로 반복자)
	

	//따라서 반복자를 써서 지울 데이터의 위치, 순번 등을 알 수 있다.

	//반복자의 확인 (포인터 선언)

	vector<int>::iterator it; // "정수 벡터"의 메모리 위치를 연산하는 포인터
								// 연산자가 안보여도 이건 포인터 (* 생략)

	//만든 반복자에 실제 메모리 위치를 할당
	it = vec.begin(); // begin() 함수 뜻 : 벡터의 첫 원소가 존재하던 메모리 위치
						// => vec.begin() : 정수 벡터의 첫 수자의 주소 (10의 주소)

	// it 가 포인터가 맞는지, 위치가 정말 데이터의 위치인지 확인

	std::cout << *it << std::endl;	// 첫 숫자 10확인 

	// 이어서 it가 "정수의 포인터"가 맞는지 다시 확인
	// (여기서 it에 숫자를 더해본다면 순서에 맞는 숫자가 나올 것)

	std::cout << *(it+1) << std::endl;	// 1출력(정수 벡터에서 1 순번이 1)
	std::cout << *(it+3) << std::endl;	// 2출력
			
	// 벡터에서 메모리 위치를 알아야 할 때가 오면 보통 배열에서 쓰던 []대신
	//이 iterator 내부 클래스를 써서 (이것도 클래스임)포인터를 구한다

	// 그리고 이 포인터, 이 포인터에서 알 수 있는 "순번의 위치" 관계를
	//위에 오류가 나던 erase에 사용한다.

	vec.erase(it + 3); // 포인터를 써서 원소 중간에 지우기

	//출력으로 확인
	for (int i = 0; i < 5; i++)
	{
		std::cout << vec[i] << std::endl;
	}

	// erase에는 이렇게 iterator를 사용해야 한다.

	//----------------------------------------------------

	//벡터 중간에 원소 추가하기: insert

	// 여기에도 반복자가 필요하다

	it = vec.begin(); // 데이터 위치를 할당하기

	vec.insert(it + 4, 999999); // 지정한 순번에 새로운 원소를 추가
								// 원래 있던 원소는 뒤로 밀려난다
	//							// 중간에 숫자를 끼워넣는 모양새

	it = vec.begin(); // 데이터 위치를 할당하기

	//intj ????????????? intj

	vec.insert(it + 1, 111111);

	for (int i = 0; i < 7; i++)
	{
		std::cout << vec[i] << std::endl;
	}
	//-----------------------------------------------------------




	////insert 다시 써보기



	//vec.erase(it + 2);

	//for (int i = 0; i < 5; i++)
	//{
	//	std::cout << vec[i] << std::endl;
	//}
	
	// 위와 같이 입력하고 실행하면 오류가 난다! (의도대로 출력 x 정상 종료 x)

	// 더 정확히는 insert , erase 실행 후 , it 의 값을 출력할 수 없게 된다

	// 그 이유는 벡터가 배열을 흉내내고 있기 때문

	// 배열을 흉내내는게 뭐가 어때서? 문제는 배열의 특성

	// 배열은 모든 데이터가 완전히 일렬로 정리되어 있다

	// 따라서 포인터 값에 +1만 해주면 원소 순번을 바꿀 수 있다

	// 벡터 역시 모든 데이터를 일렬로 확인할 수 있도록
	// 일부러 가지런한 정렬을 해서 데이터를 만들어 뒀다

	// 그런데 insert를 쓰거나 erase 를 쓰면
	//데이터의 전체 개수가 달라진다

	//이 경우 메모리 상황에 따라선 다음 원소가 들어갈 공간이
	//없을 위험도 있고, 메모리 낭비가 생길 위험도 있다
	//(빽빽한 주차장에 새로 차가 들어오거나, 안그래도 휑한 주자장에서 )
	// 또 한 대 차가 나가는 상황을 떠올려 봅시다.

	// 이 때 벡터의 특성 (배열처럼 쓸 수 있음, 데이터가 가지런함)을 지키기 위해
	// 벡터는 insert, erase 가 실행될 때 새로운 데이터 전체 개수를 계산해서
	// 해당 데이터가 들어갈 "새 공간"을 찾아낸다. 거의 매번
	
	// 이 때 데이터의 시작점을 지정했던 it의 값이 효력을 잃기 때문에 (구 주소)
	// insert , erase 실행 후, 다시 같은 it를 써서 같은 함수를 실행할 수 없다.

	// 벡터를 사용할 때 지켜야 할 중요한 주의점

	//-----------------------------------------------


	//그래서 반복자의 포인터 값을 유효하기 유지하려면 다음처럼 써야 한다

	//1. insert, erase 를 쓸 때마다 반복자를 갱신하기

	it = vec.begin(); // 매번 갱신부터 해두고
	vec.insert(it + 3, 12344556); // 그 다음에 벡터에 원소 삽입하기

	it = vec.begin(); // 매번 갱신부터 해두고
	vec.erase(it + 2);
	

	
	for (int i = 0; i < 7; i++)
	{
		std::cout << vec[i] << std::endl;
	}
	
	//2. 별도 연산, 변수 할당 없이, 필요할 때마다 계속 직접 호출하기

	vec.insert(vec.begin() + 4, 44668899); // it 대신 begin 함수 직접 호출
	vec.erase(vec.begin() + 1); // 여기서도 직접 호출

	for (int i = 0; i < 7; i++)
	{
		std::cout << vec[i] << std::endl;
	}

	//=================================================


	//이렇게 벡터가 사용하는추가 함수 중에는 필요할 때마다 호출하는편이
	//다른 변수에 할당을 해두는 것보다 좀 더 효율적인 경우가 있다

	// 위의 메모리 위치(포인터)도 그렇고... 다른 예시로는 이런 것도 있다.

	//바로 "현재 벡터의 원소 개수" = 배열의 크기

	int count = vec.size(); // 벡터의 크기
							// 언어에 따라서는 count 라고도 한다

	//위의 벡터 크기를 활용하면 벡터 출력 반복문 등에서 매우 유용하게 활용 가능

	for (int i = 0; i < vec.size(); ++i)// 원소개수를 세는 대신 size() 호출
	{

		cout << vec[i] << "\t";





	}
	//size 함수 : 벡터의 편리한 점이기도 하다
	//매번원소가 몇개일지 고민하지 않고 그냥 size만 써도 된다

	//------------------------------


	//벡터의 크기인 size()처럼 벡터 원소 개수에 무관하게 쓸 수 있는
	//다른 방법도 존재

	// 반복자를 활용(위에서 만든 it)

	it = vec.begin(); // it에 새로운 값 갱신

	for (it; //조건 1. : it가 그냥 여기 있다. =사실상 없음 
		it != vec.end();	// 진행 조건 it가 벡터의 끝까지 가지 않았음
		++it) // 반복 수행 시마다 it의 지정 주소가 +1됨
	{
		// 여기서 쓰인vec.end() : 벡터의 마지막 데이터의 다시 맨 마지막 구성이 끝나는 
		//							=마지막 데이터 아님 그 마지막 데이터조차 끝이 나서
		//							"여기서부터는 벡터 아님"을 나타내는 주소

		// 위 반복문의 의미 : "반복자가 이 벡터의 마지막이 되기 전까지 "

		// 반복할 때마다 +1되어서 주고사 "원소 1개 위치만큼" 갱신된
		//포인터의 값에 들어간 , 진짜 데이터를 출력

		std::cout << *it << std::endl;

		//이렇게 포인터 (반복자)를 사용해서도 벡터의 크기에 얽매이지 않고
		//자유롭게 벡터 속 모든 원소 출력및 호출 가능
	}

	cout << vec.front() << endl; // 벡터의 첫 원소 (데이터)
	cout << vec.back() << endl;	// 벡터의 마지막 원소 (데이터)

	//-----------------------------------------------------------

	//추가 벡터 기능들

	cout << vec.at(4) << endl; // at(n): n번째 원소 []하고 비슷하다
								// 다만 순번 연산자인 [] 표시와 달리
								// 코드로 수행하는 함수이기 때문에
								// 원소가 없으면 에러를 낸다는 것이 특징
	// 이게 뭐가 다른거냐 ? 싶을 수 있는데 미묘하게 딱 맞는 곳이 있을 수 있다
	// => 절대로 실패하면 안되는 계산이 있다? 실패하느니 앱을 꺼버려야 할 때 at()
	//=> 실패할 수도 있는데, 실패를 해도 강행을 해야하면 []연산자
	//(당연히 오류가 안나야 하는게 원래는 원칙)

	vec.resize(100); // 벡터의 크기를 다시 지정하는 함수
					// 크기를 지정 후, 남는 공간에는 int의 기본 값을 지정한다

	// 출력 (간이작성)
	for(int i = 0; i<vec.size(); ++i ){cout<<vec[i]<<endl;}


	vec.clear(); // string 과 마찬가지 벡터를 전부 비우는함수
	cout << "===========================================" << endl;
	
	for (int i = 0; i < vec.size(); ++i) { cout << vec[i] << endl; }

	vec.reserve(100);// 벡터의 크기를 다시 지정하는 함수 (2)
					// 단 , 위의 resize함수와 달리, 기본값을 주지 않는다
					// 데이터가 들어갈 자리만미리 예약을해두고 (reserve)
					// 메모리만 확보한 채 데이터를 주지 않기 때문에
					// 출력이나 연산은 불가능하다(추가는 가능)
					
	//reserve 직후 출력: 아무 것도 없음
	for (int i = 0; i < vec.size(); ++i) { cout << vec[i] << endl; }

	for (int i = 0; i < 100; ++i)
	{
		//vec[i] = i; // c++에서는 사용 불가
		vec.push_back(i);// 원소를 추가하면
	}

	//출력가능
	for (int i = 0; i < vec.size(); ++i) { cout << vec[i] << endl; }

	//어차피 push_back 써서 원소를추가하는건 거기서 거기 아니냐?
	// 굳이 reserve가 필요하냐? 이렇게 따져도 reserve는 유용하다

	//왜냐면 벡터는 결국 원소 개수가 자유로운 배열이니까
	// 원소를 덮어놓고 추가하다가 메모리가 부족해서 오류 날 수 있어서

	// 미리 자리부터 맡아 놓고 거기서 원소를 추가하면 훨씬 안정적

	
}

// 앗// 