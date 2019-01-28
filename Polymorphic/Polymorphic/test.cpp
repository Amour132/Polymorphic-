#include <iostream>
using namespace std;

class Person
{
public:
	//构造函数不能是虚函数，因为虚表指针是在初始化列表才初始化的
	//析构函数最好写成虚函数。
	//内联函数也无法成为虚函数，因为没有地址。
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
	int _b;  //成员变量不仅仅只有b还有一个虚标指针
};

class Abstract
{
public:
	virtual void Fun() = 0  // 后面跟=0 就是纯虚函数，实现了抽象类
	{                       //特点：无法实例化出对象，只有派生类重写虚函数之后才可以实例化
		cout << "I am a abstract class" << endl;
	}
};

void Test(Person& p)
{
	p.Play_sea_rover();
}

///////////////////////////////////测试多继承关系
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
	{}                     //final 修饰的基类虚函数无法被派生类重写
};
class Dz : public Car
{
public:
	virtual void Drive() override
	{                    //override修饰的基类虚函数派生类必须完成重写，否则会报错
		cout << "Dz" << endl;
	}
};


//协变 :虚函数重写的例外，重写虚函数的返回值可以不同但必须分别是基类和派生类的指针或引用
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