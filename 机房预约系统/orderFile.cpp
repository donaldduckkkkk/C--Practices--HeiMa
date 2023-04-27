#include "orderFile.h"

//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	
	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;

	this->m_size =0;

	while (ifs >> date && ifs >> interval && ifs >> stuId &&
		ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		//cout << date << endl;
		//cout << interval << endl;
		//cout << stuId << endl;
		//cout << stuName << endl;
		//cout << roomId << endl;
		//cout << status << endl;
		//cout << endl;

		string key;
		string value;
		map<string, string>m;

		//截取日期
		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		//截取时间间隔
		pos = interval.find(":"); // 4
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);  // size = 10  pos = 4  size - pos  - 1 = 6 - 1
			m.insert(make_pair(key, value));
		}

		//截取学号
		pos = stuId.find(":"); // 4
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);  // size = 10  pos = 4  size - pos  - 1 = 6 - 1
			m.insert(make_pair(key, value));
		}
		//截取姓名
		pos = stuName.find(":"); // 4
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);  // size = 10  pos = 4  size - pos  - 1 = 6 - 1
			m.insert(make_pair(key, value));
		}
		//截取机房号
		pos = roomId.find(":"); // 4
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);  // size = 10  pos = 4  size - pos  - 1 = 6 - 1
			m.insert(make_pair(key, value));
		}
		//截取预约状态
		pos = status.find(":"); // 4
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);  // size = 10  pos = 4  size - pos  - 1 = 6 - 1
			m.insert(make_pair(key, value));
		}

		this->m_orderData.insert(make_pair(this->m_size, m));
		this->m_size++;
	}

	ifs.close();
}

//更新预约记录
void OrderFile::updateOrder()
{
	if (this->m_size == 0)
	{
		return;
	}

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}

	ofs.close();
}