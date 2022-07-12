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
//	//�̷��� a = a�Ҷ� �ɰ��� ������ �߻� �ϰ���>
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
	// �̷��� a=b=c �϶��� ��į...? void �� value��? -> CMyData ������ ������������ ��ȯ���ָ� ok?



	CMyData& operator =(const CMyData& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		// a = a�϶��� ����� ������ ���� ���� ����(?)
		delete m_pnData;
		m_pnData = new int(*rhs.m_pnData);

		return *this;
	}
	//���� form ����ó�� �ܿ��� ���ô�?


	//�̵����� ������.
	// ���� ī�� ���� ������ �ϳ� ����
	// �ӽð�ü���� �ַ� ��.
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


	//���� ���� ������.
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