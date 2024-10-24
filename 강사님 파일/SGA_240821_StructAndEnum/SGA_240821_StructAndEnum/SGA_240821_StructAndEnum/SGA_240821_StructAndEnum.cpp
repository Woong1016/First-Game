﻿#include <iostream>
#include "Header.h" // 사용자 헤더 사용

// 오늘의 진도 : "사용자가 정의한 자료의 집합"에 대해
//              (user defined aggregate of data types)

// * 여기서 '사용자'란 바로 프로그래머 = 언어 사용자를 지칭



// 오늘의 과제 : 구조체 (어쩌면 열거형도) 써보기

// 여러분들이 인상깊게 했던 게임을 떠올려주세요.

// 해당 게임에 등장하는 등장인물들을 묘사하기 위한 데이터가 어떤 게 있는지 확인해주세요.

// 해당 데이터를 이용해서 먼저 구조체를 만들고, 해당 구조체를 사용해서....

// 1. (필수) 같은 구조체를 사용한, 별개의 게임 속 캐릭터 3명 이상을 출력해주세요.
//    예 : 롤이나 이터널 리턴 등 MOBA 게임의 캐릭터 스탯, 혹은
//         다크 소울이나 몬스터 헌터 등에 나오는 보스의 스탯 등
//         (캐릭터가 '사람'이 아니어도 됩니다. 건랜스 스탯 등이어도 가능)

// 2. (옵션) 해당 캐릭터의 정보 중에 진영, 소속, 기타 '열거 가능한 정보'가 있을 경우
//           열거형도 같이 만들어서 써주세요.

// * 주의사항. 캐릭터 3명 만든다고 구조체 3개 만들면 안 됩니다.

// * 복습 : char 변수명[글자수+1] 선언으로 글자를 만들 수 있습니다.
//          또한 char에도 포인터가 있습니다. (응용해보세요)



