//프로그램 및 데이터 구조화 

/*
	vector, string, sort 가 없었다면 프로그램의 덩치가 훨씬 커졌을거임
		=> 라이브러리들의 기능
			:1.  특정 문제를 해결
			 2.	 다른기능들과 연계되지 않고 독립적임 ( = 이식성이 좋음)
			 3.	 기능의 이름이 있음

			 2-1 : 프로그램의 규모가 커지면 커질수록 독립적으로 행동하지않으면 유지보수 및 관리하기 어려움
					-> 어떤 기능을 수정해야 할때 의존적인 여러 객체가있다면 모두다 수정해야하고 -> 그과정에서 또다른 문제가 발생
			
			 3-1 : 보기 편함	
*/

/*
	독립적인 설계 (구조화)
		의존적일수 밖에 없는 상황도 있음. 하지만 가능하면 모두 독립적으로 설계하는 것이 정신건강에 좋음
		(객체와 객체 사이에)

			1. 코드의 재활용성 
			2. 유지보수 
*/

/*
	상황을 가정해보자 
		교수가 성적 산출 방식을 바꾸겠다고 제작자한태 의뢰 -> 중간 30, 기말 40 과제 20 뭐 이런식으로

			+ 계약을 선임 개발자랑 한것이여서 너는 이 프로그램을 처음봄 

		streamsize prec = cout.precision();
		cout << "Your final grade is " << setprecision(3)
			<< 0.2 * midterm + 0.4 + final + 0.4 * sum / count
			<< setprecision(prec) << endl;

	    뭐 이런코드를 찾아야하는대 프로그램이 한 10만줄 정도 라면? 찾기 매우 어려워 보일것임

		=>항상 기능적 요소(연산, 데이터)들을 구조화 시켜서 저장하는 습관을 가지는게 좋음 => 메모리의 낭비? -> 이런식의 메모리는 컴파일러가 알아서 연산처리 해줌
*/
// class 1. 연산 구조화.
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

double grade(double midterm, double final, double homework) 
{
	return 0.2 * midterm + 0.4*final + 0.4*homework;
}
//이런식으로 저장이 되어있었다면? 후임 개발자는 grade를 보고 찾아가서 보면 수월했을지도?

double median(vector<double>vec)
{
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size(); //이런 vec_sz같은 다양한곳에서 창의력없는 이름은 곂칠수 있을수도 있으니 함수내부에서 지역변수로 처리하는것이 좋음
	//네임스페이스가 있다 하더라도 다른 협업자가 있으수도 있자늠 아니면 본인이 까먹고 중복 사용했을 수도 있고
	if (size == 0)
		throw std::domain_error("midian of an empty vector");
	//예외처리 -> 내가 잘 만들어준 프로그램을 사람들이 이상하게 사용하는것을 방지
	// 백터가 비어있을때 -> 과제점수가 안들어오는 예외적인 상황에서 프로그램을 던진다(throw)하고 어떤 예외 상황인지 알려줌
	
	//domain_error -> 함수의 인수가 함수가 받을수 있는값의 범위를 벗어났음을 보고할때 사용 
	// 다른 예외처리는 차차 알려주도록 하고.


	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];

}

double grade(double midterm, double final, const vector<double>& hw) //const vector을 참조한다 -> hw의 값을 바꾸는것을 허락하지 않는다.
																	 // 애초에 value로 받으면 -> 복하는 시간이 엄청 오래걸림 
{
	if (hw.size() == 0)
	{
		throw  std::domain_error("student has done no homework");
		//위에 예외 오류를 못알아 듣는 사람을 위해 해주는 작은 배려
	}
	return grade(midterm, final, median(hw)); //위에있는 grade가 호출
}

//입력스트림에 있는 값을 vector에 넣음
std::istream& read_hw(std::istream& in, vector<double>& hw)
//복사해서 받지도 않고 복사해서 반환하지도 않고 있는 그래도 받고 있는 그대로 주겟다.
{
	double x;
	if (in)
	{
		hw.clear();// 백터에 이전학생들의 점수가 남아있을수도 있음 -> 우리의 최종 목표 -> 여러 학생의 데이터 관리
		while (in >> x)
		{
			hw.push_back(x);
		}
		in.clear();// 학생의 다음 점수 입력작업을 고려해 스트림을 지움 
	}
	return in;
}


int main()
{
	cout << "Please enter your first name : ";
	string name;
	cin >> name;
	cout << "Hello, " << name << '!' << endl;

	cout << "Please enter your midterm and final exam grade : ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "Enter all your homework grade, "
		"followed by end-of-file : ";

	int count(0);
	double sum(0);

	vector<double> homework;
	double x;
	while (cin >> x)
		homework.push_back(x);

	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();

	if (size == 0)
	{
		cout << endl << "You must enter your grades."
			"Please try again." << endl;
		return 1;
	}
	
	double midian = median(homework);
	streamsize prec = cout.precision();
	cout << "your final grade is " << setprecision(3)
		<< grade(midterm, final, sum / count)
		<< setprecision(prec) << endl;


	return 0;
}