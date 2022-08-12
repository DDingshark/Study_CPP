#include"Average.h"
#include<vector>
#include<numeric>
using namespace std;
double average(vector<double> v)
{
	return accumulate(v.begin(), v.end(), 0.0 / v.size());
	//numeric해더에 선언 -> 첫인수 2개의 인수범위 값들을 더하며 세번째 인수로 주어진 값을 합하는 과정
	//0이 아닌 0.0으로 하는 이유는 int 대신 double을 사용해야 하기에
}
