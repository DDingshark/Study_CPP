#include<iostream>
#include<string>

int main()
{
	std::cout << "Please enter first name : ";
	std::string name;
	std::cin >> name;
	
	//출력메세지 작성
	const std::string greeting = "Hello" + name + '!';
	//c++의 장점 : 연산자 오버로딩(overload) 기능을 갖고있음?
// 함수도 인자에 따라서 함수명이 같을지라도 불러오는 함수가 달랐지.
// 연산자또한 같은 기호라도 피연산자들에 따라서 전혀 다른기능을 호출할 수 있다.

// 실제로 +
// 1. 처음 왼쪽 피연산자를 메모리에 저장한다.
// 2. 오른쪽 피연산자와 왼쪽 피연사자의 길이를 더한 후 +1의 크기를 할당받는다.
// 3. 피연산자들을 이어서 붙인다.

	const std::string spaces(greeting.size(), ' ');
	const std::string second = "* " + spaces + " *";
	const std::string first(second.size(), '*');

	std::cout << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << "* " << greeting <<" *" << std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;




	

	return 0;
}