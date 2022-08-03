#include< iostream>
using namespace std;
/*
	�޼��� ������ : method overide = �޼��� �����ϴ�?
									= �޼��� �����

			-> �Ļ�Ŭ�������� �޼ҵ带 �������ϸ� ���� �޼ҵ尡 ���õǰ� �Ļ�Ŭ������ �޼ҵ尡 ȣ��

	 => �� �̷��ٰ� �ϴ´� �ǻ� ����ϴ� ������ �� �Լ��� ������ �߱��ϱ���			
*/

//�ʱ� ������
class CMyData
{
public: 
	CMyData()
	{
		cout << "CMyData()" << endl;
	}
	~CMyData()
	{
		cout << "~CMyData()" << endl;
	}
	int GetData() { return m_nData; }

	void SetData(int nParam) { m_nData = nParam; }
	
private:
	int m_nData = 0;

};


class CMyDataEx : public CMyData
{
public: 
	CMyDataEx()
	{
		cout << "CMyDataEx()" << endl;
	}
	~CMyDataEx()
	{
		cout << "~CMyDataEx()" << endl;
	}
	//�Ļ�Ŭ�������� �⺻Ŭ������ �޼ҵ带 ������
	void SetData(int nParam)
		{
			
			//�Էµ������� ���� �����ϴ� ��� �߰�
			if (nParam < 0)
			{
				CMyData::SetData(0);
				//SetData(0)�̷������� ���ȣ���� �Ǳ⿡.... �ƽ���?
			}
			
			if (nParam > 10)
			{
				CMyData::SetData(10);
			}
		}
};


int main()
{
	CMyData a; 
	a.SetData(-10); // ������ Ŭ������ ����Ŭ���� 1���̴ϱ� �Ļ�Ŭ������ �Լ��� ���� ��ü�� ��
	cout << a.GetData() << endl;

	CMyDataEx b;
	b.SetData(-10); // �Ļ�Ŭ������ �����Ǹ� ������ �޷�� �� �����⶧���� 
	cout << b.GetData() << endl; // GetData() ��밡��

	//�������İ� ������
	cout << "*************" << endl;
	CMyDataEx cData; //������
	CMyData& rData = cData;
	//�������� -> �ΰ��� rData�� ������������ ī������ cData���� �ΰ��� ����� �� ���� ���ڴ� �̷����� ��... ���� ���ֱ�? 
	
	//���Ϲݸ޼���� ���������� ������, �����Լ��� �������� ������.

	rData.SetData(11);
	cout << rData.GetData() << endl;

	cout << "*************" << endl;
	CMyData* pData = new CMyDataEx; //�ϴ� �����ڴ� 2�� �ٺҸ� -> ���࿡ Ex �����ڿ� �޸� �Ҵ� ����� �־��ٸ�?
	pData->SetData(5);
	delete pData;
	//���⼭ delete�ϴ���.. CMyDataEx�� �Ҹ��ڰ� �ҷ����� X  -> �޸𸮴���
	//����ȭ �� �ʿ伺

	//��ӿ����� �����ڿ� �Ҹ����� ȣ��ñ� ����
	// -> ������ -> �������� ������ �Ƶ��� ����� ������?
	// -> �Ҹ��� -> �Ƶ���� �׾�� ������ ���ϼ� �ֳ�..? ���� ��ٴ� �̹����� �� ������ ���� Good�ϵ�!
	return 0;
}