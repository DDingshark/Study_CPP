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
/*
	��Ȳ : �߾Ӱ����� ����Ѱ� �Ƿ��� ���� �л����� 1~2���� �����ؼ� �����ѵڿ� ������� �븮�� ������ ����
		�ٴ� �������� �߾Ӱ��� �ʹ� ����� ������ ��¥�� �̷� �л����� ������ ���� ä���� �޴��� �˰�ʹٴ� �Ƿ�.



	sol 1. ��� �л��� ������ �а� ������ ��� ������ �л��� �׷��� ���� �л����� �з�
	sol 2. �� ������ ������ ���� ���� ����� ������ �� �� ������ �߾Ӱ��� ����

	sol 3. ����� �������� �߾Ӱ��� ����Ͽ������� ���ؼ� ���� �� ������ �˷��ִ� ���α׷�.

*/
int main()
{
	vector<Student_info>students;
	vector<Student_info>did, didnt;
	Student_info record;
	Student_info student;
	string::size_type maxlen = 0;



	/*while (read(cin, record))
	{
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}
	*/

	//�з� �۾��� �߰��� read
	while (read(cin, student))
	{
		if (did_all_hw(student))
			did.push_back(student);

		else
			didnt.push_back(student);
	}

	if (did.empty())
		//.empty() -> �ش� �����̳ʰ� ��������� T, �ƴϸ� F�� ��ȯ -> size ==0 �̶� �� ���̳�! -> ����� �������� �ϸ鼭 �� 0���̳� vs ����?
	{
		cout << "No student did all the homework!" << endl;
		return 1;
	}
	if (didnt.empty())
	{
		cout << "Every student did all the home work!" << endl;
		return 1;
	}

	//�з� ���� ok ���� �м��� ����ȭ ���Ѿߴ�
	// �ϴ� �� ������ �м��ϴ� �Լ��� ������...  ������ ����� ����ؾ� �ϴ±���
	//	����Լ��� ¥���� ���Ĵ� ��½�Ʈ��, ��¹��ڿ�, �м��Լ�, 2���� ���� �� �μ��� ���� �Լ��� ¥���ô�

	//write_analysis(cout, "medina", median_analysis, did, didnt);
	// ���������� ���� ��Ű���� form -> ���� median_analysis�� �����ؾߴ�. ->grade ���� �غ��ô�.
	//�м� ����
	write_analysis(cout, "median", median_analysis, did, didnt);
	// �ϴ� �߾Ӱ� ok
	write_analysis(cout, "average", average_analysis, did, didnt);
	//��հ����
	write_analysis(cout, "median of trurnd in",optimaistic_median_analysis, did, didnt);
	//�������� ���� ���������� �����Ѱ��� ������ �������̶�� ��밨�� �Լ�  
	//����.
	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
	{
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');


		try
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
