#include<iostream>
//std:: 이런거 없이 여기모든건 std가문의 것이여
using namespace std;


//매개변수가 int에대한 참조형식이다.
void Testfunc(int& rParam)
{
	// 피호출자 함수에서 원본값을바꾼다.
	rParam = 100;
}

//참조전달이며 원본의 값을 바꿀수있다.
void Swap(int& a, int& b)
{
	auto nTemp(a);
	a = b;
	b = nTemp;
}

int main()
{
	int nData(10);
	//using~ 때문에 std:: 안써도댐
	cout << nData << endl;


	//참조에 의한 인수전달 
	//매개변수가 참조형이기 때문이다.
	Testfunc(nData);
	cout << nData << endl;


	int x(10);
	int y(5);
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	Swap(x,y);
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;


	//그래서 main의 원본만보면, 이게 참조호출인지 값호출인지
	//모르기에 주의가 필요하당
	return 0;
}
