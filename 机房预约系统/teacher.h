#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include <string>
#include "globalfile.h"
#include "orderFile.h"
#include <vector>

class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(int emPid, string name, string pwd);


	//�˵�����
	virtual void openMenu();

	//�鿴�����˵�ԤԼ
	void showAllOrder(); 

	//���ԤԼ
	void validOrder();
	
	//ְ����
	int m_EmpId;

};