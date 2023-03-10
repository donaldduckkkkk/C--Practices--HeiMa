#include <iostream>
#include<string>
using namespace std;
#define max 1000



void showmenu()
{
	cout << "1.添加联系人" << endl;
	cout << "2.显示联系人" << endl;
	cout << "3.删除联系人" << endl;
	cout << "4.查找联系人" << endl;
	cout << "5.修改联系人" << endl;
	cout << "6.清空通讯录" << endl;
	cout << "0.退出通讯录" << endl;
}

struct Person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_add;
};

struct addressbook
{
	struct Person personarray[max];//person结构体变量作为addressbook结构体的成员，并且以数组的形式存储
	int m_size;
};

//添加联系人
void addperson(addressbook* abs)
{
	if (abs->m_size == max)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加联系人

		//添加姓名
		string name;
		cout << "input your name:" << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;

		//添加性别
		cout << "input your sex:" << endl;
		cout << "1--male" << endl;
		cout << "2--female" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "error,reinput!" << endl;
		}
		//更新通信录人数
		abs->m_size++;
		cout << "添加成功"<< endl;
		//system("cls");
	}
}

//显示联系人
void showperson(addressbook * abs)
{
	if (abs->m_size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->personarray[i].m_name << "\t";
			cout << "性别：" << (abs->personarray[i].m_sex == 1?"男":"女") << endl;
		}
	}
	system("pause");//按任意键继续
	system("cls");//清屏
}

//检测联系人是否存在，如果存在返回具体位置，反之返回-1
int isexist(addressbook * abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personarray[i].m_name == name)
		{
			return i;
		}
		else
		{
			return -1;
		}
	}
}

//删除联系人
void deleteperson(addressbook * abs)
{
	cout << "请输入您要删除的联系人：" << endl;

	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;//更新通讯录中的人数
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void findperson(addressbook * abs)
{
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personarray[ret].m_name << endl;
		cout << "性别：" << abs->personarray[ret].m_sex << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");//按任意键
	system("cls");//清屏
}

//修改指定联系人
void modifyperson(addressbook* abs)
{
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarray[ret].m_name = name;

		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[ret].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
	}
	system("pause");
	system("cls");
}


//清空联系人
void cleanperson(addressbook* abs)
{
	abs->m_size = 0;
	cout << "通讯录已经清空！" << endl;
	system("pause");
	system("cls");
}



int main()
{
	//创建一个结构体变量
	addressbook abs;
	abs.m_size = 0;
	int select = 0;
	while (true)
	{
		showmenu();

		cin >> select;
		switch (select)
		{
		case 1:
			addperson(&abs);
			break;
		case 2:
			showperson(&abs);
			break;
		case 3:
		{
			//cout << "请输入联系人的姓名：" << endl;
			//string name;
			//cin >> name;
			//if (isexist(&abs, name) == -1)
			//{
			//	cout << "查无此人" << endl;
			//}
			//else
			//{
			//	cout << "找到此人" << endl;
			//}
			deleteperson(&abs);
		}
			break;
		case 4:
			findperson(&abs);
			break;
		case 5:
			modifyperson(&abs);
			break;
		case 6:
			cleanperson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}