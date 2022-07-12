#include<iostream>
using namespace std;

class CIntArry
{
public:
	CIntArry(int nSize)
	{
		m_pnData = new int[nSize];
		memset(m_pnData, 0, sizeof(int) * nSize);
		//�޸� ���� Ȯ�� ���� �ʱ�ȭ
	}

	~CIntArry()
	{
		delete m_pnData;
	}

	int operator[](int nIndex) const
	{
		cout << "operator [](int nIndex) const" << endl;
		return m_pnData[nIndex];
	}

	int& operator[](int nIndex)
	{
		cout << "operator[]" << endl;
		return m_pnData[nIndex];
	}


private:
	int* m_pnData;
	int m_nSize;
};

void TestFunc(const CIntArry &arParam)
{
	cout << "TestFunc()" << endl;

	//����� ���� ������ operator [int nIndex] const �� �Ҹ���.
	cout << arParam[3] << endl;


	return;
}

int main()
{
	CIntArry arr(5);
	for (int i = 0; i < 5; ++i)
	{
		arr[i] = i + 10;
	}
	TestFunc(arr);
	return 0;
}