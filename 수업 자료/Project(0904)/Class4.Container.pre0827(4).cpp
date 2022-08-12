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
	상황 : 중앙값으로 계산한게 뽀록이 나서 학생들이 1~2개만 집중해서 제출한뒤에 고득점을 노리는 경향을 보임
		근대 교수님이 중앙값을 너무 사랑한 나머지 진짜로 이런 학생들이 이점을 갖고 채점을 받는지 알고싶다는 의뢰.



	sol 1. 모든 학생의 정보를 읽고 과제를 모두 제출한 학생과 그렇지 않은 학생들을 분류
	sol 2. 두 집단의 각각의 성적 산출 방식을 적용한 후 각 집단의 중앙값을 추출

	sol 3. 평균을 냈을때와 중앙값을 사용하였을때를 비교해서 뭐가 더 좋은지 알려주는 프로그램.

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

	//분류 작업이 추가된 read
	while (read(cin, student))
	{
		if (did_all_hw(student))
			did.push_back(student);

		else
			didnt.push_back(student);
	}

	if (did.empty())
		//.empty() -> 해당 컨테이너가 비어있으면 T, 아니면 F를 반환 -> size ==0 이랑 뭔 차이냐! -> 몇개인지 세보려고 하면서 어 0개이내 vs 없내?
	{
		cout << "No student did all the homework!" << endl;
		return 1;
	}
	if (didnt.empty())
	{
		cout << "Every student did all the home work!" << endl;
		return 1;
	}

	//분류 까진 ok 이제 분석을 구조화 시켜야댐
	// 일단 두 집단을 분석하는 함수를 만들어야...  각각의 결과를 출력해야 하는구만
	//	출력함수를 짜봐야 할탠대 출력스트림, 출력문자열, 분석함수, 2개의 백터 를 인수로 갖는 함수를 짜봅시당

	//write_analysis(cout, "medina", median_analysis, did, didnt);
	// 최종적으로 실행 시키고픈 form -> 문제 median_analysis를 구성해야댐. ->grade 에서 해봅시당.
	//분석 실행
	write_analysis(cout, "median", median_analysis, did, didnt);
	// 일단 중앙값 ok
	write_analysis(cout, "average", average_analysis, did, didnt);
	//평균값사용
	write_analysis(cout, "median of trurnd in",optimaistic_median_analysis, did, didnt);
	//제출하지 않은 과제점수가 제출한과제 점수와 같을것이라는 기대감의 함수  
	//과제.
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
