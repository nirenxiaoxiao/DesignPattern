#pragma once
#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::map;

class Shape
{
public:
	virtual ~Shape();

	virtual int Draw() = 0;

};

Shape::~Shape()
{
	cout << __FUNCTION__ <<endl;
}

class ShapeFactory
{
public:
	virtual ~ShapeFactory() ;
	virtual Shape* Create() = 0;
	static map<string, ShapeFactory*> factories;
	
public:
	friend class ShapeFactoryInitializer;
	class BadShapeCreation
	{
	public :
		BadShapeCreation(string type)
		{
			cout << "logic error " <<type <<endl;
		}
	};

	static Shape* CreateShape(const string& id) throw(BadShapeCreation)
	{
		if (factories.find(id) != factories.end())
		{
			return factories[id]->Create();
		}
		else
			throw BadShapeCreation(id);
	}
};

ShapeFactory::~ShapeFactory()
{
	cout << __FUNCTION__ <<endl;
}
map<string, ShapeFactory*> ShapeFactory::factories;

class Circle:public Shape
{
public:
	Circle();
	~Circle();
	int Draw();
	class Factory:public ShapeFactory
	{
		virtual Shape* Create()
		{
			return new Circle;
		}
		friend class ShapeFactoryInitializer;
	};
};

class Square:public Shape
{
public:
	Square();
	~Square();
	int Draw();
	class Factory:public ShapeFactory
	{
		virtual Shape* Create()
		{
			return new Square;
		}
		friend class ShapeFactoryInitializer;
	};
};



class ShapeFactoryInitializer
{
	static ShapeFactoryInitializer si;
	ShapeFactoryInitializer()
	{
		ShapeFactory::factories["Circle"] = new Circle::Factory;
		ShapeFactory::factories["Square"] = new Square::Factory;
	}
	~ShapeFactoryInitializer()
	{
		for each(const auto& factory in ShapeFactory::factories )
		{
			delete factory.second;
		}
	}
};

ShapeFactoryInitializer ShapeFactoryInitializer::si;

Circle::Circle()
{

}


Circle::~Circle()
{

}


int Circle::Draw()
{
	cout << __FUNCTION__<<endl;
	return 0;
}


Square::Square()
{

}


Square::~Square()
{

}


int Square::Draw()
{
	cout << __FUNCTION__<<endl;
	return 0;
}