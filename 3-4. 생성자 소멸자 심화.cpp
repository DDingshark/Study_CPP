#include<iostream>
using namespace std;
class CTest_mam
{
public:
	CTest_mam()
	{
		cout << "start CTest_mam" << endl;
	};
	~CTest_mam()
	{
		cout << "End CTest_mam" << endl;
	}

	int m_nData_mam;

};

class CTest_overloading
{
public:
	CTest_overloading(int nParam_1, int nParam_2)
	{
		cout << "Param :" << nParam_1 << "," << nParam_2 << endl;
	}

	CTest_overloading(int nParam_1)
	{
		cout << "Param : " << nParam_1 << endl;
	}

	int m_nData_overloading;
	//생성자 함수는 다중정의가 가능하다.

	~CTest_overloading()
	{
		cout << "end CTest_overloading" << endl;
	}
	//소멸자함수는 불가능 
};

class CTest_Referance
{
public:
	CTest_Referance(int& nParam) : m_nData(nParam) {};
	//참조형식은 생성자 초기화목록을 이용해 초기화 해야한다.
	int m_nData;
	~CTest_Referance()
	{
		cout << m_nData << endl;
	}
};
//참조형식 맴버초기화

class CTest_default
{
public:
	CTest_default(void) = default;
	//음... 그냥 없다. 
	// == CTest_default(void) = delete; 

};


int main()
{
	CTest_mam* pData = new CTest_mam[3];
	//이런식으로 동적객체의 선언도 가능하다
	delete [] pData;
	//배열의 해제은 배열로!

	CTest_overloading cData(10, 20);
	CTest_overloading cData_2(10);
	
	CTest_default k;
	return 0;
}