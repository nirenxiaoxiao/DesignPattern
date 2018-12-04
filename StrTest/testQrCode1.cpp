#include <stdio.h>
#include <assert.h>
int GetTheNumber(int n)
{
	int nCnt = 0 ;
	int theNumber = 1;
	while (nCnt < n)
	{
		theNumber++;
		if (theNumber % 2 == 0 || theNumber %3 == 0)
		{
			nCnt++;
		}
		
	}
	return theNumber;
}
int main3(int argc, const char* argv[])
{
	int nRes = GetTheNumber(2333);
	assert( 2 == GetTheNumber(1));
	assert( 4 == GetTheNumber(3));
	assert( 8 == GetTheNumber(5));
	assert( 15 == GetTheNumber(10));
	printf("%d", nRes);
	return 0;
}