//功能描述:
//提供菜单界面与用户交互I
//对演讲比赛流程进行控制
//与文件的读写交互
#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"speaker.h"
#include<algorithm>
#include<deque>
#include<numeric>
#include<string>
#include<fstream>

class SpeechManager
{
public:
	SpeechManager();

	//显示菜单
	void ShowMenu();
	//退出系统
	void Exit();

	//初始化成员
	void initMember();

	//创建12名选手
	void createSpeaker();

	//开始比赛,比赛流程控制
	void startSpeech();

	//抽签
	void speechDraw();

	//比赛
	void speechContest();

	//显示成绩
	void showScore();

	//保存成绩到文件中
	void saveFile();

	//读取文件中的往届记录
	void loadFile();

	//清空文件
	void clearFile();

	//成员属性
	//第一轮成员编号容器
	vector<int>v1;
	//第二轮成员容器
	vector<int>v2;
	//最终胜出成员容器
	vector<int>v_Winer;
	//存放编号及具体选手容器
	map<int, Speaker>mapSpeaker;
	//记录比赛轮数
	int gameRound;

	~SpeechManager();
};