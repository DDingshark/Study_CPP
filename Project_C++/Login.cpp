#pragma once
#include<iostream>
using namespace std;

void Login_Func(void)
{
	char Player_ID[] = "cpp"; //
	string Player_IN; //
	int PassWord; //
	cout << "Player_ID : " << endl;
	cin >> Player_IN;

	if (Player_ID == Player_IN)
	{
		cout << "��й�ȣ�� �Է��Ͽ� �ֽʼ� : " << endl;
		cin >> PassWord;
	}
	else
	{
		exit(1); // ���α׷� ����
	}

	cout << "�α����� �Ϸ�Ǿ����ϴ�." << endl;
}