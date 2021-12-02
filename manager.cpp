#include "manager.h"

//构造函数
Manager::Manager()
{}

//有参构造
Manager::Manager(string name, string pwd)
{
	this->initVector();
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//菜单界面
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t------------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         1.添加账号               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         2.查看账号               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         3.查看机房               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         4.清空预约               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         0.注销登录               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t------------------------------------\n";
	cout << "请选择您的操作：" << endl;
}
//初始化容器
void Manager::initVector()
{
	//初始化容器
	this->vStu.clear();
	this->vTea.clear();
	this->vTea.clear();
	//读取信息  学生
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件读取失败！" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		this->vStu.push_back(s);
	}
	//cout << "当前学生数量为：" << this->vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败！" << endl;
		return;
	}

	//读取信息  老师
	Teacher t;
	while (ifs >> t.m_empId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		this->vTea.push_back(t);
	}
	//cout << "当前教师数量为：" << this->vTea.size() << endl;
	ifs.close();

	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败！" << endl;
		return;
	}

	//读取信息  机房
	ComputerRoom cp;
	while (ifs >> cp.m_ComId && ifs >> cp.m_MaxNum)
	{
		this->vCr.push_back(cp);
	}
	//cout << "当前机房数量为：" << this->vCr.size() << endl;
	ifs.close();
}

//添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	string fileName;
	string tip;
	string errorTip;

	ofstream ofs;
	int select;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入：";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工号重复，请重新输入：";
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
		if (ret) //重复
		{
			cout << errorTip << endl;
		}
		else {
			break;
		}
	}
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功！" << endl;

	//刷新容器
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

//检测重复
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1) //检测学生重复
	{
		for (vector<Student>::iterator it = this->vStu.begin(); it != vStu.end(); it++)
		{
			if (it->m_Id == id)
			{
				return true;
			}
		}
	}
	else           //检测教师重复
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
	cout << "学号：" << stu.m_Id << " 姓名：" << stu.m_Name << endl;
}

void printTeacher(Teacher& tea)
{
	cout << "职工号：" << tea.m_empId << " 姓名：" << tea.m_Name << endl;
}
//查看账号
void Manager::showPerson()
{
	cout << "请选择查看的内容：" << endl;
	cout << "1、查看所有的学生" << endl;
	cout << "2、查看所有的老师" << endl;

	int select;
	cin >> select;
	if (select == 1)
	{
		//查看所有的学生信息
		cout << "所有学生的信息:" << endl;
		for_each(this->vStu.begin(), this->vStu.end(), printStudent);

	}
	else
	{
		//查看所有的学生信息
		cout << "所有老师的信息:" << endl;
		for_each(this->vTea.begin(), this->vTea.end(), printTeacher);
	}

	system(p_read);
	system(c_clear);;
}
//查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = this->vCr.begin(); it != vCr.end(); it++)
	{
		cout << "机房编号：" << it->m_ComId << " 机房最大容量：" << it->m_MaxNum << endl;
	}
	system(p_read);
	system(c_clear);;

}
//清空预约信息
void Manager::cleanFile()
{
	cout << "确认是否清除预约信息: " << endl;
	cout << "1、确认 " << endl;
	cout << "2、取消 " << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(COMPUTER_FILE, ios::trunc);
		ofs.close();

		cout << "清空成功！" << endl;
	}

	system(p_read);
	system(c_clear);;
}