#include<iostream>
#include<string>

using namespace std;

int main()
{
	cout << "Please enter tour first name :";
	string name;
	cin >> name;

	const string greeting = "Hello, " + name + '!';

	const int pad(1);
	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;

	cout << endl;

	for (int r = 0; r != rows; ++r)
	{
		string::size_type c = 0;
		while (c != cols)
		{
			if (r == pad + 1 && c == pad + 1)
			{
				cout << greeting;
				c += greeting.size();

			}
			else
			{
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
				{
					cout << "*";

				}
				else
				{
					cout << " ";
				}
				++c;
			}

		}
		cout << endl;
	}

	return 0;

}



/*
x.y x[y],x++, x--

++x,--y, !x

x*y, x/y, x%y

x+y, x-y

x>>y x<<y

x relop y <= >= < >

x==y x!=y

x&&y 

x||y

x=y

x op= y +=,-=, *= ...

x?y:z -> x�� ���̸� y�� ��ȯ x�� �����̸� z�� ��ȯ

*/

//string ::size_type : ��� ���ڿ��� ũ�⸦ �����Ҽ� �ִ� ��ȣ������ ����Ÿ��
//size_t : ��� ��ü�� ũ�⸦ ������ �� �ִ� ��ȣ�� ���� ����Ÿ��

//=> unsigned int
//<cstddef>

�߰����, �⸻��� ���հ������� -> ��������
20			40			40
-> ���������� ���ϴ� ���α׷�

�л����� ��?�� 

�л� �̸� : 
�߰� ���� : 
�⸻ ���� :
���� ���� : 

�л� �̸� :
�߰� ���� :
�⸻ ���� :
���� ���� :

�л� �̸� :
�߰� ���� :
�⸻ ���� :
���� ���� :

�л� �̸� :
�߰� ���� :
�⸻ ���� :
���� ���� :

�л� �̸� :
�߰� ���� :
�⸻ ���� :
���� ���� :

�л� �̸� :
�߰� ���� :
�⸻ ���� :
���� ���� :

�л� �̸� :
�߰� ���� :
�⸻ ���� :
���� ���� :


<<���� ���б� �л� ����ǥ>>
�л� �̸� : ������, �߰� : �⸻ : ���հ��� : ���� : 
�л� �̸� : ������, �߰� : �⸻ : ���հ��� : ���� : 
�л� �̸� : ������, �߰� : �⸻ : ���հ��� : ���� : 
�л� �̸� : ������, �߰� : �⸻ : ���հ��� : ���� : 
�л� �̸� : ������, �߰� : �⸻ : ���հ��� : ���� : 
<<���� ���б� �л� ����ǥ ��>>

