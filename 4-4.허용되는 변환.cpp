#include<iostream>
using namespace std;

class CTestData
{
public:
	explicit CTestData(int nParam)
		:m_nData(nParam)
	{

	}

	operator int(void)
	//형변환 연산자.
	{
		return m_nData;
	}

	int GetData() const
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


int main()
{
	CTestData a(10);
	cout << a.GetData() << endl;

	//CTestData형식에서 int 자료형으로 변활될 수 있다.
	cout << a << endl;
	cout << (int)a << endl;
	// -> C스타일인대 강제로 부아앙아ㅏㅋ 바꾸기 때문에 사용하지 않는게 좋다.
	// 항상! 통제권을 컴퓨터한태 뺏기면 안대!
	cout << static_cast<int>(a) << endl;

	

	return 0;
}