#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include<fstream>
#include "globalFile.h"
#include<vector>
#include "student.h"
#include "teacher.h"
#include<algorithm>
#include "computerRoom.h"

class Manager : public Identity
{
public:
	//构造函数
	Manager();

	//有参构造
	Manager(string name, string pwd);

	//初始化容器
	void initVector();

	//学生容器
	vector<Student> vStu;

	//教师容器
	vector<Teacher> vTea;

	//机房容量
	vector<ComputerRoom> vCr;

	//菜单界面
	virtual void operMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约信息
	void cleanFile();

	//检测重复
	bool checkRepeat(int id, int type);
};

