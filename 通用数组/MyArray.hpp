//通用的数组类
#pragma once
#include<iostream> 
using namespace std;

template<typename T>
class MyArray
{
public:
	MyArray(int capacity)//有参构造 参数：数组容量
	{
		cout << "有参构造"<<endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->m_pAddress = new T[this->m_Capacity];
	}
	//拷贝构造
	MyArray(const MyArray& arr)
	{
		cout << "拷贝构造" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->m_pAddress=arr.m_pAdddress

		//深拷贝
		this->m_pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->m_pAddress[i] = arr.m_pAddress[i];
		}
	}
	//operator=重载解决自定义类型的=赋值
	MyArray& operator=(const MyArray& arr)
	{
		cout << "operator=重载" << endl;
		//先判断原来堆区是否有数据
		if (this->m_pAddress != NULL)
		{
			delete[] this->m_pAddress;
			this->m_pAddress = NULL;
			this->m_Size = 0;
			this->m_Capacity = 0;
		}
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->m_pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->m_pAddress[i] = arr.m_pAddress[i];
		}
		return *this;
	}

	//尾插法
	void insertLast(const T& val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			cout << "error" << endl;
			return;
		}
		this->m_pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	//尾删法
	void deleteLast()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}
	//通过下标访问
	T& operator[](int index)
	{
		return this->m_pAddress[index];
	}
	//
	int getSize()
	{
		return this->m_Size;
	}
	int getCapacity()
	{
		return this->m_Capacity;
	}

	~MyArray()
	{
		cout << "析构函数" << endl;
		if (this->m_pAddress != NULL)
		{
			delete[] this->m_pAddress;
			this->m_pAddress = NULL;
		}
	}

private:
	T* m_pAddress;//元素指向堆区开辟的真实数组
	int m_Capacity;//数组容量
	int m_Size;//数组大小
};