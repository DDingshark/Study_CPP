#include<iostream>


int TestFunc(int nParam = 10);
// �Լ� ���𿡼� ����Ʈ �Ķ���͸� ������ �� �ִ�.

int TestCalc(int nParam, int nParam_1 = 10);
// ����Ʈ �Ķ���͸� ����� ���� �����ʺ��� ������� �����Ѵ�.
// ->�߰��� ����Ʈ �Ķ���͸� �����ʴ´�!
// �׷��� ��� ���ڿ� ����Ʈ �Ķ���͸� ó������ �˼� �ֱ⶧��
int main()
{
	std::cout << TestFunc() << std::endl;
	// ����Ʈ �Ķ���Ͱ��� 10������ 10�� �ѱ��.
	std::cout << TestFunc(20) << std::endl;
	// �Ķ���� ���� 20������ 20�� �ѱ��.


	std::cout << TestCalc(10) << std::endl;
	//ó������ 10 , �ι�°���ڴ� ����Ʈ�Ķ���ͷ� ����.
	std::cout << TestCalc(10,20) << std::endl;
	// 10, 20 ���� ����.
	
	return 0;
}
int TestFunc(int nParam)
// �Լ��� ���� �κп����� ����Ʈ �Ķ���͸� �����ʴ´�!
{
	return nParam;
}
int TestCalc(int nParam, int nParam_1)
{
	return (nParam + nParam_1);
}
// ȣ������ �ڵ常 ������ �Լ��� ������ �˱� ����� 
// -> ��ȣ���� �����Ѵ� -> ������� �ʴ����� ��������?