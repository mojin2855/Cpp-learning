#include<iostream>
using namespace std;
#include<string>
class Person
{
public:

	void operator()(string test)
	{
		cout << test << endl;
	}
};

void test()
{
	Person()("函数调用重载");

}
int main()
{
	test();
	system("pause");
}

