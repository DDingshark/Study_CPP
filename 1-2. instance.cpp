#include <iostream>

int main()
{
	//Instance : 경우, 예시 뭐 이런 사전적 뜻이있음.
	// 미인 카리나 이런 관계가 있을때 미인의 한 예시가 카리나 인것처럼
	// int nData  이런식에 뭔가있음 nData는 형식 int 의 한 intance이다. 라고 표현
	// C에서 했던것처럼 변수라는말을 쓰지 않고 인스턴스(instance)라고 한다.

	int a = 10; // C에서의 표현 
	int a(10); // C++에서의 표현

	int b(a); // 이런식으로도 가능
	int(10); // 이런것도 있는대 나중에 추가로 설명해주고 이런게 있구나 넘어가면 ok

	// auto : 형식을 알아서 맞쳐줘라 라는 새로운 형식 입니당.

	int a(10);
	auto b(10); // 이런식으로 
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	
	int nAge;
	std::cin >> nAge;
	std::cout << nAge << std::endl;
	// scanf 랑 참 닮아 있죵?

	return 0;

}