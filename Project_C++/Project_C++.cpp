// C++ 로 떠나는 모험.
//
// C++ 의 역사: 1980 에 ms에서 일하던 연구원이 C에 화가 많이났어요... 그래서 C with classes을 만들었다.
// 근대 이게 이름이 너무길어 C++ : 1. c++에서는 클래스 중요하다. 잘한번 녹여볼게 
// class -> 변수와 함수의 모임 ( 변수들 : 구조체 + 함수 ) + 상속
// 
// object <- 객체 : 세상을 구성하는 모든것들. 이런식래요. : 변수 함수 상수 + 이상한 구조들 
//
// 일반인 : 1GB : C++  -> 100mb변태 오히려 안좋아 , 못하는사람 -> 10GB;
//  와 저사람대단하다 진짜 변태다 
//
//
// 
// 개발 : c++ ,C, python
// 소스 -> 컴파일러 -> 링커 -> 컴퓨터가 010101010101010101010 : 
// C로쓰면 01010101 좀짧아 <- 운영체제들 좀 하드한것들 ,미사일 ,자동차 , 긴박한것들 
// 게임 핑민감 1ms 2ms c++ 게임 많이써.
//
// 
// 1. 차시 입출력과 변수의 선언및 초기화
//      + 조건문과 반복을 곁들인.
//
//		변수 : Data를 담는 공간 , 주소 (address,Location)와 값(value)
//				-> 타입(형) : int(4-8), long(4) longlong(8) short(1) float(8) -> double(8)
//								unsigned int -> 표현할수있는 수의 최댓값이 2배
// 
// 
//
//		상수 : 데이터 값 주소 값 혹은 그냥 숫자 int a = 3, Read - value
//
//
// 선언 :
// num = 3;
// int num =3;


#include <iostream> // ==  <stdio.h>

main()
{
	int nData_C = 4;
	nData_C = 3;
	// 이제 C언어 스타일 

	int nData_CPP(3.3);
	// CPP 스타일 
	// 형식자 변수명(초기값)
	int nData_CPP_2(nData_CPP);
	//nData_CPP_2 변수에 값에 nData_CPP 의 값을 오버라이팅해라 
	while (1)
	{
		nData_CPP_2 = 3;
		break;
	}
	return 0;
}