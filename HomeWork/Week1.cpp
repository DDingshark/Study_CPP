/*

1. ���� ����� ���ǹ��� �ùٸ��� �Ǵ��Ͻÿ�

const std::string hello ='Hello';
std::string message = "Hello +",world"+"!";

2. ���� ����� ���ǹ��� �ùٸ��� �Ǵ��Ͻÿ�
const std::string exclam ="!";
std::string message ="Hello"+", world"+ exclam;

3. ���� ���α׷��� �ùٸ��� �����ϴ��� �Ǵ��Ͻÿ�
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

4. ���� ���α׷��� �ùٸ��� �����ϴ��� �Ǵ��ϰ�, ������ ����° ���� }}�� };}�� ������������ ����� �� ����� ���� ������ �����Ͻÿ�
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

5. ���� ���α׷��� �ùٸ��� �����ϴ� �Ǵ��Ͽ���, ������ �ִٸ� �ùٸ��� ���ĺ��ÿ�
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

6. Samuel Beckett ó�� �ѹ��� 2���� �ܾ �Է��Ҷ��� ����� ������ ���� ���α׷��� ���� ���Ѻ��ÿ�
	�߰��� ��Ʈ��(����)�� ����� �帧�� �ۼ��Ͻÿ� 
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

7. �׵θ��� �ִ� �λ縻 ���� ���α׷����� �׵θ��� �ѷ����� �λ縻�� ���� ����� �¿������ ũ�⸦ �ٸ��� �ٲ㺸�ÿ�

8. ���� �������� �λ縻�� ����Ҷ� ����ڰ� �׵θ��� �λ縻 ������ ������ �Է��ϵ��� �ٽ� ����� ���ÿ�

9. '*'���ڷ� ���簢��, �ﰢ��, ���簢���� ���¸� ����Ͻÿ�

10. ���� �ڵ��� ������ �����Ͻÿ�
int i=0;
while(i<10)
{
	i+=1;
	std::cout<<i<<std::endl;
}

11. 10���� -5 ���� ī��Ʈ�ٿ��ϴ� ���α׷��� �ۼ��� ���ÿ�

12. [1.10)������ �ִ� ���ڵ��� ���� ����� ���α׷��� �ۼ��Ͽ� ���ÿ�

13. ���� ���α׷����� std::�� ���ӻ��� �����Ͻÿ� , �Ʒ����� �ι�° ���� std::cout���� std�� ���������� ���α׷��� ���� ���ο� ����(�Ұ�)�� ������ �����Ͻÿ�
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