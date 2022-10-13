#pragma once//防止头文件重复包含
#include <iostream>
using namespace std;
#include"worker.h"
#include<fstream>
#define FILENAME "workerFile.txt"
class WorkManager
{
public:
	WorkManager();

	//展示菜单
	void ShowMenu();
	//退出系统
	void ExitSystem();

	//记录职工人数
	int m_WorkNum;
	//职工数组指针
	Worker** m_WorkArray;
	//添加职工
	void AddWorker();

	//保存文件
	void SaveFile();
	//文件为空标志
	bool FileIsEmpty;
	//统计文件人数
	int get_FileNum();
	//将文件中的员工实例化
	void init_FileWorker();

	//显示职工
	void showWorker();

	//删除职工
	void DelWorker();
	//判断职工是否存在，返回所在数组位置，不存在返回-1
	int WorkerIsExist(int id);

	//修改职工信息
	void ModifyWorker();

	//查找职工
	void FindWorker();
	//排序
	void SortWorker();
	//清空文件
	void CleanFile();
	
	//报错函数
	void error();
	~WorkManager();
};