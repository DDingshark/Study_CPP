#include<iostream>
using namespace std;

// 임시객체 : 식별자가 부여되지 않은 객체를 임시객체라한다.
//  -> 눈에 보이지도않고 슉 생겼다 슉 사라졌다 하니까 생성자 소멸자가 갑자기 이상하게 튀어나올수 있으니 잘 알아두자.


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
		// 값은 변경하지만 이름은 그대로 둔다.

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
	//변수 이름을 넣기위한 맴버.
};

CTestData TestFunc(int nParam)
{
	// CTestData a 는 지역변수 임으로 함수스택이 끝나면 사라진다.
	CTestData a(nParam, 'a');
	return a;
}

int main()
{
	
	CTestData b(5,'b');
	cout << "*****BEFORE*****" << endl;

	//함수가 반환되면서 임시객체가 생성됐다가 대입 연산 이후 즉시 소멸한다.
	b = TestFunc(10);
	cout << "*****After*****" << endl;
	cout << b.GetData() << endl;



	return 0;
}