#include<iostream>
using namespace std;
// ���(Inherrit) 
	// 1. �ڵ带 �����ϴ� ���
	// 2. �Ը��� Ȯ��
	// 3. ������ �� ����.

// �������� Ŭ���������� ���踦 '����' <- ����, ����, �̷��� ����Ͽ�

// �θ�(�⺻, �߻�) Ŭ���� -> �ڽ�(�Ļ�, ����)Ŭ���� �� �����̸�, �ڽ�Ŭ������ �θ�Ŭ������ �������̴�.
// �޸� ũ�� �Ļ�Ŭ���� = �θ�Ŭ���� + �Ļ�Ŭ���� ��ü�� ũ��

class CMyData
{
public:
	CMyData()
	{
		cout << "CMyData()" << endl;
	}

	int GetData()
	{
		return m_nData;
	}

	void SetData(int nParam)
	{
		m_nData = nParam;
	}

protected: // �ڽ�Ŭ�������� ���� ����.
	void PrintData()
	{
		cout << "CMyData::PringData()" << endl;
	}

private: // ���� ! �Ļ�Ŭ�������� �⺻Ŭ������ �ʱ�ȭ X ������ ���� Ŭ������ �ɹ��� ����Ŭ������ �ʱ�ȭ + �ɹ������� �������̸� private�� ��������.
	int m_nData = 0;
};


class CMyDataEx :public CMyData // �Ļ�Ŭ������ ���� -> ���� �����ڴ� 99%�̻� public ����
{
public:
	CMyDataEx()
	{
		cout << "CMyDataEx()" << endl;
	}

	void TestFunc()
	{
		PrintData();
		SetData(5);
		cout << "CMyData :: GetData()" << endl;
	}


};
int main()
{

	CMyDataEx data; // �Ļ�Ŭ���� ���� ������ , �θ�Ŭ������ �����ڵ� ����ȴ� but ȣ����� != ������� �̱⿡ ȣ���� �ڽ� -> �θ� , ������ �θ� -> �ڽ�
	// �����غ��� ���.
	data.SetData(10);
	cout << data.GetData() << endl;

	data.TestFunc();
	return 0;
}