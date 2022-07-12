#include<iostream>
using namespace std;
//단항 증감 연산자 ++a , a++이런거.
// int operator ++() <- 전위
// int operator ++(int) <- 후위
//사용은 당연히 똑같이!


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