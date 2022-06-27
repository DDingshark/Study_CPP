#include<iostream>
using namespace std;
class CTest
//생성자 함수를 이용한 초기화.
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
	//클래스 내부에서의 함수선언, 정의
};

class CTest_1
{
public:
	CTest_1()
		:m_nData_1(10), m_nData_2(20)
	{}
	//초기화 목록을 이용한 초기화 
	// 참조를 초기화할때 무조건 이런식으로 해야한다.
	int m_nData_1;
	int m_nData_2;
	void Print_m_nData_1();
	//클래스 내부에서의 함수 선언
};

void CTest_1::Print_m_nData_1()
//CTest_1의 가문이니 스코프연산자로 처리해주자.
{
	cout << m_nData_1 << endl;
}
//클래스 외부에서의 함수정의

class CTest_2
{
public:
	CTest_2(int nParam)
		:m_nData_3(nParam) 
	{
		cout << m_n_Data_3 << endl;
	}
	//요런식으로도 가능합니다!
	int m_n_Data_3;
	
};
int main()
{
	CTest_2 b(10);
	CTest_2 b_1(30);

	return 0;
}
