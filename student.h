#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include<fstream>
#include "globalFile.h"
#include "computerRoom.h"
#include<vector>
#include "orderFile.h"

class Student : public Identity
{
public:
	//���캯��
	Student();
	//�вι���
	Student(int id, string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴�ҵ�ԤԼ
	void showMyOrder();
	//�鿴����ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void cancelOrder();
	//ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom> vCr;
};