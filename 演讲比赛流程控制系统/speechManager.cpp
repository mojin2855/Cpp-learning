#include "speechManager.h"
SpeechManager::SpeechManager()
{
	//��ʼ������
	this->initMember();
	//����ѡ��
	this->createSpeaker();

}

//��ʾ�˵�
void SpeechManager::ShowMenu()
{
	cout << "*********************************" << endl;
	cout << "********��ӭ�μ��ݽ�����*********" << endl;
	cout << "*********1.��ʼ�ݽ�����**********" << endl;
	cout << "*********2.�鿴�����¼**********" << endl;
	cout << "*********3.��ձ�����¼**********" << endl;
	cout << "*********0.�˳���������**********" << endl;
	cout << "*********************************" << endl;
	cout << endl;

}

//�˳�ϵͳ
void SpeechManager::Exit()
{
	cout << "��ӭ�ٴ�ʹ��" << endl;
	system("pause");
	exit(0);
}

//��ʼ����Ա
void SpeechManager::initMember()
{
	this->v1.clear();
	this->v2.clear();
	this->v_Winer.clear();
	this->mapSpeaker.clear();
	this->gameRound = 1;

}

//����12��ѡ��
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;  
		sp.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}
		//����ѡ�ֱ�Ų�����v1����
		this->v1.push_back(i + 10001);
		//ѡ�ֱ���Լ���Ӧѡ�֣�����map����
		this->mapSpeaker.insert(make_pair(i + 10001, sp));

	}
}

//��ʼ����
void SpeechManager::startSpeech()
{
	//��һ�ֿ�ʼ����
	this->gameRound = 1;
	//1.��ǩ
	this->speechDraw();
	//2.����
	this->speechContest();
	//3.��ʾ�������
	this->showScore();
	//�ڶ��ֱ���
	this->gameRound=2;
	//1.��ǩ
	this->speechDraw();
	//2.����
	this->speechContest();
	//3.��ʾ���ս��
	this->showScore();
	//����������ļ���
	this->saveFile();
	//��ʼ������
	this->initMember();
	//����ѡ��
	this->createSpeaker();

	cout << "�����������" << endl;
	system("pause");
	system("cls");
}

//��ǩ
void SpeechManager::speechDraw()
{
	cout << "��<<" << this->gameRound << ">>�ֱ���ѡ�ֽ��г�ǩ" << endl;
	cout << "--------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	if (this->gameRound == 1)
	{
		//��һ�ֱ���
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		//�ڶ��ֱ���
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

//����
void SpeechManager::speechContest()
{
	cout << "��<<" << this->gameRound << ">>�ֱ�����ʽ��ʼ" << endl;

	//׼����ʱ���� ���С��ɼ�
	multimap<double, int, greater<double> >groupScore;
	int num = 0;//��¼��Ա���� 

	vector<int> v_Src;//����ѡ������
	if (this->gameRound == 1)
	{
		v_Src = this->v1;
	}
	else
	{
		v_Src = this->v2;
	}

	//�������б���ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			cout << score << " ";
			d.push_back(score);
		}
		cout << endl;
		//ȥ����߷���ͷ�
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();
		//����ƽ����
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		cout <<"��ţ� "<<*it<<"����:"<< this->mapSpeaker[*it].m_Name << "ƽ���֣� " << avg << endl;

		//��ƽ���ַ���map������
		this->mapSpeaker[*it].m_Score[this->gameRound - 1] = avg;

		//��������ݷ��뵽��ʱС��������
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��� " << it->second << " ���� " << this->mapSpeaker[it->second].m_Name << " �ɼ� " << it->first << endl;
			}
			//ȡ��ǰ����
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
	cout << "-------------��" << this->gameRound << "�ֱ�������------------" << endl;
	system("pause");
}

//��ʾ�ɼ�
void SpeechManager::showScore()
{
	cout << "------��" << this->gameRound << "�ֽ���ѡ�����£�-----------------" << endl;
	if (this->gameRound == 1)
	{
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << "��ţ� " << *it << " ���֣� " << this->mapSpeaker[*it].m_Name << " ������ " << this->mapSpeaker[*it].m_Score[0] << endl;
		}
		system("pause");
		system("cls");
		this->ShowMenu();
	}
	else
	{
		for (vector<int>::iterator it = v_Winer.begin(); it != v_Winer.end(); it++)
		{
			cout << "��ţ� " << *it << " ���֣� " << this->mapSpeaker[*it].m_Name << " ������ " << this->mapSpeaker[*it].m_Score[1] << endl;
		}
		system("pause");
		system("cls");
	}
}


//����ɼ����ļ���
void SpeechManager::saveFile()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//׷�ӵķ�ʽд�ļ�
	//��ÿ��ѡ������д�뵽�ļ���
	for (vector<int>::iterator it = v_Winer.begin(); it != v_Winer.end(); it++)
	{
		ofs << *it << "," << this->mapSpeaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();

	cout << "�ļ��ѱ���" << endl;
}

//��ȡ�ļ��е������¼
void SpeechManager::loadFile()
{
	bool fileIsEmpty;
	//��������¼��map����
	map<int, vector<string>>m_Record;
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		fileIsEmpty = true;
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//�ļ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��
	fileIsEmpty = false;
	ifs.putback(ch);
	string data;
	int index=1;//��¼����
	
	while (ifs >> data)
	{
		vector<string> v;//��������ѡ��
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
	
		cout << "��" << it->first << "������ھ���ţ�" << it->second[0] << "  ������ " << (it->second[1]) <<
			"�Ǿ���ţ� " << it->second[2] << "  ������ " << it->second[3] << "������ţ� " << it->second[4] << "  ������ " << it->second[5]
			<< endl;
	}

	system("pause");
	system("cls");
}
//����ļ�
void SpeechManager::clearFile()
{
	cout << "�Ƿ�ȷ������ļ�,ȷ�ϣ�1��ȡ����2" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		cout << "��ճɹ�" << endl;
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