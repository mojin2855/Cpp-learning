//职工管理类负责的内容如下:
//- 与用户的沟通菜单界面
//- 对职工增删改查的操作
//- 与文件的读写交互

#include "workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>

WorkManager::WorkManager()
{
	//读取文件内容
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{//1.文件不存在
		cout << "文件不存在" << endl;
		this->m_WorkNum = 0;
		this->m_WorkArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{//2.文件存在但为空
		cout << "文件为空" << endl;
		this->m_WorkNum = 0;
		this->m_WorkArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.文件不为空
	this->FileIsEmpty = false;
	int num = this->get_FileNum();
	cout << "职工人数为" << num << endl;
	this->m_WorkNum = num;
	this->m_WorkArray = new Worker * [this->m_WorkNum];
	this->init_FileWorker();
	ifs.close();
	//测试代码
	/*for (int i = 0; i < this->m_WorkNum; i++)
	{
		cout <<"文件中的职工姓名"<< this->m_WorkArray[i]->m_Name << endl;
	}*/
	
}

//展示菜单
void WorkManager::ShowMenu()
{
	cout<<"********************************************"<<endl;
	cout<<"*********欢迎使用职工管理系统!**********"<<endl;
	cout<<"*************0.退出管理程序*************"<<endl;
	cout<<"*************1.增加职工信息*************"<<endl; 
	cout<<"*************2.显示职工信息*************" << endl;
	cout<<"*************3.删除离职职工*************"<<endl;
	cout<<"*************4.修改职工信息*************" << endl;
	cout<<"*************5.查找职工信息*************" << endl;
	cout<<"*************6.按照编号排序*************"<< endl;
	cout<<"*************7.清空所有文档*************"<< endl;
	cout<<"********************************************"<<endl;
	cout << endl;

}
//退出系统
void WorkManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
//添加职工
void WorkManager::AddWorker()
{
	cout << "请输入添加职工数量" << endl;
	int num_add=0;
	cin >> num_add;
	if (num_add > 0)
	{	//计算添加新空间大小
		int newSize = (this->m_WorkNum) + num_add;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原来空间中的职工拷贝到新空间下并清空原空间
		if (this->m_WorkArray != NULL)
		{
			for (int j = 0; j < this->m_WorkNum; j++)
			{
				newSpace[j] = this->m_WorkArray[j];
			}
		}

		//添加新数据
		for (int i = 0; i < num_add; i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int sNumber;//部门选择
			cout << "请输入第" << i + 1 << "个新职工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名" << endl;
			cin >> name;
			cout << "请选择该职工岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> sNumber;
			while ((sNumber != 1 )&& (sNumber != 2 )&&(sNumber != 3))
			{
				cout << "错误,请重新输入" << endl;
				cin >> sNumber;
			}
			Worker* worker = NULL;
			
			switch (sNumber)
			{
			case 1:
			/*{
				Employee w(id, name, sNumber);
				worker = &w;
				break;
			}*/
				worker = new Employee(id, name, sNumber);
				break;
			case 2:
			/*{
				Manager w(id, name, sNumber);
				worker = &w;
				break;
			}*/
				worker = new Manager(id, name, sNumber);
				break;
			case 3:
			/*{
				Boss w(id, name, sNumber);
				worker = &w;
				break;
			}*/
				worker =new Boss(id, name, sNumber);
				break;
			default:
				break;
			}
			newSpace[(this->m_WorkNum) + i] = worker;
		}
		//释放原空间
		if (this->m_WorkArray != NULL)
		{
			for (int i = 0; i < this->m_WorkNum; i++)
			{
				delete this->m_WorkArray[i];
				this->m_WorkArray[i] = NULL;
			}
			delete[] this->m_WorkArray;
		}
		//更改新空间的指向
		this->m_WorkArray = newSpace;
		//更新职工人数
		this->m_WorkNum = newSize;
		//提示添加成功
		cout << "成功添加" << num_add << "名新职工" << endl;
		//保存文件并修改文件空标识
		this->SaveFile();
		this->FileIsEmpty = false;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "输入数据有误" << endl;
	}

}

//保存文件
void WorkManager::SaveFile()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	//将每个人的数据写入文件
	for (int i = 0; i < this->m_WorkNum; i++)
	{
		ofs << this->m_WorkArray[i]->m_Id << " "
			<< this->m_WorkArray[i]->m_Name << " "
			<< this->m_WorkArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

//统计文件人数
int WorkManager::get_FileNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}
//将文件中的员工实例化
void WorkManager::init_FileWorker()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
	Worker* worker = NULL;
	if (dId == 1)
	{
		worker = new Employee(id, name, dId);
	}
	else if (dId == 2)
	{
		worker = new Manager(id, name, dId);
	}
	else if (dId == 3)
	{
		worker = new Boss(id, name, dId);
	}
	else
	{
		this->error();
	}
	this->m_WorkArray[index] = worker;
	index++;
	}
}

