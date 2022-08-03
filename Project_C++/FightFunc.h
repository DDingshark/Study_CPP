#pragma once
#include"PlayerData.h"
#include"Monster.h"

using namespace std;
int Random_Number(int num);
int Rest_Hp(Player_Char &Player, Monster& Monster);
int Rest_Hp(Monster &Monster, Player_Char& Player);
int Fight_Start_Tuto(Player_Char& Player, Monster& Monster);
int Connet_Monster(string mon);
void skill_selection(Player_Char& Player, Monster Monster);


























