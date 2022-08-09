#include<algorithm> //sort (비내림차순 정렬)
#include<iomanip>
#include<ios>
#include<iostream>
#include<string>
#include<vector>

using std::cin; using std::sort;
using std::cout; using std::streamsize;
using std::endl; using std::string;
using std::setprecision; using std::vector;

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
		homework.push_back(x); // push_back -> 백터타입의 일부로 정의하며 객체 homework 와 관련된 작업을 실행시킴
							   //		-> 백터의 마지막에 새 요소를 추가시킴 ???
							   //		ㅅㅂ... 이게 가능해,,,? 배열이 그냥 슉 늘어나내???
							   //		c++STL이 사기다 사기다 하는 이유가 있음... 편안함에 속지말고 이것도 나중에 만들 예정
	
	typedef vector<double>::size_type vec_sz;
	//typedef -> vector<double>::size_type 이라니 타입이름이 너무 길어요...
	// 그래서 별명을 만들어 주는 친구 vector<double>::size_type 에게 vec_sz라는 별명을 만들어줌,

	vec_sz size = homework.size();
	//그래서 vec_sz(vector<double>::size_type ) 타입의 size변수를 만들어서 .size메소드를 이용해 크기를 저장
	// ㅅㅂ 이름 똑같이 설정하지 말라매 네임스페이스 처리 안했는대 ㅅㅂ 왜 구라침?
	// 컴파일러가 상황에 맞게 알아서! 잘 처리해주는 것임 + .이것도 연산자라는 사실을 기억하면 당연히 다른것임을 인지할수있음
	if (size == 0)
	{
		cout << endl << "You must enter your grades."
			"Please try again." << endl;
		return 1; //프로그램의 비정상 종료 <- 어차피 아래로 넘어가봐야 오류 투성이 일것이고 제어할수도 없음
						//-> 로그인 했을때 처럼 귀찮으니까 꺼버리고 다시 해~ 뭐 이런느낌
	}

	sort(homework.begin(), homework.end());
	// sort : 컨테이너의 값을 비내림차순 정렬 해주는 메소드(같은 값이 있을수도 있으니까 우리가 생각하는 오름차순 그거 맞음)
	// sort(시작지점, 끝나는지점의 다음지점)
	

	// +@ 퀵정렬 알고리즘으로 시간복잡고 N임
	/*
//같은 방식을 이해할수 있는 내용들로만 작성한 코드
void quick_sort(vector<int>& data, int left, int right)
{
	if (left >= right) return;

	int pivot = right;
	int lo = left;
	int hi = pivot - 1;

	while (true)
	{
		while (data[lo] <= data[pivot] && lo <= hi) lo++;
		while (data[hi] > data[pivot] && hi > lo) hi--;

		if (lo < hi)
		{
			swap(data[lo], data[hi]);
		}
		else break;
	}

	swap(data[lo], data[pivot]);

	quick_sort(data, left, lo - 1);
	quick_sort(data, lo + 1, right);
}

//실제 c++에서 정의한 내용
struct Vector2
{
	int x;
	int y;

	Vector2(int _x, int _y) : x(_x), y(_y) { }

	bool operator<(const Vector2& a) const
	{
		return this->x < a.x;
	}
};

bool compare(const Vector2 a, const Vector2 b)
{
	return a.x < b.x;
}

struct Vector2Compare
{
	inline bool operator()(Vector2 a, Vector2 b) const
	{
		return a.x < b.x;
	}
};
[출처] [C++/알고리즘] std::sort()|작성자 꼬북거북책은북


	알고 싶을까봐 정의된거 가져옴
	*/



	//중앙값을 가져오기위한 방법.
	vec_sz mid = size / 2; 
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];
	//if문을 연산자화시켜서 반환하게함
	// 값만 필요할때는 이방법이 더 효율적임

	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3)													
		<< 0.2 * midterm + 0.4 + final + 0.4 * sum / count
		<< setprecision(prec) << endl;

	return 0;
}

// 추가 

/*
	1. 백터의 많은 개수의 요소를 추가할때는 성능이 요소개수의 비례하여 나빠지지않게 백터를구현해야댐 -> 뭐 나중에 클레스만들때 보겠읍니다.
	2. sort함수의 성능이 nlogn 보다 느리지 않도록 구현해야댐 -> 데이터의 특성, 분포도에따라 정렬성능이 달라짐 -> 여러개의 정렬알고리즘을 알고있고, 잘 써야댐.
		=> 분류, 정렬은 가장 속도를 잡아 먹는 적임을 명심.!


	1. 백터의 메모리크기 -> 배열처럼 딱맞게 크기로 할당되는것이 아니라 항상 좀더 크게할당 => 입력받은 값을 처리하는 데 필요한 만큼 커짐 
		=> 존나 많아지면 필요없는 공간이 부아아아앜 많아짐 => 티끌모아 태산이 되는대 이거 배열처럼 생각하면 죽어도 메모리 관리못함

		=> 그럼에도 성능이 많이 ㄱㅊ아서 그냥 어지간하면 STL vector을 사용함

*/