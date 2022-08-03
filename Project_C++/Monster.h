#pragma once
using namespace std;
struct Monster
{
	string Name;
	int Hp;
	int Speed;
	int Damage;
};

void Creat_Monster(Monster& Monster, int level);