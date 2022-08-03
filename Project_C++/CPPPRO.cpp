#include<iostream>
#include<random>
#include<string>
#include<cstdlib>

#include"Login.h"
using namespace std;
enum spectrum { str, speed, intel}; //
struct Player_Char
{

	string Name;
	int Leval;
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
//����ü!

struct Monster
{
	string Name;
	int Hp;
	int Speed;
	int Damage;
};


int Random_Number(int num)
{
	random_device rd; //

	mt19937 gen(rd()); //

	uniform_int_distribution<int> dis(0, num); //

	return dis(gen);
}
//������ �����ϴ� �Լ� 



int Rest_Hp(Player_Char Player, Monster Monster)
{
	cout << Player.Name << " �� ���� !" << endl; //
	double Damage = (double)Player.Damage * (1 + ((double)Random_Number(Player.stat[str]) / 10)); //
	cout << Player.Name + " ��(��)�� Damage : " << (int)Damage << endl; 
	Monster.Hp -= (int)Damage; //
	if (Monster.Hp < 0)
	{
		Monster.Hp = 0;
	}
	cout << Monster.Name << " �� ���� HP : " <<Monster.Hp<< endl;
	return Monster.Hp;
}

int Rest_Hp(Monster Monster, Player_Char Player)
{
	cout << Monster.Name << " �� ���� !" << endl; //
	double Damage = Monster.Damage * (1 + ((double)Random_Number(Player.stat[str]) / 10)); //
	cout << Monster.Name + " ��(��)�� Damage : " << (int)Damage << endl; 
	Player.Hp -= (int)Damage; //
	if (Player.Hp < 0)
	{
		Player.Hp = 0;
	}
	cout << Player.Name << " �� ���� HP : "<<Player.Hp << endl;
	return Player.Hp;
}
//���� ���ߴ� �̸��� ������ �Ķ���Ϳ� ���� ȣ��Ǵ� �Լ��� �ٸ���.


int Connet_Monster(string mon)
{
	int Player_Answer(99); //
	while (Player_Answer != 1 && Player_Answer != 2)
	{
		cout << "���濡 " << mon << "�� ��Ÿ����! " << endl;
		cout << "1 : �ο��\t2. : ��������" << endl;
		cin >> Player_Answer;
	}

	return Player_Answer;
}

int Fight_Start(Player_Char Player, Monster Monster) 
{
	do
	{
		if (Player.stat[speed] >= Monster.Speed)
		{
			do
			{
				cout << "�ൿ�� ���� �ϼ���." << endl;
				cout << "1.����, 2. ��������" << endl;
				cin >> Player.Answer; //
			} while (Player.Answer>=3);

			if (Player.Answer == 1)
			{
				Monster.Hp = Rest_Hp(Player, Monster); //
				if (Monster.Hp == 0)
				{
					cout << "�������� �̰��!" << endl;
				}
				return 0;
			}
			else
			{
				int Run_p = Random_Number(Player.stat[speed]); //
				int Run_m = Random_Number(Monster.Speed); //

				if (Run_p > Run_m)
				{
					cout << " �������� !" << endl; 
					return 0; // �Լ��� ����! ��ɾ��� ���� ���
				}
				else
				{
					cout << "���� �� �� ����!" << endl;
				}

			}
			Player.Hp = Rest_Hp(Monster, Player); //
			if (Player.Hp == 0)
			{
				cout << "�������� ����." << endl;
				return 0;
			}
		}
		else
		{
			Player.Hp = Rest_Hp(Monster, Player); //
			if (Player.Hp == 0)
			{
				cout << "�������� ����." << endl;
				return 0;
			}
			do
			{
				cout << "�ൿ�� ���� �ϼ���." << endl;
				cout << "1.����, 2. ��������" << endl;
				cin >> Player.Answer;
			} while (Player.Answer >= 3);

			if (Player.Answer == 1)
			{
				Monster.Hp = Rest_Hp(Player, Monster);
				if (Monster.Hp == 0)
				{
					cout << "�������� �̰��.!" << endl;
					Player.Exp += 10;
					Player.stat[1] += 1;
					return 0;
				}
			}
			else
			{
				int Run_p = Random_Number(Player.stat[speed]); //
				int Run_m = Random_Number(Monster.Speed); //

				if (Run_p > Run_m)
				{
					cout << " �������� !" << endl;
					return 0; // �Լ��� ����! ��ɾ��� ���� ���
				}
				else
				{
					cout << "���� �� �� ����!" << endl;
				}
			}
		}
	
		
	} while (Player.Hp != 0 && Monster.Hp != 0);
	return 0;
	// �ٴ�... ���ϱ� ���⼭ HP�� �� ������ ���Ƶ� �ᱹ�� �ο� ������ ȸ���Ǵ´�??

	// �̰� ����! �ؼ� �����ϱ�!
	// �׷� ������ �����ϰ� ������ ��� �ؾߴ�?
	// ������� ������ �˸� �Ǵ´� �̰� �����͸� �˾ƾ��մϴ�
	// ���� �ð����� �����͸� ���ؼ� ���� ������ ������ ����� ���ƿ�.

}


int main()
{
	int Player_Answer; //
//	Login_Func();
	cout << "ĳ���͸� ���� �մϴ�. �г����� �����ּ��� : " << endl;
	Player_Char Player{" ",1,0,100,100,10,{1,1,1}}; //
	cin >> Player.Name;

	cout << " ���ڱ� ������ ��Ÿ�� ��簡 �׿��� �Ѵٴ� �� �׷� �̾߱�" << endl;


	Monster Dog{ "Dog",11,2,10 }; //
	Player_Answer = Connet_Monster(Dog.Name);
	if (Player_Answer == 1)
	{
		Fight_Start(Player, Dog);
	}
	else
	{
		cout << "������ ��������" << endl;
	}
	cout << Player.stat[1] << endl;
	cout <<"���� EXP : " << Player.Exp << endl;//��?? ������ġ....
	cout << "���� HP : " << Player.Hp << endl;
	return 0;
}
//���� -> �̶� ���� �ϳ��ϳ����� ����(���� ���� ���� �Ҹ�)�� ������ ������ �Ǵ��غ���.
