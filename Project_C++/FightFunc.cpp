#pragma once
#include<iostream>
#include "PlayerData.h"
#include "Monster.h"
#include <Random>
using namespace std;

 
int Random_Number(int num)
{
	random_device rd; //

	mt19937 gen(rd()); //

	uniform_int_distribution<int> dis(0, num); //

	return dis(gen);
}

int Rest_Hp(Player_Char &Player, Monster &monster)
{
	cout << Player.Name << " �� ���� !" << endl; //
	double Damage = (double)Player.Damage * (1 + ((double)Random_Number(Player.stat[str]) / 10)); //
	cout << Player.Name + " ��(��)�� Damage : " << (int)Damage << endl;
	monster.Hp -= (int)Damage; //
	if (monster.Hp < 0)
	{
		monster.Hp = 0;
	}
	cout << monster.Name << " �� ���� HP : " << monster.Hp << endl;
	return monster.Hp;
}

int Rest_Hp(Monster &Monster, Player_Char &Player)
{
	cout << Monster.Name << " �� ���� !" << endl; //
	double Damage = Monster.Damage * (1 + ((double)Random_Number(Player.stat[str]) / 10)); //
	cout << Monster.Name + " ��(��)�� Damage : " << (int)Damage << endl;
	Player.Hp -= (int)Damage; //
	if (Player.Hp < 0)
	{
		Player.Hp = 0;
	}
	cout << Player.Name << " �� ���� HP : " << Player.Hp << endl;
	return Player.Hp;
}
//���� ���ߴ� �̸��� ������ �Ķ���Ϳ� ���� ȣ��Ǵ� �Լ��� �ٸ���.


int Connet_Monster(string mon)
{
	int Player_Answer(99); //
	while (Player_Answer != 1 && Player_Answer != 2)
	{
		cout << "���濡 " << mon << "�� ��Ÿ����! " << endl;
		cout << "1 : �ο��\t2. : ��������" << endl;
		cin >> Player_Answer;
	}

	return Player_Answer;
}

int Fight_Start_Tuto(Player_Char &Player, Monster &Monster)
{
	do
	{
		if (Player.stat[speed] >= Monster.Speed)
		{
			do
			{
				cout << "�ൿ�� ���� �ϼ���." << endl;
				cout << "1.����, 2. ��������" << endl;
				cin >> Player.Answer; //
			} while (Player.Answer >= 3);

			if (Player.Answer == 1)
			{
				Monster.Hp = Rest_Hp(Player, Monster); //
				if (Monster.Hp == 0)
				{
					cout << "�������� �̰��!" << endl;

					Player.Exp += 10;
					cout << "���� EXP : " << Player.Exp << endl;
					cout << "���� HP : " << Player.Hp << endl;
					After_fignt(Player);
				}
				return 0;
			}
			else
			{
				int Run_p = Random_Number(Player.stat[speed]); //
				int Run_m = Random_Number(Monster.Speed); //

				if (Run_p > Run_m)
				{
					cout << " �������� !" << endl;
					return 0; // �Լ��� ����! ��ɾ��� ���� ���
				}
				else
				{
					cout << "���� �� �� ����!" << endl;
				}

			}
			Player.Hp = Rest_Hp(Monster, Player); //
			if (Player.Hp == 0)
			{
				cout << "�������� ����." << endl;
				Revival(Player);
				return 0;
			}
		}
		else
		{
			Player.Hp = Rest_Hp(Monster, Player); //
			if (Player.Hp == 0)
			{
				cout << "�������� ����." << endl;
				Revival(Player);
				return 0;
			}
			do
			{
				cout << "�ൿ�� ���� �ϼ���." << endl;
				cout << "1.����, 2. ��������" << endl;
				cin >> Player.Answer;
			} while (Player.Answer >= 3);

			if (Player.Answer == 1)
			{
				Monster.Hp = Rest_Hp(Player, Monster);
				if (Monster.Hp == 0)
				{
					cout << "�������� �̰��.!" << endl;
					Player.Exp += 10;
					cout << "���� EXP : " << Player.Exp << endl;
					cout << "���� HP : " << Player.Hp << endl;
					After_fignt(Player);
					return 0;
				}
			}
			else
			{
				int Run_p = Random_Number(Player.stat[speed]); //
				int Run_m = Random_Number(Monster.Speed); //

				if (Run_p > Run_m)
				{
					cout << " �������� !" << endl;
					return 0; // �Լ��� ����! ��ɾ��� ���� ���
				}
				else
				{
					cout << "���� �� �� ����!" << endl;
				}
			}
		}


	} while (Player.Hp != 0 && Monster.Hp != 0);
	return 0;


}
//��ų ��� �߰��� �ο� ����.  <- ���� � �̸� �������� �Լ��� �� Ȱ���ؼ�...


void skill_selection(Player_Char& Player,Monster& Monster)
{
	cout<<"��ų�� ��� �ֽʽÿ� : 1.��������, 2. ���, 3. ���׽ý�, 4. ������" << endl;
	cin >> Player.Answer;
	switch (Player.Answer)
	{
	case 1:
		cout << "�������� �ߵ� !" << endl;
		AngelRey(Player, Monster);
		break;
	case 2:
		cout << "��� �ߵ� !" << endl;
		//BigBang();
		break;
	case 3:
		cout << "���׽ý� �ߵ� !" << endl;
		//Genesis();
		break;
	case 4:
		cout << "����� ���� �ߵ� !" << endl;
		//HeavensDoor();
		break;
	}
}
//1. switch ���� ���� 
//2. �Լ��� �ϼ�.
