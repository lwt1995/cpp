#include "student.h"

//构造函数
Student::Student()
{

}
//有参构造
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd;

	ifstream ifs;
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
	ifs.close();
}
//菜单界面
void Student::operMenu()
{
	cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
	cout << "\t\t------------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         1.申请预约               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         2.查看我的预约           |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         3.查看所有预约           |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         4.取消预约               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|         0.注销登录               |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t------------------------------------\n";
	cout << "请选择您的操作：" << endl;
}
//申请预约
void Student::applyOrder()
{
	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	//日期
	int date = 0;
	//时间段
	int interval = 0;
	//机房编号
	int room = 0;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请输入申请预约时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (true)
	{

		cin >> interval;
		if (interval == 1 || interval == 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请选择机房：" << endl;
	for (size_t i = 0; i < this->vCr.size(); i++)
	{
		cout << this->vCr[i].m_ComId << "号机房容量为：" << this->vCr[i].m_MaxNum << endl;
	}

	while (true)
	{
		cin >> room;
		if (room == 1 || room == 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "预约成功！审核中" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system(p_read);
	system(c_clear);;
}

//打印记录
void showOrder(OrderFile& of, int i)
{
	cout << "预约日期：周" << of.m_orderData[i]["date"];
	cout << " 时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
	cout << " 机房号：" << of.m_orderData[i]["roomId"];

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
//查看我的预约
void Student::showMyOrder()
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
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			showOrder(of, i);
		}
	}

	system(p_read);
	system(c_clear);;
}

//查看所有预约
void Student::showAllOrder()
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
		showOrder(of, i);
	}

	system(p_read);
	system(c_clear);;
}
//取消预约
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system(p_read);
		system(c_clear);;
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;

	vector<int> v;
	int index = 1;

	for (size_t i = 0; i < of.m_Size; i++)
	{
		//先判断是否自身学号
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			//再帅选状态 审核中或预约成功
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期：周" << of.m_orderData[i]["date"];
				cout << " 时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房号：" << of.m_orderData[i]["roomId"];

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
		}
	}
	cout << "请输入取消的记录，0代表返回" << endl;
	int select;

	while (true)
	{
		cin >> select;
		if (select > 0 && select <= v.size())
		{
			of.m_orderData[v[select - 1]]["status"] = "0";
			of.updateOrder();
			cout << "已取消预约！" << endl;
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