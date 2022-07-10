#include<iostream>
using namespace std;
//��ȯ������
// �Ű������� �Ѱ��� ������ �Դϴ� Conversion constructor

// ���� : �����𸣰� ���ڱ� ������ ��찡 ������ ��뿡 ��������.? explicit �� ���!


class CTestData
{
public:
	CTestData(int nParam) : m_nData(nParam)
	// explixit CTestData(int nParam)���� ��Ȯ�ϰ� ���� ���Ҷ��� ��ȯ�� �ϰԲ� �ڵ��� ����.
	{
		cout << "CTestData(int)" << endl;
	}
		//�Ű������� �ϳ����� �����ڴ� ����ȯ�� �����ϴ�.
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


//������ڵ�.
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

	//int�ڷ������� CTestData �������� ��Ȱ�� �� �ִ�.
	TestFunc(5);
	// ���⼭�� ������ �װ���
	//TestFunc(5) -> TestFunc(CTestData(5)) -> CTestData(int nParam)�� ȣ��Ǵ°���...

	cout << "*****BEGIN*****" << endl;
	TestFunc_1(5);

	// TestFunc_1(5) -> TestFunce(CTestData(5)) <- �ӽð�ü ���� <- TestFunc_1����� �ӽð�ü ���� ����?
	cout << "*****ENDL*****" << endl;

	//�����𸣰� �����Ǵ°� ����������� �׻� ��ȯ ������ �տ� explicit�� ������.
	return 0;
}
