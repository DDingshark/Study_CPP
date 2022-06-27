#include<iostream>


int TestFunc(int nParam = 10);
// 함수 선언에서 디폴트 파라미터를 선언할 수 있다.

int TestCalc(int nParam, int nParam_1 = 10);
// 디폴트 파라미터를 선언시 가장 오른쪽부터 여백없이 선언한다.
// ->중간에 디폴트 파라미터를 넣지않는다!
// 그래야 어느 인자에 디폴트 파라미터를 처리할지 알수 있기때문
int main()
{
	std::cout << TestFunc() << std::endl;
	// 디폴트 파라미터값이 10임으로 10을 넘긴다.
	std::cout << TestFunc(20) << std::endl;
	// 파라미터 값이 20임으로 20을 넘긴다.


	std::cout << TestCalc(10) << std::endl;
	//처음값을 10 , 두번째인자는 디폴트파라미터로 들어간다.
	std::cout << TestCalc(10,20) << std::endl;
	// 10, 20 으로 들어간다.
	
	return 0;
}
int TestFunc(int nParam)
// 함수의 정의 부분에서는 디폴트 파라미터를 넣지않는다!
{
	return nParam;
}
int TestCalc(int nParam, int nParam_1)
{
	return (nParam + nParam_1);
}
// 호출자의 코드만 봐서는 함수의 원형을 알기 힘들다 
// -> 모호성이 증가한다 -> 사용하지 않는편이 좋을지도?