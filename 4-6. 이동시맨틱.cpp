#include< iostream>
using namespace std;
//이동시맨틱 : move semantics
// 이동생성자와 이동 대입 연산자로 구현한다.

// 복사생성자와 대입연산자에 R_value를 참조하여 새로운 생성 및 대입해주는 이동생성자를 재공한다.

class CTestData
{
public:
	CTestData() { cout << "CTestData()" << endl; }
	~CTestData() { cout << "~CTestData()" << endl; }

	CTestData(const CTestData& rhs)
		:m_nData(rhs.m_nData)
	{
		cout << "CTestData(& rhs)" << endl;
	}



	CTestData(CTestData&& rhs)
	//이동 생성자 : rvalue 참조 (&&)를 이용해 선언
		:m_nData(rhs.m_nData)
	{
		cout << "CTestData(&& rhs)" << endl;
	}

	CTestData& operator = (const CTestData&) = default;

	int GetData()
	{
		return m_nData;
	}

	void SetData(int nParam)
	{
		m_nData = nParam;
	}

private:
	int m_nData = 10;
};

CTestData TestFunc(int nParam)
{

	cout << "**TestFunc() : Begin **" << endl;
	CTestData a;
	a.SetData(nParam);
	cout << "**TestFunc(): End****" << endl;

	return a;
}

int main()
{
	CTestData b;
	cout << "**Before******" << endl;
	b = TestFunc(10);
	//10 은 R_vlaue 니까 이동생성자 (&&rhs) 가 호출됐다.
	// + 임시객체가 만들어질때 복사생성자가아닌 다른방법으로 생성이 되었다는 말이다.

	// ->  곧 사라질 임시변수의 경우 깊은복사로 할때보다 앝은복사를 하면 원본객체의 포인터맴버가 사라지기에 효율적이다.

	cout << "**After*******" << endl;
	CTestData c(b);

	return 0;
}

