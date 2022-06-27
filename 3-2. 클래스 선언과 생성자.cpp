#include<iostream>
using namespace std;
class USERDATA
{
public:
//접근 지시자. private, protected같이 접근을 제한하는것도있음 여기선 public모두허용이란 의미.
//public : 맴버에 관한 모든외부전급을 허용.
//protect : 맴버의관한 모든 외부접근을 차단 (상속관계의 파생클래스는 허용)
//private : 상속관예의 파생클래스까지도 차단 // 기본값입니당.
	int nAge;
	char szName[32];

	void print()
	{
		printf("%d, %s\n", nAge, szName);
		//this->nAge라 서도ok print함수가속한 클래스의 맴버에 접근하는것 임으로 그냥써도 무관합니당.

	}
};


class CTest
{
public:
	CTest()
	//생성자 함수 정의
	// 이 함수는 '사용자'가 객체를 선언하면 자동적으로 호출됩니당.
	{
		//인스턴스가 생성되면 자동적으로 초기화 합니다.
		cout << "CTest() : 생성자 함수" << endl;
		m_nData = 10;
	}
	~CTest()
	{
		cout << "~CTest() 소멸자 함수" << endl;
	}

	// 생성자와 소멸자의 가장큰 특징 1. 호출시점의 자유, 2. 반환값X

	int m_nData;

	void PrintData()
	{
		cout << "PrintData : "<<m_nData << endl;
	}
};

class C_11Test
{
public:
	int n_main = 10;
	//이런식으로 선언과 동시에 초기화도 가능 ( c11이후부터)

};


CTest t_upper_main;
//이런식으로 main함수보다 위에 선언 할 수 있다.
int main()
{
	cout << "main start" << endl;

	cout << "user start" << endl;
	USERDATA user = {10, "Song" };
	user.print();
	cout << "user end" << endl;


	CTest t;
	//생성자 호출 
	t.PrintData();


	cout << "main end" << endl;
	return 0;
}
//소멸시점이 main함수 뒤로 넘어 갈 수도 있다.
