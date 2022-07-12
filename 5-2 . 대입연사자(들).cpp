#include<iostream>
using namespace std;

class CMyData
{
public:
	explicit CMyData(int nParam)
	{
		m_pnData = new int(nParam);
	}

	CMyData(const CMyData& rhs)
	{
		cout << "CMyData(&rhs)" << endl;
		m_pnData = new int(*rhs.m_pnData);
	}

	CMyData(const CMyData&& rhs)
	{
		cout << "CMyData(&&rhs)" << endl;
		m_pnData = new int(*rhs.m_pnData);
	}

	~CMyData()
	{
		cout << "~CMyData()" << endl;
		delete m_pnData;
	}

	operator int(void)
	{
		return *m_pnData;
	}

//	void operator =(const CMyData& rhs)
//	{
//		delete m_pnData;
//		m_pnData = new int(*rhs.m_pnData);
//	}
//	//이러면 a = a할때 심각한 오류가 발생 하겠죠>
//
//	void operator =(const CMyData& rhs)
//	{
//		if (this == &rhs)
//		{
//			return;
//		}
//		delete m_pnData;
//		m_pnData = new int(*rhs.m_pnData);
//	}
	// 이러면 a=b=c 일때는 어캄...? void 를 value로? -> CMyData 에대한 참조형식으로 반환해주면 ok?



	CMyData& operator =(const CMyData& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		// a = a일때를 대비한 본인의 대입 연산 통제(?)
		delete m_pnData;
		m_pnData = new int(*rhs.m_pnData);

		return *this;
	}
	//최종 form 공식처럼 외워서 씁시당?


	//이동대입 연산자.
	// 앝은 카피 이후 포인터 하나 삭제
	// 임시객체에서 주로 씀.
	CMyData& operator =(CMyData&& rhs)
	{
		m_pnData = rhs.m_pnData;
		rhs.m_pnData = nullptr;
		return *this;
	}

	CMyData operator +(CMyData& rhs)
	{
		CMyData result(0);
		result.m_pnData = new int(*m_pnData);
		*result.m_pnData += *rhs.m_pnData;
		return result;
		
	}


	//복합 대입 연산자.
	CMyData& operator +=(const CMyData& rhs)
	{
		int* m_NewData = new int(*m_pnData);
		*m_NewData += *rhs.m_pnData;

		delete m_pnData;
		*m_pnData = *m_NewData;

		return *this;
	}



private:
	int* m_pnData = nullptr;
};


int main()
{
	CMyData a(0), b(5),c(7);

	cout << "Test operator =" << endl;
	cout << a << endl;
	a = a;
	cout << a << endl;
	cout << "Test operator +=" << endl;
	a += b;
	cout << a << endl;
	cout << "Test operator CMyData (&&rhs) by +=" << endl;
	a = b+c;
	cout << a << endl;
	return 0;
}