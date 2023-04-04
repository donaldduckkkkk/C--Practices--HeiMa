#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>

/*
有5名选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中的最低分，取平均分
*/

class Person
{
public:
	Person(string name, int score)
	{
		this->m_name = name;
		this->m_avgscore = score;
	}
	string m_name;//姓名
	int m_avgscore;//平均分
};

void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
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
		cout << "选手： " << it->m_name << "打分为：" << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit <<" ";
		}
		cout<<endl;

		//排序
		sort(d.begin(), d.end());

		//去除最高分和最低分
		d.pop_back();
		d.pop_front();

		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();

		//将平均分赋给选手
		it->m_avgscore = avg;
	}
}

void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名： " << it->m_name << "分数为： " << it->m_avgscore << endl;
	}
}

int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));

	 //1.创建5名选手
	vector<Person>v;
	createPerson(v);
	////测试
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "姓名： " << (*it).m_name << "分数： " << (*it).m_avgscore << endl;
	//}
	
	 //2.给5名选手打分
	setScore(v);

	 //3.显示最后得分
	showScore(v);


	system("pause");

}