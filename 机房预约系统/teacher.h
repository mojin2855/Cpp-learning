#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include"student.h"
#include"orderFile.h"

class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���(ְ����ţ����������룩
	Teacher(int empId, string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();

	//ְ����
	int m_EmpId;
};