#include<iostream>
using namespace std;
#include "Identity.h"
#include<fstream>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

//管理员菜单
void managerMenu(Identity*& manager);
void studentMenu(Identity*& manager);
void teacherMenu(Identity*& teacher);
//登录功能
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接受用户的信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	int fId;
	string fName;
	string fPwd;
	if (type == 1)
	{
		//学生身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "学生验证登陆成功！" << endl;
				system(p_read);
				system(c_clear);;
				person = new Student(id, name, pwd);
				//学生子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//老师身份验证

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "教师验证登陆成功！" << endl;
				system(p_read);
				system(c_clear);;
				person = new Teacher(id, name, pwd);
				//教师子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员验证
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员验证登陆成功！" << endl;
				system(p_read);
				system(c_clear);;
				person = new Manager(name, pwd);
				//管理员子菜单
				managerMenu(person);
				return;
			}
		}
	}

	cout << "验证登陆失败!" << endl;
	system(p_read);
	system(c_clear);;
}

//管理员菜单
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();

		//将父类指针 转为子类指针，调用子类里面其他接口
		Manager* man = (Manager*)manager;
		int select = 0;
		//接受用户选项
		cin >> select;
		if (select == 1) //添加账号
		{
			man->addPerson();
		}
		else if (select == 2) //查看账号
		{
			man->showPerson();
		}
		else if (select == 3) //查看机房
		{
			man->showComputer();
		}
		else if (select == 4) //清空预约
		{
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功！" << endl;
			system(p_read);
			system(c_clear);;
			return;
		}
	}
}

//学生菜单
void studentMenu(Identity*& student)
{
	while (true)
	{
		//调用管理员子菜单
		student->operMenu();

		//将父类指针 转为子类指针，调用子类里面其他接口
		Student* stu = (Student*)student;
		int select = 0;
		//接受用户选项
		cin >> select;
		if (select == 1) //申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2) //查看我的预约
		{
			stu->showMyOrder();
		}
		else if (select == 3) //查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4) //取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			delete stu;
			cout << "注销成功！" << endl;
			system(p_read);
			system(c_clear);;
			return;
		}
	}
}

//学生菜单
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//调用管理员子菜单
		teacher->operMenu();

		//将父类指针 转为子类指针，调用子类里面其他接口
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		//接受用户选项
		cin >> select;
		if (select == 1) //查看所有预约
		{
			tea->showAllOrder();
		}
		else if (select == 2) //审核预约
		{
			tea->validOrder();
		}
		else                 //注销登录
		{
			delete tea;
			cout << "注销成功！" << endl;
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
		cout << "========================欢迎来到机房预约系统========================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t------------------------------\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|        1.学生代表           |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|        2.老    师           |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|        3.管 理 员           |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t|        0.退    出           |\n";
		cout << "\t\t|                             |\n";
		cout << "\t\t------------------------------\n";
		cout << "请输入您的选择：";
		cin >> select;

		switch (select)
		{
		case 1:  //学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:  //老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:   //退出
			cout << "欢迎下次使用！" << endl;
			system(p_read);
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			system(p_read);
			system(c_clear);;
			break;
		}
	}

	system(p_read);
	return 0;

}