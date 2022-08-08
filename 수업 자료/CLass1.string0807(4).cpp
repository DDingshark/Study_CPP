#include<iostream>
#include<string>

using namespace std;

int main()
{
	cout << "Please enter tour first name :";
	string name;
	cin >> name;

	const string greeting = "Hello, " + name + '!';

	const int pad(1);
	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;

	cout << endl;

	for (int r = 0; r != rows; ++r)
	{
		string::size_type c = 0;
		while (c != cols)
		{
			if (r == pad + 1 && c == pad + 1)
			{
				cout << greeting;
				c += greeting.size();

			}
			else
			{
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
				{
					cout << "*";

				}
				else
				{
					cout << " ";
				}
				++c;
			}

		}
		cout << endl;
	}

	return 0;

}



/*
x.y x[y],x++, x--

++x,--y, !x

x*y, x/y, x%y

x+y, x-y

x>>y x<<y

x relop y <= >= < >

x==y x!=y

x&&y 

x||y

x=y

x op= y +=,-=, *= ...

x?y:z -> x가 참이면 y를 반환 x가 거짓이면 z를 반환

*/

//string ::size_type : 모든 문자열의 크기를 저장할수 있는 부호가없는 정수타입
//size_t : 모든 객체의 크기를 저장할 수 있는 부호가 없는 정수타입

//=> unsigned int
//<cstddef>

중간고사, 기말고사 종합과제점수 -> 최종점수
20			40			40
-> 최종점수를 구하는 프로그램

학생수는 ㅁ?ㄹ 

학생 이름 : 
중간 점수 : 
기말 점수 :
과제 점수 : 

학생 이름 :
중간 점수 :
기말 점수 :
과제 점수 :

학생 이름 :
중간 점수 :
기말 점수 :
과제 점수 :

학생 이름 :
중간 점수 :
기말 점수 :
과제 점수 :

학생 이름 :
중간 점수 :
기말 점수 :
과제 점수 :

학생 이름 :
중간 점수 :
기말 점수 :
과제 점수 :

학생 이름 :
중간 점수 :
기말 점수 :
과제 점수 :


<<띵주 대학교 학생 점수표>>
학생 이름 : ㅇㅇㅇ, 중간 : 기말 : 종합과제 : 최종 : 
학생 이름 : ㅇㅇㅇ, 중간 : 기말 : 종합과제 : 최종 : 
학생 이름 : ㅇㅇㅇ, 중간 : 기말 : 종합과제 : 최종 : 
학생 이름 : ㅇㅇㅇ, 중간 : 기말 : 종합과제 : 최종 : 
학생 이름 : ㅇㅇㅇ, 중간 : 기말 : 종합과제 : 최종 : 
<<띵주 대학교 학생 점수표 끝>>

