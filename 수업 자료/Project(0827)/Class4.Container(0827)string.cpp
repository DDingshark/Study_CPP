#include<iostream>
#include<string>
#include<vector>
#include<cctype> //isspace함수 사용
using namespace std;
/*
	문자열또한 컨테이너의 한 종류 
		문자열은 문자로만 구성되어있고, 전부는 아니지만, 컨테이너 연산 몇가지를 지원
*/

//문자열 분할
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

//문자열 결합 (테두리 입히기)
string::size_type width(const vector <string>&v)
//제일 긴 문자열 찾기
{
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != v.size(); ++i)
	{
		maxlen = max(maxlen, v[i].size());
	}
	return maxlen;
}

vector<string>frame(const vector<string>& v)
{
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');

	//상단 테두리를 추가
	ret.push_back(border);

	//양 끝이 별표와 공백으로 둘러 싸인 문자열들을 추가
	for (vector<string>::size_type i = 0; i != v.size(); i++)
	{
		ret.push_back("* " + v[i] + string(maxlen = v[i].size(), ' ') + " *");
	}

	//하단 테두리 추가
	ret.push_back(border);
	return ret;
}

//수직 결함
vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
	//위 쪽 문자 그림을 복사
	vector<string> ret = top;
	//아래쪽 문자 그림을 복사
	for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it)
	{
		ret.push_back(*it);
	}
	// 라이브러이 이용하는 방법도 있음
	// ret.insert(ret.end(),bottom.begin(),bottom.end());
	return ret;
}

//수평 결합
vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;

	//두 문자 그림 사이에 공백 하나를 남김
	string::size_type width1 = width(left) + 1;

	//왼쪽 문자 그림과 오른쪽 문자 그림의 요소를 살펴보는 인덱스
	vector<string>::size_type i = 0, j = 0;

	//두 문자 그림의 모든 행을 살펴봄

	while (i != left.size() || j != right.size())
	{
		//두 문자 그림의 문자들을 저장 할 수있는 새로운 문자열을 생성
		string s;

		if (i != left.size())
		{
			s = left[i++];
		}

		//공백을 포함하여 문자열을 적절한 너비까지 채움
		s += string(width1 - s.size(), ' ');

		//오른쪽 문자 그림에서 행 하나를 복사
		if (j != right.size())
		{
			s += right[j++];
		}

		//새로운 문자 그림에 문자열 s를 추가
		ret.push_back(s);

	}
	return ret;
}

int main()
{
	string s;

	while (getline(cin, s)) //행 끝까지의 문자열을 입력받는 방법 
	{
		vector<string> v = split(s);

		for (vector<string>::size_type i = 0;
			i != v.size(); ++i)
		{
			cout << v[i] << endl;
		}
	}

	return 0;
}
