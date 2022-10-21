#include"manager.h"

//���캯��
Manager::Manager()
{

}

//�вι��캯��
Manager::Manager(string name, string pwd)
{
	this->initVector();
	this->initComRoom();
	this->m_Name = name;
	this->m_Pwd = pwd;
}
//��������
void Manager::operMenu()
{
	cout << "*******************��ӭ����Ա"<<this->m_Name<< "��¼��***********************" << endl;
	cout << "\t\t-----------------------------------------------\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                1.����˺�                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                2.�鿴�˺�                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                3.�鿴����                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                4.���ԤԼ                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                5.ɾ���˺�                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                0.ע����¼                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t-----------------------------------------------\n";
	cout << "��������ѡ�� ";
}
//����˺�
void Manager::addPerson()
{
	cout << "����������˺ŵ����ͣ�1.ѧ�� 2.��ʦ" << endl;

	string fileName;
	string tip;
	
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//���ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ��";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����";
	}

	ofs.open(fileName, ios::out | ios::app);//��׷�ӵķ�ʽд�ļ�

	int id;
	string name;
	string pwd;

	cout << tip << endl;
	while (true)//���ѧ��/ְ�����Ƿ��ظ�
	{
		cin >> id;
		bool ret = cheekRepeat(id, select);
		if (ret)
		{
			cout << "����ظ��������±�д" << endl;
		}
		else
		{
			break;
		}
	}
	cout << "����������" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;
	//���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	this->initVector();
	system("pause");
	system("cls");

	ofs.close();
}



void printStudent(Student& s)
{
	cout << "ѧ�ţ� " << s.m_Id << "  ����: " << s.m_Name << "  ���룺 " << s.m_Pwd << endl;
}
void printTeacher(Teacher & s)
{
	cout << "ְ���ţ� " << s.m_EmpId<< "  ����: " << s.m_Name << "  ���룺 " << s.m_Pwd << endl;
}
//�鿴�˺�
void Manager::showPerson()
{
	cout << " �鿴�˻���Ϣ��1.ѧ�� 2.��ʦ" << endl;
	int select=0;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ����Ϣ����" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "������ʦ��Ϣ����" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//��ʼ����������
void Manager::initComRoom()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	ComputerRoom c;
	while (ifs >> c.m_ComId&& ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();
}

void printComRoom(ComputerRoom&com)
{
	cout << com.m_ComId << "�Ż�������Ϊ" << com.m_MaxNum<<"��" << endl;
}
//�鿴������Ϣ
void Manager::showComputer()
{
	for_each(vCom.begin(), vCom.end(), printComRoom);
	system("pause");
	system("cls");
}
//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}

//��ʼ���˺�����
void Manager::initVector()
{
	vStu.clear();
	vTea.clear();

	//��ȡѧ����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	//cout << vStu.size();
	ifs.close();

	//��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Teacher t ;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	//cout << vTea.size();
	ifs.close();
}

//����ظ� ������ѧ��/ְ����  �������
bool Manager::cheekRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
				return true;
		}
	}
	else
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
				return true;
		}
	}
	return false;
}

//ɾ���˺�
void Manager::delPerson()
{
	cout << " ������Ҫɾ���˻���Ϣ��1.ѧ�� 2.��ʦ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ����Ϣ����" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
		cout << "������Ҫɾ�����˺�ѧ��" << endl;
		int id = 0;
		cin >> id;
		//ɾ�������е��˺�
		vector<Student>::iterator it ;
		for ( it= vStu.begin(); it < vStu.end(); it++)
		{
			if (it->m_Id == id)
			{
				vStu.erase(it);
				cout << "ɾ���ɹ�" << endl;
				//�����ļ�
				ofstream ofs(STUDENT_FILE, ios::out | ios::trunc);
				for (int i = 0; i < vStu.size(); i++)
				{
					ofs << vStu[i].m_Id << " " << vStu[i].m_Name << " " << vStu[i].m_Pwd << endl;
				}
				ofs.close();
				system("pause");
				system("cls");
				return;
			}
		}
		if (it == vStu.end())
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ����˺�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	else
	{
		cout << "������ʦ��Ϣ����" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
		cout << "������Ҫɾ�����˺�ְ����" << endl;
		int id = 0;
		cin >> id;
		//ɾ�������е��˺�
		vector<Teacher>::iterator it;
		for (it = vTea.begin(); it < vTea.end(); it++)
		{
			if (it->m_EmpId == id)
			{
				vTea.erase(it);
				cout << "ɾ���ɹ�" << endl;
				//�����ļ�
				ofstream ofs(TEACHER_FILE, ios::out | ios::trunc);
				for (int i = 0; i < vStu.size(); i++)
				{
					ofs << vStu[i].m_Id << " " << vStu[i].m_Name << " " << vStu[i].m_Pwd << endl;
				}
				ofs.close();
				system("pause");
				system("cls");
				return;
			}
		}
		if (it == vTea.end())
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ����˺�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}