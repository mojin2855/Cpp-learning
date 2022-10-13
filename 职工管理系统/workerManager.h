#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>
using namespace std;
#include"worker.h"
#include<fstream>
#define FILENAME "workerFile.txt"
class WorkManager
{
public:
	WorkManager();

	//չʾ�˵�
	void ShowMenu();
	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ������
	int m_WorkNum;
	//ְ������ָ��
	Worker** m_WorkArray;
	//���ְ��
	void AddWorker();

	//�����ļ�
	void SaveFile();
	//�ļ�Ϊ�ձ�־
	bool FileIsEmpty;
	//ͳ���ļ�����
	int get_FileNum();
	//���ļ��е�Ա��ʵ����
	void init_FileWorker();

	//��ʾְ��
	void showWorker();

	//ɾ��ְ��
	void DelWorker();
	//�ж�ְ���Ƿ���ڣ�������������λ�ã������ڷ���-1
	int WorkerIsExist(int id);

	//�޸�ְ����Ϣ
	void ModifyWorker();

	//����ְ��
	void FindWorker();
	//����
	void SortWorker();
	//����ļ�
	void CleanFile();
	
	//������
	void error();
	~WorkManager();
};