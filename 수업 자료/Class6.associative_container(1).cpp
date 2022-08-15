//
// vector,string ->���������̳� 
// 
//	���������̳��� ���� -> ����������, �ݺ��ڸ� �̿��� �˰���
//					
// ����-> ����� ���� 42�� ��Ҹ�ã���� -> ��ü ����� ������ ��û������? ->���α׷��� �ӵ� ������
//			sol. 1. ���� ¼�� �˰����� ����� ->�ʹ� �����
//			sol. 2. �׳� ���� ���α׷��� ����ϴ� ->�ذ�å x
// 
//			sol. 3 ���������̳ʸ� ����Ѵ�. 
// 
// ���������̳� -> ������ ������ �ƴ� ���� ������ �ڵ������� �Ѵ�. -> ���� �����̳ʸ� ������ �ʿ䰡���� �ν� ������ 
//		Ư�� ��Ҹ� ã���� ����.
//		(���� �˰��� ���X ->�׳� c++�� ���� �ðܿ�)
// 
//	+key �߰������� ������ �� ����.
//		=> �˰ڴٸ�, index�� ���� ����� �� 
//	
// 
// ���� �⺻���� ���� -> key-value ����
//		=> ���� �迭(associative array) C++������ �Ϲ����� ���� �迭�� map�̰� <map>������
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
	//�� �ܾ��� �󵵸� �����ϴ� ��
	//�Է��� �����鼭 �� �ܾ�� �󵵸� �����Ŵ
	map<string, int> counters;
	//map<key Type, vlaue Type> map name;
	//�ѱ���� ���ڿ� Ÿ�Կ��� intŸ�������� �� �̶�� �մϴ�.
	while (cin >> s)
	{
		++counters[s];
		//key���� indexó�� ����Ͽ� ������ value�� �ϳ� ���� -> �� ����
		// + ���ʱ�ȭ value_initialize intŸ���� value�� 0���� �ʱ�ȭ ������
	}

	//�ܾ�� �󵵸� ���
	for (map<string, int>::const_iterator it = counters.begin();
		it != counters.end(); it++)
	{
		cout << it->first << "\t" << it->second << endl;
		// �������̳ʴ� ���̺귯�� Ÿ���� pair�� ���� -> first�� second�� �ִ� ������ ����
		// Ű�� �����ϴ� first�� ���� �����ϴ� second�� ����. pair�� ���� �ݺ��ڸ� ���� ��������Ŵ
		// pair<const K,V>�� �����Ǿ�����.

		//map -> pairŸ������ �ٲ� -> �������ؼ� ���� ����
		//�� �̷��� �����ص� �ǰ�, �ƴϸ� �׳� key�� �տ������ϱ� ��.. first������
		//key�� const�� �����ȴٴ°͸� ���.
	}

	return 0;

}


//��ȣ ���� ���̺�
//	�Է��� ���ڿ����� �� �ܾ��� ��ġ�� ��Ÿ���� ���� ���� (�� dding�̶�� �ܾ ����,����,���࿡ ���Դ� �̷���)
//
// 
// �ѹ��� �� �ܾ�� �Է� �޴°� �ƴ� �ѹ��� �� �྿ �о�鿩��(getline) ���ȣȭ �ܾ ���� ��Ŵ.
//	->�� ���� �ܾ��� ������ ����.(split?	+ vector<string>�� ����
//
//������ ������� splitȰ��
bool space(char c)
{
	return isspace;
}

bool notspace(char c)
{
	return !isspace(c);
}
//end

vector<string>split(const string& s) //������ �׻� ���� + ������������ �ҷ����� ������ �����ϴ� �޸� ���� ����
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size())
	{
		while (i != s.size() && isspace(s[i]))
			//�����ϴ� ������� ���� isspace -> �ش� ������ �������� �Ǵ�
		{
			++i;
		}

		//������ ���� �ܾ��� ���� ã��
		string_size j = i;


		while (j != s.size() && !isspace(s[j]))
		{
			j++;
		}

		// ������ �ƴ� ���ڵ��� ã������
		if (i != j)
		{
			//i�������� j-i���� ���ڵ��� s�� ����
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}
//������ ������� splitȰ��
map < string, vector<int>> xref(istream& in, vector<string>find_words(const string&) = split)
																			//����Ʈ �Ķ����(default parametor) -> ���� ���������� ������ �׳� �̰��� ����.
																			//�⺻ �μ� (defalut argument)��� �ϴ´� ��� �Լ��� �Ķ���͵� ���� ��� ���ϰ� �����µ�?
{
	string line;
	int line_number = 0;
	map < string, vector<int> >ret;
							//>>���� �ϸ� ������ ����̴ϱ� >' '>����ڷ� �����ϳ� �ֱ�.

	while (getline(in, line)) 
	{
		++line_number;

		vector<string>words = find_words(line);

		for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
			ret[*it].push_back(line_number);
		//*it�� �Է��� ���� �����ϴ� �ܾ��� �ϳ�
		// �� �ܾ ���� �ε����� Ȱ�� ->ret[*it]�� ���� �ε����� ����� ���� ��ȯ -> �ش� �ܾ ������ �� ��ȣ�� ������ ��
		//	vector<int>Ÿ�� ��ü -> push_back�� ȣ���Ͽ� �� ��ȣ�� �߰� 
		//
		//
	}
	return ret;
}

//xref(cin) vs xref(cin, find_urls);�� �̷���

//����Ʈ �Ķ���� ����
/*
int sum(int a, int b = 3) //sum(int a=3,intb)�̷��� ������� -> �����Ϸ��� ����� �ƴϰ� sum(4)�̷��� ��� ������°Ǵ�...
{
	return a + b;
}
int main()
{
	int a(0);
	int c(7);
	sum(a);		-> 3
	sum(a,c);	-> 7 
	//���� ������ �ʾƵ� �⺻���� �˾Ƽ� ��
	compare���� �Ҷ��� (begin,end) vs (begin,end,compare) �����ߴ���ó��
	���� ������ ������ �׳� ������ ���� �� -> caller������ callee���� ���� ���� Ư�� ��ü�������
}
*/

int main()
{

	map<string, vector<int> > ret = xref(cin);

	for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it)
	{
		cout << it->first << " occurs on line(s): ";

		vector<int>::const_iterator line_it = it->second.begin();

		//�ش� �ܾ �� ù��° ���ȣ ���.
		cout << *line_it;
		++line_it;

		//���ȣ ���� ���. //�̷��� ������ ���� -> ó�� �ͱ��� while�� ���������� 3, ,3�� �̷����� ����̸� ���̻ڴϱ�..
		while (line_it != it->second.end())
		{
			cout << ", " << *line_it;
			++line_it;
		}
		cout << endl;
		//�ܾ���� �����ϴ� ��
	}
}

