#include<iostream>
#include<cstdio>
#include<string>

int main()
{
	// 1-1
	int nAge;
	std::cout << "나이를 입력하시오 : " << std::endl;
	std::cin >> nAge;

	char szJob[32];
	std::cout << "직업을 입력하시오 : " << std::endl;
	std::cin >> szJob;

	std::string strName;
	std::cout << "당신의 이름을 입력하시오 : " << std::endl;
	std::cin >> strName;

	std::cout << "당신의 이름은 " << strName << "이고, "
		<< "나이는 " << nAge << "살이며, "
		<< "직업은 " << szJob << "입니다." << std::endl;

	//1-2
	int a(10);
	int b(a);
	auto c(a);
	std::cout << a + b + c << std::endl;




	return 0;
}