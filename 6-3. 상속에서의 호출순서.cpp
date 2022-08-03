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
		//delete m_pszData;//파생클레스에서 부모클레스를 메모리 해제하면?
		// -> 이미 해제된 메모리를 또해제?
		
		//	-> 파생클레스는 부모것을 건들지 않는다 -> 예의
		//								(초기화, 해제) 
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