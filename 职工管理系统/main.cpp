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
	////���Դ���
	//Worker* worker = NULL;
	//worker = new Boss(1, "����", 10);
	//worker->showInfo();
	WorkManager wm;
	int choice=0;
	while (true)
	{
		wm.ShowMenu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{

		case 0://�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1://����ְ����Ϣ
			wm.AddWorker();
			break;
		case 2://��ʾְ����Ϣ
			wm.showWorker();
			break;
		case 3://ɾ��ְ��
			wm.DelWorker();
			break;
		case 4://�޸�ְ����Ϣ
			wm.ModifyWorker();
			break;
		case 5://����ְ��
			wm.FindWorker();
			break;
		case 6://����
			wm.SortWorker();
			break;
		case 7://����ĵ�
			wm.CleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	system("pause");
}

