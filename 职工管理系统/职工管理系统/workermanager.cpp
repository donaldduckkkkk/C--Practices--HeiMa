#include "workermanager.h"

WorkerManager::WorkerManager()
{
	//如果文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在但没有内容
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空!" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

	//文件存在且保存数据
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据存储到数组中
	this->init_Emp();
	
	//测试代码
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "职工编号：" << this->m_EmpArray[i]->m_Id
	//		<< "姓名：" << this->m_EmpArray[i]->m_Name
	//		<< "部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
	//}


	////初始化属性
	//this->m_EmpNum = 0;
	//this->m_EmpArray = NULL;
}

//展示菜单
void WorkerManager::Show_Menu() 
{
	cout << "*******************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！  ********" << endl;
	cout << "*************  0.退出管理程序  ************" << endl;
	cout << "*************  1.增加职工信息  ************" << endl;
	cout << "*************  2.显示职工信息  ************" << endl;
	cout << "*************  3.删除离职职工 *************" << endl;
	cout << "*************  4.修改职工信息  ************" << endl;
	cout << "*************  5.查找职工信息  ************" << endl;
	cout << "*************  6.按照编号排序  ************" << endl;
	cout << "*************  7.清空所有文档  ************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;
}

//退出系统
void WorkerManager::ExitSystem()
{
	cout << "欢迎您下次使用！" << endl;
	system("pause");
	exit(0);//退出程序
}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工的数量" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//计算添加的新空间大小
		int newsize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker** newspace = new Worker * [newsize];

		//将原空间数据下载到新空间
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}

		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int departselect;

			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;

			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> departselect;

			Worker* worker = NULL;
			switch (departselect)
			{
			case 1: //普通员工
				worker = new employee(id, name, 1);
				break;
			case 2: //经理
				worker = new manager(id, name, 2);
				break;
			case 3:  //老板
				worker = new boss(id, name, 3);
				break;
			default:
				break;
			}

			//将创建的职工指针保存到数组中
			newspace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间指向
		this->m_EmpArray = newspace;

		//更新新的职工人数
		this->m_EmpNum = newsize;

		//更新职工不为空的标识
		this->m_FileIsEmpty = false;

		cout << "成功添加" << addNum << "名新职工" << endl;

		//保存数据到文件中
		this->save();
	}
	else 
	{
		cout << "输入有误！" << endl;
	}
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

//统计文件中的个人数
int	WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}

//初始化员工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		//根据不同的部门Id创建不同对象
		if (dId == 1)  // 1普通员工
		{
			worker = new employee(id, name, dId);
		}
		else if (dId == 2) //2经理
		{
			worker = new manager(id, name, dId);
		}
		else //总裁
		{
			worker = new boss(id, name, dId);
		}
		//存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
}

//显示职工
void WorkerManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
//判断职工是否存在，存在返回职工在数组中的位置，不存在返回-1
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		//按照编号删除
		cout << "请输入您想删除的职工编号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			//同步更新到文件中
			this->save();
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工！" << endl;
		}

		system("pause");
		system("cls");
	}
}

//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];

			int newid = 0;
			string newname;
			int newdid = 0;

			cout << "查到：" << id << "号职工，请输入新的职工号：" << endl;
			cin >> newid;
			cout << "请输入新的姓名：" << endl;
			cin >> newname;
			cout << "请输入岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;

			cin >> newdid;

			Worker* worker = NULL;
			switch (newdid)
			{
			case 1:
				worker = new employee(newid, newname, newdid);
			case 2:
				worker = new manager(newid, newname, newdid);
			case 3:
				worker = new boss(newid, newname, newdid);
			default:
				break;
			}

			//更新数据到数组中
			this->m_EmpArray[ret] = worker;

			cout << "修改成功！" << endl;

			//保存到文件中
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1) //按职工号查找
		{
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2) //按姓名查找
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			bool flag = false;  //查找到的标志
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功,职工编号为："
						<< m_EmpArray[i]->m_Id
						<< " 号的信息如下：" << endl;

					flag = true;

					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				//查无此人
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}


	system("pause");
	system("cls");
}

//按照序号排序
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;


		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1) //升序
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else  //降序
				{
					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			//一开始认定的最小值或最大值是不是计算的最小值或最大值，如果不是，交换数据
			if (i != minOrMax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}

		}

		cout << "排序成功,排序后结果为：" << endl;
		this->save();
		this->Show_Emp();
	}

}

//清空文件
void WorkerManager::Clean_File()
{
	cout << "确定清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				//删除堆区的每个对象
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			//删除堆区的数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];//元素置空
			}
		}
		delete[] this->m_EmpArray;//数组置空
		this->m_EmpArray = NULL;
	}

}
