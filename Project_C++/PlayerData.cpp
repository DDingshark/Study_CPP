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
			cout << "스텟을 찍어 주십시오 1.str 2. Speed, 3. intel " << endl;
			cin >> stat_answer;
			if (stat_answer <= 3)
			{
				Player.stat[stat_answer] += 1;
				stat--;
			}
			else
			{
				cout << "잘못된 숫자입니다" << endl;
			}
		}
		stat = 1;
		while (stat != 0)
		{
			cout << "스킬 스텟을 찍어 주십시오 1.엔젤레이 , 2. 빅뱅, 3. 제네시스, 4. 헤븐즈도어" << endl;
			cin >> Player.Answer;
			if (Player.Answer <= 4)
			{
				Player.skill[Player.Answer] += 1;
				stat -= 1;

			}
			else
			{
				cout << "잘못된 선택 입니다 " << endl;
			}
		}

	}
}


void Revival(Player_Char& Player)
{
	cout << "전사 하셨습니다 " << endl;
	cout << "HP 50 인 상태로 부활합니다 " << endl;
	Player.Hp = 50;
}

void AngelRey(Player_Char& Player, Monster& Monster)
{
	if (Player.skill[0] >= 1 || Player.Mp >= 10)
	{
		cout << "엔젤 레이!" << endl;
		int Damage = (Player.Damage + (Player.skill[0] * 3 * Player.stat[intel]));
		Monster.Hp -= Damage;
		cout << "엔젤레이의 데미지 : " << endl;
		cout << "Monster 의 남은 HP : " << Monster.Hp << endl;
		Player.Mp -= 10;
	}
}