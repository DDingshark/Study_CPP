#include<iostream>
using namespace std;
//상수형 변수(메소드)는 읽기만! 가능
// 쓰기 접근 X
// 함수일경우에 함수를 실행하는것에있어 모든쓰기 차단

class CTest
{
public:
	CTest(int nParam) :m_nData(nParam) {};
	~CTest() {}
	
	int GetData()const
	// 상수형메소드로 선언 및 정의했다.
	// -> 보안, 속도, 유지보수에서 실력있는 개발자라면
		// const의 갯수를 세면 된다 라는 말이 있음.
	{
		return m_nData;
	}


	int SetData(int nParam) 
	{ 
		m_nData = nParam;
		//★m_nData =20; 
		// 출력하면 20이라 나오겠죵?
	}

private:
	int m_nData = 0;
	// 상수형메소드라도 mutable 예약어와 const_cast<>를 사용하면
	// const에도 접근하여 쓰기가 가능;
	//★mutable int m_nData =0;
};


void TestFunc(const int& nParam)
{
	int& nNewParam = const_cast<int&>(nParam);
	//상수형 참조를 일반참조로 바꿨다!
	nNewParam = 20;
	//그래서 l_value로 수정이 가능하게되었다.
}

int main()
{
	CTest a(10);
	cout << a.GetData() << endl;

	int nData(10);
	TestFunc(nData);
	cout << nData << endl;

	return 0;
}