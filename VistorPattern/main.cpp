#include <iostream>
#include <string>
#include "ToBeVisted.h"
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

class Bee:public Vistor
{

public:
	
	void visitGladiolus(Flower* f)
	{
		StringVal sval;
		sval.visitGladiolus(f);
		cout << " Bee and " << string(sval)<<endl;
	}
	void visitRenuculus(Flower* f) 
	{
		StringVal sval;
		sval.visitRenuculus(f);
		cout << " Bee and " << string(sval)<<endl;
	}	
	void visitCrysanthemum(Flower* f)
	{
		StringVal sval;
		sval.visitCrysanthemum(f);
		cout << " Bee and " << string(sval)<<endl;
	}

};

struct FlowerGen
{
	Flower* operator()()
	{
		switch(rand() % 3)
		{
		default:
		case 0:
			return new Gladioluse;
		case 1:
			return new Renuculus;
		case 2:
			return new Crysanthemum;
		}
	}
};

int main()
{
	srand(time(0));
	vector<Flower*> v(10);
	generate(v.begin(), v.end(), FlowerGen());

	StringVal sval;
	Bee bee;
	for each ( auto& item in v)
	{
		item->accept(sval);
		cout << string(sval) <<endl;

		item->accept(bee);
	}
	return 0;
}