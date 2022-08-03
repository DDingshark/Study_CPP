#include<iostream>
using namespace std;

class CMyDataA
{
public:
	CMyDataA()
	{
		cout << "CMyDataA()" << endl;
		m_pszData = new char[32];
	}
	~CMyDataA()
	{
		cout << "~CMyDataA()" << endl;
		delete m_pszData;
	}
protected:
	char* m_pszData = nullptr;
};

class CMyDataB : public CMyDataA
{
public:
	CMyDataB()
	{
		cout << "CMyDataB()" << endl;
	}
	~CMyDataB()
	{
		cout << "~CMyDataB()" << endl;
		//delete m_pszData;//�Ļ�Ŭ�������� �θ�Ŭ������ �޸� �����ϸ�?
		// -> �̹� ������ �޸𸮸� ������?
		
		//	-> �Ļ�Ŭ������ �θ���� �ǵ��� �ʴ´� -> ����
		//								(�ʱ�ȭ, ����) 
	}
};
class CMyDataC : public CMyDataB
{
public:
	CMyDataC()
	{
		cout << "CMyDataC()" << endl;
	}
	~CMyDataC()
	{
		cout << "~CMyDataC()" << endl;
	}
};


int main()
{

	CMyDataC c;
	

	return 0;
}