#pragma once
#include <string>
#include <iostream>

using namespace std;

class Dog
{
	string nm;

public:
	Dog(const string& name):nm(name)
	{
		cout <<"Creating Dog:" <<*this<<endl;
	}

	Dog(const Dog* dp, const string& msg)
	:nm(dp->nm + msg){
		cout<<"Copied dog "<< *this<< " from "
			<<*dp<<endl;

	}
	~Dog()
	{
		cout <<"Deleting Dog" <<*this <<endl;
	}

	void rename(const string& newName)
	{
		nm = newName;
		cout << "Dog renamed to " <<*this <<endl;
	}

	friend ostream&
		operator <<(ostream& os, const Dog& d)
	{
		return os << "[" << d.nm <<"]";
	}
};

class DogHouse
{
	Dog* p;
	string  houseName;
public:
	DogHouse(Dog* dog, const string& house)
	:p(dog), houseName(house)
	{
	}

	DogHouse(const DogHouse& dh)
		:p(new Dog(dh.p, " copy-constructed")),
		houseName(dh.houseName + " copy-construted")
	{

	}

	DogHouse& operator=(const DogHouse& rhd)
	{
		if (&rhd != this)
		{
			p = new Dog(rhd.p, " assigned");
			houseName = rhd.houseName + " assigned";
		}
		return *this;
	}

	void renameHouse(const string& newName)
	{
		houseName = newName;
	}

	Dog* getDog() const{return p;}

	~DogHouse(){ delete p;}

	friend ostream& operator<<(ostream&os, const DogHouse& dh)
	{
		return os<<"[" <<dh.houseName <<"] contains " << *dh.p;
	}
};

class Number
{
	int i;
public:
	Number(int ii = 0) : i(ii)
	{
	}
	const Number operator +(const Number& n) const{
		return Number(i + n.i);
	}

	friend const Number operator-(const Number&, const Number&);
	void print(ostream& os) const
	{
		os << i <<endl;
	}
	const Number& operator++() //prefix
	{
		cout << "++Number\n";
		i++;
		return *this;
	}
	const Number operator++(int) //postfix
	{
		cout << "Number ++\n";
		Number before(i);
		i++;
		return before;
	}
	friend ostream& operator<<(ostream& os, const Number& rhd)
	{
		os << rhd.i;
		return os;
	}
};

const Number operator-(const Number& n1, const Number& n2)
{
	return Number(n1.i - n2.i);
}

class Apple;
class Orange
{
public:
	Orange()
	{

	}
	Orange(Apple);
};

class Pear
{

};
class Apple
{
public:
	operator Orange()const
	{
		Orange b;
		return b;
	}
	operator Pear()const
	{
		Pear c;
		return c;
	}

	operator bool()
	{
		return false;
	}
};

void eat(Orange)
{
	cout << "eat orange" <<endl;
}
void eat(Pear)
{
	cout << "eat pear" <<endl;
}
void f(Orange) {}

class PointerWrapper
{
	int* a;
public:
	PointerWrapper()
	{
		a =new int;
		*a = 10;
	}
	
};

class Base
{
public:
	int f()const
	{
		cout <<__FUNCTION__<<endl;
		return 1;
	}

	int f(string str) const
	{
		cout<<__FUNCTION__<<str<<endl;
		return 0;
	}

	void g(){}
};

class Derived1 : public Base
{
public :
	void g()const
	{

	}
};

class Derived2:public Base{
public:
	// Redefination
	int f()const
	{
		cout <<"Derived2::f()\n";
		return 2;
	}


};

class Derived3: public Base{
public:
	// change return type
	void f()const
	{
		cout <<__FUNCTION__<<endl;
	}
};

class Derived4:public Base{
public:

	// chage argument list

	int f(int n) const{
		cout <<__FUNCTION__<<n <<endl;
		return 4;
	}
};


class Pet
{
public:
	char eat()const
	{
		return 'a';
	}
	int speak()const{
		cout << "hello" <<endl;
		return 2;
	}

	float sleep( ) const
	{
		return 3.0;
	}

	float sleep(int) const{
		return 4.0;
	}
};


class Goldfish:private Pet
{
public:
	using Pet::eat;
	using Pet::sleep;
	void wakeup()
	{
		speak();
	}
};


enum note
{
	middleC, Csharp, Cflat
};

class Instrument
{
public:
	virtual void play(note) const{
		cout << "Instrument play" <<endl;
	}
};

class Wind: public Instrument
{
	void play(note)const
	{
		cout << __FUNCTION__<<endl;
	}
};

void tune(Instrument& i )
{
	i.play(middleC);
}