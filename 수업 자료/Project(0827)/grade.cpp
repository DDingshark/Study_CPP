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

//ver1. 60점이 안된 학생들을 분류 
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
// 실제로 2개의 백터를 만듦 -> 함수 자체가만드는 벡터 , 함수를 호출할때 부수적으로 생성하는 합격학생데이터(변화시킨 참조호출된 백터)
//  
// 단점->for문을 실행한 즉시에는 원본벡터, pass,fail백터 3개의 백터가 공존하고, 메모리의 크기는 순간적으로 2배가됨
//			->결국 students=pass문을 실행 했을때 원본 데이터 삭제 후 pass백터의 값으로 복사
// sol-> fail 백터 한개를 두고 원본 벡터에서 fail로 가는 학생들을 제거하는 과정또한 추가시키면?
//			-> 백터의 제거 작업은 원본데이터가 크면 클수록 엄청나게 속도가 느려짐 N^2작업임
//
*/

/*
vector<Student_info>extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::size_type i = 0;

	while (i != students.size()) //원래사이즈가 줄어들고있으니까 미리 저장하는게아닌 현제 사이즈와 비교
	{
		if (fgrade(students[i]))  //과락이 발생하면
		{
			fail.push_back(students[i]);//fail 백터에 학생추가
			students.erase(students.begin() + i); //erase 맴버함수를 이용하여 요소삭제 + 뒤에있는것등 당기는 기능까지 있음
		} 
	
		else
			++i;
	}

	return fail;
}

*/

//반복자를 이용한 구현
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
				students.erase()가 호출된 순간 -> iter이 가리키는 요소가 재거됨 -> 반복자또한 무효로 만들어짐
					-> 가리키는 대상이 사라졌으니 참조할수도 당연히 없음 -> erase 함수는 제거한 요소의 다음 요소를 가리키는 반복자를 반환
					
			*/
		}
		else
			++iter;
	}

	return fail;
}
//하지만 데이터가 많아지면 한..(1만명?)정도만 되더라도 성능이 현저히 느려지는것은 변함이 없음 -> 데이터 구조를 잘짜는 것이 중요함
// 이 이상은 수업범위의 초과임으로 여기서 끝냄

// 리스트 vs백터 -> 70,000개 기준 리스트 9초, 백터 600초



