#pragma once

class Flower;

class Vistor
{
public:
	virtual void visitGladiolus(Flower* ) = 0;
	virtual void visitRenuculus(Flower* ) = 0;
	virtual void visitCrysanthemum(Flower* ) = 0;
	virtual ~Vistor(){};
};

class Flower
{
public:
	virtual void accept(Vistor &) = 0;
	virtual  ~Flower() {}
};

class Gladioluse:public Flower
{
	virtual void accept(Vistor& v)
	{
		v.visitGladiolus(this);
	}
};


class Renuculus:public Flower
{
	virtual void accept(Vistor& v)
	{
		v.visitRenuculus(this);
	}
};


class Crysanthemum:public Flower
{
	virtual void accept(Vistor& v)
	{
		v.visitCrysanthemum(this);
	}
};
#include <string>
using std::string;
class StringVal:public Vistor
{
	string s;
public:
	operator const string&(){ return s;}


	void visitGladiolus(Flower* )
	{
		s = "Gladiolus";
	}
	void visitRenuculus(Flower* ) 
	{
		s = "Renuculus";
	}	
	void visitCrysanthemum(Flower* )
	{
		s = "Crysanthemum";
	}

};

