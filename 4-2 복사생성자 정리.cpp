#include<iostream>
using namespace std;

class CMyData
{
public:
	CMyData(int nParam)
	{
		//������ ���� �����
		m_pnData = new int;
		*m_pnData = nParam;
	}

	CMyData(const CMyData(&rhs))
		//��������� ���� �� ����
	{
		cout << "CMyData(const CMyData &)" << endl;

		m_pnData = new int;
		//�޸� �Ҵ�


		*m_pnData = *rhs.m_pnData;
		//�����Ͱ� ����Ű�� ��ġ�� ���� ����

	}
	
	~CMyData()
			//�Ҹ�� �޸� ����
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
	//�Ҹ�� �������� �ʴ´� -> Deep���縦 ���� �ذ��ߴ�.
}