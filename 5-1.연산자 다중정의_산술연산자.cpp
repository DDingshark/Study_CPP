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
		//잊지말자 초기화!
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
		//허용되는 변환;
	{
		return m_nData;
	}

	int operator =(int nParam)
		//void로 만들면 a = b = 5이런건????
	{
		//		m_nData = nParam; 컴파일러 최적화를 믿고 메모리? 이런거하지말자
		//		똑같은 일을 하는애들은 그냥 불러쓰자. 오버해드 안커짐 컴파일러가 알아서해줌.
		//		->어? 통제? 기계를 잘 활용하는거양!
		SetData(nParam);
		return m_nData;
	}

//	CMyData& operator+( CMyData& rhs)
//		//+ 연산자 만들기. 다중정의때매 const뺐어용
//	{
//		m_nData += rhs.GetData();
//		return *this;
//	}
	//이런식으로 만들면... ?

	CMyData operator +(const CMyData& rhs) const
	{
		cout << "operator + " << endl;
		CMyData result(0);
		result.m_nData = this->m_nData + rhs.m_nData;

		return result;
		//return CMyData(this -> m_nData + rhs.m_nData; 이러면 안대?
		//이동생성자가 불러짐.어디서? 
		//result 객체가 생성될때.
		
	}
	//


	CMyData& operator=(const CMyData &rhs)
	//객체가 2개나 없어지자나 !
		// 앞에 CMyData는 결국엔 본인인대 왜 복사?
		// 뒤에 CMyData는 그냥 있는거 가져오면 대자나!
	{
		SetData(rhs.GetData());
		return *this;
		//본인 반환 이니까 *this
	}
	//다중정의를 이용해서 a=b 이런식으로의 대입연산자도 지원!



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
	b.SetData(6); //이거 단순대입으로 잘 할수 있을거같은대?
	// a=5이렇게...
	cout << a+b << endl;
	a.SetData(7);
	a.operator=(7);
	a = 7;
	//사용자 입장에서는 기본연산처럼보임 -> 프로그램을 짤때 기본연산은 
	//절대로 오류가 나면 안대.. 왜? 사용자가 아무런 의심없이 사용하지 않기 때문에 디버깅이 산으로 갈수도 잇음.
	//나중에 예외처리 이런거 잘 활용하자....
	
	//혹시 a = b =5;
	//이런건? 대입연산자함수를 void로 해서 ㅠㅠ a= void이런식으로댐....
	//1. int operator =(int param) { SetData(); return m_nData;} 이렇게?
	//2. 다중정의로 클래스 형식으로도 = 할수 있게 다중정의?


	cout << a + b << endl;
	//a+b 이걸 하고싶은대...
	//a.GetData()+b.GetData()이러면 좀.. 그렇자나..... 맴버가 이거 하나만 있는것도 아니고 
	// 
	//어머? 형변환 연산자만 했는대 오류가 안나내?
	// -> 컴파일러가 지가 알아서 해버린거야....
	//	->기계한태 지지말자... : '잘'에 도달하지 못한다 이러면...


	cout << "End of operator = " << endl;
	cout << "Start of operator + " << endl;

	CMyData c(10);
	CMyData d(20);
	CMyData e;
	CMyData result = c+d;
	e=result;



	cout << e << endl;
	cout << "End of Main" << endl;

	//뭔가 원하던 결과가 아닌대.... 
	//허용되는 변환 때매 뭔가 내부적으로 연산자함수를 안부르는거같아... ㅠㅠㅇ
	return 0;
}