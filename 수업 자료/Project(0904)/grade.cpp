#include<vector>
#include<stdexcept>
#include<algorithm>
#include"grade.h"
#include"median.h"
#include"Student_info.h"
#include"Average.h"

using namespace std;
double grade_aux(const Student_info& s)
{
	try {
		return grade(s);
	}
	catch (domain_error)
	{
		return grade(s.midterm, s.final, 0);
	}
}
//grade�Լ��� �����ϱ⿡ �ռ� ���� �˻� ��� + � grade�� �ҷ��;����� ��Ȯ����
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

bool fgrade(const Student_info& s)
{
	return grade(s) < 69;
}

double average_grade(const Student_info& s)
{
	return grade(s.midterm, s.final, average(s.homework));
}

vector<Student_info>extract_fails(vector<Student_info>& students)
{
	vector<Student_info>fail;
	vector<Student_info>::iterator iter = students.begin();
	while (iter != students.end())
	{
		if (fgrade(*iter))
		{
			fail.push_back(*iter);
			iter = students.erase(iter);
	
		}
		else
			++iter;
	}

	return fail;
}

double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	//transform(students.begin(), students.end(), back_inserter(grades), grade);
	
	//ù 2���� �ݺ��ڴ� ���������� ����� �л��� ������ ��������
	// 3��°�� �� ������ ������ ��ġ
	// tranesform �� ȣ���Ҷ��� ���� ������ ���� ������ ������� Ȯ���ؾߴ�. -> back_inserter�Լ��� �ذ�
	// 1~2 ���� ���� ���� grade�� ������ ����� grades���Ϳ� ����.
	// ������ ���� ������ �ӳ�! -> grade�� �������ǵ� �Լ����� ��üȭ���Ѽ� �˷��� �ʿ䰡����
	// + ������ ���� ���� �л��� ��쿡 transform�Լ��� �ƹ��ϵ� ���� ���ɼ�������.
	// �׷��� ����ó���� grade_aux ��� ����� ���ž�

	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	//���� �Լ�
	return median(grades);
}

void write_analysis(ostream& out, const string& name, double analysis(const vector<Student_info>&), const std::vector<Student_info>& did, const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did)
		<< ", median(didnt) = " << analysis(didnt) << endl;
}

double average_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), average_grade);
	return median(grades);
}

double optimaistic_median(const Student_info& s)
{
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

	if (nonzero.empty())
		return grade(s.midterm, s.final, 0);
	else
		return grade(s.midterm, s.final, median(nonzero));
}
