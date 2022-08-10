#include<vector>
#include<stdexcept>
#include"grade.h"
#include"median.h"
#include"Student_info.h"

using std::domain_error;
using std::vector;


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

//ver1. 60���� �ȵ� �л����� �з� 
/*
vector<Student_info>extract_fails(vector<Student_info>& students)
{
	vector<Student_info>pass, fail;

	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
	{
		if (fgrade(students[i]))
		{
			fail.push_back(students[i]);
		}

		else
		{
			pass.push_back(students[i]));
		}

		students = pass;
		return fail;
	}
}
//
// ������ 2���� ���͸� ���� -> �Լ� ��ü������� ���� , �Լ��� ȣ���Ҷ� �μ������� �����ϴ� �հ��л�������(��ȭ��Ų ����ȣ��� ����)
//  
// ����->for���� ������ ��ÿ��� ��������, pass,fail���� 3���� ���Ͱ� �����ϰ�, �޸��� ũ��� ���������� 2�谡��
//			->�ᱹ students=pass���� ���� ������ ���� ������ ���� �� pass������ ������ ����
// sol-> fail ���� �Ѱ��� �ΰ� ���� ���Ϳ��� fail�� ���� �л����� �����ϴ� �������� �߰���Ű��?
//			-> ������ ���� �۾��� ���������Ͱ� ũ�� Ŭ���� ��û���� �ӵ��� ������ N^2�۾���
//
*/

/*
vector<Student_info>extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::size_type i = 0;

	while (i != students.size()) //��������� �پ��������ϱ� �̸� �����ϴ°Ծƴ� ���� ������� ��
	{
		if (fgrade(students[i]))  //������ �߻��ϸ�
		{
			fail.push_back(students[i]);//fail ���Ϳ� �л��߰�
			students.erase(students.begin() + i); //erase �ɹ��Լ��� �̿��Ͽ� ��һ��� + �ڿ��ִ°͵� ���� ��ɱ��� ����
		} 
	
		else
			++i;
	}

	return fail;
}

*/

//�ݺ��ڸ� �̿��� ����
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
			/*
				students.erase()�� ȣ��� ���� -> iter�� ����Ű�� ��Ұ� ��ŵ� -> �ݺ��ڶ��� ��ȿ�� �������
					-> ����Ű�� ����� ��������� �����Ҽ��� �翬�� ���� -> erase �Լ��� ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ
					
			*/
		}
		else
			++iter;
	}

	return fail;
}
//������ �����Ͱ� �������� ��..(1����?)������ �Ǵ��� ������ ������ �������°��� ������ ���� -> ������ ������ ��¥�� ���� �߿���
// �� �̻��� ���������� �ʰ������� ���⼭ ����

// ����Ʈ vs���� -> 70,000�� ���� ����Ʈ 9��, ���� 600��



