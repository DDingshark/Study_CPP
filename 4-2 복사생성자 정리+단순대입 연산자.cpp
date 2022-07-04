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

	CMyData& operator =(const CMyData& rhs)
		// �ܼ����� �������Լ��� �����ϴ¸��
		// �ڼ��Ѱ� �ڿ��� �����ϰ� �ܿ���!
	{
		*m_pnData = *rhs.m_pnData;
		return this;
	}

private:
	int* m_pnData = nullptr;
};
int main()
{
	CMyData a(10);
	CMyData b(a);
	CMyData c(20);

	a = c;
	//a.operator = (c); �� �Ȱ��� �ǹ� �Դϴ�.
	//�ܼ������� �õ��ϸ� ���ɹ��� ���� �״�� �����Ѵ�.
	cout << a.GetData << endl;
	cout << c.GetData << endl;
	return 0;
	//�Ҹ�� �������� �ʴ´� -> Deep���縦 ���� �ذ��ߴ�.
}