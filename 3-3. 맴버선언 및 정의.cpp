#include<iostream>
using namespace std;
class CTest
//������ �Լ��� �̿��� �ʱ�ȭ.
{
public:
	CTest()
	{
		m_nData = 10;
	}

	int m_nData;
	void Print_n_mData()
	{
		cout << m_nData << endl;
	}
	//Ŭ���� ���ο����� �Լ�����, ����
};

class CTest_1
{
public:
	CTest_1()
		:m_nData_1(10), m_nData_2(20)
	{}
	//�ʱ�ȭ ����� �̿��� �ʱ�ȭ 
	// ������ �ʱ�ȭ�Ҷ� ������ �̷������� �ؾ��Ѵ�.
	int m_nData_1;
	int m_nData_2;
	void Print_m_nData_1();
	//Ŭ���� ���ο����� �Լ� ����
};

void CTest_1::Print_m_nData_1()
//CTest_1�� �����̴� �����������ڷ� ó��������.
{
	cout << m_nData_1 << endl;
}
//Ŭ���� �ܺο����� �Լ�����

int main()
{


	return 0;
}