// SGA_240911_Pair_and_Map.cpp

#include <iostream>

#include "GlobalData.h"     // 전역 변수 (+함수)
#include "ListController.h" // 리스트 관리 클래스
#include "SampleStaticClass.h" // 엩. 이건 뭐죠???
//----------------------------------------------

// 오늘의 과제 : 맵 써보기

// 1. int와 string으로 구성된 맵 변수를 만들어주세요.

// 2. 맵에 여러분들이 좋아하는 단어를 순서대로 번호를 매겨서 맵에 넣어주세요.

// 3. 숫자만 넣으면 자동으로 단어가 출력되는 함수를 작성한 다음 호출해주세요.

// 4 . (옵션) 단어를 입력하면 (단어만 입력해도) 자동으로 맵에 단어가 등록되는
//            함수도 만들어주세요. 이 때 키 값은 선착순으로 들어가야 할 겁니다.
//            static을 쓰면 편할 수 있지만, 쓰지 않으셔도 괜찮습니다!





// static은 나중이 되면 싫어도 실습을 하게 될 겁니다. 지금은 괜찮습니다.



//----------------------------------------------
#include "StaticStudy.h" // 정적 데이터 호출 헤더

#include <stdlib.h> // C++ 표준 기능
#include <map>      // 'map' 기능

