#pragma once

// 우리가 만든 네임스페이스 헤더

//네임스페이스 작성
namespace CustomNamespace1
{
    //네임스페이스 속에 함수 작성하기

    int Operation(int x, int y) // "계산"이라는 이름의 함수
    {
        return x + y;
    }

    // 여기 작성된 함수는 CustomNamespace1 이 이름 속에 포함된다

    // 작성하는 함수는 얼마든지 추가 가능 (이 안에서만 중복 없으면 OK)

    int Mult(int x, int y)
    {
        return x * y;
    }

} // ; 불필요

// 다른 이름의 네임스페이스 작성
namespace CustomNamespace2
{
    int Operation(int x, int y) // 위와 똑같은 이름의 함수
    {
        return x - y;
    }
}