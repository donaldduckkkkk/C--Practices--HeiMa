#include "boss.h"

//构造函数
boss::boss(int id, string name, int did)
{
	//初始化
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//显示个人信息
void boss::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：将任务下发给经理！" << endl;
}

//获取岗位信息
string boss::getDeptName()
{
	return string("老板");
}