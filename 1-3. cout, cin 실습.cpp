#include<iostream>
#include<cstdio>
#include<string>

int main()
{
	// 1-1
	int nAge;
	std::cout << "���̸� �Է��Ͻÿ� : " << std::endl;
	std::cin >> nAge;

	char szJob[32];
	std::cout << "������ �Է��Ͻÿ� : " << std::endl;
	std::cin >> szJob;

	std::string strName;
	std::cout << "����� �̸��� �Է��Ͻÿ� : " << std::endl;
	std::cin >> strName;

	std::cout << "����� �̸��� " << strName << "�̰�, "
		<< "���̴� " << nAge << "���̸�, "
		<< "������ " << szJob << "�Դϴ�." << std::endl;

	//1-2
	int a(10);
	int b(a);
	auto c(a);
	std::cout << a + b + c << std::endl;




	return 0;
}