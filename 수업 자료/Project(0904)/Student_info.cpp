#include"Student_info.h"

using std::istream;
using std::vector;

istream& read_hw(istream& in, vector<double>& hw)
{
	double x;
	if (in)
	{
		hw.clear();
		while (in >> x)
		{
			hw.push_back(x);
		}
		in.clear();
	}
	return in;
}

istream& read(istream& is, Student_info& s)
{
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

bool did_all_hw(const Student_info& s)
{
	return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
	//find 함수의 반환 값과 homework.end의 반환 값을 비교하여 모든 숙제를 했는지 확인
}
