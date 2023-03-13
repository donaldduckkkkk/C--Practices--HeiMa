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
		cout << "煮水" << endl;
	}
	virtual void brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	virtual void pourincup()
	{
		cout << "倒入杯中" << endl;
	}
	virtual void putsomething()
	{
		cout << "加入糖和牛奶" << endl;
	}
};

class tea : public abstractdrinking
{
public:
	virtual void boil()
	{
		cout << "煮矿泉水" << endl;
	}
	virtual void brew()
	{
		cout << "冲泡茶叶" << endl;
	}
	virtual void pourincup()
	{
		cout << "倒入杯中" << endl;
	}
	virtual void putsomething()
	{
		cout << "加入枸杞" << endl;
	}
};

void dowork(abstractdrinking * abs)
{
	abs->makedrink();
	delete abs;//手动开辟手动释放
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