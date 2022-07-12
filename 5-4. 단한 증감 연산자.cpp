#include<iostream>
using namespace std;
//���� ���� ������ ++a , a++�̷���.
// int operator ++() <- ����
// int operator ++(int) <- ����
//����� �翬�� �Ȱ���!


class CMyData 
{
public:
	CMyData(int nParam)
		: m_nData(nParam)
	{

	}
	~CMyData()
	{

	}

	operator int()
	{
		return m_nData;
	}

	int operator ++()
	{
		cout << "operator ++()" << endl;
		return m_nData++;
	}

	int operator ++(int)
	{
		cout << "operator ++(int)" << endl;
		int nData = m_nData;
		m_nData++;

		return nData;
	}




private:
	int m_nData = 0;
};
int main()
{
	CMyData a(5);
	cout << ++a << endl;
	cout << a << endl;
	cout << a++ << endl;
	cout << a << endl;

	return 0;
}