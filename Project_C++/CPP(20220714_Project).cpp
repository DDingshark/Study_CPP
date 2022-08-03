#include<iostream>
#include<random>
#include<string>
#include<cstdlib>

#include"Monster.h"
#include"PlayerData.h"
#include"Answer.h"
#include"Login.h"
#include"FightFunc.h"

using namespace std;



int main()
{
	int Player_Answer; //
//	Login_Func();
	cout << "캐릭터를 생성 합니다. 닉네임을 적어주세요 : " << endl;

	Player_Char Player{" ",1,0,100,100,10,{1,1,1}}; //
	cin >> Player.Name;

	cout << " 갑자기 마왕이 나타나 용사가 죽여야 한다는 뭐 그런 이야기" << endl;


	Monster Dog{ "Dog",11,2,10 }; //
	Player_Answer = Connet_Monster(Dog.Name);
	if (Player_Answer == 1)
	{
		Fight_Start_Tuto(Player, Dog);
	}
	else
	{
		cout << "무사히 도망갔다" << endl;
	}
	


	Monster Cat;
	Creat_Monster(Cat, 2);
	Player_Answer = Connet_Monster(Cat.Name);
	if (Player_Answer == 1)
	{
		Fight_Start_Tuto(Player, Cat);
	}
	else
	{
		cout << "무사히 도망갔다" << endl;
	}

	return 0;
}



// 숙제 :
// 크기가 100인 int 형 배열을 오름차순과 내림차순으로 정렬. 안하면 도망 8/첫주 주말수업까지. 
// + 변수의 생명.(2주짜리)





