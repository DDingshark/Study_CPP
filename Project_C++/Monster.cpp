#pragma once
#include<iostream>
#include"Monster.h"
#include"FightFunc.h"
using namespace std;

void Creat_Monster(Monster& Monster, int level)
{
	string Name;
	cout << "몬스터의 이름을 설정해 주십시오" << endl;
	cin >> Name;
	Monster.Name = Name;
	Monster.Hp = 10 * Random_Number(level);
	Monster.Damage = 10 + Random_Number(level);
	Monster.Speed = level;
}


