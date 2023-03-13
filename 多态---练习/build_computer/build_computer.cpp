#include<iostream>
using namespace std;
#include <string>

class CPU
{
public:
	virtual void calculate() = 0;
};

class VideoCard
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	void work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

	//析构函数释放条件
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}

		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}

		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}

//定义属性
private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};

class IntelCPU : public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel的CPU开始工作了！" << endl;
	}
};

class IntelVideoCard : public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel的显卡开始工作了！" << endl;
	}
};

class IntelMemory : public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel的内存开始工作了！" << endl;
	}
};

class LenovoCPU : public CPU
{
public:
	virtual void calculate()
	{
		cout << "联想的CPU开始工作了！" << endl;
	}

};

class LenovoVideoCard : public VideoCard
{
public:
	virtual void display()
	{
		cout << "联想的显卡开始工作了！" << endl;
	}

};

class LenovolMemory : public Memory
{
public:
	virtual void storage()
	{
		cout << "联想的内存开始工作了！" << endl;
	}

};

void test01()
{
	//第一台电脑---父类指针指向子类对象（多态）
	CPU * intercpu = new IntelCPU;
	VideoCard * intercard = new IntelVideoCard;
	Memory * intermemory = new IntelMemory;
	cout << "=====开始工作！=====" << endl;

	//创建第一台电脑
	Computer* computer1 = new Computer(intercpu, intercard, intermemory);
	computer1->work();
	delete computer1;
}

int main()
{
	test01();
}