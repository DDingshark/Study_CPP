#include<algorithm> 
#include<iomanip>
#include<ios>
#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"median.h"
#include"Student_info.h"
#include"grade.h"

using std::cin; using std::sort;
using std::cout; using std::streamsize;
using std::endl; using std::string;
using std::setprecision; using std::vector;
using std::max;

int main()
{
	vector<Student_info>students;
	Student_info record;
	string::size_type maxlen = 0;

	while (read(cin, record))
	{
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

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
