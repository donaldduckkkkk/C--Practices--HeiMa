#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class employee :public Worker
{
public:

	//���캯��
	employee(int id, string name, int did);

	//��ʾ������Ϣ
	virtual void showInfo();//������д�����еĺ���

	//��ȡ��λ��Ϣ
	virtual string getDeptName();
};
