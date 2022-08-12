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
//grade함수가 실행하기에 앞서 오류 검사 기능 + 어떤 grade를 불러와야할지 명확해짐
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
	
	//첫 2개의 반복자는 최종점수를 계산할 학생의 정보의 범위지정
	// 3번째는 그 점수를 저장할 위치
	// tranesform 을 호출할때는 최종 점수를 넣을 공간이 충분한지 확인해야댐. -> back_inserter함수로 해결
	// 1~2 인자 까지 각각 grade를 연산한 결과를 grades백터에 넣음.
	// 오류가 나는 이유가 머냐! -> grade가 다중정의된 함수여서 구체화시켜서 알려줄 필요가있음
	// + 과제를 전혀 안한 학생인 경우에 transform함수가 아무일도 안할 가능성이있음.
	// 그래서 예외처리를 grade_aux 라고 만들어 볼거야

	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	//최종 함수
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
