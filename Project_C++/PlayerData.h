#pragma once
#include"Monster.h"
using namespace std;

enum spectrum { str, speed, intel }; 
enum skill_name {��������, ���, ���׽ý�, ������};
struct Player_Char
{

	string Name;
	int Level;
	double Exp;
	int Hp;
	int Mp;
	int Damage;
	int stat[3] = { 0, };
	// ap �� �� ���ǵ�, ���±����� 
	int skill[4] = { 0, };
	//ĳ���ʹ� �ִ� ��ų�� 4��
	int Answer;
};

void After_fignt(Player_Char& Player);
void Revival(Player_Char& Player);


void AngelRey(Player_Char& Player, Monster& Monster);

