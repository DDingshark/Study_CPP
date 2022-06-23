#include<iostream>

int main()
{
	//C언어
	int* pnData_C = (int*)malloc(sizeof(int));
	int* pnData_1_C = (int*)malloc(sizeof(int) * 5);

	free(pnData_C);
	free(pnData_1_C);
	//C++ new 라는 연산자를 통해 동적할당
	//사이즈에 대한 암기? 필요 없음 

	int* pnData_CPP = new int;
	int* pnData_1_CPP = new int[5];

	delete pnData_CPP;
	delete[] pnData_1_CPP;
	//배열(class)로 했으면 지울때도 배열로 지워야한당
	return 0;

}