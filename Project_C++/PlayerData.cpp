#pragma once
#include<iostream>
#include "PlayerData.h"
#include "Monster.h"
using namespace std;

void After_fignt(Player_Char& Player)
{
	if (Player.Exp >= Player.Level * 10)
	{
		cout << "***Level UP!*****" << endl;
		Player.Level += 1;
		Player.Exp = 0;
		int stat(3);
		unsigned int stat_answer;
		while (stat != 0)
		{
			cout << "������ ��� �ֽʽÿ� 1.str 2. Speed, 3. intel " << endl;
			cin >> stat_answer;
			if (stat_answer <= 3)
			{
				Player.stat[stat_answer] += 1;
				stat--;
			}
			else
			{
				cout << "�߸��� �����Դϴ�" << endl;
			}
		}
		stat = 1;
		while (stat != 0)
		{
			cout << "��ų ������ ��� �ֽʽÿ� 1.�������� , 2. ���, 3. ���׽ý�, 4. ������" << endl;
			cin >> Player.Answer;
			if (Player.Answer <= 4)
			{
				Player.skill[Player.Answer] += 1;
				stat -= 1;

			}
			else
			{
				cout << "�߸��� ���� �Դϴ� " << endl;
			}
		}

	}
}


void Revival(Player_Char& Player)
{
	cout << "���� �ϼ̽��ϴ� " << endl;
	cout << "HP 50 �� ���·� ��Ȱ�մϴ� " << endl;
	Player.Hp = 50;
}

void AngelRey(Player_Char& Player, Monster& Monster)
{
	if (Player.skill[0] >= 1 || Player.Mp >= 10)
	{
		cout << "���� ����!" << endl;
		int Damage = (Player.Damage + (Player.skill[0] * 3 * Player.stat[intel]));
		Monster.Hp -= Damage;
		cout << "���������� ������ : " << endl;
		cout << "Monster �� ���� HP : " << Monster.Hp << endl;
		Player.Mp -= 10;
	}
}