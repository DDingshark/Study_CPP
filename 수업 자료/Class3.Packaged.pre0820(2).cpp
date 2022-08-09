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
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}
double median(vector<double>vec)
{
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	if (size == 0)
		throw std::domain_error("midian of an empty vector");

	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double grade(double midterm, double final, const vector<double>& hw) 
{
	if (hw.size() == 0)
	{
		throw  std::domain_error("student has done no homework");
	}
	return grade(midterm, final, median(hw)); 
}

std::istream& read_hw(std::istream& in, vector<double>& hw)
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
	read_hw(cin, homework);

	try // try 와 catch사이의 실행문이 catch(error) error에 해당하는 error를 낸다면 실행 아니면 건너뜀.
	{
		double final_grade = grade(midterm, final, homework);
		streamsize prec = cout.precision(3);
		cout << "your final grade is " << setprecision(3)
			<< final_grade << setprecision(prec) << endl;
	}

	catch (std::domain_error)
	{
		cout << endl << "You must enter your grades. "
			"Please try again." << endl;

		return 1;
	}

	return 0;
}

//연산 구조화. fin 