#include "employee.h"

//���캯��
employee::employee(int id, string name, int did)
{
	//��ʼ��
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//��ʾ������Ϣ
void employee::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ����ɾ�����������" << endl;
}

//��ȡ��λ��Ϣ
string employee::getDeptName()
{
	return string("Ա��");
}