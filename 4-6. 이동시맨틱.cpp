#include< iostream>
using namespace std;
//�̵��ø�ƽ : move semantics
// �̵������ڿ� �̵� ���� �����ڷ� �����Ѵ�.

// ��������ڿ� ���Կ����ڿ� R_value�� �����Ͽ� ���ο� ���� �� �������ִ� �̵������ڸ� ����Ѵ�.

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
	//�̵� ������ : rvalue ���� (&&)�� �̿��� ����
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
	//10 �� R_vlaue �ϱ� �̵������� (&&rhs) �� ȣ��ƴ�.
	// + �ӽð�ü�� ��������� ��������ڰ��ƴ� �ٸ�������� ������ �Ǿ��ٴ� ���̴�.

	// ->  �� ����� �ӽú����� ��� ��������� �Ҷ����� �������縦 �ϸ� ������ü�� �����͸ɹ��� ������⿡ ȿ�����̴�.

	cout << "**After*******" << endl;
	CTestData c(b);

	return 0;
}

