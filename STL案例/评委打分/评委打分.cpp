#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>

/*
��5��ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί�е���ͷ֣�ȡƽ����
*/

class Person
{
public:
	Person(string name, int score)
	{
		this->m_name = name;
		this->m_avgscore = score;
	}
	string m_name;//����
	int m_avgscore;//ƽ����
};

void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		int score = 0;
		Person p(name,score);
		v.push_back(p);
	}
}

void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		cout << "ѡ�֣� " << it->m_name << "���Ϊ��" << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit <<" ";
		}
		cout<<endl;

		//����
		sort(d.begin(), d.end());

		//ȥ����߷ֺ���ͷ�
		d.pop_back();
		d.pop_front();

		//ȡƽ����
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();

		//��ƽ���ָ���ѡ��
		it->m_avgscore = avg;
	}
}

void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������ " << it->m_name << "����Ϊ�� " << it->m_avgscore << endl;
	}
}

int main()
{
	//���������
	srand((unsigned int)time(NULL));

	 //1.����5��ѡ��
	vector<Person>v;
	createPerson(v);
	////����
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "������ " << (*it).m_name << "������ " << (*it).m_avgscore << endl;
	//}
	
	 //2.��5��ѡ�ִ��
	setScore(v);

	 //3.��ʾ���÷�
	showScore(v);


	system("pause");

}