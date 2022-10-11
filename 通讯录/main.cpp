#include <iostream>
#include <string>
using namespace std;
#define MAX 100

// 1.��ʾ���˵�
void showMenu()
{
    cout << "*********************" << endl;
    cout << "****1�������ϵ��****" << endl;
    cout << "****2����ʾ��ϵ��****" << endl;
    cout << "****3��ɾ����ϵ��****" << endl;
    cout << "****4��������ϵ��****" << endl;
    cout << "****5���޸���ϵ��****" << endl;
    cout << "****6�������ϵ��****" << endl;
    cout << "****0���˳�ͨѶ¼****" << endl;
    cout << "*********************" << endl;
}

//�����ϵ�˽ṹ��
struct Person
{
    //����
    string m_Name;
    //�Ա� 1 �� 2 Ů
    int m_Sex;
    //����
    string m_Age;
    //�绰
    string m_Phone;
    //סַ
    string m_Addr;
};

//���ͨѶ¼�ṹ��
struct AddressBooks
{
    //ͨѶ¼�б������ϵ������
    struct Person personArray[MAX];

    //ͨѶ¼�б������ϵ�˸���
    int m_Size;
};

// 1�������ϵ��
void addPerson(AddressBooks* abs)
{
    if (abs->m_Size >= MAX)
    {
        cout << "ͨѶ¼�������޷����" << endl;
        return;
    }
    else
    {
        //��Ӿ�����ϵ��

        //����
        cout << "������������" << endl;
        cin >> abs->personArray[abs->m_Size].m_Name;
        //�Ա�
        cout << "�������Ա�1--���ԣ�2--Ů��" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "������������������" << endl;
        }
        //����
        cout << "����������" << endl;
        cin >> abs->personArray[abs->m_Size].m_Age;
        //�绰
        cout << "��������ϵ�绰" << endl;
        cin >> abs->personArray[abs->m_Size].m_Phone;
        //סַ
        cout << "�������ͥסַ" << endl;
        cin >> abs->personArray[abs->m_Size].m_Addr;

        cout << "��ӳɹ�" << endl;
        //����ͨѶ¼����
        abs->m_Size++;

        system("pause");
        system("cls");
    }
}

// 2����ʾ��ϵ��
void showPerson(AddressBooks* abs)
{
    if (abs->m_Size == 0)
    {
        cout << "ͨѶ¼Ϊ��" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "����: " << abs->personArray[i].m_Name << "\t"
                << "\t"
                << "�Ա�: " << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t"
                << "\t"
                << "����: " << abs->personArray[i].m_Age << "\t"
                << "\t"
                << "�绰: " << abs->personArray[i].m_Phone << "\t"
                << "\t"
                << "סַ: " << abs->personArray[i].m_Addr << endl;
        }
    }
    system("pause");
    system("cls");
}

int isExist(AddressBooks* abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (name == abs->personArray[i].m_Name)
        {
            return i;
        }
    }
    return -1;
}

// 3��ɾ����ϵ��
void deletePerson(AddressBooks* abs)
{
    cout << "������Ҫɾ������ϵ������" << endl;

    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->m_Size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "ɾ���ɹ�" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "���޴���" << endl;
        system("pause");
        system("cls");
    }
}

// 4��������ϵ��
void findPerson(AddressBooks* abs)
{
    cout << "������Ҫ���ҵ���ϵ������" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "����: " << abs->personArray[ret].m_Name << "\t\t"
            << "�Ա�: " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t\t"
            << "����: " << abs->personArray[ret].m_Age << "\t\t"
            << "�绰: " << abs->personArray[ret].m_Phone << "\t\t"
            << "סַ: " << abs->personArray[ret].m_Addr << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "���޴���" << endl;
        system("pause");
        system("cls");
    }
}

// 5���޸���ϵ��
void modifyPerson(AddressBooks* abs)
{
    cout << "������Ҫ�޸ĵ���ϵ������" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "������������" << endl;
        cin >> abs->personArray[ret].m_Name;
        cout << "�������Ա�,1--����,2--Ů��" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "������������������" << endl;
        }
        cout << "����������" << endl;
        cin >> abs->personArray[ret].m_Age;
        //�绰
        cout << "��������ϵ�绰" << endl;
        cin >> abs->personArray[ret].m_Phone;
        //סַ
        cout << "�������ͥסַ" << endl;
        cin >> abs->personArray[ret].m_Addr;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "���޴���" << endl;
        system("pause");
        system("cls");
    }
}

// 6�������ϵ��
void cleanPerson(AddressBooks* abs)
{
    abs->m_Size = 0;
    cout << "�����" << endl;
    system("pause");
    system("cls");
}

int main()
{
    struct AddressBooks abs; //����ͨѶ¼
    abs.m_Size = 0;          //��ʼ��ͨѶ¼����
    int select = 0;
    while (true)
    {
        showMenu();
        cout << "��ѡ��Ҫ���еĲ���" << endl;
        cin >> select;
        switch (select)
        {
        case 1: // 1�������ϵ��
            addPerson(&abs);
            break;
        case 2: // 2����ʾ��ϵ��
            showPerson(&abs);
            break;
        case 3: // 3��ɾ����ϵ��
            deletePerson(&abs);
            break;
        case 4: // 4��������ϵ��
            findPerson(&abs);
            break;
        case 5: // 5���޸���ϵ��
            modifyPerson(&abs);
            break;
        case 6: // 6�������ϵ��
            cleanPerson(&abs);
            break;
        case 0: // 0���˳�ͨѶ¼
            cout << "��ӭ�´�ʹ��" << endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    }

    system("pause");
    return 0;
    
}
