#include<iostream>
//std:: �̷��� ���� ������� std������ ���̿�
using namespace std;


//�Ű������� int������ ���������̴�.
void Testfunc(int& rParam)
{
	// ��ȣ���� �Լ����� ���������ٲ۴�.
	rParam = 100;
}

//���������̸� ������ ���� �ٲܼ��ִ�.
void Swap(int& a, int& b)
{
	auto nTemp(a);
	a = b;
	b = nTemp;
}

int main()
{
	int nData(10);
	//using~ ������ std:: �Ƚᵵ��
	cout << nData << endl;


	//������ ���� �μ����� 
	//�Ű������� �������̱� �����̴�.
	Testfunc(nData);
	cout << nData << endl;


	int x(10);
	int y(5);
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;

	Swap(x,y);
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;


	//�׷��� main�� ����������, �̰� ����ȣ������ ��ȣ������
	//�𸣱⿡ ���ǰ� �ʿ��ϴ�
	return 0;
}
