#include<iostream>
using namespace std;
#include<string>

class abstractdrinking
{
public:
	virtual void boil() = 0;
	virtual void brew() = 0;
	virtual void pourincup() = 0;
	virtual void putsomething() = 0;

	void makedrink()
	{
		boil();
		brew();
		pourincup();
		putsomething();
	}
};

class coffee : public abstractdrinking
{
public:
	virtual void boil()
	{
		cout << "��ˮ" << endl;
	}
	virtual void brew()
	{
		cout << "���ݿ���" << endl;
	}
	virtual void pourincup()
	{
		cout << "���뱭��" << endl;
	}
	virtual void putsomething()
	{
		cout << "�����Ǻ�ţ��" << endl;
	}
};

class tea : public abstractdrinking
{
public:
	virtual void boil()
	{
		cout << "���Ȫˮ" << endl;
	}
	virtual void brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}
	virtual void pourincup()
	{
		cout << "���뱭��" << endl;
	}
	virtual void putsomething()
	{
		cout << "�������" << endl;
	}
};

void dowork(abstractdrinking * abs)
{
	abs->makedrink();
	delete abs;//�ֶ������ֶ��ͷ�
}

void test01()
{
	dowork(new coffee);
	cout << "------------" << endl;
	dowork(new tea);
}

int main()
{
	test01();
}