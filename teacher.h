#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include<vector>
#include "orderFile.h"

class Teacher : public Identity
{
public:
	//���캯��
	Teacher();

	//�вι���
	Teacher(int empId, string name, string pwd);

	//ְ�����
	int m_empId;

	//�˵�����
	virtual void operMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();
};