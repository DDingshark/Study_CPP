#include<iostream>

int main()
{
	int nData(10);
	std::cout << nData << std::endl;

	int& rData(nData);
	rData = 0;
	std::cout << nData << std::endl;
	std::cout << rData << std::endl;


	//주소까지 똑같은 쌍둥이 입니다!
	std::cout << &nData << std::endl;
	std::cout << &rData << std::endl;

	return 0;
}