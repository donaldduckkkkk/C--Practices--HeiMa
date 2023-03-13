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

	//���������ͷ�����
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

//��������
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
		cout << "Intel��CPU��ʼ�����ˣ�" << endl;
	}
};

class IntelVideoCard : public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel���Կ���ʼ�����ˣ�" << endl;
	}
};

class IntelMemory : public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel���ڴ濪ʼ�����ˣ�" << endl;
	}
};

class LenovoCPU : public CPU
{
public:
	virtual void calculate()
	{
		cout << "�����CPU��ʼ�����ˣ�" << endl;
	}

};

class LenovoVideoCard : public VideoCard
{
public:
	virtual void display()
	{
		cout << "������Կ���ʼ�����ˣ�" << endl;
	}

};

class LenovolMemory : public Memory
{
public:
	virtual void storage()
	{
		cout << "������ڴ濪ʼ�����ˣ�" << endl;
	}

};

void test01()
{
	//��һ̨����---����ָ��ָ��������󣨶�̬��
	CPU * intercpu = new IntelCPU;
	VideoCard * intercard = new IntelVideoCard;
	Memory * intermemory = new IntelMemory;
	cout << "=====��ʼ������=====" << endl;

	//������һ̨����
	Computer* computer1 = new Computer(intercpu, intercard, intermemory);
	computer1->work();
	delete computer1;
}

int main()
{
	test01();
}