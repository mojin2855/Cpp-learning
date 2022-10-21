//项目需求：设计一个机房预约系统
//
//分别有三种身份使用该程序
//学生代表 : 申请使用机房。
//教师:审核学生的预约申请。
//管理员:给学生、教师创建账号。
//
//机房简介
//机房总共有3间
//1号机房-- - 最大容量20人。
//2号机房-- - 最多容是50人
//3号机房-- - 最多容量100人
//
//申请简介
//申请的订单每周由管理员负责清空。
//学生可以预约未来一周内的机房使用，预约的日期为周一至周五，预约时需要选择预约时段(上午、下午)
//教师来审核预约，依据实际情况审核预约通过或者不通过
//
//系统具体需求
//·首先进入登录界面，可选登录身份有 :
//学生代表
//老师。
//管理员。
//退出。
//·每个身份都需要进行验证后，进入子菜单
//学生需要输入 : 学号、姓名、登录密码。
//老师需要输入:职工号、姓名、登录密码。
//管理员需要输入:管理员姓名、登录密码。
//·学生具体功能
//申请预约-- - 预约机房。
//查看自身的预约-- - 查看自己的预约状态。
//查看所有预约-- - 查看全部预约信息以及预约状态。
//取消预约-- - 取消自身的预约，预约成功或审核中的预约均可取消。
//注销登录-- - 退出登录。
//·教师具体功能
//查看所有预约--查看全部预约信息以及预约状态。
//审核预约-- - 对学生的预约进行审核。
//注销登录-- - 退出登录。
//·管理员具体功能
//添加账号―--添加学生或教师的账号，需要检测学生编号或教师职工号是否重复。
//查看账号-- - 可以选择查看学生或教师的全部信息。
//查看机房-- - 查看所有机房的信息。
//清空预约-- - 清空所有预约记录。
// *删除账号-- -删除学生或老师的账号。（后期增加的功能）
//注销登录-- - 退出登录。


#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include"manager.h"
#include"student.h"
#include"teacher.h"

void startMenu()
{
	cout << "*****************************欢迎使用机房预约系统************************" << endl;
	cout << endl << "请输入您的身份" << endl;
	cout << "\t\t-----------------------------------------------\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                1.学生代表                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                2.老    师                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                3.管 理 员                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                0.退    出                    |\n";
	cout << "\t\t-----------------------------------------------\n";
	cout << "输入您的选择： ";
}

//进入管理员子菜单界面
void managerMenu(Identity * &manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();
		//将父类指针转为子类指针，调用子类方法
		Manager* man = (Manager*)manager;

		int  select;
		cin >> select;
		if (select == 1)//添加账号
		{
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			man->showPerson();
		}
		else if (select == 3)//查看机房信息
		{
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			man->cleanFile();
		}
		else if (select == 5)//删除账号
		{
			man->delPerson();
		}
		else//注销登录
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//进入学生子菜单界面
void studentMenu(Identity*&student)
{
	while (true)
	{
		//调用学生子菜单
		student->operMenu();
		Student* stu = (Student*)student;

		int  select;
		cin >> select;
		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)//查看我的预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancelOrder();
		}
		else//注销登录
		{
			delete stu;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入老师子菜单界面
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();
		Teacher *tea= (Teacher*)teacher;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//审核预约
			tea->validOrder();
		}
		else
		{
			//注销登录
			delete tea;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录功能 参数：操作文件名 操作身份类型
void LoginIn(string fileName, int type)
{
	//父类指针，用于指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//接受用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)
	{
		//学生
		cout << "请输入您的学号" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		//老师
		cout << "请输入您的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;
	int fId;//从文件中读取的id号
	string fName;//从文件中获取的名字
	string fPwd;//从文件中获取的密码
	if (type == 1)
	{
		 //学生身份验证，与文件信息比较
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				ifs.close();
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//职工身份验证，与文件信息比较
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				ifs.close();
				cout << "职工验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证，与文件信息比较
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				ifs.close();
				cout << "管理员验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manager( name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登录失败" << endl;
	ifs.close();
	system("pause");
	system("cls");
	return;
}



int main()
{
	int select = 0;
	while (true)
	{
		startMenu();
		cin >> select;
		switch (select)
		{
		case 1://学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}

