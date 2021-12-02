#include "orderFile.h"

//��������
void subStr(string str, map<string, string>& m);
//���캯��
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;  //����
	string interval; //ʱ���
	string stuId;   //ѧ�����
	string stuName;  //����
	string roomId;   //�������
	string status;   //ԤԼ״̬

	this->m_Size = 0;
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		map<string, string> m;

		//��ȡʱ��
		subStr(date, m);
		//��ȡʱ�ζ�
		subStr(interval, m);
		//��ȡѧ��
		subStr(stuId, m);
		//��ȡ����
		subStr(stuName, m);
		//��ȡ����id
		subStr(roomId, m);
		//��ȡ״̬
		subStr(status, m);

		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;

	}
	ifs.close();

}

//��ȡ�ַ���
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

//����ԤԼ��¼
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