int main()
{
    // Homework(); // 과제 풀이 및 오늘의 고민거리 확인
                   // (자세한 내용은 함수 정의에서 보세요)
    //----------------------------------------------

    // 오늘의 진도 : 고민거리를 뒤에서부터 하나씩

    // 1. static 지시 : 정적 선언.
    //    정적 선언으로 변수를 만들면 정적 변수라고 지칭
    //                 함수를 만들면 정적 함수라고 지칭

    // -> 데이터를 만든 후, 해당 위치까지를 컴퓨터한테 정확하게 지시하는 것.
    //    그래서 "정적" 선언 (static : 정확한, 움직이지 않는, 못박힌)

    // -> "데이터의 위치까지 지시한다"는 말은 무슨 의미인가?
    //    컴퓨터가 데이터의 이름, 만들어진 곳, 거기에 있는 데이터까지를
    //    전부 합쳐서 완전히 한 세트로 판단한다는 뜻. 쉽게 풀어서 해설하면...
    
    //    (기술적으론 조금 다르지만, 개념에선) 해당 데이터를 *유일무이*한 걸로
    //    판단하게 만든다는 뜻.

    // static으로 만들어진 데이터는 그래서....

    // -> (1) 원래라면 없어졌어야 할 때가 되어도 (용도가 다 된다든가,
    //        지역변수인데 함수가 끝났다든가) 데이터가 그 자리에 그대로 남는다

    // -> (2) 복제 불가 -> 클래스 안이라든가, 함수 안이라든가 하는 위치에 따라
    //        여러 지역 변수, 멤버 변수가 있을 법한 상황이 되더라도
    //        static으로 지시된 데이터라면 오직 하나만 존재한다.

    // -> (3) 유일무이하기 때문에, 역설적으로 자료형(혹은 구조체, 혹은 클래스)
    //        ... 등을 실제로 구현할 인스턴스나 변수가 없어도 (객체가 없어도)
    //        자료형, 혹은 참조 가능한 코드만 있으면 호출할 수가 있다!
    //        클래스명으로 인스턴스 생성 후, 인스턴스에서 데이터 호출 x
    //        그냥 클래스명에서 곧바로 데이터 호출 o


    // * 직접 써보기 위해서 파일과 데이터 생성 후에 main에서 호출

    //동적 변수를 쓴 함수 시험하기
    DynamicVarTest();
    DynamicVarTest(); // 2번 실행하면 결과는?

    // 결과 : 2번 다 1부터 10까지 출력
    // 이유 : 각 함수가 실행될 때마다 별도의 공간에서 별도의 변수가 만들어지고,
    //        만들어질 때마다 변수는 코드에 의해 0으로 초기화되기 때문.

    // 정적 변수를 쓴 함수를 시험하기

    StaticVarTest();
    StaticVarTest(); // 2번째 실행 때 결과 주목

    // 결과 : 2번째에서 11부터 20까지 출력
    // 이유 : 첫 함수가 실행될 때, static으로 지시된 데이터가 만들어지고,
    //        컴퓨터가 그 데이터, 이름, 위치까지 완전히 각인을 한 것
    //        두 번째로 함수가 실행됐을 때, 이미 정해진 곳에 데이터가 만들어져 있어서
    //        컴퓨터는 더 이상 (굳이) 데이터를 만들지 않고, 대신 이미 있는 데이터를
    //        이어받아서 계속 쓴 것. 그 때문에 초기화가 일어나지 않고 (생략)
    //        첫 함수 연산 때 정해진 10이라는 데이터 값이 계속 연산에 활용된 것.

    // static을 함수나 클래스에 쓸 경우

    //StaticClass sc; // 만들 때 문제 없음. -> 실행할 때 문제
                     // 참조 대상이 유일한데, 인스턴스를 이렇게 만든다는 건
                    // 마치 복제 데이터가 존재할 수 있다는 식으로 이해될 수 있어서
                    // static을 이용해서 인스턴스 역시 정적으로 만들거나...
                    // 아예 안 만들거나 해야 한다
                    // * 정적 선언된 클래스를 만들면 이 인스턴스는 앱하고 같이 종료
                    //   (지역변수처럼 만들어도, 변수와 마찬가지로, 계속 남는다)

    // SampleA::Print(); // 정적으로 만든 함수는 (참조 대상이 유일하니까)
                      // 객체가 없어도 곧장 호출 가능

                      // 위의 정적 클래스(StaticClass)와 같이 생각하면
                      // static 클래스는 안에 있는 데이터들도 모두 static이어야 한다는 뜻
                      // 그렇게 코딩한 후, 객체 없이 사용

    // SampleB* sb = new SampleB();
    // 이 인스턴스를 만들면 자동으로 샘플A 클래스의 정적 객체 생성

    // sb->data.value = 100; // 값 넣어주기

    //이어서...
    // SampleB* sb2 = new SampleB(); // 샘플B의 인스턴스 하나 더
    
    // std::cout << sb2->data.value << std::endl;

    // -------------------------------------------------------------

    // 진도 2. 데이터의 한 쌍 다루기

    // 지금까지 데이터는 한 이름에 한 데이터
    // -> 한 이름에 두 데이터를 다루기
    // "페어"라고 한다

    // 페어의 기본 작성 방법
    std::pair<char, int> dict = { 'a', 10 };

    // 벡터와 마찬가지로 pair 뒤에 <>를 넣어서, 어떤 두 자료형을 한 세트로 구성할지
    // 정확히 정해줘야 한다.

    // 변수명 뒤에는 {}로 묶어서 각 자료형에 대응하는 두 데이터를 입력한다

    // 출력
    //std::cout << dict << std::endl; // 이거 안됨. -> 데이터의 집합이니까 (구조체와 유사)

    // 출력 (진짜) : 변수의 각 데이터 부분을 따로 지칭을 한 번 더 해줘야 한다
    std::cout << dict.first << std::endl; // 페어의 첫 번째 자료형
    std::cout << dict.second << std::endl; // 페어의 두 번째 자료형

    // 여기서 first, second를 프로그래밍에서 이론적으로 지칭하는 이름이 존재한다
    // first에 해당하는 -> 또 다른 이름과도 같은 데이터를 '키(key, 고유값)'라고 한다
    // second에 해당하는 -> 실질 데이터에 해당하는 부분을 '밸류(value, 값)'라고 한다

    // ...key가 이렇게 이름을 담당할 거면 그냥 변수 이름 써도 되지 않나?

    // 변수의 이름(+메모리 주소)이 의미를 가지는 건 앱을 실행하는 컴퓨터에게뿐.
    // -> 앱을 사용하는 최종 사용자(게임이면 플레이어)라든가, 다른 앱(게임이면 서버)
    //    입장에서는 외부에서 해당 데이터가 어떻게 구분되는지 모른다
    //    외부에서 봤을 때도 데이터에 해당하는 의미 구분을 알기 위해서
    //    구분용 데이터를 추가하는 것 : 그게 페어의 존재 목적

    // 그래서 C++의 페어를 다른 언어에서는 '항목'으로 지칭하기도 한다

    //---------------------------------------------------------------

    // 데이터 둘을 한 세트로 묶은 것이 페어라면, 페어를 묶은 것은 무엇인가?

    // -> 도표(map)이다. 언어에 따라서는 사전(딕셔너리)이라고도 한다

    // 맵(map) 작성 방법

    std::map<int, char> testMap; // <>로 어떤 두 자료형의 조합인지 지정 필수

    // 맵의 특징 : 페어를 묶은 것 = 여러 데이터의 집합 = 이것도 자료 구조
    //            기본 사용 방법이나 개념은 다른 자료구조와 유사

    // 다만.....
    // testMap.push_back() // 리스트와 다르게, 맵은 push, pop이 없다

    // 왜냐면 "차례"가 존재하는 벡터, 리스트와 다르게
    // 맵은 그냥 페어를 모아놓은 것뿐이라서 (=직선으로 만든 표가 아니라 '도표')

    // 맵에서는 그래서 insert를 바로 쓴다
    std::pair<int, char> pair1 = { 1, 'a' }; // 맵의 항목이 될 수 있는 페어
    testMap.insert(pair1); // insert로 맵에 데이터를 추가

    std::pair<int, char> pair2 = { 2, 'b' };
    std::pair<int, char> pair3 = { 3, 'c' };
    std::pair<int, char> pair4 = { 3, 'd' };
    std::pair<int, char> pair5 = { 5, 'e' };

    testMap.insert(pair2);
    testMap.insert(pair3);
    testMap.insert(pair4);
    testMap.insert(pair5);

    //비교용
    std::pair<int, char> pair6 = { 6, 'e' };
    testMap.insert(pair6);

    // 비교용 2
    std::pair<int, char> pair7 = { 9, 'x' }; // 키가 9
    testMap.insert(pair7);
    std::pair<int, char> pair8 = { 8, 'y' }; // 키가 8
    testMap.insert(pair8);
    std::pair<int, char> pair9 = { 0, 'z' }; // 키는 0
    testMap.insert(pair9);

    // 출력
    for (int i = 0; i < testMap.size(); i++)
    {
        std::cout << testMap[i] << std::endl; // "들어가 있는" 순서는 호출 가능
                                              // []는 사용가능
                                              // * map에서는 의미가 약간 다르긴 하다
    }
    // 출력 결과 확인 후 알 수 있는 것
    
    // 1. insert를 쓰면 맵에 원소를 쉽게 넣을 수 있다
    // 2. map에 들어가는 원소끼리는 first의 중복을 허용하지 않는다
    // 3. 중복이 일어날 경우, 나중에 들어가는 값이 무시된다
    // 4. second는 중복이 일어나도 괜찮다
    // 5. 왜 push, pop은 안 되는데 순서를 지칭하는 []는 되는가???
    //    -> 먼저, map의 특성을 다시 살펴보면 데이터가 선착순으로 들어가지 않는다
    //    -> 더 중요한 것, []는 사실 순서의 의미가 아니다. map에서 쓰이는 []는 예외
    //       map의 []는 무엇인가? 인덱스 연산자가 아니라, "질의문"
    //       구체적으로는 "이 키에 해당하는 밸류가 있습니까?"라는 질문을 하는 것에 가깝다
    //       map에 해당 데이터가 있으면 맞는 연산을 하고, 없으면 "아무 것도 없다"를 출력한다.
    
    //       결과적으로 보자면, 키가 정수인 맵에서, 반복문을 통한 일괄연산을 한다고 했을 때
    //       맵은 사실상 자동 정렬을 스스로 해주는 것이나 다름없는 결과를 보여준다
    //       (넣는 순서가 12345 9876 이었어도 출력을 시키면 12345 6789 이렇게 해준다)

    //       더 간단하게 : 맵은 자동 정렬을 해준다!

    // 나중에 우리가 "1번 데이터는 이거, 2번 데이터는 저거...." 같은 식으로
    //  데이터를 구성하거나....

    // 혹은 문자를 문자열로 조합해서 "앞 아래 대각선 아래 손"이런 기호로 만들었다고 하면
    // 이에 맞는 데이터를 쌍으로 묶어서 맵에 넣어주고
    // 나중에는 키 값만 가지고 실제 데이터를 (예 : 아도겐) 찾아서 호출해줄 수 있다

}





