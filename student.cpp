#include "student.h"

//���캯��
Student::Student()
{

}
//�вι���
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}

	//��ȡ��Ϣ  ����
	ComputerRoom cp;
	while (ifs >> cp.m_ComId && ifs >> cp.m_MaxNum)
	{
		this->vCr.push_back(cp);
	}
	ifs.close();
}
//�˵�����
void Student::operMenu()
{
	cout << "��ӭѧ������" << this->m_Name << "��¼��" << endl;
	cout << "\t\t------------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         1.����ԤԼ               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         2.�鿴�ҵ�ԤԼ           |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         3.�鿴����ԤԼ           |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         4.ȡ��ԤԼ               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         0.ע����¼               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t------------------------------------\n";
	cout << "��ѡ�����Ĳ�����" << endl;
}
//����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

	//����
	int date = 0;
	//ʱ���
	int interval = 0;
	//�������
	int room = 0;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "����������ԤԼʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true)
	{

		cin >> interval;
		if (interval == 1 || interval == 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "��ѡ�������" << endl;
	for (size_t i = 0; i < this->vCr.size(); i++)
	{
		cout << this->vCr[i].m_ComId << "�Ż�������Ϊ��" << this->vCr[i].m_MaxNum << endl;
	}

	while (true)
	{
		cin >> room;
		if (room == 1 || room == 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ��������" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system(p_read);
	system(c_clear);;
}

//��ӡ��¼
void showOrder(OrderFile& of, int i)
{
	cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
	cout << " ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
	cout << " �����ţ�" << of.m_orderData[i]["roomId"];

	//1 �����  2 ��ԤԼ -1 ԤԼʧ��  0 ԤԼ��ȡ��
	int status = atoi(of.m_orderData[i]["status"].c_str());
	switch (status)
	{
	case 1:
		cout << " ״̬�������" << endl;
		break;
	case 2:
		cout << " ״̬����ԤԼ" << endl;
		break;
	case -1:
		cout << " ״̬��ԤԼʧ��" << endl;
		break;
	case 0:
		cout << " ״̬��ԤԼ��ȡ��" << endl;
		break;
	default:
		cout << " ״̬��δ֪" << endl;
		break;
	}
}
//�鿴�ҵ�ԤԼ
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system(p_read);
		system(c_clear);;
		return;
	}

	for (size_t i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			showOrder(of, i);
		}
	}

	system(p_read);
	system(c_clear);;
}

//�鿴����ԤԼ
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system(p_read);
		system(c_clear);;
		return;
	}

	for (size_t i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "��";
		showOrder(of, i);
	}

	system(p_read);
	system(c_clear);;
}
//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system(p_read);
		system(c_clear);;
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int> v;
	int index = 1;

	for (size_t i = 0; i < of.m_Size; i++)
	{
		//���ж��Ƿ�����ѧ��
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			//��˧ѡ״̬ ����л�ԤԼ�ɹ�
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
				cout << " ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << " �����ţ�" << of.m_orderData[i]["roomId"];

				//1 �����  2 ��ԤԼ -1 ԤԼʧ��  0 ԤԼ��ȡ��
				int status = atoi(of.m_orderData[i]["status"].c_str());
				switch (status)
				{
				case 1:
					cout << " ״̬�������" << endl;
					break;
				case 2:
					cout << " ״̬����ԤԼ" << endl;
					break;
				case -1:
					cout << " ״̬��ԤԼʧ��" << endl;
					break;
				case 0:
					cout << " ״̬��ԤԼ��ȡ��" << endl;
					break;
				default:
					cout << " ״̬��δ֪" << endl;
					break;
				}
			}
		}
	}
	cout << "������ȡ���ļ�¼��0������" << endl;
	int select;

	while (true)
	{
		cin >> select;
		if (select > 0 && select <= v.size())
		{
			of.m_orderData[v[select - 1]]["status"] = "0";
			of.updateOrder();
			cout << "��ȡ��ԤԼ��" << endl;
			break;
		}
		else if (select == 0)
		{
			break;
		}
		else
		{
			cout << "�����������������룺" << endl;
		}
	}

	system(p_read);
	system(c_clear);;
}