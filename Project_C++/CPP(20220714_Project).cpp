#include<iostream>
#include<random>
#include<string>
#include<cstdlib>

#include"Monster.h"
#include"PlayerData.h"
#include"Answer.h"
#include"Login.h"
#include"FightFunc.h"

using namespace std;



int main()
{
	int Player_Answer; //
//	Login_Func();
	cout << "ĳ���͸� ���� �մϴ�. �г����� �����ּ��� : " << endl;

	Player_Char Player{" ",1,0,100,100,10,{1,1,1}}; //
	cin >> Player.Name;

	cout << " ���ڱ� ������ ��Ÿ�� ��簡 �׿��� �Ѵٴ� �� �׷� �̾߱�" << endl;


	Monster Dog{ "Dog",11,2,10 }; //
	Player_Answer = Connet_Monster(Dog.Name);
	if (Player_Answer == 1)
	{
		Fight_Start_Tuto(Player, Dog);
	}
	else
	{
		cout << "������ ��������" << endl;
	}
	


	Monster Cat;
	Creat_Monster(Cat, 2);
	Player_Answer = Connet_Monster(Cat.Name);
	if (Player_Answer == 1)
	{
		Fight_Start_Tuto(Player, Cat);
	}
	else
	{
		cout << "������ ��������" << endl;
	}

	return 0;
}



// ���� :
// ũ�Ⱑ 100�� int �� �迭�� ���������� ������������ ����. ���ϸ� ���� 8/ù�� �ָ���������. 
// + ������ ����.(2��¥��)





