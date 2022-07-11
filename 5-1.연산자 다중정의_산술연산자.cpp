#include<iostream>
using namespace std;

class CMyData
{
public:
	CMyData()
	{
		cout << "CMyData()" << endl;
	}

	CMyData(const CMyData& rhs)
	{
		cout << "CMyData(const CMyData& rhs" << endl;
		m_nData = rhs.m_nData;
		//�������� �ʱ�ȭ!
	}

	CMyData(const CMyData&& rhs)
	{
		cout << "CMyData(const CMyData&& rhs)" << endl;
		m_nData = rhs.m_nData;
	}

	explicit CMyData(int nParam)
	{
		cout << "CMyData(int)" << endl;
		m_nData = nParam;
	}
	~CMyData()
	{
		cout << "~CMyData()" << endl;
	}


	operator int(void)
		//���Ǵ� ��ȯ;
	{
		return m_nData;
	}

	int operator =(int nParam)
		//void�� ����� a = b = 5�̷���????
	{
		//		m_nData = nParam; �����Ϸ� ����ȭ�� �ϰ� �޸�? �̷�����������
		//		�Ȱ��� ���� �ϴ¾ֵ��� �׳� �ҷ�����. �����ص� ��Ŀ�� �����Ϸ��� �˾Ƽ�����.
		//		->��? ����? ��踦 �� Ȱ���ϴ°ž�!
		SetData(nParam);
		return m_nData;
	}

//	CMyData& operator+( CMyData& rhs)
//		//+ ������ �����. �������Ƕ��� const�����
//	{
//		m_nData += rhs.GetData();
//		return *this;
//	}
	//�̷������� �����... ?

	CMyData operator +(const CMyData& rhs) const
	{
		cout << "operator + " << endl;
		CMyData result(0);
		result.m_nData = this->m_nData + rhs.m_nData;

		return result;
		//return CMyData(this -> m_nData + rhs.m_nData; �̷��� �ȴ�?
		//�̵������ڰ� �ҷ���.���? 
		//result ��ü�� �����ɶ�.
		
	}
	//


	CMyData& operator=(const CMyData &rhs)
	//��ü�� 2���� �������ڳ� !
		// �տ� CMyData�� �ᱹ�� �����δ� �� ����?
		// �ڿ� CMyData�� �׳� �ִ°� �������� ���ڳ�!
	{
		SetData(rhs.GetData());
		return *this;
		//���� ��ȯ �̴ϱ� *this
	}
	//�������Ǹ� �̿��ؼ� a=b �̷��������� ���Կ����ڵ� ����!



	void SetData(int nParam)
	{
		m_nData = nParam;
	}

	int GetData(void) const
	{
		return m_nData;
	}


private:
	int m_nData = 0;
};

int main()
{
	CMyData a;
	CMyData b;
	a.SetData(5);
	b.SetData(6); //�̰� �ܼ��������� �� �Ҽ� �����Ű�����?
	// a=5�̷���...
	cout << a+b << endl;
	a.SetData(7);
	a.operator=(7);
	a = 7;
	//����� ���忡���� �⺻����ó������ -> ���α׷��� ©�� �⺻������ 
	//����� ������ ���� �ȴ�.. ��? ����ڰ� �ƹ��� �ǽɾ��� ������� �ʱ� ������ ������� ������ ������ ����.
	//���߿� ����ó�� �̷��� �� Ȱ������....
	
	//Ȥ�� a = b =5;
	//�̷���? ���Կ������Լ��� void�� �ؼ� �Ф� a= void�̷������δ�....
	//1. int operator =(int param) { SetData(); return m_nData;} �̷���?
	//2. �������Ƿ� Ŭ���� �������ε� = �Ҽ� �ְ� ��������?


	cout << a + b << endl;
	//a+b �̰� �ϰ������...
	//a.GetData()+b.GetData()�̷��� ��.. �׷��ڳ�..... �ɹ��� �̰� �ϳ��� �ִ°͵� �ƴϰ� 
	// 
	//���? ����ȯ �����ڸ� �ߴ´� ������ �ȳ���?
	// -> �����Ϸ��� ���� �˾Ƽ� �ع����ž�....
	//	->������� ��������... : '��'�� �������� ���Ѵ� �̷���...


	cout << "End of operator = " << endl;
	cout << "Start of operator + " << endl;

	CMyData c(10);
	CMyData d(20);
	CMyData e;
	CMyData result = c+d;
	e=result;



	cout << e << endl;
	cout << "End of Main" << endl;

	//���� ���ϴ� ����� �ƴѴ�.... 
	//���Ǵ� ��ȯ ���� ���� ���������� �������Լ��� �Ⱥθ��°Ű���... �ФФ�
	return 0;
}