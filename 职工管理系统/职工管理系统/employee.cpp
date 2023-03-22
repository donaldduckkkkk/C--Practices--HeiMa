#include "employee.h"

//构造函数
employee::employee(int id, string name, int did)
{
	//初始化
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//显示个人信息
void employee::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成经理交代的任务！" << endl;
}

//获取岗位信息
string employee::getDeptName()
{
	return string("员工");
}