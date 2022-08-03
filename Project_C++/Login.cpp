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
		cout << "비밀번호를 입력하여 주십쇼 : " << endl;
		cin >> PassWord;
	}
	else
	{
		exit(1); // 프로그램 종료
	}

	cout << "로그인이 완료되었습니다." << endl;
}