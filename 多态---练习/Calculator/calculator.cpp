#include<iostream>
using namespace std;
#include<string >

class calculator
{
public:
	int getresult(string oper)
	{
		if (oper == "+")
		{
			return m_num1 + m_num2;
		}
		else if (oper == "-")
		{
			return m_num1 - m_num2;
		}
		else if (oper == "*")
		{
			return m_num1 * m_num2;
		}
		
	}
	int m_num1;
	int m_num2;
};

void test01()
{
	calculator c;
	c.m_num1 = 10;
	c.m_num2 = 10;

	cout << c.m_num1 << " + " << c.m_num2 << " = " << c.getresult("+") << endl;
	cout << c.m_num1 << " - " << c.m_num2 << " = " << c.getresult("-") << endl;
	cout << c.m_num1 << " * " << c.m_num2 << " = " << c.getresult("*") << endl;

}

//利用多态实现计算器
class abstractcalculator
{
public:
	virtual int getresult() 
	{
		return 0;
	}

	int m_num1;
	int m_num2;
};
//加法
class addcalculator : public abstractcalculator
{
public:
	int getresult()
	{
		return m_num1 + m_num2;
	}
};

//减法
class minuscalculator :public abstractcalculator
{
public:
	int getresult()
	{
		return m_num1 - m_num2;

	}
};

//乘法
class multipycalculator :public abstractcalculator
{
public:
	int getresult()
	{
		return m_num1 * m_num2;

	}
};

void test02()
{
	abstractcalculator* abc = new addcalculator;//父类指针或者父类引用指向子类对象 
	abc->m_num1 = 10;
	abc->m_num2 = 10;
	cout << abc->m_num1 << " + " << abc->m_num2 << " = " << abc->getresult() << endl;
	delete abc;

	//减法
	abc = new minuscalculator;
	abc->m_num1 = 10;
	abc->m_num2 = 10;
	cout << abc->m_num1 << " - " << abc->m_num2 << " = " << abc->getresult() << endl;


}

int main()
{
	//test01();
	test02();
}