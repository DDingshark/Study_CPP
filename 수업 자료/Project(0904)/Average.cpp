#include"Average.h"
#include<vector>
#include<numeric>
using namespace std;
double average(vector<double> v)
{
	return accumulate(v.begin(), v.end(), 0.0 / v.size());
	//numeric�ش��� ���� -> ù�μ� 2���� �μ����� ������ ���ϸ� ����° �μ��� �־��� ���� ���ϴ� ����
	//0�� �ƴ� 0.0���� �ϴ� ������ int ��� double�� ����ؾ� �ϱ⿡
}
