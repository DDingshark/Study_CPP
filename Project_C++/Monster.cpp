#pragma once
#include<iostream>
#include"Monster.h"
#include"FightFunc.h"
using namespace std;

void Creat_Monster(Monster& Monster, int level)
{
	string Name;
	cout << "������ �̸��� ������ �ֽʽÿ�" << endl;
	cin >> Name;
	Monster.Name = Name;
	Monster.Hp = 10 * Random_Number(level);
	Monster.Damage = 10 + Random_Number(level);
	Monster.Speed = level;
}


