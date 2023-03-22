#include "workermanager.h"

WorkerManager::WorkerManager()
{
	//����ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ����ڵ�û������
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��!" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

	//�ļ������ұ�������
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݴ洢��������
	this->init_Emp();
	
	//���Դ���
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id
	//		<< "������" << this->m_EmpArray[i]->m_Name
	//		<< "���ű�ţ�" << this->m_EmpArray[i]->m_DeptId << endl;
	//}


	////��ʼ������
	//this->m_EmpNum = 0;
	//this->m_EmpArray = NULL;
}

//չʾ�˵�
void WorkerManager::Show_Menu() 
{
	cout << "*******************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ��  ********" << endl;
	cout << "*************  0.�˳��������  ************" << endl;
	cout << "*************  1.����ְ����Ϣ  ************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  ************" << endl;
	cout << "*************  3.ɾ����ְְ�� *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  ************" << endl;
	cout << "*************  5.����ְ����Ϣ  ************" << endl;
	cout << "*************  6.���ձ������  ************" << endl;
	cout << "*************  7.��������ĵ�  ************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void WorkerManager::ExitSystem()
{
	cout << "��ӭ���´�ʹ�ã�" << endl;
	system("pause");
	exit(0);//�˳�����
}

void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//������ӵ��¿ռ��С
		int newsize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newspace = new Worker * [newsize];

		//��ԭ�ռ��������ص��¿ռ�
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}

		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int departselect;

			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;

			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> departselect;

			Worker* worker = NULL;
			switch (departselect)
			{
			case 1: //��ͨԱ��
				worker = new employee(id, name, 1);
				break;
			case 2: //����
				worker = new manager(id, name, 2);
				break;
			case 3:  //�ϰ�
				worker = new boss(id, name, 3);
				break;
			default:
				break;
			}

			//��������ְ��ָ�뱣�浽������
			newspace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ�ָ��
		this->m_EmpArray = newspace;

		//�����µ�ְ������
		this->m_EmpNum = newsize;

		//����ְ����Ϊ�յı�ʶ
		this->m_FileIsEmpty = false;

		cout << "�ɹ����" << addNum << "����ְ��" << endl;

		//�������ݵ��ļ���
		this->save();
	}
	else 
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

//�����ļ�
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

//ͳ���ļ��еĸ�����
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

//��ʼ��Ա��
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
		//���ݲ�ͬ�Ĳ���Id������ͬ����
		if (dId == 1)  // 1��ͨԱ��
		{
			worker = new employee(id, name, dId);
		}
		else if (dId == 2) //2����
		{
			worker = new manager(id, name, dId);
		}
		else //�ܲ�
		{
			worker = new boss(id, name, dId);
		}
		//�����������
		this->m_EmpArray[index] = worker;
		index++;
	}
}

//��ʾְ��
void WorkerManager::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
//�ж�ְ���Ƿ���ڣ����ڷ���ְ���������е�λ�ã������ڷ���-1
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

//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		//���ձ��ɾ��
		cout << "����������ɾ����ְ����ţ�" << endl;
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
			//ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << endl;
		}

		system("pause");
		system("cls");
	}
}

//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];

			int newid = 0;
			string newname;
			int newdid = 0;

			cout << "�鵽��" << id << "��ְ�����������µ�ְ���ţ�" << endl;
			cin >> newid;
			cout << "�������µ�������" << endl;
			cin >> newname;
			cout << "�������λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;

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

			//�������ݵ�������
			this->m_EmpArray[ret] = worker;

			cout << "�޸ĳɹ���" << endl;

			//���浽�ļ���
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1) //��ְ���Ų���
		{
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2) //����������
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			bool flag = false;  //���ҵ��ı�־
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ�,ְ�����Ϊ��"
						<< m_EmpArray[i]->m_Id
						<< " �ŵ���Ϣ���£�" << endl;

					flag = true;

					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				//���޴���
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}


	system("pause");
	system("cls");
}

//�����������
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;


		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1) //����
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else  //����
				{
					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			//һ��ʼ�϶�����Сֵ�����ֵ�ǲ��Ǽ������Сֵ�����ֵ��������ǣ���������
			if (i != minOrMax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}

		}

		cout << "����ɹ�,�������Ϊ��" << endl;
		this->save();
		this->Show_Emp();
	}

}

//����ļ�
void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

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
				//ɾ��������ÿ������
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			//ɾ������������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
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
				delete this->m_EmpArray[i];//Ԫ���ÿ�
			}
		}
		delete[] this->m_EmpArray;//�����ÿ�
		this->m_EmpArray = NULL;
	}

}