//--------------------------------------
// 전역 헤더에서 만든 함수를 여기서 정의

void Homework() // 과제 풀이 함수
{
    // 전역변수 "homeworkList" 활용

    // 과제 풀이 예시 (1)
    ReadyList();
    ShowList();

    AddIntToList(3, 333);
    ShowList();

    RemoveIntFromList(3);
    ShowList();

    // 과제 풀이 예시 (2)
    ListController* listControl = new ListController();
    listControl->AddElementInt(&homeworkList, 5, 5555);
    ShowList();

    listControl->RemoveElementInt(&homeworkList, 5);
    ShowList();

    // 과제 풀이.......예?제 (3)

    SampleStaticClass::AddElementInt(&homeworkList, 7, 77777);
    //...이게 뭐지? 객체 선언은 어디다 두고 왜 함수부터???
    ShowList(); // ...이게 외 됌?

    SampleStaticClass::RemoveElementInt(&homeworkList, 7);
    //??????????
    ShowList(); // ...왜 되는 거임?

    //SampleStaticClass* sam = new SampleStaticClass();
    //sam->AddElementInt(&homeworkList, 8, 888888); // 왜 이렇게 안 했을까?

    //-------------------------------------------------------

    // 과제 풀이를 통한... 오늘의 고민거리 둘

    // 1. 리스트 관리 함수를 만들어보니... 꼭 리스트만이 아니라도
    // "특정 인덱스에 나머지 데이터"로 정의되는 데이터 한 쌍의 형태가
    // 생각보다 공식화시키면 쓸 데가 많은 것 같네??

    // 2. 방금 위에 저거 뭐임? 객체 선언은 어디다 팔아먹었음?
    //    클래스 헤더에 있는 static은 또 뭐임?

    // ........에 대한 이야기를 이어가고자 합니다.

    //-------------------------------------------------------
}

