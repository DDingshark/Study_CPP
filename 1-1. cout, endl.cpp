// C++_study.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>

//c++ 에서는 사용자 지정 헤더파일 말고는 .h사용하지 않음

int main()
{
    std::cout << 10 << std::endl;
  
    // std  -> namespace 인대 -> 마땅한 한국어가 X -> '소속' 정도로 생각
    // cout -> console out으로 생각 
    //      : 1. std :: cout << value 
    //              value 의 형식에 상관없이 알아서 출력해준다.  
    // <<   -> re-direct 연산자 함수 
    // endl -> 끝났당!
    std::cout << 10 << std::endl;
    std::cout << 10U << std::endl;
    std::cout << 10.5 << std::endl;
    std::cout << 10.5F << std::endl;
    std::cout << 3+4 << std::endl;

    return 0;
}
