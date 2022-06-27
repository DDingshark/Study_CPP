#include<iostream>
using namespace std;
class CTest_mam
{
public:
	CTest_mam()
	{
		cout << "start CTest_mam" << endl;
	};
	~CTest_mam()
	{
		cout << "End CTest_mam" << endl;
	}

	int m_nData_mam;

};

class CTest_overloading
{
public:
	CTest_overloading(int nParam_1, int nParam_2)
	{
		cout << "Param :" << nParam_1 << "," << nParam_2 << endl;
	}

	CTest_overloading(int nParam_1)
	{
		cout << "Param : " << nParam_1 << endl;
	}

	int m_nData_overloading;
	//������ �Լ��� �������ǰ� �����ϴ�.

	~CTest_overloading()
	{
		cout << "end CTest_overloading" << endl;
	}
	//�Ҹ����Լ��� �Ұ��� 
};

class CTest_Referance
{
public:
	CTest_Referance(int& nParam) : m_nData(nParam) {};
	//���������� ������ �ʱ�ȭ����� �̿��� �ʱ�ȭ �ؾ��Ѵ�.
	int m_nData;
	~CTest_Referance()
	{
		cout << m_nData << endl;
	}
};
//�������� �ɹ��ʱ�ȭ

class CTest_default
{
public:
	CTest_default(void) = default;
	//��... �׳� ����. 
	// == CTest_default(void) = delete; 

};


int main()
{
	CTest_mam* pData = new CTest_mam[3];
	//�̷������� ������ü�� ���� �����ϴ�
	delete [] pData;
	//�迭�� ������ �迭��!

	CTest_overloading cData(10, 20);
	CTest_overloading cData_2(10);
	
	CTest_default k;
	return 0;
}