#include <iostream>

int main()
{
	//Instance : ���, ���� �� �̷� ������ ��������.
	// ���� ī���� �̷� ���谡 ������ ������ �� ���ð� ī���� �ΰ�ó��
	// int nData  �̷��Ŀ� �������� nData�� ���� int �� �� intance�̴�. ��� ǥ��
	// C���� �ߴ���ó�� ������¸��� ���� �ʰ� �ν��Ͻ�(instance)��� �Ѵ�.

	int a = 10; // C������ ǥ�� 
	int a(10); // C++������ ǥ��

	int b(a); // �̷������ε� ����
	int(10); // �̷��͵� �ִ´� ���߿� �߰��� �������ְ� �̷��� �ֱ��� �Ѿ�� ok

	// auto : ������ �˾Ƽ� ������� ��� ���ο� ���� �Դϴ�.

	int a(10);
	auto b(10); // �̷������� 
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	
	int nAge;
	std::cin >> nAge;
	std::cout << nAge << std::endl;
	// scanf �� �� ��� ����?

	return 0;

}