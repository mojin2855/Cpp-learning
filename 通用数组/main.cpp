//案例描述:实现一个通用的数组类，要求如下:
//·可以对内置数据类型以及自定义数据类型的数据进行存储
//·将数组中的数据存储到堆区
//·构造函数中可以传入数组的容量
//·提供对应的拷贝构造函数以及operator = 防止浅拷贝问题
//·提供尾插法和尾删法对数组中的数据进行增加和删除
//·可以通过下标的方式访问数组中的元素
//·可以获取数组中当前元素个数和数组的容量

#include<iostream>
#include"MyArray.hpp"
#include<string>
using namespace std;

void test01()
{
	/*MyArray<int>ma1(10);
	MyArray<int>ma2(ma1);
	MyArray<int>ma3(100);
	ma3 = ma1;*/
	MyArray<int>arr(5);
	for (int i = 0; i < 5; i++)
	{
		arr.insertLast(i);
	}
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
	cout << arr.getSize() << endl;
	cout << arr.getCapacity() << endl;
	arr.deleteLast();
	cout << arr.getSize() << endl;
	cout << arr.getCapacity() << endl;
}

//测试自定义数据类型
class Person
{
public:
	Person(){}
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void test02()
{
	MyArray<Person>arr(10);
	Person p1("zhang3", 10);
	Person p2("zhang4", 10);
	Person p3("zhang5", 10);
	Person p4("zhang6", 10);
	arr.insertLast(p1);
	arr.insertLast(p2);
	arr.insertLast(p3);
	//arr.insertLast(p4);
	arr[3] = p4;
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "name: " << arr[i].m_Name << "   age: " << arr[i].m_Age << endl;

	}
	cout << "arr size:" << arr.getSize() << "   arr capacity: " << arr.getCapacity() << endl;
}
int main()
{
	test02();

	system("pause");
	return 0;
}