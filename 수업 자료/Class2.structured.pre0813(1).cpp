//�����ð� ����
#include<iostream>
#include<ios> //����� ���̺귯������ ���۵� ���ڳ� ������ ũ�⸦ ��Ÿ������ -> streamsizeȰ��
#include<iomanip> // ��� ����� ��ȿ�ڸ����� ���� setprecison
#include<string>

using std::cin;  using std::setprecision;
using std::cout; using std::string;
using std::endl; using std::streamsize;

int  main()
{
	cout << "Please enter your first name : ";
	string name;
	cin >> name;
	cout << "Hello, " << name << '!' << endl;

	cout << "Please enter your midterm and final exam grade : ";
	double midterm, final;
	cin >> midterm >> final;
	/*
	cin<<midterm; 
	cin<<final; ���� �ǹ�

	+ �� final �� ���� �ٸ���? ->  �ٸ�������ϴ� ����� �߿� �ϳ��δ� �׳� �����̸����� ���ڴٰ�
	������ �����Ѱ�.

	*/

	cout << "Enter all your homework grade, "
		"followed by end-of-file : ";
	/*
	="En~~~gradem, follwed ~file"<<endl; �̰Ŷ� ���� ����� ���� ->�������츮������ �̷��Ե� ��
	*/

	int count(0);
	double sum(0);

	double x;
	while (cin >> x) // cin>>x �� �����ϴ� ������ �������� ->����
	{
		++count;
		sum += x;
	}

	streamsize prec = cout.precision();//���е��� ��ȯ�� �����ϴ� cout�� �޼ҵ�.
	cout << "Your final grade is " << setprecision(3)//3�ڸ��� ��Ʈ���� �������ּ��� �̷����� ���۾��Դϴ�.
														//���� �Ҽ������� ��2�ڸ� �� 1�ڸ��� �ڸ�
		<< 0.2 * midterm + 0.4 + final + 0.4 * sum / count
		<< setprecision(prec) << endl;
			//���Ŀ� ���� �ļ������ ����Ͽ� ���е��� �ٽ� �����·� �ٲ����

	/*
	
	streamsize prec = cout.precision(3);//���е��� �������� ��ȯ�� 3���� ����
	cout<<"Your final grade is"
		<<0.2 midterm+0.4*final+0.4 sum/count<<endl;

	cout.precision(prec);

	//�� ������� �� ������� ���̾�
	//->���е� ������ �Ѵ��� �˾ƺ��� �����

	*/
	return 0;
}


/*
while(cin>>x)
	�ؼ� : cin �� ǥ�� ���̺귯���� �Ϻ��� istream Ŭ���� ������ cin�� ���� ���ڷ� �ٲܼ�����.
		+�ش� ���ڰ��� bool������ �ٲپ� �����Ǻ��� ����Ҽ�����.

	

	��Ʈ������ �Է°����� ������ ���� ��Ȳ
	1. EOF 
	2. ������ Ÿ�԰� �����ʴ°��� �Է�
	3. �ý��� �Է���ġ���� �ϵ���� ��ָ� ���������� = Ű���� �������̽�
	=>������ ��ȯ 
*/