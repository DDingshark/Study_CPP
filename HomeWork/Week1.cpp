/*

1. 다음 상수의 정의문이 올바른지 판단하시오

const std::string hello ='Hello';
std::string message = "Hello +",world"+"!";

2. 다음 상수의 정의문이 올바른지 판단하시오
const std::string exclam ="!";
std::string message ="Hello"+", world"+ exclam;

3. 다음 프로그램이 올바르게 동작하는지 판단하시오
#include<iostream>
#include<string>

int main()
{
	{
		const std::string s = "a string";
		std::cout<<s<<std::endl;
	}
	{
		const std::string s ="another string";
		std::cout<<s<<endl;

	}

	return 0;
}

4. 다음 프로그램이 올바르게 동작하는지 판단하고, 끝에서 세번째 행의 }}를 };}로 변경했을때의 결과와 그 결과가 나온 이유를 설명하시오
#include<iostream>
#include<string>

int main()
{
	const std::string s ="a string"
	std::cout<<s<<str::endl;
	{
		const std::string s ="another string";
		str::cout<<s<<std::endl;
	}}
	return 0;
}

5. 다음 프로그램이 올바르게 동작하는 판단하여라, 오류가 있다면 올바르게 고쳐보시오
#include<iostream>
#include<string>

int main()
{
	{
		std::string s = 'a string';
		{
			std::string x = s+", relly";
			std::cout<<s<<std::endl;
		}

		std::cout<<x<<std::endl;
	}
	return 0;
}

6. Samuel Beckett 처럼 한번에 2개의 단어를 입력할때의 결과를 예상해 본후 프로그램을 실행 시켜보시오
	추가로 스트림(버퍼)의 입출력 흐름을 작성하시오 
#include<iostream>
#include<string>

int main()
{

	std::cout<<"What is your name? ";
	std::string name;
	str::cin>>name;
	str:: cout<<"Hello, "<<name<<std::endl<<"And what is yours?";
	std::cin>>name;
	std::cout<<"Hello "<<name<<"; nice to meet you too!>>std::endl;
	return 0;

7. 테두리가 있는 인사말 예제 프로그램에서 테두리로 둘러쌓인 인사말의 상하 공백과 좌우공백의 크기를 다르게 바꿔보시오

8. 같은 예제에서 인사말을 출력할때 사용자가 테두리와 인사말 사이의 공백을 입력하도록 다시 만들어 보시오

9. '*'문자로 정사각형, 삼각형, 직사각형의 형태를 출력하시오

10. 다음 코드의 동작을 설명하시오
int i=0;
while(i<10)
{
	i+=1;
	std::cout<<i<<std::endl;
}

11. 10에서 -5 까지 카운트다운하는 프로그램을 작성해 보시오

12. [1.10)범위에 있는 숫자들의 곱을 만드는 프로그램을 작성하여 보시오

13. 다음 프로그램에서 std::의 쓰임새를 설명하시오 , 아래에서 두번째 행의 std::cout에서 std를 지웠을때의 프로그램의 동작 여부와 실행(불가)의 이유를 설명하시오
int main()
{
	int k(0);
	while(k!=10)
	{
		using std::cout;
		cout<<"*";
		++k;
	}
	std::cout<<std::endl;
	return 0;
}

*/