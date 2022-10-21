#include"teacher.h"



//默认构造
Teacher::Teacher()
{

}
//有参构造
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}
//菜单界面
void Teacher::operMenu()
{
	cout << "*******************欢迎老师" << this->m_Name << "登录！***********************" << endl;
	cout << "\t\t-----------------------------------------------\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                1.查看所有预约                |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                2.审核预约                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                0.注销登录                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t-----------------------------------------------\n";
	cout << "输入您的选择： ";
}
//查看所有预约
void Teacher::showAllOrder()
{
	Student().showAllOrder();
}
//审核预约
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约记录如下" << endl;

	int index = 1;
	vector<int> v;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << index++ << "、";
			cout << "预约时间：周" << of.m_orderData[i]["date"];
			cout << "    时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "    机房号：" << of.m_orderData[i]["roomId"];
			cout << "    预约人姓名：" << of.m_orderData[i]["stuName"];
			cout << "    预约人学号：" << of.m_orderData[i]["stuId"] << endl;
		}
	}

	
	while (true)
	{
		cout << "请输入要审核的记录，0返回" << endl;
		int select = 0;
		int ret = 0;
		cin >> select;
		if (select == 0)
		{
			system("cls");
			return;
		}
		else if (select >0 && select <= v.size())
		{
			cout << "请输入审核结果,1.通过  2.不通过" << endl;
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
			cout << "审核完毕" << endl;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
}