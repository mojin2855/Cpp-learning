#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include"globalFile.h"
#include<string>
#include<map>
class OrderFile
{
public:
	//���캯��
	OrderFile();
	//����ԤԼ��¼
	void updateOrder();
	//��¼ԤԼ����
	int m_Size;
	//��¼����ԤԼ��Ϣ������
	map<int, map<string, string>>m_orderData;
};