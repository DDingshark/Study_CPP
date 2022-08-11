// 간단한 C++ 프로그램
// 주석 -> comment : 컴파일과정에서 생략댐 // /* comment */

#include<iostream>
/*
	#include -> c++ 대다수의 기능은 기본영역(core language)이 아닌 표중라이브러리 (standard library)
	 에 저장이 되어있음

	 -> 여러가지 라이브러리의 기능을 사용하고싶으면 그 기능이 저장되어있는(정의되어있는) 헤더파일을
	 미리(전처리기가) 설치를 시켜줘야 찾아서 쓸수있음(컴파일러가)

	 < >(angle brakets) : 내장되어있는 탐색순서에 맞게 탐색 -> 표준 라이브러리를 호출한다.

	 사용자지정 라이브러리를 사용하고 싶을때는 -> 미리 경로를 알려주는 방법, 같은 폴더에 넣고 "이름"

*/
int main()
/*
	함수(Function) -> 프로그램 일부분에 이름을 붙인것 
	프로그램의 다른영역(= 스택의 외부범위, =라이브러리에서의 호출)에서 호출하거나 실생할 수 있게 함.  
*/
{ //L_Curly brace
	// statment
	std::cout << "Hello World ! " << std::endl;
	/*
		std::  -> std 라는 네임스페이스에 속해있음을 나타냄
		std -> 표준 라이브러리가 제공하는 모든 기능들은 std네임스페이스에 저장되어있음.

		std::cout -> 표준 출력 스트림 (standard output stream) GUI운영체제 기반에서 연관된 창에 실행문에 적힌 내용을 출력

		std::endl -> 표준 출력 스트림에 이 코드를 넣으면 더이상 그행에 어떠한 내용도 출력하지 않음.
	*/

	/*
		+@
		표현식(expression)과 범위(scope)

		표현식 -> 프로그램에 무엇인가 계산하도록 요청하는것/
			표현식을 실행했을때는 부수적인 효과가 있을 수도 있음(side effect)

			ex -> 3+4; 7을반환 

			std::cout<<"Hello World !"<<std::endl;

			
			<< : 기호연산자(operator) , std::cout, "Hello World !", std::endl :피연산자(operand)

			스트림 기반 출력을 제공하는 타입의 이름은 std::ostream
			 
			 << : 왼쪽 우선 결합성 성질을 가짐 
			 (((std::cout<<"Hello")<<"World")<<endl);
			 

			 -> 첫번째 << :
			 std::ostream 타입인 std::cout을 첫번째 피연산자로 가짐 + 알수없는 타입의 문자열 리터럴 ("Hello World !")

			 << : 오른쪽 피연산자를 왼쪽 피연산자에 해당하는 스트림에 문자를 넣음 

			 두번째 << 왼쪽 피연산자들은 std::ostream 을 반환하는 표현식이고 왼족 피연산자는 조작어(manipulator) 
			 std::endl을 스트림에 넣으면 문자열을 넣는것과 다르게 조작어의 기능을 수행시키고
			 std::ostream을 반환 

			 출력을 얻었자나 -> cout이라는 함수의 side effect 
			=> 1. 반환값을 사용할 필요가 없으니까 따로 메모리를 할당하지 않음
			   2. ;로 끝내버리면 반환하는 값을 구현체가 무시한듦
			   
		scope 해당 이름이(별명이 -> 공간 -> 메모리가) 문맥적의미가 유지되는 프로그램의 영역
			1. std::cout <- 정규화된 이름 ::연산자 (scope operator) -> 넴임스페이스 std의 범위에있는 cout을 가져오겠다.

			2. { } -> 지역변수의 수명이 유지되는 여역.





				
	
	*/
	return 0;
	/*
		함수의 정의부분에서 반환타입과 반환 값이 정확이 일치해야댐.
		함수의 종료시점은 여러개가될수있음.
	
	*/
} //R_Culry brace
