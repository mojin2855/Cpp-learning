#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<vector>
#include"computerRoom.h"
#include"globalFile.h"
#include<fstream>
#include<algorithm>
//ѧ����
class Student:public Identity
{
public:

	//Ĭ�Ϲ���
	Student();
	//�вι��죬������ѧ�ţ�����������
	Student(int id, string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴����ԤԼ
	void showMyOrder();
	//�鿴����ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void cancelOrder();
	//ѧ��ѧ��
	int m_Id;
	//��ʼ��������Ϣ
	void initComRoom();
	//��������
	vector<ComputerRoom>vCom;

};