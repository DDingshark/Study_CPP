#include<iostream>

int main()
{
	//C���
	int* pnData_C = (int*)malloc(sizeof(int));
	int* pnData_1_C = (int*)malloc(sizeof(int) * 5);

	free(pnData_C);
	free(pnData_1_C);
	//C++ new ��� �����ڸ� ���� �����Ҵ�
	//����� ���� �ϱ�? �ʿ� ���� 

	int* pnData_CPP = new int;
	int* pnData_1_CPP = new int[5];

	delete pnData_CPP;
	delete[] pnData_1_CPP;
	//�迭(class)�� ������ ���ﶧ�� �迭�� �������Ѵ�
	return 0;

}