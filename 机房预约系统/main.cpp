//��Ŀ�������һ������ԤԼϵͳ
//
//�ֱ����������ʹ�øó���
//ѧ������ : ����ʹ�û�����
//��ʦ:���ѧ����ԤԼ���롣
//����Ա:��ѧ������ʦ�����˺š�
//
//�������
//�����ܹ���3��
//1�Ż���-- - �������20�ˡ�
//2�Ż���-- - �������50��
//3�Ż���-- - �������100��
//
//������
//����Ķ���ÿ���ɹ���Ա������ա�
//ѧ������ԤԼδ��һ���ڵĻ���ʹ�ã�ԤԼ������Ϊ��һ�����壬ԤԼʱ��Ҫѡ��ԤԼʱ��(���硢����)
//��ʦ�����ԤԼ������ʵ��������ԤԼͨ�����߲�ͨ��
//
//ϵͳ��������
//�����Ƚ����¼���棬��ѡ��¼����� :
//ѧ������
//��ʦ��
//����Ա��
//�˳���
//��ÿ����ݶ���Ҫ������֤�󣬽����Ӳ˵�
//ѧ����Ҫ���� : ѧ�š���������¼���롣
//��ʦ��Ҫ����:ְ���š���������¼���롣
//����Ա��Ҫ����:����Ա��������¼���롣
//��ѧ�����幦��
//����ԤԼ-- - ԤԼ������
//�鿴�����ԤԼ-- - �鿴�Լ���ԤԼ״̬��
//�鿴����ԤԼ-- - �鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬��
//ȡ��ԤԼ-- - ȡ�������ԤԼ��ԤԼ�ɹ�������е�ԤԼ����ȡ����
//ע����¼-- - �˳���¼��
//����ʦ���幦��
//�鿴����ԤԼ--�鿴ȫ��ԤԼ��Ϣ�Լ�ԤԼ״̬��
//���ԤԼ-- - ��ѧ����ԤԼ������ˡ�
//ע����¼-- - �˳���¼��
//������Ա���幦��
//����˺ŨD--���ѧ�����ʦ���˺ţ���Ҫ���ѧ����Ż��ʦְ�����Ƿ��ظ���
//�鿴�˺�-- - ����ѡ��鿴ѧ�����ʦ��ȫ����Ϣ��
//�鿴����-- - �鿴���л�������Ϣ��
//���ԤԼ-- - �������ԤԼ��¼��
// *ɾ���˺�-- -ɾ��ѧ������ʦ���˺š����������ӵĹ��ܣ�
//ע����¼-- - �˳���¼��


#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include"manager.h"
#include"student.h"
#include"teacher.h"

void startMenu()
{
	cout << "*****************************��ӭʹ�û���ԤԼϵͳ************************" << endl;
	cout << endl << "�������������" << endl;
	cout << "\t\t-----------------------------------------------\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                1.ѧ������                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                2.��    ʦ                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                3.�� �� Ա                    |\n";
	cout << "\t\t|                                              |\n";
	cout << "\t\t|                0.��    ��                    |\n";
	cout << "\t\t-----------------------------------------------\n";
	cout << "��������ѡ�� ";
}

//�������Ա�Ӳ˵�����
void managerMenu(Identity * &manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();
		//������ָ��תΪ����ָ�룬�������෽��
		Manager* man = (Manager*)manager;

		int  select;
		cin >> select;
		if (select == 1)//����˺�
		{
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			man->showPerson();
		}
		else if (select == 3)//�鿴������Ϣ
		{
			man->showComputer();
		}
		else if (select == 4)//���ԤԼ
		{
			man->cleanFile();
		}
		else if (select == 5)//ɾ���˺�
		{
			man->delPerson();
		}
		else//ע����¼
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//����ѧ���Ӳ˵�����
void studentMenu(Identity*&student)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->operMenu();
		Student* stu = (Student*)student;

		int  select;
		cin >> select;
		if (select == 1)//����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2)//�鿴�ҵ�ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3)//�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else//ע����¼
		{
			delete stu;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//������ʦ�Ӳ˵�����
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();
		Teacher *tea= (Teacher*)teacher;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//�鿴����ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//���ԤԼ
			tea->validOrder();
		}
		else
		{
			//ע����¼
			delete tea;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼���� �����������ļ��� �����������
void LoginIn(string fileName, int type)
{
	//����ָ�룬����ָ���������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//�����û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)
	{
		//ѧ��
		cout << "����������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		//��ʦ
		cout << "����������ְ����" << endl;
		cin >> id;
	}
	cout << "�������û���" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;
	int fId;//���ļ��ж�ȡ��id��
	string fName;//���ļ��л�ȡ������
	string fPwd;//���ļ��л�ȡ������
	if (type == 1)
	{
		 //ѧ�������֤�����ļ���Ϣ�Ƚ�
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				ifs.close();
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//ְ�������֤�����ļ���Ϣ�Ƚ�
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				ifs.close();
				cout << "ְ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա�����֤�����ļ���Ϣ�Ƚ�
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				ifs.close();
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager( name, pwd);
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ��" << endl;
	ifs.close();
	system("pause");
	system("cls");
	return;
}



int main()
{
	int select = 0;
	while (true)
	{
		startMenu();
		cin >> select;
		switch (select)
		{
		case 1://ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}

