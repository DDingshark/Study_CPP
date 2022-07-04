#include<iostream>
using namespace std;

class CMyData
{
public:
	CMyData(int nParam)
	{
		//생성시 공간 만들기
		m_pnData = new int;
		*m_pnData = nParam;
	}

	CMyData(const CMyData(&rhs))
		//복사생성자 정의 및 선언
	{
		cout << "CMyData(const CMyData &)" << endl;

		m_pnData = new int;
		//메모리 할당


		*m_pnData = *rhs.m_pnData;
		//포인터가 가리키는 위치에 값을 복사

	}
	
	~CMyData()
			//소멸시 메모리 해제
	{
		delete m_pnData;
	}

	int GetData()
	{
		if (m_pnData != nullptr)
		{
			return *m_pnData;
		}
		return 0;
	}

	CMyData& operator =(const CMyData& rhs)
		// 단순대입 연산자함수를 정의하는모습
		// 자세한건 뒤에더 설명하고 외워라!
	{
		*m_pnData = *rhs.m_pnData;
		return this;
	}

private:
	int* m_pnData = nullptr;
};
int main()
{
	CMyData a(10);
	CMyData b(a);
	CMyData c(20);

	a = c;
	//a.operator = (c); 랑 똑같은 의미 입니당.
	//단순대입을 시도하면 모든맴버의 값을 그대로 복사한다.
	cout << a.GetData << endl;
	cout << c.GetData << endl;
	return 0;
	//소멸시 오류나지 않는다 -> Deep복사를 통해 해결했다.
}