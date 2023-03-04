#include <iostream>
#include<string>
using namespace std;
#define max 1000



void showmenu()
{
	cout << "1.�����ϵ��" << endl;
	cout << "2.��ʾ��ϵ��" << endl;
	cout << "3.ɾ����ϵ��" << endl;
	cout << "4.������ϵ��" << endl;
	cout << "5.�޸���ϵ��" << endl;
	cout << "6.���ͨѶ¼" << endl;
	cout << "0.�˳�ͨѶ¼" << endl;
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
	struct Person personarray[max];//person�ṹ�������Ϊaddressbook�ṹ��ĳ�Ա���������������ʽ�洢
	int m_size;
};

//�����ϵ��
void addperson(addressbook* abs)
{
	if (abs->m_size == max)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//�����ϵ��

		//�������
		string name;
		cout << "input your name:" << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;

		//����Ա�
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
		//����ͨ��¼����
		abs->m_size++;
		cout << "��ӳɹ�"<< endl;
		//system("cls");
	}
}

//��ʾ��ϵ��
void showperson(addressbook * abs)
{
	if (abs->m_size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->personarray[i].m_name << "\t";
			cout << "�Ա�" << (abs->personarray[i].m_sex == 1?"��":"Ů") << endl;
		}
	}
	system("pause");//�����������
	system("cls");//����
}

//�����ϵ���Ƿ���ڣ�������ڷ��ؾ���λ�ã���֮����-1
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

//ɾ����ϵ��
void deleteperson(addressbook * abs)
{
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;

	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;//����ͨѶ¼�е�����
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}

//������ϵ��
void findperson(addressbook * abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personarray[ret].m_name << endl;
		cout << "�Ա�" << abs->personarray[ret].m_sex << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");//�������
	system("cls");//����
}

//�޸�ָ����ϵ��
void modifyperson(addressbook* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personarray[ret].m_name = name;

		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[ret].m_sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}
	}
	system("pause");
	system("cls");
}


//�����ϵ��
void cleanperson(addressbook* abs)
{
	abs->m_size = 0;
	cout << "ͨѶ¼�Ѿ���գ�" << endl;
	system("pause");
	system("cls");
}



int main()
{
	//����һ���ṹ�����
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
			//cout << "��������ϵ�˵�������" << endl;
			//string name;
			//cin >> name;
			//if (isexist(&abs, name) == -1)
			//{
			//	cout << "���޴���" << endl;
			//}
			//else
			//{
			//	cout << "�ҵ�����" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
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