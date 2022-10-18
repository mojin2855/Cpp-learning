//程序要求
//比赛规则
//·学校举行一场演讲比赛，共有12个人参加。比赛共两轮，第一轮为淘汰赛，第二轮为决赛。
//·每名选手都有对应的编号，如10001 ~10012
//·比赛方式分组比赛，每组6个人;
//·第一轮分为两个小组，整体按照选手编号进行抽签后顺序演讲。
//·十个评委分别给每名选手打分，去除最高分和最低分，求的平均分为本轮选手的成绩。
//  当小组演讲完后，淘汰组内排名最后的三个选手，前三名晋级，进入下一轮的比赛。
//·第二轮为决赛，前三名胜出
//·每轮比赛过后需要显示晋级选手的信息
#include<iostream>
using namespace std;
#include<string>
#include"speechManager.h"
#include<ctime>

int main()
{
	srand((unsigned int)time(NULL));
	//创建管理类
	SpeechManager manager;
	//测试代码
	/*for (map<int, Speaker>::iterator it = manager.mapSpeaker.begin(); it != manager.mapSpeaker.end(); it++)
	{
		cout << "选手编号" << it->first << "选手姓名" << it->second.m_Name<< endl;
	}*/
	int choice = 0;
	while (true)
	{
		manager.ShowMenu();
		cout << "请选择要进行的操作" << endl;
		cin >> choice;
		if (choice == 0 || choice == 1 || choice == 2 || choice == 3)
		{
			switch (choice)
			{
			case 1://开始比赛
				manager.startSpeech();
				break;
			case 2://历史记录
				manager.loadFile();
				break;
			case 3://清空记录
				manager.clearFile();
				break;
			case 0://退出系统
				manager.Exit();
				break;
			default:
				system("cls");
				break;
			}
		}
		
	}
	

	system("pause");
	return 0;
}