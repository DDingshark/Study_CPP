#include<iostream>
using namespace std;
//����� ����(�޼ҵ�)�� �б⸸! ����
// ���� ���� X
// �Լ��ϰ�쿡 �Լ��� �����ϴ°Ϳ��־� ��羲�� ����

class CTest
{
public:
	CTest(int nParam) :m_nData(nParam) {};
	~CTest() {}
	
	int GetData()const
	// ������޼ҵ�� ���� �� �����ߴ�.
	// -> ����, �ӵ�, ������������ �Ƿ��ִ� �����ڶ��
		// const�� ������ ���� �ȴ� ��� ���� ����.
	{
		return m_nData;
	}


	int SetData(int nParam) 
	{ 
		m_nData = nParam;
		//��m_nData =20; 
		// ����ϸ� 20�̶� ��������?
	}

private:
	int m_nData = 0;
	// ������޼ҵ�� mutable ������ const_cast<>�� ����ϸ�
	// const���� �����Ͽ� ���Ⱑ ����;
	//��mutable int m_nData =0;
};


void TestFunc(const int& nParam)
{
	int& nNewParam = const_cast<int&>(nParam);
	//����� ������ �Ϲ������� �ٲ��!
	nNewParam = 20;
	//�׷��� l_value�� ������ �����ϰԵǾ���.
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