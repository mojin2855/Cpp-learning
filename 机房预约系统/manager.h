#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
#include<vector>
#include<algorithm>
class Manager :public Identity
{
public:
	//构造函数
	Manager();
	//有参构造函数
	Manager(string name,string pwd);
	//操作界面
	virtual void operMenu();
	//添加账号
	void addPerson();
	//查看账号
	void showPerson();
	//查看机房信息
	void showComputer();
	//清空预约记录
	void cleanFile();
	//删除账号
	void delPerson();

	//初始化容器
	void initVector();
	//检测重复 参数：学号/职工号  检测类型
	bool cheekRepeat(int id, int type);
	//学生容器
	vector<Student> vStu;
	//老师容器
	vector<Teacher> vTea;
	//初始化机房容器
	void initComRoom();
	//机房容器
	vector<ComputerRoom>vCom;
};
