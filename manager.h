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
	//���캯��
	Manager();

	//�вι���
	Manager(string name, string pwd);

	//��ʼ������
	void initVector();

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//��������
	vector<ComputerRoom> vCr;

	//�˵�����
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��Ϣ
	void cleanFile();

	//����ظ�
	bool checkRepeat(int id, int type);
};

