#include<iostream>
using namespace std;
// 상속(Inherrit) 
	// 1. 코드를 재사용하는 방법
	// 2. 규모의 확장
	// 3. 관계의 한 유형.

// 여러가지 클레스사이의 관계를 '설계' <- 과거, 현재, 미래를 고려하여

// 부모(기본, 추상) 클레스 -> 자식(파생, 구현)클래스 의 관계이며, 자식클레스는 부모클레스의 의존적이다.
// 메모리 크기 파생클래스 = 부모클래스 + 파생클레스 자체의 크기

class CMyData
{
public:
	CMyData()
	{
		cout << "CMyData()" << endl;
	}

	int GetData()
	{
		return m_nData;
	}

	void SetData(int nParam)
	{
		m_nData = nParam;
	}

protected: // 자식클래스에서 접근 가능.
	void PrintData()
	{
		cout << "CMyData::PringData()" << endl;
	}

private: // 주의 ! 파생클래스에서 기본클래스의 초기화 X 무조건 본인 클래스의 맴버는 본인클래스가 초기화 + 맴버변수는 가급적이면 private로 선언하자.
	int m_nData = 0;
};


class CMyDataEx :public CMyData // 파생클래스의 선언 -> 접근 지시자는 99%이상 public 으로
{
public:
	CMyDataEx()
	{
		cout << "CMyDataEx()" << endl;
	}

	void TestFunc()
	{
		PrintData();
		SetData(5);
		cout << "CMyData :: GetData()" << endl;
	}


};
int main()
{

	CMyDataEx data; // 파생클래스 선언 이지만 , 부모클래스의 생성자도 실행된다 but 호출시점 != 실행시전 이기에 호출은 자식 -> 부모 , 실행은 부모 -> 자식
	// 생각해보면 상식.
	data.SetData(10);
	cout << data.GetData() << endl;

	data.TestFunc();
	return 0;
}