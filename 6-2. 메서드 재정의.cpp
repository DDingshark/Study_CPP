#include< iostream>
using namespace std;
/*
	메서드 재정의 : method overide = 메서드 무시하다?
									= 메서드 덮어쓰기

			-> 파생클레스에서 메소드를 재정의하면 원래 메소드가 무시되고 파생클레스의 메소드가 호출

	 => 뭐 이렇다곤 하는대 실상 사용하는 이유는 두 함수의 공존을 추구하긴함			
*/

//초기 제작자
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
	//파생클레서에서 기본클레스의 메소드를 재정의
	void SetData(int nParam)
		{
			
			//입력데이터의 값을 보정하는 기능 추가
			if (nParam < 0)
			{
				CMyData::SetData(0);
				//SetData(0)이래버리면 재귀호출이 되기에.... 아시죠?
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
	a.SetData(-10); // 생성된 클레스가 구형클레스 1개이니까 파생클래스의 함수는 존재 자체도 모름
	cout << a.GetData() << endl;

	CMyDataEx b;
	b.SetData(-10); // 파생클레스가 생성되면 그위로 쭈루룩 다 댈고오기때문에 
	cout << b.GetData() << endl; // GetData() 사용가능

	//참조형식과 실형식
	cout << "*************" << endl;
	CMyDataEx cData; //실형식
	CMyData& rData = cData;
	//참조형식 -> 인간인 rData를 가져오기위해 카리나인 cData에서 인간의 모습만 쏙 빼서 쓰겠다 이런말로 뭐... 이해 해주길? 
	
	//★일반메서드는 참조형식을 따르고, 가상함수는 실형식을 따른다.

	rData.SetData(11);
	cout << rData.GetData() << endl;

	cout << "*************" << endl;
	CMyData* pData = new CMyDataEx; //일단 생성자는 2개 다불림 -> 만약에 Ex 생성자에 메모리 할당 기능이 있었다면?
	pData->SetData(5);
	delete pData;
	//여기서 delete하더라도.. CMyDataEx의 소멸자가 불러지지 X  -> 메모리누수
	//가상화 의 필요성

	//상속에서의 생성자와 소멸자의 호출시기 차이
	// -> 생성자 -> 엄마부터 만들어야 아들이 만들어 지겠죠?
	// -> 소멸자 -> 아들부터 죽어야 엄마를 죽일수 있나..? 껍질 깐다는 이미지를 잘 생각해 보면 Good일듯!
	return 0;
}