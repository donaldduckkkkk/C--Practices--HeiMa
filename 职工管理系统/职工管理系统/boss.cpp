#include "boss.h"

//���캯��
boss::boss(int id, string name, int did)
{
	//��ʼ��
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//��ʾ������Ϣ
void boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ�𣺽������·�������" << endl;
}

//��ȡ��λ��Ϣ
string boss::getDeptName()
{
	return string("�ϰ�");
}