#include<iostream>

int main()
{
	int aList[7] = { 10,20,30,40,50,60,70 };

	//�б����� + �������� �� �ҷ��ɴϴ�!
	for (auto n : aList)
		n = 0;
	for (auto n : aList)
		std::cout << n << std::endl;

	//������� �ϰ������ ����ȣ���!
	for (auto& n : aList)
		n = 0;

	for (auto n : aList)
		std::cout << n << std::endl;

	return 0;
}