#include<iostream>
using namespace std;

class CTest
{
public:
	CTest()
	{
		cout << "CTest()" << endl;
		m_pData = new int(5);
}
	~CTest()
	{
		cout << "~CTest()" << endl;
		delete m_pData;
	}
	CTest(const CTest& rhs)
		//복사생성자 선언 및 정의: 클래스이름(const 클래스이름 &rhs);
	{
		cout << "CTest(const CTest &)" << endl;
//		this->m_nData = rhs.m_nData; //맴버값을 단순대입으로 복사한다.
		//pointer에대한 shallow카피 -> 나중에 지울때 문제발생
		// 왜? -> a,b가 가르키는 대상이똑같아서 delete할때문제발생
		this->m_pData = new int(*rhs.m_pData);
		//Deep
	}

	void SetData(int nParam)
	{
		*m_pData = nParam;
	}
	int GetData()
	{ 
		return *m_pData;
	}
	int m_nData = 0; // C++11 스타일(생성자로 생성 안해도 ㅇㅋ
private:
	int* m_pData = nullptr; // NULL포인터

};
int main()
{

	int nData = 5;
	
	int* pA = &nData;
	int* pB = NULL;
	pB = pA; //Shallow

	int* pC = new int(*pA); //Deep
	cout << *pA << endl;
	cout << *pB << endl;
	cout << *pC << endl;
	//nData(대상체)는 1개인대 포인터가2개<-접근방법(참조수단)이2개
	//DeepCopy ; 대상체를 여러개로카피
	//ShallowCopy : 참조자가 여러개로 카피

	CTest a;
	a.m_nData = 300;
	CTest b(a);//<<-- 복사생성자가 불림
	cout << a.m_nData << endl; //300
	cout << b.m_nData << endl; // 0? <- 
	return 0;

}