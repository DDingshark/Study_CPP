#include<iostream>

int main()
{
	int nData(10);
	std::cout << nData << std::endl;

	int& rData(nData);
	rData = 0;
	std::cout << nData << std::endl;
	std::cout << rData << std::endl;


	//�ּұ��� �Ȱ��� �ֵ��� �Դϴ�!
	std::cout << &nData << std::endl;
	std::cout << &rData << std::endl;

	return 0;
}