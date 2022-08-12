#include<iostream>
#include<vector>
#include<string>
#include<cctype> 
#include<iterator>
#include<algorithm> //��κ��� �� �������� �����ϴ� �˰����� �� ��������
using namespace std;
/*
	1. ���ڿ� �м�
		2���� ���ڿ��� ��ġ�� ���
		for(vector<string>::const_ilterator it=bottom.begin();it!=bottom.end();++i
			{
				ret.push_back(*it)
			}
		//�� �̷����� �ڵ� ���൵ �߾����� ->���ڿ�(���ڵ��� �����̳�)�̶�� �Ϳ� ����

		ret.insert(ret.end(),bottom.begin(),bottom(end));
		//�̷����� �ڵ� ���൵ �־��� -> ���Ͱ� �����ϴ� ������ �̿�

		->���� �������� �����ذ�
		copy(bottom.begin(),bottom.end(),back_inserter(ret));
			->copy�� ���ʸ�(generic) �˰��� , back_inserter()�Լ��� �ݺ��� �����

		���ʸ� �˰��� -> Ư�� ������ �����̳ʿ� ������ ������ �μ��� Ÿ������ �����Ϳ� �����ϴ� ����� 
			�����ϴ�(?) �����ϴ�(?)�˰���
			->�Ϲ������� �����̳��� ��Ҹ� �����ϴ´� �ݺ��ڸ� �����(������������ �������� Xģ������ ���)
			  by. �ݺ��� �μ��� ���� begin,end,out�� �μ��� �ִ� copy�˰����� out���� �����ϴ� ��ҵ��� �������� �ʿ��Ѹ�ŭ ������ Ȯ���Ͽ� ����

		copy(begin,end,out)
		==
		while(begin!=end)
		{
			*out++ = *begin++;(���� �����Ŀ� ���ؾ� ������ ������������ ���)
		}

		�׷��� �ݺ��� ��Ͱ� ����(iterator adaptor) iterator�� ���� 
		�Ϲ������� back_insertor ����Ϸ��� ��Ŭ��� ��Ŵ -> �����̳ʸ� �μ��� ����ϸ� , �����̳��� ���� �߰���
		�������� �ݺ��ڸ� ��ȯ 

		�� �̷��� �����߳�! �׷��� 1. �����̳��� Ȯ��� ����߰��� ���������� �и���ų���� -> �˾Ƽ� �� �˾ƺ�����		
*/

/*
	1-2. ���ο� split
*/

//���� ���� Ȯ��
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
		//������� ����
		i = find_if(i,str.end(), notspace);

		//�����ܾ��� ���� ã��
		iter j = find_if(i, str.end(), space);

		//[i,j]������ ���ڸ� ���� 
		if(i != str.end())
			ret.push_back(string(i, j));
		i = j;
	}
	return ret;
}
/*
	finde_if(1,2,3) 1,2�� �������� ��Ÿ���� �ݺ���, 3�� �����Լ�->�μ��� �˻��Ͽ� ��,���� ��ȯ
		->���� ��ȯ�ϴ� ��Ҹ� ã���� �Լ� ����
		-> ������ ��ã���� 2�� ��ȯ 

	�ռ� ������ split���� ���� -> ����

*/


//�쿵�� �����ؼ�
bool is_palindrome(const string& s)
{
	return equal(s.begin(), s.end(), s.rbegin());
}
//equal -> ������ �ݴ��� �� ���ڿ��� ���� ������ �Ǻ��ϴ� �Լ� (1,2)�� �ݺ��ڴ� ó���� �� , 3�� 2�� �������� ��Ÿ��
	//ũ�Ⱑ ���ٰ� �����ϰ� �����ϴ� �Լ�

//URLã��
/*
	� ������ �Ȱ� �׾ȿ� �ִ� url�� ã�� �� ��ȯ 
	url -> �������� �̸� :// ���ҽ� �̸� 
		=> ���ڿ� �μ��� ���޹޾� �ش� ���ڿ��� �����ϴ� ://�� ã�� �ڿ� �յڿ� �ִ� �̸����� ã����� 
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

//url_beg , url_after �� ���
// text http :// www.navmer.com more text
//    b=uel_beg(b,e)                after =url_end(b,e)
// b-> ��ȿ�� url�� �ִ��� �ĺ��Ͽ� url�̸� ���������� �̸��� ù��° ���ڸ� �����ϴ� �ݺ��ڸ� ��ȯ 
// �������� e�� ��ȯ

// end -> url�� ã���ָ� url�� ���� ã�Ƽ� ��ȯ

string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
	return find_if(b, e, not_url_char);
}

bool not_url_char(char c)
{
	static const string url_ch = "~;/?:@=&$-_+!*'(),"; //url �� �� �� �ִ� ���ĺ��� ���� �̿��� ����


	//c�� url�� ���� �ִ� �������� Ȯ���ϸ� ������ ��ȯ 
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());

}

//���丮�� Ŭ���� ������ (storage class specifier )  = static�� full name
//isalnum -> cctype������ -> �μ��� ������ ���ڰ� ���ĺ��̳� �������� ���� �Ǻ� 
//find -> find_if�� ����° �μ�ȣ�� �ϴ´�� ����° �μ��� Ư�� ���� ã�� �˰���

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
	static const string sep = ";//";
	typedef string::const_iterator iter;

	//i�� ���� ��ȣ�� �߰��� ��ġ�� ǥ��
	iter i = b;
	while ((i = search(i, e, sep.begin(), sep.end())) != e)
	{
		//���б�ȣ�� ���� ž�� ������ ó�� �Ǵ� �������� �ִ��� Ȯ��
		if (i!= b && i + sep.size() != e)
		{
			//beg�� ���������� ������ġ ǥ��
			iter beg = i;
			while (beg != b && isalpha(beg[-1]))
			{
				--beg;
			}

			//���б�ȣ �յڷ� url�� �Ϻο��� ��ȿ�� ���ڰ� �ϳ��ϵ� �ִ��� Ȯ��
			if (beg != i && !not_url_char(i[sep.size()]))
			{
				return beg;
			}
			//�߰��� ���б�ȣ�� url�Ϻΰ� �ƴϹǷ� �ش籸�� ��ȣ ���ĸ� ǥ���ϵ��� i�� ����.
			i += sep.size();
		}
		return e;
	}
}
int main()
{

	return 0;
}