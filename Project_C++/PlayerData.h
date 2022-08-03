#pragma once
#include"Monster.h"
using namespace std;

enum spectrum { str, speed, intel }; 
enum skill_name {엔젤레이, 빅뱅, 제네시스, 헤븐즈도어};
struct Player_Char
{

	string Name;
	int Level;
	double Exp;
	int Hp;
	int Mp;
	int Damage;
	int stat[3] = { 0, };
	// ap 는 힘 스피드, 지력까지만 
	int skill[4] = { 0, };
	//캐릭터당 최대 스킬은 4개
	int Answer;
};

void After_fignt(Player_Char& Player);
void Revival(Player_Char& Player);


void AngelRey(Player_Char& Player, Monster& Monster);

