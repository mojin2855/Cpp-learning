#include "speechManager.h"
SpeechManager::SpeechManager()
{
	//初始化属性
	this->initMember();
	//创建选手
	this->createSpeaker();

}

//显示菜单
void SpeechManager::ShowMenu()
{
	cout << "*********************************" << endl;
	cout << "********欢迎参加演讲比赛*********" << endl;
	cout << "*********1.开始演讲比赛**********" << endl;
	cout << "*********2.查看往届记录**********" << endl;
	cout << "*********3.清空比赛记录**********" << endl;
	cout << "*********0.退出比赛程序**********" << endl;
	cout << "*********************************" << endl;
	cout << endl;

}

//退出系统
void SpeechManager::Exit()
{
	cout << "欢迎再次使用" << endl;
	system("pause");
	exit(0);
}

//初始化成员
void SpeechManager::initMember()
{
	this->v1.clear();
	this->v2.clear();
	this->v_Winer.clear();
	this->mapSpeaker.clear();
	this->gameRound = 1;

}

//创建12名选手
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		Speaker sp;  
		sp.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}
		//创建选手编号并放入v1容器
		this->v1.push_back(i + 10001);
		//选手编号以及对应选手，放入map容器
		this->mapSpeaker.insert(make_pair(i + 10001, sp));

	}
}

//开始比赛
void SpeechManager::startSpeech()
{
	//第一轮开始比赛
	this->gameRound = 1;
	//1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3.显示晋级结果
	this->showScore();
	//第二轮比赛
	this->gameRound=2;
	//1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3.显示最终结果
	this->showScore();
	//保存分数到文件中
	this->saveFile();
	//初始化属性
	this->initMember();
	//创建选手
	this->createSpeaker();

	cout << "本届比赛结束" << endl;
	system("pause");
	system("cls");
}

//抽签
void SpeechManager::speechDraw()
{
	cout << "第<<" << this->gameRound << ">>轮比赛选手进行抽签" << endl;
	cout << "--------------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
	if (this->gameRound == 1)
	{
		//第一轮比赛
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		//第二轮比赛
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "---------------------" << endl;
	system("pause");

}

//比赛
void SpeechManager::speechContest()
{
	cout << "第<<" << this->gameRound << ">>轮比赛正式开始" << endl;

	//准备临时容器 存放小组成绩
	multimap<double, int, greater<double> >groupScore;
	int num = 0;//记录人员个数 

	vector<int> v_Src;//比赛选手容器
	if (this->gameRound == 1)
	{
		v_Src = this->v1;
	}
	else
	{
		v_Src = this->v2;
	}

	//遍历所有比赛选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//评委打分
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			cout << score << " ";
			d.push_back(score);
		}
		cout << endl;
		//去除最高分最低分
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();
		//计算平均分
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		cout <<"编号： "<<*it<<"姓名:"<< this->mapSpeaker[*it].m_Name << "平均分： " << avg << endl;

		//将平均分放入map容器中
		this->mapSpeaker[*it].m_Score[this->gameRound - 1] = avg;

		//将打分数据放入到临时小组容器中
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号 " << it->second << " 姓名 " << this->mapSpeaker[it->second].m_Name << " 成绩 " << it->first << endl;
			}
			//取走前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&&count<3; it++,count++)
			{
				if (this->gameRound == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					v_Winer.push_back((*it).second);
				}
			}
			groupScore.clear();
		}
	}
	cout << "-------------第" << this->gameRound << "轮比赛结束------------" << endl;
	system("pause");
}

//显示成绩
void SpeechManager::showScore()
{
	cout << "------第" << this->gameRound << "轮晋级选手如下：-----------------" << endl;
	if (this->gameRound == 1)
	{
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << "编号： " << *it << " 名字： " << this->mapSpeaker[*it].m_Name << " 分数： " << this->mapSpeaker[*it].m_Score[0] << endl;
		}
		system("pause");
		system("cls");
		this->ShowMenu();
	}
	else
	{
		for (vector<int>::iterator it = v_Winer.begin(); it != v_Winer.end(); it++)
		{
			cout << "编号： " << *it << " 名字： " << this->mapSpeaker[*it].m_Name << " 分数： " << this->mapSpeaker[*it].m_Score[1] << endl;
		}
		system("pause");
		system("cls");
	}
}


//保存成绩到文件中
void SpeechManager::saveFile()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//追加的方式写文件
	//将每个选手数据写入到文件中
	for (vector<int>::iterator it = v_Winer.begin(); it != v_Winer.end(); it++)
	{
		ofs << *it << "," << this->mapSpeaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();

	cout << "文件已保存" << endl;
}

//读取文件中的往届记录
void SpeechManager::loadFile()
{
	bool fileIsEmpty;
	//存放往届记录的map容器
	map<int, vector<string>>m_Record;
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		fileIsEmpty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件不为空
	fileIsEmpty = false;
	ifs.putback(ch);
	string data;
	int index=1;//记录届数
	
	while (ifs >> data)
	{
		vector<string> v;//存放往届获奖选手
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(',', start);
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			start = pos + 1;
		}
		m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
	
	for (map<int, vector<string>>::iterator it = m_Record.begin(); it !=m_Record.end(); it++)
	{
	
		cout << "第" << it->first << "届比赛冠军编号：" << it->second[0] << "  分数： " << (it->second[1]) <<
			"亚军编号： " << it->second[2] << "  分数： " << it->second[3] << "季军编号： " << it->second[4] << "  分数： " << it->second[5]
			<< endl;
	}

	system("pause");
	system("cls");
}
//清空文件
void SpeechManager::clearFile()
{
	cout << "是否确认清空文件,确认：1；取消：2" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		cout << "清空成功" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");
	}
}

SpeechManager::~SpeechManager()
{

}