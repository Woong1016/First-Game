
#include <iostream>
#include <vector>
#include <string.h>

// 오늘의 진도: 큐 , 디큐

#include <queue> // 큐 기능 (queue , 자료구조의 하나)
#include <deque> // 디큐 기능 (dequeue, 자료 구조의 하나)

// + 싱글턴 : 앱 실행 시에 유일하게 존재하는 객체

#include "SampleSingleton.h" // 샘플용 싱글턴

//샘플 싱글턴을 사용하는 인스턴스 (전역변수)

SampleSingleton* instance = nullptr; // 처음 만들때는 아무것도 없이









int main()
{
    // 큐( queue)
	// 자료 구조의 하나. 데이터를 빠르게 넣고 , 빠르게 빼는 것..
	// "먼저 들어간 데이터를 먼저 빼는 것"에 우선순위를 두고 만들었다.

	// 예 :1,3,5,7,9,2,4,6,8 순서로 데이터를 넣은 후,
	// 정확히 넣은 순서대로 데이터를 다시 찾아내는
	//  (1,3,5,7,9,2,4,6,8)데에 특화됨

	//	이런 데이터 처리 방법을 "먼저 넣은 게 먼저 나온다"(first in , first out)
	//

	// 큐 사용해보기


	std::queue<int> que; //  무엇의 큐인지 <>로 지정할 것. 


	// 큐에 자료를 넣을 때는 "순서대로 넣는다.
	// -> 나중에 넣는 데이터는 거의 대부분 제일 마지막에 넣는다

	que.push(10); // 추가가 곧 "제일 마지막"을 의미하니까 push뒤에 back 조차 생략
	que.push(9);
	que.push(8);
	que.push(7);
	que.push(6);
	que.push(99);
	que.push(100);

	// queue 자료를 뺄 때는 "앞에서부터 뺀다"

	que.pop(); // pop뒤에도 back생략

	// 출력

	std::cout << que.front() << std::endl;
	std::cout << que.front() << std::endl;
	std::cout << que.front() << std::endl;
	
	// -> front 후에 pop을 실행하고 , 다시 그 다음에 front를 실행하면
	
	que.pop();
	std::cout << que.front() << std::endl;
	
	// 삭제 후 큐의 첫데이터는?
	// 벡터였으면 실행도 pop_back 이고 , 결과도 100이 지워졌겠지만
	// 큐의 경우 , pop을 실행하면 제일 먼저 들어간 데이터가 사라진다.

	//큐는 다른 함수도 쓰지만 위에있는 push, pop, front 정도를 제일 많이 쓴다.

	//--------------------------------------


	//큐는 언제 쓰는가? : 데이터 관리 x // 데이터의 기록, 축적, 그리고 대기 o

	//공통점은 이 데이터가 1. 끝까지 그냥 그 자리에 남든가

	//2. 최대한 빨리 선착순으로 해결돼서 나가야 되든가 둘 중 한 경우라는 것

	//----------------------------------------------

	//이렇게 큐가 단순하게 만들어져서 모든 게 해결되면 좋겠지만 

	//간혹 예외가 생긴다. 1. 진짜 급한 최우선 데이터가 갑자기 들어오거나

	// 2. 메모리 공간 화곱를 하다가 데이터 앞뒤로 여유를 두어줘야 할 때
	// (그러면 자연수럽게 데이터 앞에 대한 고려도 하게 된다,


	// 이럴 때 사용할 수 있는 고급 큐가 따로 있다 : 양방향 큐
	// (double ended queue ) 줄이면 dequeue 라고 부른다

	// 발음은 D-Q혹은 덱이라고 한다,

	//-------------------------------

	//디큐 사용해보기

	std::deque<int> dq; //디큐 니까 dq 큐와 마찬가지로 템플릿 지정 필요
						// 철자가 dequeue가 아닌 것에 주의

	//디큐에 데이터 넣기
	dq.push_back(6);	// 데이터 마지막에 (목록 뒤에서 ) 추가
	dq.push_back(7);
	dq.push_back(8);
	dq.push_back(9);
	dq.push_back(10);

	dq.push_front(6); // push + front " 데이터 앞에 추가
			// 큐의 끝이 양쪽에 있어서 앞에서도 뒤에서도 추가가 가능
	dq.push_front(8);
	dq.push_front(9);
	dq.push_front(10);
	dq.push_front(7);



	// 삭제 전에 출력해보기

	for (int i = 0; i < dq.size(); i++)
	{
		std::cout << dq[i] << std::endl;	
											//인덱스 연산자 사용 가능
											//데이터 앞뒤로 공간을 확보하고
											//데이터를 정렬하는 과정에서
											//데이터 위치가 이웃했기 때문
											// 
											// 
											// 
											//

	}

	std::cout << "-------------------"<<std::endl;

	// 디큐에서 데이터 빼기

	dq.pop_back(); // 디큐에서 제일 마지막에 있는 데이터 삭제
	
	dq.pop_front(); // 디큐에서 제일 앞에 있는 데이터 삭제

	// 데이터를 뺀 후 출력

	for (int i = 0; i < dq.size(); i++)
	{
		std::cout << dq[i] << std::endl;

	}

	// -------------------------------


	// 여기까지가 디큐

	//큐나 디큐나 일단은 선착순 실행을 목적으로 만들어

	// 지원하는 함수가 별로 없거나 , 많기는 한데 딱히 많이 쓰지는 않는다

	// (그리고 다행인 일이지만 벡터오 함수 사용이 비슷하기도 하다)

	//-> push , pop ,front 의 사용에 먼저 익숙해지면 된다.(중요)


	//--------------------------------------------------------

	// 샘플 싱글턴 써보기

	//SampleSingleton* newinstance = new SampleSingleton(); // 생성안됨

	//생성자가 prinvate라서 안됨
	//	만든다고 한들 static이라 여기서 만들기 부적절

	

	//-> 싱글턴을 만들기 위해서는 전역변수 위치에 instance가 미리 있어주면 좋다


	//instance = new SampleSingleton(); // 이런식도 불가능


	//-> 싱글턴 호출은 클래스를 통한 Get 함수로 수행

	SampleSingleton::Get(); // 이렇게 부른다

	// 샘플 싱글턴 안에 이쓴ㄴ 데이터 써보기

	std::cout << SampleSingleton::Get()->data << std::endl;

	std::cout<<SampleSingleton::Get()->data << std::endl; //다시 출력

}

