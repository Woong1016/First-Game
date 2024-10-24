
// 전처리기 명령어의 소개

// ....하기 전에 :

// 1. 모든 전처리기는 # 연산자를 붙이고 시작한다
// 2. 모든 전처리기는 (소개에서 밝혔듯) 컴파일 단계에서 수행한다
//    따라서 조건문 등을 지정하는 경우를 제외하면
//    해당 텍스트를 어디에서 작성했는지가 크게 중요하지 않은 경우가 종종 있다

// 그래서 전처리기가 필요한 경우, 조건문 등을 지정하는 경우를 제외하면...
// 모든 코드의 제일 앞에, 제일 바깥에, 제일 먼저 전처리기 코드를 몰아서 써주는
// 경향이 있다.

// 3. 전처리기 코드는 줄 끝에 ; 없다. (있으면 오류) : 처리하는 컴파일러가 다르니까
//    {}로 범위를 지정하는 경우도 많지 않다
//    -> 전처리기 오류가 여기서 나는 경우도 많으므로 주의

//------------------------------------

// 전처리기 명령어 진짜 소개

// 1. pragma : 이어지는 추가 명령어와 합쳐서 컴파일 규칙을 정한다
//    대표적으로 pragma once가 있다 : 중복으로 읽는 헤더가 있으면 1회만 작업

#pragma once

// 2. include : 우리가 그동안 너무나 친숙하게 썼던 전처리기 코드
//              이어지는 파일 이름과 합쳐서 해당 파일을 코드 내용에 포함시킨다
//              "사전 로딩" 정도로 이해해도 좋다

// * include 대상 활용 팁, <> ""의 차이

//   <>는 c++의 내부 기능. c++이 설치된 컴퓨터라면 해당 기능은 있는 걸로 친다
//   특히 윈도우의 경우, 윈도우 폴더 안에 지정하는 이름의 파일이 실제로 있다
//   (대부분 system32, system62)

//   ""는 c++의 기본 내부 기능에는 없었고, 나중에 사용자(프로그래머)가
//   자기 폴더에 (그러니까 지금 여기에) 직접 추가한 파일이라는 뜻.
//   만들었거나, 다른 곳에서 복사해서 폴더에 붙여넣기했거나.

//   -> 그래서 우리가 만든 헤더는 ""로, string, vector 등을 포함할 때는
//      <string> <vector> 등으로 포함했던 것

#include <stdlib.h> // c++이면 어련히 갖고 있을 것 같은 그 기능들
#include "Test.h" // 우리가 만들어서 지금 이 폴더에만 존재하는 파일

// - 그래서 이 코드를 쓸 때는 약간의 주의사항이 포함된다.
// <>로 기능을 넣을 때는 다른 컴퓨터가 같은 버전의 C++을 갖고 있는지 확인 필요
// ""로 기능을 넣을 때는 이 폴더에 있는 파일이 100% 온전하게 공유되도록 조치 필요


// * 본론 *

// 3. define : 흔히 매크로라고 부르는, 코드 텍스트 변환 지시

// -> 이어지는 단어 둘을 연결시켜서, 이후 첫 단어를 입력하면, 두 번째 단어로 바꾼다

#define ARRAY_SIZE 10 // ARRAY_SIZE라는 단어를 10이라는 단어로 바꾼다
                      // 주의 : 코드나 데이터를 바꾸는 게 아니다.
                      //        진짜 텍스트를 바꾸는 것.

// -> 나중에 코드 사용처에서 첫 단어(여기서는 ARRAY_SIZE)를 입력하면
//    실제로 컴퓨터가 컴파일을 할 때는 이 텍스트가 10인 것으로 받아들이게 된다.

#define SUTJA int

// -> 나중에 코드 사용처에서 SUTJA를 입력하면, 컴퓨터는 int로 알아듣는다

// -> 작성한 define, 즉 '매크로'는 메인 함수에서 확인

#define TEST_STRING "안녕하세요, 이재훈입니다!"

// ----------------------------------------------------

// 여기까지가 매크로의 기본적인 설명

// 전처리기의 매크로 명령어에는 한 가지 기능이 더 있다

// 바로 "해당 단어가 선언된 적이 있다는 사실 그 자체"

#define IAMHERE // IAMHERE 뒤에 아무 것도 없음. 따라서 변환불가

// -> 아무 것도 없어서 아무 데도 쓸모가 없는 거 아니냐 싶지만, 그렇지만도 않다

//    바로 이 단어가 존재한다는 사실 자체가 중요하다.

// 이 코드를 내가 적음으로 인해, 지금 이 파일은 컴파일 중에

// 이후 IAMHERE라는 단어를 또 보게 되면 반드시 그에 반응을 할 것.


// 4. if / ifdef / elif / endif : 전처리 조건문
//    + ifndef / undef / else

// 전처리기에서 판단하고, 전처리기 단계에서 조절하는 조건문.

// 해당 조건이 맞으면 밑에 있는 코드를 수행

// 그렇지 못하면 아예 텍스트를 빼버린다.

// 일반 조건문과 추가로 다른 점은 전처리 단계에서 실행하므로

// 매크로를 감지할 수 있다. 그리고 보통은 매크로로 연산을 해줘야 한다.

// 그래서 전처리 조건문에 사용하기 위한 매크로를 몇 가지 추가로 작성

#define CONDITION_A 10
#define CONDITION_B 20

// -> 메인 함수에서 사용