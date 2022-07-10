#include<iostream>
using namespace std;

// �ӽð�ü : �ĺ��ڰ� �ο����� ���� ��ü�� �ӽð�ü���Ѵ�.
//  -> ���� ���������ʰ� �� ����� �� ������� �ϴϱ� ������ �Ҹ��ڰ� ���ڱ� �̻��ϰ� Ƣ��ü� ������ �� �˾Ƶ���.


class CTestData
{
public:
	CTestData (int nParam, char* pszName)
		: m_nData(nParam), m_pszName(pszName)
	{
		cout << "CTestData(int nParam, char* pszName)" << endl;
	}

	~CTestData()
	{
		cout << "~CTestData(): " <<m_pszName<< endl;
	}

	CTestData(const CTestData& rhs)
		: m_nData(rhs.m_nData), m_pszName(rhs.m_pszName)
	{
		cout << "CTestData(const CTestData &)" << m_pszName<< endl;
	}

	CTestData& operator =(const CTestData& rhs)
	{
		cout << "operator=" << endl;
		m_nData = rhs.m_nData;
		// ���� ���������� �̸��� �״�� �д�.

		return *this;

	}
	
	int GetData()const
	{
		return m_nData;
	}
	void SetData(int nParam)
	{
		m_nData = nParam;
	}
private:
	int m_nData = 0;
	char* m_pszName = nullptr;
	//���� �̸��� �ֱ����� �ɹ�.
};

CTestData TestFunc(int nParam)
{
	// CTestData a �� �������� ������ �Լ������� ������ �������.
	CTestData a(nParam, 'a');
	return a;
}

int main()
{
	
	CTestData b(5,'b');
	cout << "*****BEFORE*****" << endl;

	//�Լ��� ��ȯ�Ǹ鼭 �ӽð�ü�� �����ƴٰ� ���� ���� ���� ��� �Ҹ��Ѵ�.
	b = TestFunc(10);
	cout << "*****After*****" << endl;
	cout << b.GetData() << endl;



	return 0;
}