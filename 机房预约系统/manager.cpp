#include"manager.h"

//构造函数
Manager::Manager()
{

}

//有参构造函数
Manager::Manager(string name, string pwd)
{
	this->initVector();
	this->initComRoom();
	this->m_Name = name;
	this->m_Pwd = pwd;
}
//操作界面
void Manager::operMenu()
{
	cout << "*******************欢迎管理员"<<this->m_Name<< "登录！***********************" << endl;
	cout << "\t\t-----------------------------------------------\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                1.添加账号                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                2.查看账号                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                3.查看机房                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                4.清空预约                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                5.删除账号                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                0.注销登录                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t-----------------------------------------------\n";
	cout << "输入您的选择： ";
}
//添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号的类型，1.学生 2.老师" << endl;

	string fileName;
	string tip;
	
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//添加学生
		fileName = STUDENT_FILE;
		tip = "请输入学号";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工号";
	}

	ofs.open(fileName, ios::out | ios::app);//以追加的方式写文件

	int id;
	string name;
	string pwd;

	cout << tip << endl;
	while (true)//检测学号/职工号是否重复
	{
		cin >> id;
		bool ret = cheekRepeat(id, select);
		if (ret)
		{
			cout << "编号重复，请重新编写" << endl;
		}
		else
		{
			break;
		}
	}
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;
	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;
	this->initVector();
	system("pause");
	system("cls");

	ofs.close();
}



void printStudent(Student& s)
{
	cout << "学号： " << s.m_Id << "  姓名: " << s.m_Name << "  密码： " << s.m_Pwd << endl;
}
void printTeacher(Teacher & s)
{
	cout << "职工号： " << s.m_EmpId<< "  姓名: " << s.m_Name << "  密码： " << s.m_Pwd << endl;
}
//查看账号
void Manager::showPerson()
{
	cout << " 查看账户信息，1.学生 2.老师" << endl;
	int select=0;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生信息如下" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "所有老师信息如下" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//初始化机房容器
void Manager::initComRoom()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	ComputerRoom c;
	while (ifs >> c.m_ComId&& ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();
}

void printComRoom(ComputerRoom&com)
{
	cout << com.m_ComId << "号机房容量为" << com.m_MaxNum<<"人" << endl;
}
//查看机房信息
void Manager::showComputer()
{
	for_each(vCom.begin(), vCom.end(), printComRoom);
	system("pause");
	system("cls");
}
//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}

//初始化账号容器
void Manager::initVector()
{
	vStu.clear();
	vTea.clear();

	//读取学生信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	//cout << vStu.size();
	ifs.close();

	//读取老师信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Teacher t ;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	//cout << vTea.size();
	ifs.close();
}

//检测重复 参数：学号/职工号  检测类型
bool Manager::cheekRepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
				return true;
		}
	}
	else
	{
		//检测老师
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
				return true;
		}
	}
	return false;
}

//删除账号
void Manager::delPerson()
{
	cout << " 请输入要删除账户信息，1.学生 2.老师" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生信息如下" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
		cout << "请输入要删除的账号学号" << endl;
		int id = 0;
		cin >> id;
		//删除容器中的账号
		vector<Student>::iterator it ;
		for ( it= vStu.begin(); it < vStu.end(); it++)
		{
			if (it->m_Id == id)
			{
				vStu.erase(it);
				cout << "删除成功" << endl;
				//更新文件
				ofstream ofs(STUDENT_FILE, ios::out | ios::trunc);
				for (int i = 0; i < vStu.size(); i++)
				{
					ofs << vStu[i].m_Id << " " << vStu[i].m_Name << " " << vStu[i].m_Pwd << endl;
				}
				ofs.close();
				system("pause");
				system("cls");
				return;
			}
		}
		if (it == vStu.end())
		{
			cout << "删除失败，未找到该账号" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	else
	{
		cout << "所有老师信息如下" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
		cout << "请输入要删除的账号职工号" << endl;
		int id = 0;
		cin >> id;
		//删除容器中的账号
		vector<Teacher>::iterator it;
		for (it = vTea.begin(); it < vTea.end(); it++)
		{
			if (it->m_EmpId == id)
			{
				vTea.erase(it);
				cout << "删除成功" << endl;
				//更新文件
				ofstream ofs(TEACHER_FILE, ios::out | ios::trunc);
				for (int i = 0; i < vStu.size(); i++)
				{
					ofs << vStu[i].m_Id << " " << vStu[i].m_Name << " " << vStu[i].m_Pwd << endl;
				}
				ofs.close();
				system("pause");
				system("cls");
				return;
			}
		}
		if (it == vTea.end())
		{
			cout << "删除失败，未找到该账号" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}