/*


** 주의!!
* 
* 클래스를 만들 때, static으로 선언한 데이터, 특히 변수는
* 
* .cpp 파일에서 작성, 수정하면 안 됩니다!
* 
* 이유 1. : 다른 파일에서 읽을 때마다 .cpp 파일을 재로딩하면서
*           새로운 값으로 재정의될 위험이 있기 때문이라고 합니다.
*           (다만 시간이 흐르면서 이 문제가 고쳐짐)
* 
* 이유 2. : ....그냥요 ㅠㅠ 아무튼 안 됩니다.
* 

따라서 아래 모든 코드는 주석으로 처리합니다.
상세 코드 전문이 헤더에 있으므로 참조해주세요.

#include "SampleSingleton.h"


SampleSingleton* SampleSingleton::Get()
{
    // 이 클래스의 유일무이한 데이터를 밖에서 호출하게 해주는 함수
    // 해당 데이터의 이름은 헤더에서 확인 : 여기서는 instance

    // 먼저 instance가 있는지 없는지부터 확인
    if (instance == nullptr) // nullptr : '포인터가 없거나, 데이터가 포인터로 인정되지 않음'
                             // 즉 instance가 nullptr : 아직 지정값이 없다
                             // 따라서 아직 instance가 없다
    {
        // instance가 존재하지 않는다면 -> 새로 하나 만든다.
        instance = new SampleSingleton(); // 인수를 하나 주고 생성
    }

    // instance가 없었다면 윗줄에서 만들어졌을 것.
    // instance가 있다면 static으로 확고하게, 유일하게 존재할 것

    // 그러므로 그 데이터를 반환하면 된다
    return instance;
}

void SampleSingleton::Delete()
{
    // 소멸자를 밖에서 부르거나 관리하지 못하니까
    // 밖에서 이 데이터를 지워달라고 요청할 수 있도록

    delete instance; // delete : 지시어 중 하나. 용어로 표현하면 '포인터의 할당 권한을 반환'
                     // 정확히는 "이 메모리는 이제 주인이 없으니까 맘대로 쓰세요"
                     // 그래서 데이터는 남기도, 안 남기도 하지만, 컴퓨터는 언제든 이 주소에
                     // 필요하면 다른 데이터를 쓸 수 있다.

    instance = nullptr; // 이 변수 값도 이제 포인터가 아니라고 지정

    // 이러면 클래스가 스스로 소멸자를 부르지 않아도,
    // 외부에서 클래스를 바로 지우지 못해도,
    // instance 데이터는 지울 수가 있다.
}

SampleSingleton::SampleSingleton()
{
    // 인스턴스의 진짜 생성자
    // 오직 인스턴스가 존재하지 않았을 때, Get 함수에 의해서만 호출

    data = 0;
}

SampleSingleton::~SampleSingleton()
{
    // 앱이 끝나서 이 클래스의 객체가 완전 소멸할 때 수행할 일
    // 지금은 적지 않는다.
}

*/