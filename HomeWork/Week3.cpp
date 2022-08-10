/*
	(순차 sequentail)컨테이너 인터페이스 

	container<T>::iterator , container<T>::const iterator
	container<T>::size_type
	container<T> c
	container<T>c(c2)
	container<T>c(n)
	container<T>c(n,t) 
	container<T>c(b,e) (왜 똑같은 형식이 2개있는지 찾아보시오)
	c.bigin() c.rbigin()
	c.end()	c.rend()
	c=c2
	c.size()
	c.empty()
	c.insert(d,b,e)
	c.erase(it)
	c.erase(b,e)
	c.push_back(t)
	
	임의적 접근을 허락하는 컨테이너는 지원
	c[n]

	반복자 연산
	*it
	it->x
	it++,it--
	b==e , b!=e

	문자열 타입
	s.substr(i,j)
	getline(is,s)
	s+=s2

	백터타입(일부)
	v.reserve(n)
	v.resize(n)

	숙제
	1. 순열 인덱스를 만드는 프로그램을 설계하고 구현하라. 순열 인덱스에서는 각 구문을 이루는 모든 단어로 인덱스를 만든다
		input
			The quick brown fox
			jumped over the face

		output
			The quick			brown fox
			jumped over the		face
			The quick brown		fox
								jumped over the face
				     jumped		over the face
					    The		quick brown fox
				jumped over		the face
								The quick brown fox

		만드는 방법
			1. 입력의 각 행을 읽고 해당 행의 회전 집단을 만든다. ( 123/n 231/n 312 이런식)
			2. 회전 집단을 정렬한다.
			3, 구분 기호를 찾고 구문을 우너래대로 되돌린 후, 순열 인덱스를 알맞은 형태로 출력한다. 

	
	2. 기존 문자열에 있는 모든 행에 최대 가로크기로 공백을 채운 문자열을 반환하는 center(const vector<string&)함수를 구현하라
	   이때 공백은 문자열의 양측에 균등하게 채워진다. (제일 긴문자열을 기준으로 중앙정렬을 하라는 말입니다)

	3. extract_fails함수는 입력벡터인 students에서 과락 학생을 각각 제거한다. 기준 점수를 통과한 학생들의 정보를
		students의 시작지점으로 복사한 후 , resize함수를 사용하여 students의 끝에서부터 여분의 요소를 제거하도록 다시작성해보고
		성능을 비교하라

	4. frame 함수를 호출하여 동작을 확인하라
		width 함수와 frame함수가 어떻게 동작하는지 추적하고, 예상했던 결과가 아니라면 예상한 결과가되도록 변경하라.

	5. hact 함수에서 s를 while문의 바깥에 정의하면 어떻게 될까?

	6. 입력데이터를 받아 대문자를 포함하지 않는 단어를 먼저 출력하고, 뒤이어 하나 이상의 대문자를 포함하는 단어를 출력하는 프로그램을 작성하라

	7. 회문은 오른쪽으로 읽으니 왼쪽으로 읽으나 같은 우영우 같은 단어다. 입력받은 단어들중 회문을 찾아 출력하는 프로그램을 작성하라

	8. 텍스트 처리과정에서 단어에 어센더(ascender) 나 디센더(descender)가 있는지 파악하면 유용할때가 있다.
		어센더는 소문자 x가 기준일때 x보다 위쪽으로 뻗은 문자이다. 예를들면 b,d,f,h,k,l,t 가 어센더 문자이다.
		디센더 문자는  g j,p,q,y 가 디센더 문자이다. 입력받은 단어에서 각 철자가 어센더 또는 디센더인지 판별하는 프로그램을 작성하라.




*/