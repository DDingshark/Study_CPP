//���α׷� �� ������ ����ȭ 

/*
	vector, string, sort �� �����ٸ� ���α׷��� ��ġ�� �ξ� Ŀ��������
		=> ���̺귯������ ���
			:1.  Ư�� ������ �ذ�
			 2.	 �ٸ���ɵ�� ������� �ʰ� �������� ( = �̽ļ��� ����)
			 3.	 ����� �̸��� ����

			 2-1 : ���α׷��� �Ը� Ŀ���� Ŀ������ ���������� �ൿ���������� �������� �� �����ϱ� �����
					-> � ����� �����ؾ� �Ҷ� �������� ���� ��ü���ִٸ� ��δ� �����ؾ��ϰ� -> �װ������� �Ǵٸ� ������ �߻�
			
			 3-1 : ���� ����	
*/

/*
	�������� ���� (����ȭ)
		�������ϼ� �ۿ� ���� ��Ȳ�� ����. ������ �����ϸ� ��� ���������� �����ϴ� ���� ���Űǰ��� ����
		(��ü�� ��ü ���̿�)

			1. �ڵ��� ��Ȱ�뼺 
			2. �������� 
*/

/*
	��Ȳ�� �����غ��� 
		������ ���� ���� ����� �ٲٰڴٰ� ���������� �Ƿ� -> �߰� 30, �⸻ 40 ���� 20 �� �̷�������

			+ ����� ���� �����ڶ� �Ѱ��̿��� �ʴ� �� ���α׷��� ó���� 

		streamsize prec = cout.precision();
		cout << "Your final grade is " << setprecision(3)
			<< 0.2 * midterm + 0.4 + final + 0.4 * sum / count
			<< setprecision(prec) << endl;

	    �� �̷��ڵ带 ã�ƾ��ϴ´� ���α׷��� �� 10���� ���� ���? ã�� �ſ� ����� ���ϰ���

		=>�׻� ����� ���(����, ������)���� ����ȭ ���Ѽ� �����ϴ� ������ �����°� ���� => �޸��� ����? -> �̷����� �޸𸮴� �����Ϸ��� �˾Ƽ� ����ó�� ����
*/
// class 1. ���� ����ȭ.
#include<algorithm> 
#include<iomanip>
#include<ios>
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>

using std::cin; using std::sort;
using std::cout; using std::streamsize;
using std::endl; using std::string;
using std::setprecision; using std::vector;

double grade(double midterm, double final, double homework) 
{
	return 0.2 * midterm + 0.4*final + 0.4*homework;
}
//�̷������� ������ �Ǿ��־��ٸ�? ���� �����ڴ� grade�� ���� ã�ư��� ���� ������������?

double median(vector<double>vec)
{
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size(); //�̷� vec_sz���� �پ��Ѱ����� â�Ƿ¾��� �̸��� ��ĥ�� �������� ������ �Լ����ο��� ���������� ó���ϴ°��� ����
	//���ӽ����̽��� �ִ� �ϴ��� �ٸ� �����ڰ� �������� ���ڴ� �ƴϸ� ������ ��԰� �ߺ� ������� ���� �ְ�
	if (size == 0)
		throw std::domain_error("midian of an empty vector");
	//����ó�� -> ���� �� ������� ���α׷��� ������� �̻��ϰ� ����ϴ°��� ����
	// ���Ͱ� ��������� -> ���������� �ȵ����� �������� ��Ȳ���� ���α׷��� ������(throw)�ϰ� � ���� ��Ȳ���� �˷���
	
	//domain_error -> �Լ��� �μ��� �Լ��� ������ �ִ°��� ������ ������� �����Ҷ� ��� 
	// �ٸ� ����ó���� ���� �˷��ֵ��� �ϰ�.


	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];

}

double grade(double midterm, double final, const vector<double>& hw) //const vector�� �����Ѵ� -> hw�� ���� �ٲٴ°��� ������� �ʴ´�.
																	 // ���ʿ� value�� ������ -> ���ϴ� �ð��� ��û �����ɸ� 
{
	if (hw.size() == 0)
	{
		throw  std::domain_error("student has done no homework");
		//���� ���� ������ ���˾� ��� ����� ���� ���ִ� ���� ���
	}
	return grade(midterm, final, median(hw)); //�����ִ� grade�� ȣ��
}

//�Է½�Ʈ���� �ִ� ���� vector�� ����
std::istream& read_hw(std::istream& in, vector<double>& hw)
//�����ؼ� ������ �ʰ� �����ؼ� ��ȯ������ �ʰ� �ִ� �׷��� �ް� �ִ� �״�� �ְٴ�.
{
	double x;
	if (in)
	{
		hw.clear();// ���Ϳ� �����л����� ������ ������������ ���� -> �츮�� ���� ��ǥ -> ���� �л��� ������ ����
		while (in >> x)
		{
			hw.push_back(x);
		}
		in.clear();// �л��� ���� ���� �Է��۾��� ����� ��Ʈ���� ���� 
	}
	return in;
}


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
		homework.push_back(x);

	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();

	if (size == 0)
	{
		cout << endl << "You must enter your grades."
			"Please try again." << endl;
		return 1;
	}
	
	double midian = median(homework);
	streamsize prec = cout.precision();
	cout << "your final grade is " << setprecision(3)
		<< grade(midterm, final, sum / count)
		<< setprecision(prec) << endl;


	return 0;
}