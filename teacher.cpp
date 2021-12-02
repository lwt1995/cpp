#include "teacher.h"

//���캯��
Teacher::Teacher()
{

}

//�вι���
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_empId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t------------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         1.�鿴����ԤԼ           |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         2.���ԤԼ               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         0.ע��ԤԼ               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t------------------------------------\n";
	cout << "��ѡ�����Ĳ�����" << endl;
}


//��ӡ��¼
void showOrder_print(OrderFile& of, int i)
{
	cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
	cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
	cout << " ѧ�ţ�" << of.m_orderData[i]["stuId"];
	cout << " ������" << of.m_orderData[i]["stuName"];
	cout << " ������" << of.m_orderData[i]["roomId"];

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
//�鿴����ԤԼ
void Teacher::showAllOrder()
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
		showOrder_print(of, i);
	}

	system(p_read);
	system(c_clear);
}

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system(p_read);
		system(c_clear);;
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;

	vector<int> v;
	int index = 1;

	for (size_t i = 0; i < of.m_Size; i++)
	{

		//��˧ѡ״̬ ��˳ɹ���ԤԼ�ɹ�
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << index++ << "��";
			showOrder_print(of, i);
		}
	}
	cout << "��������˵�ԤԼ��¼��0������" << endl;
	int select = 0;
	int ret = 0;

	while (true)
	{
		cin >> select;
		if (select > 0 && select <= v.size())
		{
			cout << "��������˽��" << endl;
			cout << "1��ͨ��" << endl;
			cout << "2����ͨ��" << endl;
			cin >> ret;
			if (ret == 1)
			{
				of.m_orderData[v[select - 1]]["status"] = "2";
			}
			else
			{
				of.m_orderData[v[select - 1]]["status"] = "-1";
			}
			of.updateOrder();
			cout << "�����ϣ�" << endl;
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