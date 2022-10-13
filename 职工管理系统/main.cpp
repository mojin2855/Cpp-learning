#include<iostream>
using namespace std;
#include<string>
#include <fstream>
#include"workerManager.h"
#include"worker.h"
//#include"employee.h"
//#include"manager.h"
//#include"boss.h"


int main()
{
	////测试代码
	//Worker* worker = NULL;
	//worker = new Boss(1, "张三", 10);
	//worker->showInfo();
	WorkManager wm;
	int choice=0;
	while (true)
	{
		wm.ShowMenu();
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice)
		{

		case 0://退出系统
			wm.ExitSystem();
			break;
		case 1://增加职工信息
			wm.AddWorker();
			break;
		case 2://显示职工信息
			wm.showWorker();
			break;
		case 3://删除职工
			wm.DelWorker();
			break;
		case 4://修改职工信息
			wm.ModifyWorker();
			break;
		case 5://查找职工
			wm.FindWorker();
			break;
		case 6://排序
			wm.SortWorker();
			break;
		case 7://清空文档
			wm.CleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	system("pause");
}

