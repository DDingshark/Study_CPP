//���� 2 ���� ����� ->�˲� ������ �ۿ¹���

// ���� -> ����
//	��� +����
// ��� ���� ������ �� �̷������� ���� -> ���� ������ ����� �ִ� ���α׷�
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

// �� ���α׷��� the table jumps whereever it wants ��� ������ ����� ���������캸�鼭 ���α׷��� �۵������� ����
//���α׷��� ó�� -> ������ ����� ��Ģ�� ã�� ���� ���� -> <sentance> the <noun_phrase> <verb> <location>
//���� ���α׷���  <noun_phrase>�� �ش��ϴ� ��Ģ�� ���� ���� <noun_phrase> 
// table�� ����ϰ� ~~~ location���� ���� ������ �ϼ� �ϰԵǴ� �� �׷� ���α׷��� �ɰ� ������

//1. ���� ���̺� ���� 
//	���� ���̺��� <ī�װ�> �� �Ϲ� �ܾ�� ����
//	�� ���װ��� �ϳ��̻��� ��Ģ�� ������, �Ϲ� �ܾ�� �׳� �Ϲ� �ܾ ����.
//	���α׷��� < >���� ���ڿ��� �߰��Ѵٸ� �ش� ���ڿ��� ī�װ� ������ �̿� ������ ��Ģ�� ã�� ������ �������� Ȯ��
//  <>������ ���� ���ڿ��� �ִٸ� ���忡 ���� ��ġ����
// 
//	��... �ϴ� sectance�� ����� ��Ģ�� ã���� -> �ش� ��Ģ���� noun_phrase,verb,location�� ��Ģ�� �ѹ� �� Ÿ�� �����ҰŰ�����..
//	map<K.V> -> K�� stringŸ������ <rule> �� �̷��� �Ѵ�ġ��... ��... �տ� the�� �ֳ�
//				����� ���� 
//				'the'�� ī�׷α⸦ key�� ���� map�� ����� value�� vector<string>�� ����ؼ� �ϳ��� �����ü� �ְ�.
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

/* ���ڰ� ���鹮���̸� true, �׷��� �ʴٸ� false�� ���� */
bool space(char c)
{
    return isspace(c);
}

/* ���ڰ� ���鹮���̸� false, �׷��� �ʴٸ� ture�� ���� */
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
        // �� ���� ��ĭ�� ���� 
        i = find_if(i, str.end(), not_space);

        // �ܾ��� ���� �˻� 
        iter j = find_if(i, str.end(), space);

        // [i,j) ������ �ܾ ���� 
        if (i != str.end())
            ret.push_back(string(i, j));

        // ���� �ܾ �˻� 
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
    // �Է� string�� ����ȣ�� �ѷ��׿����� �ʴٸ� �� ��ü�� ����� �Ϻΰ� �ȴ�. 
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