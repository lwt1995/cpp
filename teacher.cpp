#include "teacher.h"

//构造函数
Teacher::Teacher()
{

}

//有参构造
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_empId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//菜单界面
void Teacher::operMenu()
{
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t------------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         1.查看所有预约           |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         2.审核预约               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         0.注销预约               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t------------------------------------\n";
	cout << "请选择您的操作：" << endl;
}


//打印记录
void showOrder_print(OrderFile& of, int i)
{
	cout << "预约日期：周" << of.m_orderData[i]["date"];
	cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
	cout << " 学号：" << of.m_orderData[i]["stuId"];
	cout << " 姓名：" << of.m_orderData[i]["stuName"];
	cout << " 机房：" << of.m_orderData[i]["roomId"];

	//1 审核中  2 已预约 -1 预约失败  0 预约已取消
	int status = atoi(of.m_orderData[i]["status"].c_str());
	switch (status)
	{
	case 1:
		cout << " 状态：审核中" << endl;
		break;
	case 2:
		cout << " 状态：已预约" << endl;
		break;
	case -1:
		cout << " 状态：预约失败" << endl;
		break;
	case 0:
		cout << " 状态：预约已取消" << endl;
		break;
	default:
		cout << " 状态：未知" << endl;
		break;
	}
}
//查看所有预约
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system(p_read);
		system(c_clear);;
		return;
	}

	for (size_t i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、";
		showOrder_print(of, i);
	}

	system(p_read);
	system(c_clear);
}

//审核预约
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system(p_read);
		system(c_clear);;
		return;
	}
	cout << "待审核的预约记录如下：" << endl;

	vector<int> v;
	int index = 1;

	for (size_t i = 0; i < of.m_Size; i++)
	{

		//再帅选状态 审核成功或预约成功
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << index++ << "、";
			showOrder_print(of, i);
		}
	}
	cout << "请输入审核的预约记录，0代表返回" << endl;
	int select = 0;
	int ret = 0;

	while (true)
	{
		cin >> select;
		if (select > 0 && select <= v.size())
		{
			cout << "请输入审核结果" << endl;
			cout << "1、通过" << endl;
			cout << "2、不通过" << endl;
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
			cout << "审核完毕！" << endl;
			break;
		}
		else if (select == 0)
		{
			break;
		}
		else
		{
			cout << "输入有误请重新输入：" << endl;
		}
	}
	system(p_read);
	system(c_clear);;

}