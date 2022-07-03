#include<iostream>
using namespace std;

class CTest
{
public:
	CTest()
	{
		cout << "CTest()" << endl;
		m_pData = new int(5);
}
	~CTest()
	{
		cout << "~CTest()" << endl;
		delete m_pData;
	}
	CTest(const CTest& rhs)
		//��������� ���� �� ����: Ŭ�����̸�(const Ŭ�����̸� &rhs);
	{
		cout << "CTest(const CTest &)" << endl;
//		this->m_nData = rhs.m_nData; //�ɹ����� �ܼ��������� �����Ѵ�.
		//pointer������ shallowī�� -> ���߿� ���ﶧ �����߻�
		// ��? -> a,b�� ����Ű�� ����̶Ȱ��Ƽ� delete�Ҷ������߻�
		this->m_pData = new int(*rhs.m_pData);
		//Deep
	}

	void SetData(int nParam)
	{
		*m_pData = nParam;
	}
	int GetData()
	{ 
		return *m_pData;
	}
	int m_nData = 0; // C++11 ��Ÿ��(�����ڷ� ���� ���ص� ����
private:
	int* m_pData = nullptr; // NULL������

};
int main()
{

	int nData = 5;
	
	int* pA = &nData;
	int* pB = NULL;
	pB = pA; //Shallow

	int* pC = new int(*pA); //Deep
	cout << *pA << endl;
	cout << *pB << endl;
	cout << *pC << endl;
	//nData(���ü)�� 1���δ� �����Ͱ�2��<-���ٹ��(��������)��2��
	//DeepCopy ; ���ü�� ��������ī��
	//ShallowCopy : �����ڰ� �������� ī��

	CTest a;
	a.m_nData = 300;
	CTest b(a);//<<-- ��������ڰ� �Ҹ�
	cout << a.m_nData << endl; //300
	cout << b.m_nData << endl; // 0? <- 
	return 0;

}