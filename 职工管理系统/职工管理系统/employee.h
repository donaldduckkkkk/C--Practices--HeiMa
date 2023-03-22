#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class employee :public Worker
{
public:

	//构造函数
	employee(int id, string name, int did);

	//显示个人信息
	virtual void showInfo();//子类重写父类中的函数

	//获取岗位信息
	virtual string getDeptName();
};
