#include<iostream>

//������ �ڵ�
// ������ ��ü�����̴� '�ν�'�� �ٲ�� �Ҷ����Դ�! 
// �����ڰ� ����ڸ� ����ؾ��Ѵ�...
// -> �ý��� ���ο��� �� ���ư��� �� ¥�� + ����ڰ� �������� '��'����� �� �ְ� ¥���Ѵ�.
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
	}//�ٸ��ɹ��� ������ ���� but ����׽������� �Ȱ���
} USERDATA;

void printUserData(USERDATA* pUser)
{
	printf("%d, %s\n", pUser-> nAge, pUser->szName);
}
///////////////////////////////////////

//����� �ڵ� : ����� ������ ������ ����ϴ��ǹ�
int main()
{
	USERDATA a = {20, "Song",printUserData};
	//���
	//1
	printf("%d, %s\n", a.nAge, a.szName);
	//2
	printUserData(&a);
	//�������̽��Լ� : ����ڰ� �Լ����ο� �������� �˾ƾ����ʿ䰡X 
	// -> �������� ����ڸ����� ��� -> ������ ���ɼ��� ����.
	
	//3
	a.Print(&a);
	//�ڷᱸ�������� ����� ����� �����ϴ°�ó������
	// ?? Ŭ����.??? (���� ���ܰ�)

	//4
	//a.Print(); // C++��Ÿ�� : a�� �ɹ��δ� a�� �ּҸ� ����?
				 // c++���� �����մϴ�! but�޸� ���η� ���� //3�̶��Ȱ��� -> ���Ŀ� this�����ͷ� �߰�����
	return 0;
}