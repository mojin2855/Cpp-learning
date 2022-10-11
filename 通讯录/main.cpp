#include <iostream>
#include <string>
using namespace std;
#define MAX 100

// 1.显示主菜单
void showMenu()
{
    cout << "*********************" << endl;
    cout << "****1、添加联系人****" << endl;
    cout << "****2、显示联系人****" << endl;
    cout << "****3、删除联系人****" << endl;
    cout << "****4、查找联系人****" << endl;
    cout << "****5、修改联系人****" << endl;
    cout << "****6、清空联系人****" << endl;
    cout << "****0、退出通讯录****" << endl;
    cout << "*********************" << endl;
}

//设计联系人结构体
struct Person
{
    //姓名
    string m_Name;
    //性别 1 男 2 女
    int m_Sex;
    //年龄
    string m_Age;
    //电话
    string m_Phone;
    //住址
    string m_Addr;
};

//设计通讯录结构体
struct AddressBooks
{
    //通讯录中保存的联系人数组
    struct Person personArray[MAX];

    //通讯录中保存的联系人个数
    int m_Size;
};

// 1、添加联系人
void addPerson(AddressBooks* abs)
{
    if (abs->m_Size >= MAX)
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else
    {
        //添加具体联系人

        //姓名
        cout << "请输入姓名：" << endl;
        cin >> abs->personArray[abs->m_Size].m_Name;
        //性别
        cout << "请输入性别，1--男性，2--女性" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }
        //年龄
        cout << "请输入年龄" << endl;
        cin >> abs->personArray[abs->m_Size].m_Age;
        //电话
        cout << "请输入联系电话" << endl;
        cin >> abs->personArray[abs->m_Size].m_Phone;
        //住址
        cout << "请输入家庭住址" << endl;
        cin >> abs->personArray[abs->m_Size].m_Addr;

        cout << "添加成功" << endl;
        //更新通讯录人数
        abs->m_Size++;

        system("pause");
        system("cls");
    }
}

// 2、显示联系人
void showPerson(AddressBooks* abs)
{
    if (abs->m_Size == 0)
    {
        cout << "通讯录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名: " << abs->personArray[i].m_Name << "\t"
                << "\t"
                << "性别: " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t"
                << "\t"
                << "年龄: " << abs->personArray[i].m_Age << "\t"
                << "\t"
                << "电话: " << abs->personArray[i].m_Phone << "\t"
                << "\t"
                << "住址: " << abs->personArray[i].m_Addr << endl;
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

// 3、删除联系人
void deletePerson(AddressBooks* abs)
{
    cout << "输入你要删除的联系人姓名" << endl;

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
        cout << "删除成功" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "查无此人" << endl;
        system("pause");
        system("cls");
    }
}

// 4、查找联系人
void findPerson(AddressBooks* abs)
{
    cout << "输入你要查找的联系人姓名" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名: " << abs->personArray[ret].m_Name << "\t\t"
            << "性别: " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t\t"
            << "年龄: " << abs->personArray[ret].m_Age << "\t\t"
            << "电话: " << abs->personArray[ret].m_Phone << "\t\t"
            << "住址: " << abs->personArray[ret].m_Addr << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "查无此人" << endl;
        system("pause");
        system("cls");
    }
}

// 5、修改联系人
void modifyPerson(AddressBooks* abs)
{
    cout << "输入你要修改的联系人姓名" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "请输入姓名：" << endl;
        cin >> abs->personArray[ret].m_Name;
        cout << "请输入性别,1--男性,2--女性" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }
        cout << "请输入年龄" << endl;
        cin >> abs->personArray[ret].m_Age;
        //电话
        cout << "请输入联系电话" << endl;
        cin >> abs->personArray[ret].m_Phone;
        //住址
        cout << "请输入家庭住址" << endl;
        cin >> abs->personArray[ret].m_Addr;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "查无此人" << endl;
        system("pause");
        system("cls");
    }
}

// 6、清空联系人
void cleanPerson(AddressBooks* abs)
{
    abs->m_Size = 0;
    cout << "已清空" << endl;
    system("pause");
    system("cls");
}

int main()
{
    struct AddressBooks abs; //创建通讯录
    abs.m_Size = 0;          //初始化通讯录人数
    int select = 0;
    while (true)
    {
        showMenu();
        cout << "请选择要进行的操作" << endl;
        cin >> select;
        switch (select)
        {
        case 1: // 1、添加联系人
            addPerson(&abs);
            break;
        case 2: // 2、显示联系人
            showPerson(&abs);
            break;
        case 3: // 3、删除联系人
            deletePerson(&abs);
            break;
        case 4: // 4、查找联系人
            findPerson(&abs);
            break;
        case 5: // 5、修改联系人
            modifyPerson(&abs);
            break;
        case 6: // 6、清空联系人
            cleanPerson(&abs);
            break;
        case 0: // 0、退出通讯录
            cout << "欢迎下次使用" << endl;
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