void ReadyList()
{
    homeworkList.push_back(1);
    homeworkList.push_back(2);
    homeworkList.push_back(3);
    homeworkList.push_back(4);
    homeworkList.push_back(5);
    homeworkList.push_back(6);
    homeworkList.push_back(7);
    homeworkList.push_back(8);
    homeworkList.push_back(9);
    homeworkList.push_back(10);
}

void ShowList()
{
    std::cout << "------------------------" << std::endl;
    std::list<int>::iterator iter = homeworkList.begin();
    for (iter; iter != homeworkList.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }
    std::cout << "------------------------" << std::endl;
}

void AddIntToList(int index, int value)
{
    //반복자 준비
    std::list<int>::iterator iter = homeworkList.begin();

    for (int i = 0; i < index; i++) // 정수 i를 매개변수 index만큼 돌린다
    {
        iter++; //반복문의 목적은 바로 iter의 차례 진행.
    }
    // -> 이 반복문이 끝났을 때, iter가 시작 데이터로부터 index 칸만큼 진행한다.

    // 그 위치에 값을 넣으면 된다

    homeworkList.emplace(iter, value);
    //homeworkList.insert(iter, value); // 이래도 된다
}

void RemoveIntFromList(int index)
{
    std::list<int>::iterator iter = homeworkList.begin();
    for (int i = 0; i < index; i++, iter++)
    {
        // 반복 시의 변화를 2개 이상 적어도 된다
        // (매개변수나 멤버 이니셜라이저처럼 , 표시로 개별 연산 구분
    }

    homeworkList.erase(iter);
}