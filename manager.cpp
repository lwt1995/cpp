#include "manager.h"

//���캯��
Manager::Manager()
{}

//�вι���
Manager::Manager(string name, string pwd)
{
	this->initVector();
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t------------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         1.����˺�               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         2.�鿴�˺�               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         3.�鿴����               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         4.���ԤԼ               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         0.ע����¼               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t------------------------------------\n";
	cout << "��ѡ�����Ĳ�����" << endl;
}
//��ʼ������
void Manager::initVector()
{
	//��ʼ������
	this->vStu.clear();
	this->vTea.clear();
	this->vTea.clear();
	//��ȡ��Ϣ  ѧ��
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		this->vStu.push_back(s);
	}
	//cout << "��ǰѧ������Ϊ��" << this->vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}

	//��ȡ��Ϣ  ��ʦ
	Teacher t;
	while (ifs >> t.m_empId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		this->vTea.push_back(t);
	}
	//cout << "��ǰ��ʦ����Ϊ��" << this->vTea.size() << endl;
	ifs.close();

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
	//cout << "��ǰ��������Ϊ��" << this->vCr.size() << endl;
	ifs.close();
}

//����˺�
void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string fileName;
	string tip;
	string errorTip;

	ofstream ofs;
	int select;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ������������룺";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ������������룺";
	}
	ofs.open(fileName, ios::out | ios::app);

	int id = 0;
	string name;
	string pwd;

	cout << tip << endl;

	while (true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret) //�ظ�
		{
			cout << errorTip << endl;
		}
		else {
			break;
		}
	}
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ���" << endl;

	//ˢ������
	if (select == 1)
	{
		Student s(id, name, pwd);
		this->vStu.push_back(s);
	}
	else
	{
		Teacher t(id, name, pwd);
		this->vTea.push_back(t);
	}

	system(p_read);
	system(c_clear);;

	ofs.close();

}

//����ظ�
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1) //���ѧ���ظ�
	{
		for (vector<Student>::iterator it = this->vStu.begin(); it != vStu.end(); it++)
		{
			if (it->m_Id == id)
			{
				return true;
			}
		}
	}
	else           //����ʦ�ظ�
	{
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != vTea.end(); it++)
		{
			if (it->m_empId == id)
			{
				return true;
			}
		}
	}
	return false;
}

void printStudent(Student& stu)
{
	cout << "ѧ�ţ�" << stu.m_Id << " ������" << stu.m_Name << endl;
}

void printTeacher(Teacher& tea)
{
	cout << "ְ���ţ�" << tea.m_empId << " ������" << tea.m_Name << endl;
}
//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴�����ݣ�" << endl;
	cout << "1���鿴���е�ѧ��" << endl;
	cout << "2���鿴���е���ʦ" << endl;

	int select;
	cin >> select;
	if (select == 1)
	{
		//�鿴���е�ѧ����Ϣ
		cout << "����ѧ������Ϣ:" << endl;
		for_each(this->vStu.begin(), this->vStu.end(), printStudent);

	}
	else
	{
		//�鿴���е�ѧ����Ϣ
		cout << "������ʦ����Ϣ:" << endl;
		for_each(this->vTea.begin(), this->vTea.end(), printTeacher);
	}

	system(p_read);
	system(c_clear);;
}
//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = this->vCr.begin(); it != vCr.end(); it++)
	{
		cout << "������ţ�" << it->m_ComId << " �������������" << it->m_MaxNum << endl;
	}
	system(p_read);
	system(c_clear);;

}
//���ԤԼ��Ϣ
void Manager::cleanFile()
{
	cout << "ȷ���Ƿ����ԤԼ��Ϣ: " << endl;
	cout << "1��ȷ�� " << endl;
	cout << "2��ȡ�� " << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(COMPUTER_FILE, ios::trunc);
		ofs.close();

		cout << "��ճɹ���" << endl;
	}

	system(p_read);
	system(c_clear);;
}