//��������:ʵ��һ��ͨ�õ������࣬Ҫ������:
//�����Զ��������������Լ��Զ����������͵����ݽ��д洢
//���������е����ݴ洢������
//�����캯���п��Դ������������
//���ṩ��Ӧ�Ŀ������캯���Լ�operator = ��ֹǳ��������
//���ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
//������ͨ���±�ķ�ʽ���������е�Ԫ��
//�����Ի�ȡ�����е�ǰԪ�ظ��������������

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

//�����Զ�����������
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