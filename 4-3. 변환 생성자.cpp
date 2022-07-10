#include<iostream>
using namespace std;
//변환생성자
// 매개변수가 한개인 생성자 입니당 Conversion constructor

// 주의 : 나도모르게 갑자기 나오는 경우가 있으니 사용에 주의하자.? explicit 꼭 명심!


class CTestData
{
public:
	CTestData(int nParam) : m_nData(nParam)
	// explixit CTestData(int nParam)으로 명확하게 내가 원할때만 변환을 하게끔 코딩을 하자.
	{
		cout << "CTestData(int)" << endl;
	}
		//매개변수가 하나뿐인 생성자는 형변환이 가능하다.
	CTestData(const CTestData& rhs) : m_nData(rhs.m_nData)
	{
		cout << "CTestData(const CTestData &)" << endl;
	}

	~CTestData()
	{
		cout << "~CTestData()" << endl;
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
};


//사용자코드.
void TestFunc(CTestData param)
{
	cout << "TestFunc() : " << param.GetData() << endl;
}

void TestFunc_1(const CTestData& nParam)
{
	cout << "TestFunc_1() :" << nParam.GetData() << endl;
}


int main()
{

	//int자료형에서 CTestData 형식으로 변활될 수 있다.
	TestFunc(5);
	// 여기서의 문제는 그거지
	//TestFunc(5) -> TestFunc(CTestData(5)) -> CTestData(int nParam)이 호출되는거지...

	cout << "*****BEGIN*****" << endl;
	TestFunc_1(5);

	// TestFunc_1(5) -> TestFunce(CTestData(5)) <- 임시객체 생성 <- TestFunc_1종료시 임시객체 삭제 ㅇㅋ?
	cout << "*****ENDL*****" << endl;

	//나도모르게 생성되는걸 막고싶을때는 항상 변환 생성자 앞에 explicit를 붙이자.
	return 0;
}
