// c++로 떠나는 모험.
//1 차시. 입출력과 변수의 선언및 초기화
//  + 조건문 반복문
// 
//
// 
// 변수 : Data를 담는 공간 , 주소(address, location)+ 값(value) (L_value) <- Location value
//      -> 타입 : int(4) longlong(8)  float(8) -> double(8) unsigned int(4)-> 수의 범위는 같지만, 최댓값이 2배
//              : class 타입(변수와 함수들의 모임), point(다른 변수의 주소를 값으로 가지는) 타입도 있다.
//              : auto 타입 <- 나중에 설명해드릴게
// 
//상수 : 데이터의 값, 주소의 값, 혹은 그냥 숫자들 (R_value) <- Read only!! 



//int nData_C = 10; // C언어의 스타일
//int nData_CPP(10); // C++의 스타일
//
//double nDataF_C = 10;
//double nDataF_CPP(nDataF_C); // 이런식으로도 가능 -> nDataF_CPP = nDataF_C 랑 같은말
//
//for (int i = 0; i < 10; i++) // for(int i=0 <-이친구를이용해 반복문을 정의할거야 ; i<10 <- 조건 ; i++ 후속작업) 
//{
//    std::cout << "반복횟수 : " << i + 1 << std::endl;
//    // std::cout : 
//    // std : namespace : 가문 , 소속
//    // :: 스코프 연산자 ->  std의 가문의 cout을 호출하겠다 뭐 이런식
//    // cout console out 이라는 printf 보다 성능이 좋다 -> " %d ",a 이런식으로 안하고 그냥 형을 맞쳐줌 
//    // endl <- 엔드라인 print의 끝이다 뭐 이런느낌문장끝에 \n 대신 쳐주는 느낌.
//    // << 이거는... 그냥 나중에 설명 //그냥 외우는 방법도 있음.
//}

#include "stdafx.h"
#include <iostream>
#include<string>


using namespace std; // std가문애들은 생략하겠다.

void FightStart_Func(string monster)
{
    
}

int Attack_Func(int nData_DEMEGE, int nData_HP) // Paramater
//Return Type FuncName (Paramater)
{
    nData_HP -= nData_DEMEGE;

    if (nData_HP < 0)
    {
        nData_HP = 0;
    }

    return nData_HP; // Return Value
}

//게임을 하기 앞서 뭐먼저 해야하지? 로그인
int main()
{
    int Player_ID,Player_Password;
    cout << " Player_ID를 입력하시오 :  " << endl;
    cin >> Player_ID;

    if (Player_ID == 20220707)
    {
        cout << " Password를 입력하시오 : " << endl; // 출력하는방법
        cin >> Player_Password; // 입력하는 방법

        if (Player_Password == 1234)// 조건문 사용방법
        {
            int Answer_IN;
            int Player_Do;//변수의 선언
            cout << "확인되었습니다 캐릭터를 생성합니다 " << endl;

            // 로그인 완료

            string Player_Name;
            cin >> Player_Name;

            unsigned int Player_HP(100);// 변수의 선언 및 초기화
            int Player_Demege(10);
            double Player_Speed(5);

            cout << "당신의 캐릭터의 이름은 :" << Player_Name << "\n당신의 캐릭터의 HP,DEMEGE,SPEED는 각각 " << Player_Demege <<", "<< Player_HP <<", "<<Player_Speed <<"입니다"<< endl;

           

            string Computer_Mon("Hotdog");
            unsigned int Hotdog_HP(20);
            int Hotdog_Demege(3);
            const double Hotdog_Speed(6); // 상수화 시킨다 = 쓸수가 없다 = 읽기전용 
            

            cout << "전방에 Hotdog가 있습니다 싸우시겠습니까? (Y=1/N=2)" << endl;
            cin >> Answer_IN;
            
            while (1) // 1= Ture 니까 계속 반복
            {
                if (Answer_IN == 1)
                {
                    for (int i = 0; i < 1; i++)
                    {
                        cout << "전투가 시작되었다." << endl;
                        if (Hotdog_Speed >= Player_Speed)
                        {
                            cout << "HotDog의 공격" << endl;
                            Player_HP -= Hotdog_Demege;
                            cout << "남은 HP :" << Player_HP << endl;

                            //아직 튜토리얼이라 공격만 할 수 있다.
                            cout << "어떤 행동을 하시겠습니까? : 1. 공격" << endl;
                            cin >> Player_Do;

                            if (Player_Do == 1)
                            {
                                Hotdog_HP -= Player_Demege;
                                cout << "HotDog의 남은 HP: " << Hotdog_HP << endl;
                            }

                        }
                        
                    }
                    
                    cout << "HotDog가 도망쳤다! 전투를종료합니다." << endl;
                    
                    
                    break;
                }


                else
                {
                    cout << "도망칠수 없다!" << endl;
                    cout << "전방에 Hotdog가 있습니다 싸우시겠습니까? (Y=1/N=2)" << endl;
                    cin >> Answer_IN;

                }
            }




            











































        }
        else
        {
            cout << "비밀번호가 틀렸습니다." << endl;
        }
    }

    else
    {
        cout << "누구십니까?" << endl;
    }
    return 0;
}

