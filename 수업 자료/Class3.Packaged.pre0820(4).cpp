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
