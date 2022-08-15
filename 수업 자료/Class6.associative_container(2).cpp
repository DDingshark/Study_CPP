//예시 2 문장 만들기 ->죄끔 유명한 퍼온문제

// 영어 -> 문장
//	명사 +동사
// 명사 동사 목적어 뭐 이런식으로 구성 -> 임의 문장을 만들어 주는 프로그램
//
/*
	table
	category		rule
	<noun>			cat
	<noun>			dog
	<noun>			table
	<noun_phrase>	<noun>
	<noun_phrase>	<adjective>, <noun_phrase>
	<adjective>		large
	<adjective>		brown
	<verb>			jumps
	<verb>			sits
	<location>		on the stairs
	<location>		under the sky
	<location>		wherever it wants
	<sentence>		the <noun_phrase> <verb> <location>

*/

// 이 프로그램이 the table jumps whereever it wants 라는 문장을 만드는 과정을살펴보면서 프로그램의 작동과정을 설계
//프로그램의 처음 -> 문장을 만드는 규칙을 찾는 동작 실행 -> <sentance> the <noun_phrase> <verb> <location>
//먼저 프로그램은  <noun_phrase>에 해당하는 규칙을 임의 선택 <noun_phrase> 
// table을 사용하고 ~~~ location까지 가서 문장을 완성 하게되는 뭐 그런 프로그램이 될것 같은대

//1. 문법 테이블 포현 
//	문법 테이블이 <카테고리> 와 일반 단어로 구성
//	각 가테고리는 하나이상의 규칙이 있으며, 일반 단어에는 그냥 일반 단어가 있음.
//	프로그램이 < >묶인 문자열을 발견한다면 해당 문자열은 카테고리 임으로 이와 연관된 규칙을 찾아 오른쪽 방향으로 확장
//  <>묶이지 않은 문자열이 있다면 문장에 직접 배치가능
// 
//	으... 일단 sectance를 만드는 규칙을 찾은후 -> 해당 규칙에서 noun_phrase,verb,location의 규칙을 한번 더 타고 가야할거같은대..
//	map<K.V> -> K는 string타입으로 <rule> 뭐 이렇게 한다치자... 하... 앞에 the도 있내
//				상관은 없내 
//				'the'와 카테로기를 key로 갖는 map을 만들고 value로 vector<string>을 사용해서 하나씩 가져올수 있게.
// 

#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <map> 

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

/* 인자가 공백문자이면 true, 그렇지 않다면 false를 리턴 */
bool space(char c)
{
    return isspace(c);
}

/* 인자가 공백문자이면 false, 그렇지 않다면 ture를 리턴 */
bool not_space(char c)
{
    return !isspace(c);
}

vector<string> split(const string& str)
{
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = str.begin();

    while (i != str.end())
    {
        // 맨 앞의 빈칸을 무시 
        i = find_if(i, str.end(), not_space);

        // 단어의 끝을 검색 
        iter j = find_if(i, str.end(), space);

        // [i,j) 범위의 단어를 복사 
        if (i != str.end())
            ret.push_back(string(i, j));

        // 다음 단어를 검색 
        i = j;
    }
    return ret;
}

Grammar read_grammar(istream& in)
{
    Grammar ret;
    string line;

    while (getline(in, line))
    {
        vector<string> entry = split(line);

        // 
        if (!entry.empty())
            ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }
    return ret;

}

int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");

    const int bucket_size = RAND_MAX / n; // 32767 / 10 3276 

    int r;

    do    r = rand() / bucket_size;
    while (r >= n); //  

    return r;
}

bool bracketed(const string& s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
    // 입력 string이 각괄호로 둘러쌓여있지 않다면 그 자체로 출력의 일부가 된다. 
    if (!bracketed(word))
    {
        ret.push_back(word);
    }
    else
    {
        Grammar::const_iterator it = g.find(word);

        if (it == g.end())
            throw logic_error("empty rule");

        const Rule_collection& c = it->second;

        const Rule& r = c[nrand(c.size())];

        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
    }
}

vector<string> gen_sentence(const Grammar& g)
{
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

int main()
{
    vector<string> sentence = gen_sentence(read_grammar(cin));

    vector<string>::const_iterator it = sentence.begin();

    if (!sentence.empty())
    {
        cout << *it;
        ++it;
    }

    while (it != sentence.end())
    {
        cout << " " << *it;
        ++it;
    }
    cout << endl;

    return 0;
}