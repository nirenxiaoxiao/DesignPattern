#include <stdio.h>
class Base
{
public:
	int CallPack()
	{
		Pack();
		return 0;
	}
	int Pack()
	{
		printf("Base pack %d\n", 1);
		return 0;
	}
};
class Child1:public Base
{
public:
	int Pack()
	{
		printf("Child1 pack %d\n", 11);
		return 0;
	}
};

class Child2:public Base
{
public:
	int Pack()
	{
		printf("Child2 pack %d\n", 22);
		return 0;
	}
};

