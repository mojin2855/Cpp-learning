//ְ�������ฺ�����������:
//- ���û��Ĺ�ͨ�˵�����
//- ��ְ����ɾ�Ĳ�Ĳ���
//- ���ļ��Ķ�д����

#include "workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>

WorkManager::WorkManager()
{
	//��ȡ�ļ�����
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{//1.�ļ�������
		cout << "�ļ�������" << endl;
		this->m_WorkNum = 0;
		this->m_WorkArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{//2.�ļ����ڵ�Ϊ��
		cout << "�ļ�Ϊ��" << endl;
		this->m_WorkNum = 0;
		this->m_WorkArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.�ļ���Ϊ��
	this->FileIsEmpty = false;
	int num = this->get_FileNum();
	cout << "ְ������Ϊ" << num << endl;
	this->m_WorkNum = num;
	this->m_WorkArray = new Worker * [this->m_WorkNum];
	this->init_FileWorker();
	ifs.close();
	//���Դ���
	/*for (int i = 0; i < this->m_WorkNum; i++)
	{
		cout <<"�ļ��е�ְ������"<< this->m_WorkArray[i]->m_Name << endl;
	}*/
	
}

//չʾ�˵�
void WorkManager::ShowMenu()
{
	cout<<"********************************************"<<endl;
	cout<<"*********��ӭʹ��ְ������ϵͳ!**********"<<endl;
	cout<<"*************0.�˳��������*************"<<endl;
	cout<<"*************1.����ְ����Ϣ*************"<<endl; 
	cout<<"*************2.��ʾְ����Ϣ*************" << endl;
	cout<<"*************3.ɾ����ְְ��*************"<<endl;
	cout<<"*************4.�޸�ְ����Ϣ*************" << endl;
	cout<<"*************5.����ְ����Ϣ*************" << endl;
	cout<<"*************6.���ձ������*************"<< endl;
	cout<<"*************7.��������ĵ�*************"<< endl;
	cout<<"********************************************"<<endl;
	cout << endl;

}
//�˳�ϵͳ
void WorkManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
//���ְ��
void WorkManager::AddWorker()
{
	cout << "���������ְ������" << endl;
	int num_add=0;
	cin >> num_add;
	if (num_add > 0)
	{	//��������¿ռ��С
		int newSize = (this->m_WorkNum) + num_add;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ���ռ��е�ְ���������¿ռ��²����ԭ�ռ�
		if (this->m_WorkArray != NULL)
		{
			for (int j = 0; j < this->m_WorkNum; j++)
			{
				newSpace[j] = this->m_WorkArray[j];
			}
		}

		//���������
		for (int i = 0; i < num_add; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int sNumber;//����ѡ��
			cout << "�������" << i + 1 << "����ְ���ı��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> sNumber;
			while ((sNumber != 1 )&& (sNumber != 2 )&&(sNumber != 3))
			{
				cout << "����,����������" << endl;
				cin >> sNumber;
			}
			Worker* worker = NULL;
			
			switch (sNumber)
			{
			case 1:
			/*{
				Employee w(id, name, sNumber);
				worker = &w;
				break;
			}*/
				worker = new Employee(id, name, sNumber);
				break;
			case 2:
			/*{
				Manager w(id, name, sNumber);
				worker = &w;
				break;
			}*/
				worker = new Manager(id, name, sNumber);
				break;
			case 3:
			/*{
				Boss w(id, name, sNumber);
				worker = &w;
				break;
			}*/
				worker =new Boss(id, name, sNumber);
				break;
			default:
				break;
			}
			newSpace[(this->m_WorkNum) + i] = worker;
		}
		//�ͷ�ԭ�ռ�
		if (this->m_WorkArray != NULL)
		{
			for (int i = 0; i < this->m_WorkNum; i++)
			{
				delete this->m_WorkArray[i];
				this->m_WorkArray[i] = NULL;
			}
			delete[] this->m_WorkArray;
		}
		//�����¿ռ��ָ��
		this->m_WorkArray = newSpace;
		//����ְ������
		this->m_WorkNum = newSize;
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << num_add << "����ְ��" << endl;
		//�����ļ����޸��ļ��ձ�ʶ
		this->SaveFile();
		this->FileIsEmpty = false;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "������������" << endl;
	}

}

//�����ļ�
void WorkManager::SaveFile()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	//��ÿ���˵�����д���ļ�
	for (int i = 0; i < this->m_WorkNum; i++)
	{
		ofs << this->m_WorkArray[i]->m_Id << " "
			<< this->m_WorkArray[i]->m_Name << " "
			<< this->m_WorkArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

//ͳ���ļ�����
int WorkManager::get_FileNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}
//���ļ��е�Ա��ʵ����
void WorkManager::init_FileWorker()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
	Worker* worker = NULL;
	if (dId == 1)
	{
		worker = new Employee(id, name, dId);
	}
	else if (dId == 2)
	{
		worker = new Manager(id, name, dId);
	}
	else if (dId == 3)
	{
		worker = new Boss(id, name, dId);
	}
	else
	{
		this->error();
	}
	this->m_WorkArray[index] = worker;
	index++;
	}
}

