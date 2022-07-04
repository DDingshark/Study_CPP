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

private:
	int* m_pnData = nullptr;
};
int main()
{
	CMyData a(10);
	CMyData b(a);

	

	return 0;
	//소멸시 오류나지 않는다 -> Deep복사를 통해 해결했다.
}