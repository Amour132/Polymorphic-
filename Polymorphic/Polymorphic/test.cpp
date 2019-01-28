#include <iostream>
using namespace std;

class Person
{
public:
	//���캯���������麯������Ϊ���ָ�����ڳ�ʼ���б�ų�ʼ����
	//�����������д���麯����
	//��������Ҳ�޷���Ϊ�麯������Ϊû�е�ַ��
	/*virtual*/ Person(const string& name = "djh") :_name(name)
	{}
	 virtual void Play_sea_rover()
	{
		cout << "Play_sea_rover need 60 yuan" << endl;
	}
private:
	string _name;
};

class Student:public Person
{
public:
	virtual void Play_sea_rover()
	{
		cout << "Play_sea_rover need 30 yuan" << endl;
	}
private:
	int _b;  //��Ա����������ֻ��b����һ�����ָ��
};

class Abstract
{
public:
	virtual void Fun() = 0  // �����=0 ���Ǵ��麯����ʵ���˳�����
	{                       //�ص㣺�޷�ʵ����������ֻ����������д�麯��֮��ſ���ʵ����
		cout << "I am a abstract class" << endl;
	}
};

void Test(Person& p)
{
	p.Play_sea_rover();
}

///////////////////////////////////���Զ�̳й�ϵ
class A
{
public:
	virtual void Fun1()
	{
		cout << "Fun1-A" << endl;
	}
	virtual void Fun2()
	{
		cout << "Fun2-A" << endl;
	}
	virtual void Fun3()
	{
		cout << "Fun3-A" << endl;
	}
};
class B
{
public:
	virtual void Fun1()
	{
		cout << "Fun1-B" << endl;
	}
	virtual void Fun2()
	{
		cout << "Fun2-B" << endl;
	}
	virtual void Fun3()
	{
		cout << "Fun3-B" << endl;
	}
};
 
class C
{
	virtual void Fun1()
	{
		cout << "Fun1-C" << endl;
	}
	virtual void Fun3()
	{
		cout << "Fun2-C" << endl;
	}
	virtual void Fun4()
	{
		cout << "Fun3-C" << endl;
	}
};

//C++11
class Car
{
public:
	virtual void Drive() //final
	{}                     //final ���εĻ����麯���޷�����������д
};
class Dz : public Car
{
public:
	virtual void Drive() override
	{                    //override���εĻ����麯����������������д������ᱨ��
		cout << "Dz" << endl;
	}
};


//Э�� :�麯����д�����⣬��д�麯���ķ���ֵ���Բ�ͬ������ֱ��ǻ�����������ָ�������
class a
{};

class b : public a
{};

class P
{
public:
	virtual a* f()
	{
		return new a;
	}
};

class S : public P
{
	virtual b* f()
	{
		return new b;
	}
};


int main()
{
	/*A a;
	B b;
	C c;*/
	/*Person p;
	Student s;
	Test(s);
	Test(p);*/
	Dz d;
	d.Drive();
	return 0;
}