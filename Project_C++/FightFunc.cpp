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
	cout << Player.Name << " 의 공격 !" << endl; //
	double Damage = (double)Player.Damage * (1 + ((double)Random_Number(Player.stat[str]) / 10)); //
	cout << Player.Name + " 이(가)준 Damage : " << (int)Damage << endl;
	monster.Hp -= (int)Damage; //
	if (monster.Hp < 0)
	{
		monster.Hp = 0;
	}
	cout << monster.Name << " 의 남은 HP : " << monster.Hp << endl;
	return monster.Hp;
}

int Rest_Hp(Monster &Monster, Player_Char &Player)
{
	cout << Monster.Name << " 의 공격 !" << endl; //
	double Damage = Monster.Damage * (1 + ((double)Random_Number(Player.stat[str]) / 10)); //
	cout << Monster.Name + " 이(가)준 Damage : " << (int)Damage << endl;
	Player.Hp -= (int)Damage; //
	if (Player.Hp < 0)
	{
		Player.Hp = 0;
	}
	cout << Player.Name << " 의 남은 HP : " << Player.Hp << endl;
	return Player.Hp;
}
//전에 말했던 이름은 같지만 파라미터에 따라 호출되는 함수가 다르다.


int Connet_Monster(string mon)
{
	int Player_Answer(99); //
	while (Player_Answer != 1 && Player_Answer != 2)
	{
		cout << "전방에 " << mon << "이 나타났다! " << endl;
		cout << "1 : 싸우기\t2. : 도망가기" << endl;
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
				cout << "행동을 선택 하세요." << endl;
				cout << "1.공격, 2. 도망가기" << endl;
				cin >> Player.Answer; //
			} while (Player.Answer >= 3);

			if (Player.Answer == 1)
			{
				Monster.Hp = Rest_Hp(Player, Monster); //
				if (Monster.Hp == 0)
				{
					cout << "전투에서 이겼다!" << endl;

					Player.Exp += 10;
					cout << "얻은 EXP : " << Player.Exp << endl;
					cout << "남은 HP : " << Player.Hp << endl;
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
					cout << " 도망갔다 !" << endl;
					return 0; // 함수의 종료! 명령어라고 보면 댈듯
				}
				else
				{
					cout << "도망 갈 수 없다!" << endl;
				}

			}
			Player.Hp = Rest_Hp(Monster, Player); //
			if (Player.Hp == 0)
			{
				cout << "전투에서 졌다." << endl;
				Revival(Player);
				return 0;
			}
		}
		else
		{
			Player.Hp = Rest_Hp(Monster, Player); //
			if (Player.Hp == 0)
			{
				cout << "전투에서 졌다." << endl;
				Revival(Player);
				return 0;
			}
			do
			{
				cout << "행동을 선택 하세요." << endl;
				cout << "1.공격, 2. 도망가기" << endl;
				cin >> Player.Answer;
			} while (Player.Answer >= 3);

			if (Player.Answer == 1)
			{
				Monster.Hp = Rest_Hp(Player, Monster);
				if (Monster.Hp == 0)
				{
					cout << "전투에서 이겼다.!" << endl;
					Player.Exp += 10;
					cout << "얻은 EXP : " << Player.Exp << endl;
					cout << "남은 HP : " << Player.Hp << endl;
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
					cout << " 도망갔다 !" << endl;
					return 0; // 함수의 종료! 명령어라고 보면 댈듯
				}
				else
				{
					cout << "도망 갈 수 없다!" << endl;
				}
			}
		}


	} while (Player.Hp != 0 && Monster.Hp != 0);
	return 0;


}
//스킬 기능 추가한 싸움 구현.  <- 내가 몇개 미리 만들어놓은 함수를 잘 활용해서...


void skill_selection(Player_Char& Player,Monster& Monster)
{
	cout<<"스킬을 골라 주십시오 : 1.엔젤레이, 2. 빅뱅, 3. 제네시스, 4. 헤븐즈도어" << endl;
	cin >> Player.Answer;
	switch (Player.Answer)
	{
	case 1:
		cout << "엔젤레이 발동 !" << endl;
		AngelRey(Player, Monster);
		break;
	case 2:
		cout << "빅뱅 발동 !" << endl;
		//BigBang();
		break;
	case 3:
		cout << "제네시스 발동 !" << endl;
		//Genesis();
		break;
	case 4:
		cout << "헤븐즈 도어 발동 !" << endl;
		//HeavensDoor();
		break;
	}
}
//1. switch 문의 이해 
//2. 함수의 완성.
