#include <iostream>
using namespace std;
#include "identity.h"
#include <fstream>
#include "globalfile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

//进入学生子菜单界面
void studentMenu(Identity* & student)
{
	while (true)
	{
		//调用学生子菜单
		student->openMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if(select == 2)//查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有人的预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			//注销登录
			delete student;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//进入教师子菜单
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//调用子菜单界面
		teacher->openMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0; //接受用户选择

		cin >> select;

		if (select == 1) //查看所有预约
		{
			tea->showAllOrder();
		}
		else if (select == 2) //审核预约
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}



//进入管理员菜单子界面
void managerMenu(Identity*& manager)//用父类指针去接收他
{
	while (true)
	{
		//调用管理员子菜单
		manager->openMenu();

		//将父类指针转为子类指针，调用子类里其他接口
		Manager* man = (Manager*)manager;

		int select = 0;

		//接受用户选项
		cin >> select;
		if (select == 1)//添加账号
		{
			cout << "添加账号！" << endl;
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			cout << "查看账号！" << endl;
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			cout << "查看机房！" << endl;
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			cout << "清空预约！" << endl;
			man->clearRecord();
		}
		else
		{
			delete manager;//销毁堆区对象
			cout << "注销成功！" <<endl;
			system("pause");
			system("cls");

			return;
		}
	}
}

//登录功能 参数 操作文件名 操作身份类型
void LoginIn(string fileName, int type)
{
	//定义父类指针指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接受的用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入您的用户名：" << endl;
	cin >> name;
	cout << "请输入您的密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		int fID;
		string fName;
		string fPwd;
		while (ifs >> fID && ifs >> fName && ifs >> fPwd)
		{
			if (id == fID && name == fName && pwd == fPwd)
			{
				cout << "学生验证登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生的子菜单界面
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		//老师身份验证
		int fID;
		string fName;
		string fPwd;
		while (ifs >> fID && ifs >> fName && ifs >> fPwd)
		{
			if (id == fID && name == fName && pwd == fPwd)
			{
				cout << "教师验证登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师的子菜单界面
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员验证登陆成功！" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);
				//进入管理员的子菜单界面
				managerMenu(person);
				return;
			}
		}
	}
	cout << "登录验证失败" << endl;
	system("pause");
	system("cls");

}

int main()
{
	int select = 0; //用于接受用户的选择

	while (true)
	{
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select; //接受用户选择

		switch (select)
		{
		case 1://学生
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://老师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出
			cout << "欢迎下次使用！" << endl;
			system("pause");
			break;
		dafault:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	} 

}