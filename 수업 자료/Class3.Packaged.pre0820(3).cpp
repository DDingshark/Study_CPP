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
/*
	���� ���� ��Ȳ -> ��������� ���� �𸣴´� �� Ŭ������ �ִ� �л��� ������ �����ϴ� ���α׷�
*/

/*
	�Է� ���

	Smith 93 01 30 20 10
	DDIng 100 100 30 30 30
	...

	���
	DDIng	99.3
	Smith	30.2
	...(���ĺ��� ����)

	�̷������� ����
*/

/*
	������ ������ ����
*/


struct Student_info
{
	string name;
	double midterm, final;
	vector<double> homework;
};

std::istream& read_hw(std::istream& in, vector<double>& hw)
{
	double x;
	if (in)
	{
		hw.clear();
		while (in >> x)
		{
			hw.push_back(x);
		}
		in.clear();
	}
	return in;
}

std::istream& read(std::istream& is, Student_info& s)
{
	is >> s.name >> s.midterm >> s.final;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
	read_hw(is, s.homework);
	return is;
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

double median(vector<double>vec)
{
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	if (size == 0)
		throw std::domain_error("midian of an empty vector");

	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}


double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
	{
		throw  std::domain_error("student has done no homework");
	}
	return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}





int main()
{
	vector<Student_info>students;
	Student_info record;
	string::size_type maxlen = 0;

	while (read(cin, record))
	{
		maxlen = std::max(maxlen, record.name.size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare); //�л����� �̸������� ����
	//struct ������ student �� > ������ Ȱ�� �Ұ�
	// sort�� ���Ǹ� ���� 3��° ���ڸ� �ָ� �� ���ڸ� Ȱ���Ͽ� ������ -> compare�� �����ؼ� Ȱ���Ŵ


	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
	{
		//�̸��� ������ ������ �����Ͽ� maxlen +1���� ���ڸ� ���
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');


		try // try �� catch������ ���๮�� catch(error) error�� �ش��ϴ� error�� ���ٸ� ���� �ƴϸ� �ǳʶ�.
		{
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << "your final grade is " << setprecision(3)
				<< final_grade << setprecision(prec) << endl;
		}

		catch (std::domain_error)
		{
			cout << endl << "You must enter your grades. "
				"Please try again." << endl;

			return 1;
		}
	}
	return 0;
}


// cnrk