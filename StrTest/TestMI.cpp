#include <iostream>
using namespace std;


class  A
{
public:
	A()
	{
		cout <<"A cons"<<endl;
	}
	virtual void f()
	{
		cout << "A::f" <<endl;
	}
protected:
private:
};


class  B : public A
{
public:
	B()
	{
		cout <<"B cons"<<endl;
	}
	void f()
	{
		cout << "B::f" <<endl;
	}
protected:
private:
};


class  C: public B
{
public:
	C()
	{
		cout <<"C cons"<<endl;
	}
	void f()
	{
		cout << "C::f" <<endl;
	}
protected:
private:
};


int main3()
{
	B* obj= new C;

	obj->f();
	return 0;
}