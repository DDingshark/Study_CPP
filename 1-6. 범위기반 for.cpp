#include<iostream>

int main()
{
	int aList[7] = { 10,20,30,40,50,60,70 };

	//읽기전용 + 지역변수 로 불러옵니다!
	for (auto n : aList)
		n = 0;
	for (auto n : aList)
		std::cout << n << std::endl;

	//쓰기까지 하고싶으면 참조호출로!
	for (auto& n : aList)
		n = 0;

	for (auto n : aList)
		std::cout << n << std::endl;

	return 0;
}