#include<iostream>
using namespace std;
#include "Identity.h"
#include<fstream>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

//����Ա�˵�
void managerMenu(Identity*& manager);
void studentMenu(Identity*& manager);
void teacherMenu(Identity*& teacher);
//��¼����
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û�����Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	int fId;
	string fName;
	string fPwd;
	if (type == 1)
	{
		//ѧ�������֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "ѧ����֤��½�ɹ���" << endl;
				system(p_read);
				system(c_clear);;
				person = new Student(id, name, pwd);
				//ѧ���Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "��ʦ��֤��½�ɹ���" << endl;
				system(p_read);
				system(c_clear);;
				person = new Teacher(id, name, pwd);
				//��ʦ�Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա��֤
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "����Ա��֤��½�ɹ���" << endl;
				system(p_read);
				system(c_clear);;
				person = new Manager(name, pwd);
				//����Ա�Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}

	cout << "��֤��½ʧ��!" << endl;
	system(p_read);
	system(c_clear);;
}

//����Ա�˵�
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();

		//������ָ�� תΪ����ָ�룬�����������������ӿ�
		Manager* man = (Manager*)manager;
		int select = 0;
		//�����û�ѡ��
		cin >> select;
		if (select == 1) //����˺�
		{
			man->addPerson();
		}
		else if (select == 2) //�鿴�˺�
		{
			man->showPerson();
		}
		else if (select == 3) //�鿴����
		{
			man->showComputer();
		}
		else if (select == 4) //���ԤԼ
		{
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ���" << endl;
			system(p_read);
			system(c_clear);;
			return;
		}
	}
}

//ѧ���˵�
void studentMenu(Identity*& student)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		student->operMenu();

		//������ָ�� תΪ����ָ�룬�����������������ӿ�
		Student* stu = (Student*)student;
		int select = 0;
		//�����û�ѡ��
		cin >> select;
		if (select == 1) //����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2) //�鿴�ҵ�ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3) //�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4) //ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else
		{
			delete stu;
			cout << "ע���ɹ���" << endl;
			system(p_read);
			system(c_clear);;
			return;
		}
	}
}

//ѧ���˵�
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		teacher->operMenu();

		//������ָ�� תΪ����ָ�룬�����������������ӿ�
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		//�����û�ѡ��
		cin >> select;
		if (select == 1) //�鿴����ԤԼ
		{
			tea->showAllOrder();
		}
		else if (select == 2) //���ԤԼ
		{
			tea->validOrder();
		}
		else                 //ע����¼
		{
			delete tea;
			cout << "ע���ɹ���" << endl;
			system(p_read);
			system(c_clear);;
			return;
		}
	}
}

int main()
{

	int select = 0;

	while (true)
	{
		cout << "========================��ӭ��������ԤԼϵͳ========================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t------------------------------\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|        1.ѧ������           |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|        2.��    ʦ           |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|        3.�� �� Ա           |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|        0.��    ��           |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t------------------------------\n";
		cout << "����������ѡ��";
		cin >> select;

		switch (select)
		{
		case 1:  //ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:  //��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:   //�˳�
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system(p_read);
			return 0;
			break;
		default:
			cout << "�����������������룡" << endl;
			system(p_read);
			system(c_clear);;
			break;
		}
	}

	system(p_read);
	return 0;

}