#pragma once

namespace CustomNameSpace1
{

	//네임 스페이스 속에 함수 작성하기
	int Operation(int x, int y) // 계산이라는 이름의 함수
	{
		return x + y;
	}
	//작성된 함수는 CustomNameSpace1이 이름속에 포함된다
	int Mult(int x, int y) // 계산이라는 이름의 함수
	{
		return x + y;
	}
}// ; 불필요


namespace CustomNameSpace2

{
	int Operation(int x, int y) // 위와 똑같은 이름의 함수
	{

		return x - y;
	}

	// 여기 작성된 함수는 CustomBNamespace1이 이름속에 포함된다
	//작성하는 함수는 얼마든지 추가 가능
	
}


