//����Ҫ��
//��������
//��ѧУ����һ���ݽ�����������12���˲μӡ����������֣���һ��Ϊ��̭�����ڶ���Ϊ������
//��ÿ��ѡ�ֶ��ж�Ӧ�ı�ţ���10001 ~10012
//��������ʽ���������ÿ��6����;
//����һ�ַ�Ϊ����С�飬���尴��ѡ�ֱ�Ž��г�ǩ��˳���ݽ���
//��ʮ����ί�ֱ��ÿ��ѡ�ִ�֣�ȥ����߷ֺ���ͷ֣����ƽ����Ϊ����ѡ�ֵĳɼ���
//  ��С���ݽ������̭����������������ѡ�֣�ǰ����������������һ�ֵı�����
//���ڶ���Ϊ������ǰ����ʤ��
//��ÿ�ֱ���������Ҫ��ʾ����ѡ�ֵ���Ϣ
#include<iostream>
using namespace std;
#include<string>
#include"speechManager.h"
#include<ctime>

int main()
{
	srand((unsigned int)time(NULL));
	//����������
	SpeechManager manager;
	//���Դ���
	/*for (map<int, Speaker>::iterator it = manager.mapSpeaker.begin(); it != manager.mapSpeaker.end(); it++)
	{
		cout << "ѡ�ֱ��" << it->first << "ѡ������" << it->second.m_Name<< endl;
	}*/
	int choice = 0;
	while (true)
	{
		manager.ShowMenu();
		cout << "��ѡ��Ҫ���еĲ���" << endl;
		cin >> choice;
		if (choice == 0 || choice == 1 || choice == 2 || choice == 3)
		{
			switch (choice)
			{
			case 1://��ʼ����
				manager.startSpeech();
				break;
			case 2://��ʷ��¼
				manager.loadFile();
				break;
			case 3://��ռ�¼
				manager.clearFile();
				break;
			case 0://�˳�ϵͳ
				manager.Exit();
				break;
			default:
				system("cls");
				break;
			}
		}
		
	}
	

	system("pause");
	return 0;
}