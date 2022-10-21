#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
#include<vector>
#include<algorithm>
class Manager :public Identity
{
public:
	//���캯��
	Manager();
	//�вι��캯��
	Manager(string name,string pwd);
	//��������
	virtual void operMenu();
	//����˺�
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void cleanFile();
	//ɾ���˺�
	void delPerson();

	//��ʼ������
	void initVector();
	//����ظ� ������ѧ��/ְ����  �������
	bool cheekRepeat(int id, int type);
	//ѧ������
	vector<Student> vStu;
	//��ʦ����
	vector<Teacher> vTea;
	//��ʼ����������
	void initComRoom();
	//��������
	vector<ComputerRoom>vCom;
};