//显示职工
void WorkManager::showWorker()
{
	if (this->FileIsEmpty || this->m_WorkNum == 0)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_WorkNum; i++)
		{
			this->m_WorkArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//删除职工
void WorkManager::DelWorker()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入你想删除的职工编号" << endl;
		int num;
		cin >> num;
		int index = this->WorkerIsExist(num);
		if (index == -1)
		{
			cout << "职工不存在" << endl;
		}
		else
		{
			for (int i = index; i < this->m_WorkNum - 1; i++)
			{
				this->m_WorkArray[i] = this->m_WorkArray[i + 1];
			}
			delete this->m_WorkArray[this->m_WorkNum - 1];//清空末位
			this->m_WorkArray[this->m_WorkNum - 1]=NULL;
			this->m_WorkNum--;
			this->SaveFile();
			cout << "删除成功" << endl;
		}
		system("pause");
		system("cls");
	}
}
//判断职工是否存在，返回所在数组位置，不存在返回-1
int WorkManager::WorkerIsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_WorkNum; i++)
	{
		if (this->m_WorkArray[i]->m_Id == id)
		{
			return i;
		}
	}
	return index;
}

//修改职工信息
void WorkManager::ModifyWorker()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入要修改的职工编号" << endl;
		int num;
		cin >> num;
		int ret = this->WorkerIsExist(num);
		if (ret != -1)
		{
			delete this->m_WorkArray[ret];
			int newId = 0;
			string newName = "";
			int newDept = 0;

			cout << "查到" << num << "号职工，请输入新职工编号" << endl;
			cin >> newId;
			cout << "请输入新职工姓名" <<  endl;
			cin >> newName;
			cout << "请输入新职工岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> newDept;

			Worker *worker= NULL;
			if (newDept == 1)
			{
				worker = new Employee(newId, newName, newDept);
			}
			else if (newDept == 2)
			{
				worker = new Manager(newId, newName, newDept);
			}
			else if (newDept == 3)
			{
				worker = new Boss(newId, newName, newDept);
			}
			else
			{
				this->error();
			}
			this->m_WorkArray[ret] = worker;
			this->SaveFile();
			cout << "修改成功" << endl;
		}
		else
		{
			cout << "该职工不存在" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工
void WorkManager::FindWorker()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入查找方式：1.按照编号   2.按照姓名" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id=0;
			cout << "请输入要查找的职工编号" << endl;
			cin >> id;
			int ret = this->WorkerIsExist(id);
			if (ret != -1)
			{
				cout << "查找成功，职工信息如下" << endl;
				this->m_WorkArray[ret]->showInfo();
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			string findname = "";
			bool findworker = false;
			cout << "请输入要查找的职工名字" << endl;
			cin >> findname;
			for (int i = 0; i < this->m_WorkNum; i++)
			{
				if (this->m_WorkArray[i]->m_Name == findname)
				{
					cout << "查找成功，职工信息如下" << endl;
					this->m_WorkArray[i]->showInfo();
					bool findworker = true;
				}
			}
			if (findworker == false)
			{
				cout << "查无此人" << endl;
			}
		}
		else
		{
			this->error();
		}
	}
	system("pause");
	system("cls");
}

//排序
void WorkManager::SortWorker()
{
	if (this->FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：1.按照职工号升序  2.按照职工号降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_WorkNum; i++)
		{
			int MINorMAX = i;//最大值或最小值下标
			for (int j = i + 1; j < this->m_WorkNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_WorkArray[MINorMAX]->m_Id > this->m_WorkArray[j]->m_Id)
					{
						MINorMAX = j;
					}
				}
				else if (select == 2)
				{
					if (this->m_WorkArray[MINorMAX]->m_Id < this->m_WorkArray[j]->m_Id)
					{
						MINorMAX = j;
					}
				}
				else
				{
					this->error();
				}
			}
			//判断一开始认定的最大或最小值是不是计算的最大或最小值，如果不是，交换数据
			if (i!= MINorMAX)
			{
				Worker* temp = this->m_WorkArray[MINorMAX];
				this->m_WorkArray[MINorMAX] = this->m_WorkArray[i];
				this->m_WorkArray[i] = temp;
			}
		}
		cout << "排序成功"<<endl;
		this->SaveFile();
		this->showWorker();
	}
}

//清空文件
void WorkManager::CleanFile()
{
	cout<<"确定清空?"<< endl;
	cout << "1、确定"<< endl;
	cout << "2、返回"<< endl ;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();

		if (this->m_WorkArray != NULL)
		{
			//删除堆区的职工对象
			for (int i = 0; i < this->m_WorkNum; i++)
			{
				delete this->m_WorkArray[i];
				this->m_WorkArray[i] = NULL;
			}
			delete[] this->m_WorkArray;
			this->m_WorkArray = NULL;
			this->FileIsEmpty = true;
			this->m_WorkNum= 0;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

//报错函数
void WorkManager ::error()
{
	cout << "program error" << endl;
	system("pause");
	exit(0);
}
WorkManager::~WorkManager()
{
	if (this->m_WorkArray != NULL)
	{
		//删除堆区的职工对象
		for (int i = 0; i < this->m_WorkNum; i++)
		{
			delete this->m_WorkArray[i];
			this->m_WorkArray[i] = NULL;
		}
		delete[] this->m_WorkArray;
		this->m_WorkArray = NULL;
	}
}