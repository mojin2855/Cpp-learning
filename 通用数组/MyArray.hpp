//ͨ�õ�������
#pragma once
#include<iostream> 
using namespace std;

template<typename T>
class MyArray
{
public:
	MyArray(int capacity)//�вι��� ��������������
	{
		cout << "�вι���"<<endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->m_pAddress = new T[this->m_Capacity];
	}
	//��������
	MyArray(const MyArray& arr)
	{
		cout << "��������" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->m_pAddress=arr.m_pAdddress

		//���
		this->m_pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->m_pAddress[i] = arr.m_pAddress[i];
		}
	}
	//operator=���ؽ���Զ������͵�=��ֵ
	MyArray& operator=(const MyArray& arr)
	{
		cout << "operator=����" << endl;
		//���ж�ԭ�������Ƿ�������
		if (this->m_pAddress != NULL)
		{
			delete[] this->m_pAddress;
			this->m_pAddress = NULL;
			this->m_Size = 0;
			this->m_Capacity = 0;
		}
		//���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->m_pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->m_pAddress[i] = arr.m_pAddress[i];
		}
		return *this;
	}

	//β�巨
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
	//βɾ��
	void deleteLast()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}
	//ͨ���±����
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
		cout << "��������" << endl;
		if (this->m_pAddress != NULL)
		{
			delete[] this->m_pAddress;
			this->m_pAddress = NULL;
		}
	}

private:
	T* m_pAddress;//Ԫ��ָ��������ٵ���ʵ����
	int m_Capacity;//��������
	int m_Size;//�����С
};