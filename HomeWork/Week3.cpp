/*
	(���� sequentail)�����̳� �������̽� 

	container<T>::iterator , container<T>::const iterator
	container<T>::size_type
	container<T> c
	container<T>c(c2)
	container<T>c(n)
	container<T>c(n,t) 
	container<T>c(b,e) (�� �Ȱ��� ������ 2���ִ��� ã�ƺ��ÿ�)
	c.bigin() c.rbigin()
	c.end()	c.rend()
	c=c2
	c.size()
	c.empty()
	c.insert(d,b,e)
	c.erase(it)
	c.erase(b,e)
	c.push_back(t)
	
	������ ������ ����ϴ� �����̳ʴ� ����
	c[n]

	�ݺ��� ����
	*it
	it->x
	it++,it--
	b==e , b!=e

	���ڿ� Ÿ��
	s.substr(i,j)
	getline(is,s)
	s+=s2

	����Ÿ��(�Ϻ�)
	v.reserve(n)
	v.resize(n)

	����
	1. ���� �ε����� ����� ���α׷��� �����ϰ� �����϶�. ���� �ε��������� �� ������ �̷�� ��� �ܾ�� �ε����� �����
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

		����� ���
			1. �Է��� �� ���� �а� �ش� ���� ȸ�� ������ �����. ( 123/n 231/n 312 �̷���)
			2. ȸ�� ������ �����Ѵ�.
			3, ���� ��ȣ�� ã�� ������ ��ʷ���� �ǵ��� ��, ���� �ε����� �˸��� ���·� ����Ѵ�. 

	
	2. ���� ���ڿ��� �ִ� ��� �࿡ �ִ� ����ũ��� ������ ä�� ���ڿ��� ��ȯ�ϴ� center(const vector<string&)�Լ��� �����϶�
	   �̶� ������ ���ڿ��� ������ �յ��ϰ� ä������. (���� �乮�ڿ��� �������� �߾������� �϶�� ���Դϴ�)

	3. extract_fails�Լ��� �Էº����� students���� ���� �л��� ���� �����Ѵ�. ���� ������ ����� �л����� ������
		students�� ������������ ������ �� , resize�Լ��� ����Ͽ� students�� ���������� ������ ��Ҹ� �����ϵ��� �ٽ��ۼ��غ���
		������ ���϶�

	4. frame �Լ��� ȣ���Ͽ� ������ Ȯ���϶�
		width �Լ��� frame�Լ��� ��� �����ϴ��� �����ϰ�, �����ߴ� ����� �ƴ϶�� ������ ������ǵ��� �����϶�.

	5. hact �Լ����� s�� while���� �ٱ��� �����ϸ� ��� �ɱ�?

	6. �Էµ����͸� �޾� �빮�ڸ� �������� �ʴ� �ܾ ���� ����ϰ�, ���̾� �ϳ� �̻��� �빮�ڸ� �����ϴ� �ܾ ����ϴ� ���α׷��� �ۼ��϶�

	7. ȸ���� ���������� ������ �������� ������ ���� �쿵�� ���� �ܾ��. �Է¹��� �ܾ���� ȸ���� ã�� ����ϴ� ���α׷��� �ۼ��϶�

	8. �ؽ�Ʈ ó���������� �ܾ ���(ascender) �� �𼾴�(descender)�� �ִ��� �ľ��ϸ� �����Ҷ��� �ִ�.
		����� �ҹ��� x�� �����϶� x���� �������� ���� �����̴�. ������� b,d,f,h,k,l,t �� ��� �����̴�.
		�𼾴� ���ڴ�  g j,p,q,y �� �𼾴� �����̴�. �Է¹��� �ܾ�� �� ö�ڰ� ��� �Ǵ� �𼾴����� �Ǻ��ϴ� ���α׷��� �ۼ��϶�.




*/