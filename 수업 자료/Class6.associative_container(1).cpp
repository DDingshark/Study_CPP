//
// vector,string ->순차컨테이너 
// 
//	순차컨테이너의 장점 -> 순서를유지, 반복자를 이용한 알고리즘
//					
// 단점-> 요소의 값이 42인 요소를찾을때 -> 전체 요소의 갯수가 엄청많으면? ->프로그램의 속도 느려짐
//			sol. 1. 존나 쩌는 알고리즘을 만든다 ->너무 어려움
//			sol. 2. 그냥 느린 프로그램을 사용하다 ->해결책 x
// 
//			sol. 3 연관컨테이너를 사용한다. 
// 
// 연관컨테이너 -> 삽입한 순서가 아닌 값의 순서로 자동정렬을 한다. -> 직접 컨테이너를 조작할 필요가없이 훨신 빠르게 
//		특정 요소를 찾을수 잇음.
//		(정렬 알고리즘 사용X ->그냥 c++에 몸을 맡겨용)
// 
//	+key 추가정보를 포함할 수 있음.
//		=> 알겠다만, index와 같은 기능을 함 
//	
// 
// 가장 기본적인 구조 -> key-value 구조
//		=> 연관 배열(associative array) C++에서의 일반적인 연관 배열을 map이고 <map>에있음
//
//

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;
int main()
{
	string s;
	//각 단어의 빈도를 저장하는 맵
	//입력을 읽으면서 각 단어와 빈도를 저장시킴
	map<string, int> counters;
	//map<key Type, vlaue Type> map name;
	//한국어로 문자열 타입에서 int타입으로의 맵 이라고 합니다.
	while (cin >> s)
	{
		++counters[s];
		//key값은 index처럼 사용하여 연관된 value를 하나 더함 -> 빈도 증가
		// + 값초기화 value_initialize int타입의 value면 0으로 초기화 시켜줌
	}

	//단어와 빈도를 출력
	for (map<string, int>::const_iterator it = counters.begin();
		it != counters.end(); it++)
	{
		cout << it->first << "\t" << it->second << endl;
		// 맵컨테이너는 라이브러리 타입인 pair을 제공 -> first와 second가 있는 데이터 구조
		// 키를 포함하는 first와 값을 포함하는 second가 있음. pair의 값을 반복자를 통해 역참조시킴
		// pair<const K,V>로 구성되어있음.

		//map -> pair타입으로 바꿈 -> 역참조해서 값을 빼옴
		//뭐 이렇게 이해해도 되고, 아니면 그냥 key가 앞에있으니까 뭐.. first겠지뭐
		//key는 const로 설정된다는것만 기억.
	}

	return 0;

}


//상호 참조 테이블
//	입력한 문자열에서 각 단어의 위치를 나타내는 것을 만들어봄 (뭐 dding이라는 단어가 몇행,몇행,몇행에 나왔다 이런식)
//
// 
// 한번에 한 단어씩만 입력 받는게 아닌 한번에 한 행씩 읽어들여서(getline) 행번호화 단어를 연관 시킴.
//	->한 행을 단어들로 나눠서 저장.(split?	+ vector<string>에 저장
//
//기존에 만들었던 split활용
bool space(char c)
{
	return isspace;
}

bool notspace(char c)
{
	return !isspace(c);
}
//end

vector<string>split(const string& s) //원본은 항상 보존 + 참조형식으로 불러오는 이유는 복사하는 메모리 릭을 방지
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size())
	{
		while (i != s.size() && isspace(s[i]))
			//선행하는 공백들을 무시 isspace -> 해당 문자자 공백인지 판단
		{
			++i;
		}

		//순서상 다음 단어의 끝을 찾음
		string_size j = i;


		while (j != s.size() && !isspace(s[j]))
		{
			j++;
		}

		// 공백이 아닌 문자들을 찾았을때
		if (i != j)
		{
			//i에서부터 j-i개의 문자들을 s에 복사
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}
//기존에 만들었던 split활용
map < string, vector<int>> xref(istream& in, vector<string>find_words(const string&) = split)
																			//디폴트 파라미터(default parametor) -> 따로 지정해주지 않으면 그냥 이값을 대입.
																			//기본 인수 (defalut argument)라고도 하는대 사실 함수든 파라미터든 딱히 상관 안하고 막쓰는듯?
{
	string line;
	int line_number = 0;
	map < string, vector<int> >ret;
							//>>요롷게 하면 연산자 취급이니까 >' '>요로코롬 공백하나 주기.

	while (getline(in, line)) 
	{
		++line_number;

		vector<string>words = find_words(line);

		for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
			ret[*it].push_back(line_number);
		//*it는 입력한 행을 구성하는 단어중 하나
		// 그 단어를 맵의 인덱스로 활용 ->ret[*it]는 맵의 인덱스가 저장된 값을 반환 -> 해당 단어가 등장한 행 번호를 저장한 값
		//	vector<int>타입 객체 -> push_back을 호출하여 행 번호를 추가 
		//
		//
	}
	return ret;
}

//xref(cin) vs xref(cin, find_urls);뭐 이런식

//디폴트 파라미터 설명
/*
int sum(int a, int b = 3) //sum(int a=3,intb)이런건 절대못함 -> 컴파일러가 사람도 아니고 sum(4)이러면 어디에 넣으라는건대...
{
	return a + b;
}
int main()
{
	int a(0);
	int c(7);
	sum(a);		-> 3
	sum(a,c);	-> 7 
	//따로 말하지 않아도 기본값이 알아서 들어감
	compare선언 할때도 (begin,end) vs (begin,end,compare) 선언했던것처럼
	따로 말하지 않으면 그냥 설정한 값이 들어감 -> caller만보고 callee예측 절대 못함 특히 객체지향언어에서
}
*/

int main()
{

	map<string, vector<int> > ret = xref(cin);

	for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it)
	{
		cout << it->first << " occurs on line(s): ";

		vector<int>::const_iterator line_it = it->second.begin();

		//해당 단어가 들어간 첫번째 행번호 출력.
		cout << *line_it;
		++line_it;

		//행번호 마저 출력. //이렇게 설계한 이유 -> 처음 것까지 while을 돌려버리면 3, ,3뭐 이런식의 출력이면 안이쁘니까..
		while (line_it != it->second.end())
		{
			cout << ", " << *line_it;
			++line_it;
		}
		cout << endl;
		//단어들을 구분하는 행
	}
}

