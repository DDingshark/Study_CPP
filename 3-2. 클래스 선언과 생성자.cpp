#include<iostream>
using namespace std;
class USERDATA
{
public:
//���� ������. private, protected���� ������ �����ϴ°͵����� ���⼱ public�������̶� �ǹ�.
	int nAge;
	char szName[32];

	void print()
	{
		printf("%d, %s\n", nAge, szName);
		//this->nAge�� ����ok print�Լ������� Ŭ������ �ɹ��� �����ϴ°� ������ �׳ɽᵵ �����մϴ�.

	}
};


class CTest
{
public:
	CTest()
	//������ �Լ� ����
	// �� �Լ��� '�����'�� ��ü�� �����ϸ� �ڵ������� ȣ��˴ϴ�.
	{
		//�ν��Ͻ��� �����Ǹ� �ڵ������� �ʱ�ȭ �մϴ�.
		cout << "CTest() : ������ �Լ�" << endl;
		m_nData = 10;
	}
	~CTest()
	{
		cout << "~CTest() �Ҹ��� �Լ�" << endl;
	}

	// �����ڿ� �Ҹ����� ����ū Ư¡ 1. ȣ������� ����, 2. ��ȯ��X

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
	//�̷������� ����� ���ÿ� �ʱ�ȭ�� ���� ( c11���ĺ���)

};


CTest t_upper_main;
//�̷������� main�Լ����� ���� ���� �� �� �ִ�.
int main()
{
	cout << "main start" << endl;

	cout << "user start" << endl;
	USERDATA user = {10, "Song" };
	user.print();
	cout << "user end" << endl;


	CTest t;
	//������ ȣ�� 
	t.PrintData();


	cout << "main end" << endl;
	return 0;
}
//�Ҹ������ main�Լ� �ڷ� �Ѿ� �� ���� �ִ�.