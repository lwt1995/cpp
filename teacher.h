#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include<vector>
#include "orderFile.h"

class Teacher : public Identity
{
public:
	//构造函数
	Teacher();

	//有参构造
	Teacher(int empId, string name, string pwd);

	//职工编号
	int m_empId;

	//菜单界面
	virtual void operMenu();
	//查看所有预约
	void showAllOrder();
	//审核预约
	void validOrder();
};