//��������:
//�ṩ�˵��������û�����I
//���ݽ��������̽��п���
//���ļ��Ķ�д����
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

	//��ʾ�˵�
	void ShowMenu();
	//�˳�ϵͳ
	void Exit();

	//��ʼ����Ա
	void initMember();

	//����12��ѡ��
	void createSpeaker();

	//��ʼ����,�������̿���
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ�ɼ�
	void showScore();

	//����ɼ����ļ���
	void saveFile();

	//��ȡ�ļ��е������¼
	void loadFile();

	//����ļ�
	void clearFile();

	//��Ա����
	//��һ�ֳ�Ա�������
	vector<int>v1;
	//�ڶ��ֳ�Ա����
	vector<int>v2;
	//����ʤ����Ա����
	vector<int>v_Winer;
	//��ű�ż�����ѡ������
	map<int, Speaker>mapSpeaker;
	//��¼��������
	int gameRound;

	~SpeechManager();
};