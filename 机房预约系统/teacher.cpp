#include"teacher.h"



//Ĭ�Ϲ���
Teacher::Teacher()
{

}
//�вι���
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}
//�˵�����
void Teacher::operMenu()
{
	cout << "*******************��ӭ��ʦ" << this->m_Name << "��¼��***********************" << endl;
	cout << "\t\t-----------------------------------------------\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                1.�鿴����ԤԼ                |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                2.���ԤԼ                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                0.ע����¼                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t-----------------------------------------------\n";
	cout << "��������ѡ�� ";
}
//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	Student().showAllOrder();
}
//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼����" << endl;

	int index = 1;
	vector<int> v;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << index++ << "��";
			cout << "ԤԼʱ�䣺��" << of.m_orderData[i]["date"];
			cout << "    ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "    �����ţ�" << of.m_orderData[i]["roomId"];
			cout << "    ԤԼ��������" << of.m_orderData[i]["stuName"];
			cout << "    ԤԼ��ѧ�ţ�" << of.m_orderData[i]["stuId"] << endl;
		}
	}

	
	while (true)
	{
		cout << "������Ҫ��˵ļ�¼��0����" << endl;
		int select = 0;
		int ret = 0;
		cin >> select;
		if (select == 0)
		{
			system("cls");
			return;
		}
		else if (select >0 && select <= v.size())
		{
			cout << "��������˽��,1.ͨ��  2.��ͨ��" << endl;
			cin >> ret;
			if (ret == 1)
			{
				of.m_orderData[v[select - 1]]["status"] = "2";
			}
			else
			{
				of.m_orderData[v[select - 1]]["status"] = "-1";
			}
			of.updateOrder();
			cout << "������" << endl;
		}
		else
		{
			cout << "������������������" << endl;
		}
	}
}