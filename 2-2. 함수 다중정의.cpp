#include<iostream>

// C 언어 에서 처리하면
int Add_C_int(int a, int b)
{
	return a + b;
}
double Add_C_double(double a, double b)
{
	return a + b;
}
// 이런식으로 같은 이름을 가진 함수를 선언 할 수없다.

//C++에서는 
int Add_CPP(int a, int b)
{
	return a + b;
}
double Add_CPP(double a, double b)
{
	return a + b;
}
// 이런식으로 같은 이름을 가진 함수들을 만들 수 있다. -> 콜러를 보고 콜리를 유추할 수 없다 -> 모호성이 증가한다 ...ㅠㅠ

//근대 이렇게 형식마다 쓰는거 너무불편해 ㅠ...
template <typename T>
//템플릿 -> 틀
// 타입네임 -> 자료형
// => 자료형에따라 함수를 알아서 다중정의해서 만들어 준다! 
T Add_Tem(T a, T b)
{
	return a + b;
}
// 이런식으로 다중정의보다 함수 템플릿을 활용하자. 
int main()
{
	std::cout << Add_CPP(3, 5) << std::endl;
	std::cout << Add_CPP(3.3, 4.4) << std::endl;
	// 분명히 위에 함수랑 아래함수는 다름함수이다. <- 함수명(호출자)는 예명이고, 진짜이름은 링커가 처리한다!
	// 파라미터의 형태로 함수를 다르게 호출한다.

	std::cout << Add_Tem(1, 2) << std::endl;
	std::cout << Add_Tem(1.1, 2.3) << std::endl;
	// 함수 템플릿을 이용해 자료형별로 알아서 다중정의가 되도록 설계하자!
	// 이름은 같지만 링커수준에서의 함수본명은 서로 다르다! -> 결국 같은 이름의 함수는 여러개일순 없지만, 같은 예명의 함수는 여러개일수 있다.
	return 0;
}