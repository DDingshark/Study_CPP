#include<iostream>
#include<vector>
#include<string>
#include<cctype> 
#include<iterator>
#include<algorithm> //대부분의 이 수업에서 수개하는 알고리즘은 다 여기있음
using namespace std;
/*
	1. 문자열 분석
		2개의 문자열을 합치는 방법
		for(vector<string>::const_ilterator it=bottom.begin();it!=bottom.end();++i
			{
				ret.push_back(*it)
			}
		//뭐 이런식의 코드 진행도 했었었고 ->문자열(문자들의 컨테이너)이라는 것에 초점

		ret.insert(ret.end(),bottom.begin(),bottom(end));
		//이런식의 코드 진행도 있었음 -> 백터가 제공하는 연산을 이용

		->좀더 보편적인 문제해결
		copy(bottom.begin(),bottom.end(),back_inserter(ret));
			->copy는 제너릭(generic) 알고리즘 , back_inserter()함수는 반복자 어댑터

		제너릭 알고리즘 -> 특정 종류의 컨테이너에 속하지 않으며 인수의 타입으로 데이터에 접근하는 방법을 
			제공하는(?) 포함하는(?)알고리즘
			->일반적으로 컨테이너의 요소를 조작하는대 반복자를 사용함(임의적접근을 제공하지 X친구들을 배려)
			  by. 반복자 인수를 통해 begin,end,out이 인수로 있는 copy알고리즘은 out에서 시작하는 요소들이 순차열에 필요한만큼 공간을 확장하여 복사

		copy(begin,end,out)
		==
		while(begin!=end)
		{
			*out++ = *begin++;(연산 진행후에 더해야 함으로 후위증감식을 사용)
		}

		그래서 반복자 어뎁터가 뭔대(iterator adaptor) iterator에 정의 
		일반적으로 back_insertor 사용하려고 인클루드 시킴 -> 컨테이너를 인수로 사용하며 , 컨테이너의 값을 추가할
		목적지인 반복자를 반환 

		왜 이렇게 설계했냐! 그러면 1. 컨테이너의 확장과 요소추가를 개념적으로 분리시킬려고 -> 알아서 잘 알아보세용		
*/

/*
	1-2. 새로운 split
*/

//공백 여부 확인
bool space(char c)
{
	return isspace;
}

bool notspace(char c)
{
	return !isspace(c);
}
//end

vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	vector<string>ret;
	iter i = str.begin();
	while (i != str.end())
	{
		//선행공백 무시
		i = find_if(i,str.end(), notspace);

		//다음단어의 끝을 찾음
		iter j = find_if(i, str.end(), space);

		//[i,j]범위의 문자를 복사 
		if(i != str.end())
			ret.push_back(string(i, j));
		i = j;
	}
	return ret;
}
/*
	finde_if(1,2,3) 1,2는 순차열을 나타내는 반복자, 3은 서술함수->인수를 검사하여 참,거짓 반환
		->참을 반환하는 요소를 찾으면 함수 종료
		-> 끝까지 못찾으면 2를 반환 

	앞서 정의한 split와의 차이 -> 숙제

*/


//우영우 문제해설
bool is_palindrome(const string& s)
{
	return equal(s.begin(), s.end(), s.rbegin());
}
//equal -> 순서가 반대인 두 문자열이 같은 값인지 판별하는 함수 (1,2)의 반복자는 처음과 끝 , 3은 2의 시작점을 나타냄
	//크기가 같다고 가정하고 진행하는 함수

//URL찾기
/*
	어떤 문서를 훑고 그안에 있는 url을 찾아 서 반환 
	url -> 포로토콜 이름 :// 리소스 이름 
		=> 문자열 인수를 전달받아 해당 문자열이 포함하는 ://을 찾은 뒤에 앞뒤에 있는 이름들을 찾을기능 
*/

vector<string> find_urls(const string& s)
{
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();

	while (b != e)
	{
		b = url_beg(b, e);
		if (b != e)
		{
			iter after = url_end(b, e);

			ret.push_back(string(b, after));

			b = after;
		}
	}
	return ret;
}

//url_beg , url_after 의 고민
// text http :// www.navmer.com more text
//    b=uel_beg(b,e)                after =url_end(b,e)
// b-> 유효한 url이 있는지 식별하여 url이면 프로토콜의 이름의 첫번째 문자를 참조하는 반복자를 반환 
// 못했으면 e를 반환

// end -> url을 찾아주면 url의 끝을 찾아서 반환

string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
	return find_if(b, e, not_url_char);
}

bool not_url_char(char c)
{
	static const string url_ch = "~;/?:@=&$-_+!*'(),"; //url 에 들어갈 수 있는 앟파벳과 숫자 이외의 문자


	//c가 urlㅇ 들어갈수 있는 문자인지 확인하면 음수를 반환 
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());

}

//스토리지 클래스 저장자 (storage class specifier )  = static의 full name
//isalnum -> cctype에정의 -> 인수로 전달한 문자가 알파벳이나 숫자인지 여부 판별 
//find -> find_if의 세번째 인수호출 하는대신 세번째 인수의 특정 값을 찾는 알고리즘

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
	static const string sep = ";//";
	typedef string::const_iterator iter;

	//i는 구분 기호를 발견한 위치를 표시
	iter i = b;
	while ((i = search(i, e, sep.begin(), sep.end())) != e)
	{
		//구분기호가 현태 탑색 볌위의 처음 또는 마지막에 있는지 확인
		if (i!= b && i + sep.size() != e)
		{
			//beg는 프로토콜의 시작위치 표기
			iter beg = i;
			while (beg != b && isalpha(beg[-1]))
			{
				--beg;
			}

			//구분기호 앞뒤로 url의 일부에서 유효한 문자가 하나하도 있는지 확인
			if (beg != i && !not_url_char(i[sep.size()]))
			{
				return beg;
			}
			//발견한 구분기호는 url일부가 아니므로 해당구분 기호 이후를 표시하도록 i를 증가.
			i += sep.size();
		}
		return e;
	}
}
int main()
{

	return 0;
}