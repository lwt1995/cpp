#include "orderFile.h"

//声明方法
void subStr(string str, map<string, string>& m);
//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;  //日期
	string interval; //时间段
	string stuId;   //学生编号
	string stuName;  //姓名
	string roomId;   //机房编号
	string status;   //预约状态

	this->m_Size = 0;
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		map<string, string> m;

		//截取时间
		subStr(date, m);
		//截取时段段
		subStr(interval, m);
		//截取学号
		subStr(stuId, m);
		//截取姓名
		subStr(stuName, m);
		//截取机房id
		subStr(roomId, m);
		//截取状态
		subStr(status, m);

		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;

	}
	ifs.close();

}

//截取字符串
void subStr(string str, map<string, string>& m)
{
	int pos = str.find(":");
	if (pos != -1)
	{
		string key = str.substr(0, pos);
		string value = str.substr(pos + 1);
		//cout << "key:" << key << " value:" << value << endl;
		m.insert(make_pair(key, value));
	}
}

//更新预约记录
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);

	for (size_t i = 0; i < this->m_Size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;;
	}
	ofs.close();
}
