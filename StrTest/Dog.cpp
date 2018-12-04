#include "Dog.h"
#include <map>
using std::map;
int mainDog()
{
	DogHouse fidos(new Dog("Fido"), "FidoHouse");

	cout<<fidos <<endl;

	DogHouse fidos2 = fidos;

	fidos2.getDog()->rename("Spot");
	fidos2.renameHouse("Spothouse");
	cout<<fidos2 <<endl;

	fidos = fidos2; // assignment;

	cout <<fidos <<endl;

	fidos.getDog()->rename("Max");
	fidos2.renameHouse("Maxhouse");

	cout << endl;
	return 0;
}

int mainNumber()
{
	Number a(47), b(11), c(10);

	a + b;
	a + 1;
//	1 + a;
	a - b;
	a - 1;
	1 - a;
	(a + b - c).print(cout);

	cout <<a <<endl;
	return 0;
}

int mainApple()
{
	mainNumber();
	Apple a;
	//f(a);

	eat(a);

	if(a)
	{

	}
	return 0;
}
int count = 0;
void out_of_memory()
{
	cerr<< "memory exhausted after " <<count << " allocation!" <<endl;
	exit(1);
}
void* operator new(size_t sz)
{
	printf("operator new : %d Bytes\n", sz);
	void* m = malloc(sz);
	if (!m)
	{
		puts("out of memory");
	}
	return m;
}

void* operator new[](size_t sz)
{
	printf("operator new[] : %d Bytes\n", sz);
	void* m = malloc(sz);
	if (!m)
	{
		puts("out of memory");
	}
	return m;
}


void operator delete[](void* m )
{
	puts("operater delete ");
	free(m);
}

class S
{
	int i[100];
public:
	S()
	{
		puts("S::S()");
	}
	virtual ~S()
	{
		puts("S::~S()");
	}
	virtual int foo()
	{
		puts("foo");
		return 0;
	}
	virtual int foo2()
	{
		puts("foo2");
		return 0;
	}
};
int mainNew()
{

	puts("Creating & destroying an int");
	int *p = new int(44);


	delete p;

	puts("Creating & destroy an s");

	S* s = new S;
	delete s;

	puts("Creating & destroying S[3]");


	S* sarr = new S[3];

	delete []sarr;
	//set_new_handler(out_of_memory);
	
	return 0;
}


//derived
int main()
{
	string s(" hello ");
	Derived1 d1;
	int x = d1.f();
	d1.f(s);
	Derived2 d2;
	x = d2.f();

//	d2.f(s);

	Derived3 d3;
	d3.f();
//	x = d3.f();

	Derived4 d4;

	x = d4.f(1);


	Goldfish bob;
	bob.eat();
	bob.sleep();
	bob.sleep(0);
	bob.wakeup();

	Wind flute;
	tune(flute);

	std::map<int,int> Container;
	for each(const auto& i in Container)
	{
		cout << i.second;
	}
}