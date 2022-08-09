#include<algorithm> //sort (�񳻸����� ����)
#include<iomanip>
#include<ios>
#include<iostream>
#include<string>
#include<vector>

using std::cin; using std::sort;
using std::cout; using std::streamsize;
using std::endl; using std::string;
using std::setprecision; using std::vector;

int main()
{
	cout << "Please enter your first name : ";
	string name;
	cin >> name;
	cout << "Hello, " << name << '!' << endl;

	cout << "Please enter your midterm and final exam grade : ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "Enter all your homework grade, "
		"followed by end-of-file : ";

	int count(0);
	double sum(0);

	vector<double> homework;
	double x;
	while (cin >> x)
		homework.push_back(x); // push_back -> ����Ÿ���� �Ϻη� �����ϸ� ��ü homework �� ���õ� �۾��� �����Ŵ
							   //		-> ������ �������� �� ��Ҹ� �߰���Ŵ ???
							   //		����... �̰� ������,,,? �迭�� �׳� �� �þ��???
							   //		c++STL�� ���� ���� �ϴ� ������ ����... ����Կ� �������� �̰͵� ���߿� ���� ����
	
	typedef vector<double>::size_type vec_sz;
	//typedef -> vector<double>::size_type �̶�� Ÿ���̸��� �ʹ� ����...
	// �׷��� ������ ����� �ִ� ģ�� vector<double>::size_type ���� vec_sz��� ������ �������,

	vec_sz size = homework.size();
	//�׷��� vec_sz(vector<double>::size_type ) Ÿ���� size������ ���� .size�޼ҵ带 �̿��� ũ�⸦ ����
	// ���� �̸� �Ȱ��� �������� ����� ���ӽ����̽� ó�� ���ߴ´� ���� �� ����ħ?
	// �����Ϸ��� ��Ȳ�� �°� �˾Ƽ�! �� ó�����ִ� ���� + .�̰͵� �����ڶ�� ����� ����ϸ� �翬�� �ٸ������� �����Ҽ�����
	if (size == 0)
	{
		cout << endl << "You must enter your grades."
			"Please try again." << endl;
		return 1; //���α׷��� ������ ���� <- ������ �Ʒ��� �Ѿ���� ���� ������ �ϰ��̰� �����Ҽ��� ����
						//-> �α��� ������ ó�� �������ϱ� �������� �ٽ� ��~ �� �̷�����
	}

	sort(homework.begin(), homework.end());
	// sort : �����̳��� ���� �񳻸����� ���� ���ִ� �޼ҵ�(���� ���� �������� �����ϱ� �츮�� �����ϴ� �������� �װ� ����)
	// sort(��������, ������������ ��������)
	

	// +@ ������ �˰������� �ð������ N��
	/*
//���� ����� �����Ҽ� �ִ� �����θ� �ۼ��� �ڵ�
void quick_sort(vector<int>& data, int left, int right)
{
	if (left >= right) return;

	int pivot = right;
	int lo = left;
	int hi = pivot - 1;

	while (true)
	{
		while (data[lo] <= data[pivot] && lo <= hi) lo++;
		while (data[hi] > data[pivot] && hi > lo) hi--;

		if (lo < hi)
		{
			swap(data[lo], data[hi]);
		}
		else break;
	}

	swap(data[lo], data[pivot]);

	quick_sort(data, left, lo - 1);
	quick_sort(data, lo + 1, right);
}

//���� c++���� ������ ����
struct Vector2
{
	int x;
	int y;

	Vector2(int _x, int _y) : x(_x), y(_y) { }

	bool operator<(const Vector2& a) const
	{
		return this->x < a.x;
	}
};

bool compare(const Vector2 a, const Vector2 b)
{
	return a.x < b.x;
}

struct Vector2Compare
{
	inline bool operator()(Vector2 a, Vector2 b) const
	{
		return a.x < b.x;
	}
};
[��ó] [C++/�˰���] std::sort()|�ۼ��� ���ϰź�å����


	�˰� ������� ���ǵȰ� ������
	*/



	//�߾Ӱ��� ������������ ���.
	vec_sz mid = size / 2; 
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];
	//if���� ������ȭ���Ѽ� ��ȯ�ϰ���
	// ���� �ʿ��Ҷ��� �̹���� �� ȿ������

	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)													
		<< 0.2 * midterm + 0.4 + final + 0.4 * sum / count
		<< setprecision(prec) << endl;

	return 0;
}

// �߰� 

/*
	1. ������ ���� ������ ��Ҹ� �߰��Ҷ��� ������ ��Ұ����� ����Ͽ� ���������ʰ� ���͸������ؾߴ� -> �� ���߿� Ŭ�������鶧 �������ϴ�.
	2. sort�Լ��� ������ nlogn ���� ������ �ʵ��� �����ؾߴ� -> �������� Ư��, ������������ ���ļ����� �޶��� -> �������� ���ľ˰����� �˰��ְ�, �� ��ߴ�.
		=> �з�, ������ ���� �ӵ��� ��� �Դ� ������ ���.!


	1. ������ �޸�ũ�� -> �迭ó�� ���°� ũ��� �Ҵ�Ǵ°��� �ƴ϶� �׻� ���� ũ���Ҵ� => �Է¹��� ���� ó���ϴ� �� �ʿ��� ��ŭ Ŀ�� 
		=> ���� �������� �ʿ���� ������ �ξƾƾƝ� ������ => Ƽ����� �»��� �Ǵ´� �̰� �迭ó�� �����ϸ� �׾ �޸� ��������

		=> �׷����� ������ ���� �����Ƽ� �׳� �������ϸ� STL vector�� �����

*/