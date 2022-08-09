//지난시간 복습
#include<iostream>
#include<ios> //입출력 라이브러리에서 전송된 문자나 버퍼의 크기를 나타내려고 -> streamsize활용
#include<iomanip> // 출력 결과의 유효자릿수를 결정 setprecison
#include<string>

using std::cin;  using std::setprecision;
using std::cout; using std::string;
using std::endl; using std::streamsize;

int  main()
{
	cout << "Please enter your first name : ";
	string name;
	cin >> name;
	cout << "Hello, " << name << '!' << endl;

	cout << "Please enter your midterm and final exam grade : ";
	double midterm, final;
	cin >> midterm >> final;
	/*
	cin<<midterm; 
	cin<<final; 같은 의미

	+ 왜 final 만 색이 다른가? ->  다른기능을하는 예약어 중에 하나인대 그냥 변수이름으로 쓰겠다고
	깡으로 선언한것.

	*/

	cout << "Enter all your homework grade, "
		"followed by end-of-file : ";
	/*
	="En~~~gradem, follwed ~file"<<endl; 이거랑 같은 기능을 수행 ->가독성살리기위해 이렇게도 씀
	*/

	int count(0);
	double sum(0);

	double x;
	while (cin >> x) // cin>>x 가 실행하는 역할이 무엇인지 ->숙제
	{
		++count;
		sum += x;
	}

	streamsize prec = cout.precision();//정밀도를 반환후 세팅하는 cout의 메소드.
	cout << "Your final grade is " << setprecision(3)//3자리로 스트림을 수정해주세요 이런느낌 조작어입니다.
														//보통 소수점기준 앞2자리 뒤 1자리로 자름
		<< 0.2 * midterm + 0.4 + final + 0.4 * sum / count
		<< setprecision(prec) << endl;
			//이후에 있을 후속출력을 대비하여 정밀도를 다시 원상태로 바꿔놓음

	/*
	
	streamsize prec = cout.precision(3);//정밀도의 이전값을 반환후 3으로 세팅
	cout<<"Your final grade is"
		<<0.2 midterm+0.4*final+0.4 sum/count<<endl;

	cout.precision(prec);

	//이 방법보다 위 방법으로 많이씀
	//->정밀도 세팅을 한눈에 알아보기 어려움

	*/
	return 0;
}


/*
while(cin>>x)
	해설 : cin 은 표준 라이브러리의 일부인 istream 클레스 임으로 cin의 값을 숫자로 바꿀수있음.
		+해당 숫자값을 bool값으로 바꾸어 조건판별에 사용할수있음.

	

	스트림에서 입력값으로 읽을수 없는 상황
	1. EOF 
	2. 변수의 타입과 맞지않는값을 입력
	3. 시스템 입력장치에서 하드웨어 장애를 감지했을때 = 키보드 망가짐이슈
	=>거짓을 반환 
*/