int main()
{
    // "사용자가 정의한 자료의 집합"이란?

    // -> 현실이든, 앱이든, 게임이든, 한 대상이 하나의 자료로만 이루어지진 않기에

    // 때로는 여러 자료를 나열한 다음 해당 자료의 총 집합으로서 대상을 묘사해야

    // 할 수도 있다. 그리고 이 개념을 지원하기 위한 프로그래밍 문법의 총칭이

    // 바로 "사용자가 정의한 자료의 집합"이다.

    // -> 다른 말로, "변수를 모아서 새로운 이름의 집합으로 만들고 명명하는 것."

    // --------------------------------------------------------------

    // 그리고 자료 집합의 기본이자, 첫 번째이자, 가장 대표적인 것

    // -> 배열 : 이미 우리가 아는 그것.

    // 또 배열에 이어서, 배열과는 다른 형태를 구현하기 위한 문법도 있다.
    // (배열은 모든 원소가 자료형이 똑같은데, 실제로는 세부 자료형이 달라야 할 수도 있다)

    // (예 : 롤 챔피언 = 이름 + 진영 + 역할 + 체력 + 체력 재생....기타등등)

    // 이렇게 서로 다른 자료형을 묶어서 집합으로 만드는 것 중

    // 가장 대표적인 문법 : "구조체" (struct)

    //-------------------------------------------

    // 구조체

    // 구조체의 기본 구조 : 'A라는 구조체 = int 변수, float 변수 등등...의 합'

    // 기본 코드 형태는 아래와 같다

    struct MyStruct // struct : 이 데이터가 구조체임을 나타내는 지시어
                    // MyStruct : 구조체의 이름
    {               // 구조체는 { 로 작성 시작, }로 작성 종료, ; 필수
        
        // 이 안에 변수들을 넣는다

        int number; // MyStruct라는 구조체 안에는 number라는 이름의 숫자가
                    // 있을 거라고 설정을 해둔다 (값은 아직 모른다)

        float pointNumber; // 소수도 있다고 설정을 해둔다.

        bool trueOrFalse; // 참이냐 거짓이냐를 구분하는 변수도 있다고 해둔다.

        // 이 밖에 필요한 무엇이든 여기서 적으면 '구조체의 구성요소'인 걸로 친다

        // 이렇게 여기서 만들어진 구조체의 세부 구성요소를

        // '구성요소'(member, 멤버) 혹은 자료행(field, 필드)이라고 한다.
    };

    // 그리고 구조체는 여러 개를 마음대로 만들 수도 있다

    struct OtherStruct // 또 다른 구조체
    {
        int number; // 다른 구조체를 위한 멤버
                    // 서로 다른 구조체에 속했기 때문에
                    // 위에 쓰인 멤버와 철자가 같아도 된다 (중복 안됨)
                    // (물론 여기서는 중복하면 안됨)
    };

    // 이렇게 만든 구조체를 사용하는 법

    // 구조체도 사실 자료형을 한데 묶어서 새로운 이름을 붙인 것.
    // -> 해당 이름을 사용하면 마치 새로운 자료형이 있는 것처럼 쓸 수 있다
    //    그래서 이 부분을 곡해하면 "구조체 = 사용자 정의 자료형"으로 이해하기도

    // 어쨌든, 쓰는 입장에선 자료형을 쓰는 것과 크게 다르지 않다

    MyStruct instance; // 실제 구조체 사용
    // MyStruct : 위에서 만들었던 구조체의 이름...을 마치 자료형인 것처럼 쓴 것
    // instance : 구조체라는 '자료형 같은 것'을 원형으로 한 진짜 데이터 (실질사례)

    // 말하자면
    // 1. 먼저 자료형을 모아 구조체를 만든다 (이건 아직 변수 아님)
    
    // 2. 1.에서 만든 구조체를 이용해 '변수'를 선언한다 (이쪽이 구조체 변수)
    //    이렇게 구조체로부터 만들어진 진짜 데이터, 진짜 변수를 '인스턴스'라고 한다

    // 3. 만든 인스턴스의 내부에 있는 세부 변수 항목을 설정하면 끝

    instance.number = 10; // 위 구조체 {} 안에서 설정했던 number의 값 할당
    instance.pointNumber = 200.0f;  // 여기서 쓰인 . 기호 : 접근 연산자
    instance.trueOrFalse = true;    // -> 데이터 안에 세부 항목이 있을 경우 호출

    // 구조체 사용의 특징 겸 논리적 도출 가능한 특성

    //변수의 경우 다음 논리가 성립한다
    int a = 100;    // 이런 정수가 있고
    int b = 200;    // 이런 정수도 있다면 이 두 코드는...말이 된다
                    // -> 이 둘은 형식(int)는 공유했지만 실제 내용은 공유 x

    // 구조체도 마찬가지다 (=쓰는 입장에선 자료형과 다를 것이 별로 없다)
    
    MyStruct instance2; // 같은 구조체로, 다른 변수를 만든다면

    instance2.number = 22;          // 다른 세부항목을 줄 수도 있다
    instance2.pointNumber = 333.3f;
    instance2.trueOrFalse = false;

    // 왜? instance와 instance2는 형식만 같지, 실제 내용은 전혀 다른
    // 별개의 변수이므로.

    // 확인
    std::cout << instance.number << std::endl; // '인스턴스' 숫자 출력
                                               // 구조체 속 세부항목도 출력대상 가능
    std::cout << instance2.number << std::endl; // 인스턴스2 숫자 출력

    // 이런 인스턴스는 구조체를 이용해 필요할 때마다
    // 별개의 변수(구조체 변수)를 작성함으로써
    // 각 데이터를 독립적으로 유지하는 데에 유용하다

    // 사례 : 온라인 게임의 인스턴스 던전 (그 인스턴스가 이 인스턴스)

    //----------------------------------

    // 구조체의 (쉽게 짐작 가능한) 응용

    struct BigStruct // 구조체가 있으면
    {
        int number; // 일반 변수도 쓸 수 있는데
        
        OtherStruct smallStruct; // 다른 구조체가 먼저 만들어진 게 있다면
                                 // 그 구조체도 멤버로 쓸 수 있다.

        // 그래서 이 아래로 BigStruct 형식으로 선언된 변수가 있다면
        // 그 변수 안에는 smallStruct라는 이름의, OtherStruct 형식 구조체가
        // 또 들어있는 것
    };

    // 실제로 써보기

    BigStruct bigStruct; // 큰 구조체 선언

    bigStruct.number = 1000; // 큰 구조체 안에 있던 숫자 할당

    bigStruct.smallStruct.number = 77777; // 큰 구조체 속, 작은 구조체에 있던
                                          // 해당 구조의 멤버도 할당

    std::cout << bigStruct.number << std::endl;
    std::cout << bigStruct.smallStruct.number << std::endl;


    // 그리고 구조체도 자료형의 집합으로서, 쓰는 입장에선 자료형과 거의 같다...
    // -> 구조체 변수 역시, 지역 변수와 전역 변수로 만들 수 있다

    // -> 혹시 main() 바깥, 혹은 헤더에서 구조체가 만들어졌을 경우
    //    해당 구조체 형식을 쓰는 구조체 변수를 여기서 또 만들 수 있다

    // -> 확인하기 위해, 헤더에서 구조체를 작성한 후, 여기서 사용

    // 헤더에서 작성해둔 구조체로 구조체 변수 선언

    Champion Garen;         // 뚜벅이
    Champion Sylas;         // 짤랑이

    // 해당 변수의 세부 사항을 할당할 수 있다

    Garen.hitPoint = 690;
    Garen.hitPointRestore = 8;
    Garen.atk = 69;
    Garen.atkSpeed = 0.625f;
    Garen.def = 38;
    Garen.res = 32;
    Garen.range = 175;
    Garen.moveSpeed = 340;

    Sylas.hitPoint = 600;
    Sylas.hitPointRestore = 9;
    Sylas.atk = 61;
    Sylas.atkSpeed = 0.645f;
    Sylas.def = 29;
    Sylas.res = 32;
    Sylas.range = 175;
    Sylas.moveSpeed = 340;

    // 이렇게 두 구조체 변수(인스턴스)에 각각 일부는 같고, 일부는 다른 데이터를 줘서
    // 독립된 세부 항목을 갖춘 두 챔피언을 묘사할 수 있다

    // -> 더불어서 전역 변수 자리에 선언된 구조체를 형식으로 쓸 수 있음을 확인

    // =====================================================

    // 구조체를 사용할 때, 기본적으로 권하지 않는 사용례
    // + 꼭 필요한 때에 한해서 고급 코딩으로 쓰는 예시

    struct AdvStruct
    {
        int number = 100; // 가능. 권장은 아님.
    };

    AdvStruct adv; // 구조체가 만들어지는 순간
    std::cout << adv.number << std::endl; // 값이 무조건 정해져서

    // 나도 모르게 구조체의 값을 미리 줌으로써 의도치 않은 데이터를 만들 수도 있다

    // -> 다만 언급했듯 필요한 경우에는 고급 코딩으로 이런 코딩을 쓰기도 한다

    // 요약 : 구조체를 만들 때는 가능하면 미리 값을 준비하지 말 것
    //        구조체를 만들고, 그 다음에 제대로 데이터를 할당할 것

    // * 이렇게 데이터 위주, 그리고 최소한의 형식 설계로만 이루어진 구조체를
    //   고전적 구조체라고 한다 (classic struct, 혹은 plane old data)

    // * AdvStruct는 POD 아님. 나머지 우리가 위에서 만든 구조체가 POD인 것

    // 이것 말고도 구조체의 형태는 여러 가지가 있다 (단 오늘은 여기까지만)

    // ====================================================

    // 구조체가 이렇게 고전적 데이터 집합으로만 쓰일 때 맞닥뜨리는 좋은 점과
    // 나쁜 점이 있다. 좋은 점은 "보면 알기 쉽다"는 것이고....

    // 나쁜 점으로는 아래와 같은 사례의 발생 가능성이 있다는 것.

    struct DangerousStruct
    {
        const int id; // id를 상수로 여기서 만들면?

        // 이거 된다. 오류 안 난다.
        // 왜냐면 지금 이 코드는 어디까지나 설계일 뿐이니까.
    };

    // 하지만 위 구조체를 써서 구조체 변수로 만들 때, 문제가 생긴다

    //DangerousStruct ds; // <- 당장 이 때부터 오류
    //ds.id = 1000;       // <- 당연히 이것 또한 오류

    // 그런데 게임 속 인물처럼 id가 꼭 있어야 하는 경우도 분명히 있는데???

    // -> 이 때 이 난제를 해결할 방법이 몇 가지가 있다. 그 중, 가장 원론적인 것이
    //    바로 상수 포인터.

    struct ConStruct
    {
        int var00000; // 숨기는 데이터
        const int* id; // 이쪽을 'id'로 제작
    };

    ConStruct cs;
    cs.var00000 = 0; // 의문의 원소에 값을 조용히 주고
    cs.id = &cs.var00000; // cs의 id가 cs의 멤버 00000을 참조하도록

    // *cs.id = 1000; // 수정을 방지 가능

    //================================================================

    // 여기까지 구조체

    //================================================================



    // 이어서 사용자 정의 자료 집합의 또 다른 형태

    // 개발이 진행되면 여러 독립적인 개별 사례가 동일 범주에 들어갈 수도 있다
    // (예 : 국가의 이름, 소속 진영, 사람의 성별, 가위바위보의 경우의 수 등)

    // 여기에 개별로 수치를 부여할 수도 있지만 (0이면 가위, 1이면 바위, 2면 보)
    // 반대로 코드를 이름으로 명명할 수도 있다 ("가위"라고 불러서 0이라는 숫자 호출)

    // 이렇게 의미와 숫자를 결부시켜서 하나의 대응으로 만드는 것,
    // 혹은 이름으로 숫자를 부르는 것을 '수치화, 혹은 열거(enumeration)'라고 한다

    // (변수를 따로 생성하는 것이 아니라, 아예 이름에 숫자를 붙이는 것임에 주목)

    // C++에서 이렇게 열거를 구현하는 것을 열거형이라고 하며 (enumerator)

    // 열거형 역시 일종의 자료의 집합인 것처럼 설정 가능하다

    // 사용 예시 : 색깔의 이름에 수치 부여하기

    enum COLOR // enum : 열거형 지시, COLOR : 열거형의 이름 (구분 위해 보통 대문자)
    {
        COLOR_WHITE,
        COLOR_BLACK,
        COLOR_RED,
        COLOR_GREEN,
        COLOR_BLUE

        // 이렇게만 적어도 열거형이 된다.
        // 각각의 이름은 그 자체가 의미를 가진 이름으로 인정되고,
        // 해당 이름이 적힌 순서대로 순번에 해당하는 숫자를 부여받는다
        // * COLOR_WHITE가 0인 걸로 치고, 그 뒤부터 +1
    };

    // 열거형 실제로 써보기

    // 열거형은 작성됐을 때, 이미 이름에 숫자가 붙은 것
    // 따라서 따로 무슨 선언을 더 할 필요가 없다. 그냥 이름이 곧 숫자

    // 그래서 열거형에서 적었던 이름을 그대로 적으면 출력은 숫자인 것처럼 취급
    std::cout << COLOR_WHITE << std::endl; // 나는 하얀색이라고 했지만 0이 출력
    std::cout << COLOR_BLACK << std::endl; // 1
    std::cout << COLOR_RED << std::endl;   // 2
    std::cout << COLOR_GREEN << std::endl; // 3
    std::cout << COLOR_BLUE << std::endl;  // 4

    // 더불어서 열거형에 숫자를 직접 부여하고 싶은 경우
    // (의미에 해당하는 별개의 숫자가 있는 경우) 수동 할당 가능

    enum POSTNO // 우편번호
    {
        SEOUL = 1000, // 서울의 우편번호는 1000이라고 치고 (줄은 ,로 마무리)
        INCHEON,      // 인천은 값을 미리 주지 않고, 컴퓨터가 알아서 주게 한다
        BUSAN = 44972, // 부산은 44972라고 치면
        GIJANG,

        JEJU = 999, // 제주 999 (가상의 우편번호)
        DOKDO,      // 독도...는 자동 순번 받기
    };

    //우편번호를 출력했을 때 결과
    std::cout << SEOUL << std::endl;
    std::cout << BUSAN << std::endl;

    // 직접 값을 지정하지 않은 경우
    std::cout << INCHEON << std::endl;
    std::cout << GIJANG << std::endl;

    // -> 열거형에 값을 직접 준 항목과 안 준 항목이 있을 경우,
    //    값을 안 준 항목은 바로 앞 순번 항목이 가졌던 숫자에서 +1을 한다

    // ...어 그러면 숫자가 중복될 수도 있겠는데?

    std::cout << DOKDO << std::endl; // 나오긴 하지만, 서울과 구분 불가
                                     // -> 중복에 주의!!!

    // -------------------------------------

    // 열거형도 당연히 전역변수로서 작성 가능

    std::cout << JUNIOR << std::endl;
    std::cout << SENIOR << std::endl;

    // ----------------------------------------


    // 여기까지 열거형

    // 구조체, 열거형까지가 사용자 자료 집합의 기초 형태

    // -> 이 기초적인 자료 집합에서 기능을 덧붙이고...

    // 쓸 수 있는 자료의 범위를 늘려주면....

    // 이제 프로그래밍은 단순한 계산이 아니라 개념의 대상화가 가능해진다.

    // 구조체와 열거형은 변수를 하나로 묶어서 독립된 개념으로 표현하는 첫걸음!

    // 코드도 코드인데 주석을 위주로 한 배경에 더욱 집중해주세요

    // -> 그리고 배경이 익숙해지면 코드도 직접 써봅시다.
}