#include<iostream>
#include<string>

int main()
{
	std::cout << "Please enter first name : ";
	std::string name;
	std::cin >> name;
	
	//��¸޼��� �ۼ�
	const std::string greeting = "Hello" + name + '!';
	//c++�� ���� : ������ �����ε�(overload) ����� ��������?
// �Լ��� ���ڿ� ���� �Լ����� �������� �ҷ����� �Լ��� �޶���.
// �����ڶ��� ���� ��ȣ�� �ǿ����ڵ鿡 ���� ���� �ٸ������ ȣ���� �� �ִ�.

// ������ +
// 1. ó�� ���� �ǿ����ڸ� �޸𸮿� �����Ѵ�.
// 2. ������ �ǿ����ڿ� ���� �ǿ������� ���̸� ���� �� +1�� ũ�⸦ �Ҵ�޴´�.
// 3. �ǿ����ڵ��� �̾ ���δ�.

	const std::string spaces(greeting.size(), ' ');
	const std::string second = "* " + spaces + " *";
	const std::string first(second.size(), '*');

	std::cout << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << "* " << greeting <<" *" << std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;




	

	return 0;
}