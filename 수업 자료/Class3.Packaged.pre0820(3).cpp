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
	본래 문제 상황 -> 몇명인지는 나는 모르는대 한 클레스에 있는 학생의 성적을 산출하는 프로그램
*/

/*
	입력 방법

	Smith 93 01 30 20 10
	DDIng 100 100 30 30 30
	...

	출력
	DDIng	99.3
	Smith	30.2
	...(알파벳식 나열)

	이런식으로 가정
*/

/*
	데이터 구조의 설계
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

	sort(students.begin(), students.end(), compare); //학생들을 이름순으로 정렬
	//struct 구조인 student 는 > 연산자 활용 불가
	// sort의 정의를 보면 3번째 인자를 주면 그 인자를 활용하여 비교해줌 -> compare을 정의해서 활용시킴


	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
	{
		//이름과 오른쪽 공백을 포함하여 maxlen +1개의 문자를 출력
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');


		try // try 와 catch사이의 실행문이 catch(error) error에 해당하는 error를 낸다면 실행 아니면 건너뜀.
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