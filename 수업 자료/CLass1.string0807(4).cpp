#include<iostream>
#include<string>

using namespace std;

int main()
{
	cout << "Please enter tour first name :";
	string name;
	cin >> name;

	const string greeting = "Hello, " + name + '!';

	const int pad(1);
	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;

	cout << endl;

	for (int r = 0; r != rows; ++r)
	{
		string::size_type c = 0;
		while (c != cols)
		{
			if (r == pad + 1 && c == pad + 1)
			{
				cout << greeting;
				c += greeting.size();

			}
			else
			{
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
				{
					cout << "*";

				}
				else
				{
					cout << " ";
				}
				++c;
			}

		}
		cout << endl;
	}

	return 0;

}



/*
x.y x[y],x++, x--

++x,--y, !x

x*y, x/y, x%y

x+y, x-y

x>>y x<<y

x relop y <= >= < >

x==y x!=y

x&&y 

x||y

x=y

x op= y +=,-=, *= ...

x?y:z -> x亜 凧戚檎 y研 鋼発 x亜 暗憎戚檎 z研 鋼発

*/

//string ::size_type : 乞窮 庚切伸税 滴奄研 煽舌拝呪 赤澗 採硲亜蒸澗 舛呪展脊
//size_t : 乞窮 梓端税 滴奄研 煽舌拝 呪 赤澗 採硲亜 蒸澗 舛呪展脊

//=> unsigned int
//<cstddef>

掻娃壱紫, 奄源壱紫 曽杯引薦繊呪 -> 置曽繊呪
20			40			40
-> 置曽繊呪研 姥馬澗 覗稽益轡

俳持呪澗 け?ぉ 

俳持 戚硯 : 
掻娃 繊呪 : 
奄源 繊呪 :
引薦 繊呪 : 

俳持 戚硯 :
掻娃 繊呪 :
奄源 繊呪 :
引薦 繊呪 :

俳持 戚硯 :
掻娃 繊呪 :
奄源 繊呪 :
引薦 繊呪 :

俳持 戚硯 :
掻娃 繊呪 :
奄源 繊呪 :
引薦 繊呪 :

俳持 戚硯 :
掻娃 繊呪 :
奄源 繊呪 :
引薦 繊呪 :

俳持 戚硯 :
掻娃 繊呪 :
奄源 繊呪 :
引薦 繊呪 :

俳持 戚硯 :
掻娃 繊呪 :
奄源 繊呪 :
引薦 繊呪 :


<<愚爽 企俳嘘 俳持 繊呪妊>>
俳持 戚硯 : ししし, 掻娃 : 奄源 : 曽杯引薦 : 置曽 : 
俳持 戚硯 : ししし, 掻娃 : 奄源 : 曽杯引薦 : 置曽 : 
俳持 戚硯 : ししし, 掻娃 : 奄源 : 曽杯引薦 : 置曽 : 
俳持 戚硯 : ししし, 掻娃 : 奄源 : 曽杯引薦 : 置曽 : 
俳持 戚硯 : ししし, 掻娃 : 奄源 : 曽杯引薦 : 置曽 : 
<<愚爽 企俳嘘 俳持 繊呪妊 魁>>