//��ʾְ��
void WorkManager::showWorker()
{
	if (this->FileIsEmpty || this->m_WorkNum == 0)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_WorkNum; i++)
		{
			this->m_WorkArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//ɾ��ְ��
void WorkManager::DelWorker()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "����������ɾ����ְ�����" << endl;
		int num;
		cin >> num;
		int index = this->WorkerIsExist(num);
		if (index == -1)
		{
			cout << "ְ��������" << endl;
		}
		else
		{
			for (int i = index; i < this->m_WorkNum - 1; i++)
			{
				this->m_WorkArray[i] = this->m_WorkArray[i + 1];
			}
			delete this->m_WorkArray[this->m_WorkNum - 1];//���ĩλ
			this->m_WorkArray[this->m_WorkNum - 1]=NULL;
			this->m_WorkNum--;
			this->SaveFile();
			cout << "ɾ���ɹ�" << endl;
		}
		system("pause");
		system("cls");
	}
}
//�ж�ְ���Ƿ���ڣ�������������λ�ã������ڷ���-1
int WorkManager::WorkerIsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_WorkNum; i++)
	{
		if (this->m_WorkArray[i]->m_Id == id)
		{
			return i;
		}
	}
	return index;
}

//�޸�ְ����Ϣ
void WorkManager::ModifyWorker()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�ְ�����" << endl;
		int num;
		cin >> num;
		int ret = this->WorkerIsExist(num);
		if (ret != -1)
		{
			delete this->m_WorkArray[ret];
			int newId = 0;
			string newName = "";
			int newDept = 0;

			cout << "�鵽" << num << "��ְ������������ְ�����" << endl;
			cin >> newId;
			cout << "��������ְ������" <<  endl;
			cin >> newName;
			cout << "��������ְ����λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> newDept;

			Worker *worker= NULL;
			if (newDept == 1)
			{
				worker = new Employee(newId, newName, newDept);
			}
			else if (newDept == 2)
			{
				worker = new Manager(newId, newName, newDept);
			}
			else if (newDept == 3)
			{
				worker = new Boss(newId, newName, newDept);
			}
			else
			{
				this->error();
			}
			this->m_WorkArray[ret] = worker;
			this->SaveFile();
			cout << "�޸ĳɹ�" << endl;
		}
		else
		{
			cout << "��ְ��������" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkManager::FindWorker()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ��1.���ձ��   2.��������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id=0;
			cout << "������Ҫ���ҵ�ְ�����" << endl;
			cin >> id;
			int ret = this->WorkerIsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ���ְ����Ϣ����" << endl;
				this->m_WorkArray[ret]->showInfo();
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
		else if (select == 2)
		{
			string findname = "";
			bool findworker = false;
			cout << "������Ҫ���ҵ�ְ������" << endl;
			cin >> findname;
			for (int i = 0; i < this->m_WorkNum; i++)
			{
				if (this->m_WorkArray[i]->m_Name == findname)
				{
					cout << "���ҳɹ���ְ����Ϣ����" << endl;
					this->m_WorkArray[i]->showInfo();
					bool findworker = true;
				}
			}
			if (findworker == false)
			{
				cout << "���޴���" << endl;
			}
		}
		else
		{
			this->error();
		}
	}
	system("pause");
	system("cls");
}

//����
void WorkManager::SortWorker()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��1.����ְ��������  2.����ְ���Ž���" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_WorkNum; i++)
		{
			int MINorMAX = i;//���ֵ����Сֵ�±�
			for (int j = i + 1; j < this->m_WorkNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_WorkArray[MINorMAX]->m_Id > this->m_WorkArray[j]->m_Id)
					{
						MINorMAX = j;
					}
				}
				else if (select == 2)
				{
					if (this->m_WorkArray[MINorMAX]->m_Id < this->m_WorkArray[j]->m_Id)
					{
						MINorMAX = j;
					}
				}
				else
				{
					this->error();
				}
			}
			//�ж�һ��ʼ�϶���������Сֵ�ǲ��Ǽ����������Сֵ��������ǣ���������
			if (i!= MINorMAX)
			{
				Worker* temp = this->m_WorkArray[MINorMAX];
				this->m_WorkArray[MINorMAX] = this->m_WorkArray[i];
				this->m_WorkArray[i] = temp;
			}
		}
		cout << "����ɹ�"<<endl;
		this->SaveFile();
		this->showWorker();
	}
}

//����ļ�
void WorkManager::CleanFile()
{
	cout<<"ȷ�����?"<< endl;
	cout << "1��ȷ��"<< endl;
	cout << "2������"<< endl ;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
		ofs.close();

		if (this->m_WorkArray != NULL)
		{
			//ɾ��������ְ������
			for (int i = 0; i < this->m_WorkNum; i++)
			{
				delete this->m_WorkArray[i];
				this->m_WorkArray[i] = NULL;
			}
			delete[] this->m_WorkArray;
			this->m_WorkArray = NULL;
			this->FileIsEmpty = true;
			this->m_WorkNum= 0;
		}
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}

//������
void WorkManager ::error()
{
	cout << "program error" << endl;
	system("pause");
	exit(0);
}
WorkManager::~WorkManager()
{
	if (this->m_WorkArray != NULL)
	{
		//ɾ��������ְ������
		for (int i = 0; i < this->m_WorkNum; i++)
		{
			delete this->m_WorkArray[i];
			this->m_WorkArray[i] = NULL;
		}
		delete[] this->m_WorkArray;
		this->m_WorkArray = NULL;
	}
}