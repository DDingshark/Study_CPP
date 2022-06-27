#include<iostream>

//제작자 코드
// 이제는 객체지향이니 '인식'을 바꿔야 할때가왔다! 
// 제작자가 사용자를 배려해야한다...
// -> 시스템 내부에서 잘 돌아가게 잘 짜고 + 사용자가 오류없이 '잘'사용할 수 있게 짜야한다.
typedef struct USERDATA
{
	int nAge;
	char szName[32];
	void(*Print)(struct USERDATA*);

	void printUserData(USERDATA* pUser)
	{
		printf("%d, %s\n", pUser->nAge, pUser->szName);
	}

	void Print2()
	{
		printf("%d, %s\n", nAge, szName);
	}
}
{
	int nAge;
	char szName[32];
	void(*Print)(struct USERDATA*);
	
	void printUserData(USERDATA* pUser)
	{
		printf("%d, %s\n", pUser->nAge, pUser->szName);
	}

	void Print2()
	{
		printf("%d, %s\n",nAge,szName);
	}//다른맴버의 접근이 용이 but 디버그시위에랑 똑같음
} USERDATA;

void printUserData(USERDATA* pUser)
{
	printf("%d, %s\n", pUser-> nAge, pUser->szName);
}
///////////////////////////////////////

//사용자 코드 : 만들어 놓은걸 가져다 사용하는의미
int main()
{
	USERDATA a = {20, "Song",printUserData};
	//출력
	//1
	printf("%d, %s\n", a.nAge, a.szName);
	//2
	printUserData(&a);
	//인터페이스함수 : 사용자가 함수내부에 무었들을 알아야할필요가X 
	// -> 제작자의 사용자를위한 배려 -> 오류날 가능성이 낮다.
	
	//3
	a.Print(&a);
	//자료구조내에서 출력의 기능을 제공하는것처럼보임
	// ?? 클래스.??? (아직 전단계)

	//4
	//a.Print(); // C++스타일 : a의 맴버인대 a의 주소를 몰라?
				 // c++에서 가능합니다! but메모리 내부로 들어가면 //3이랑똑같음 -> 추후에 this포인터로 추가설명
	return 0;
}