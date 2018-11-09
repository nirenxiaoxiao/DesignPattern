#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
using namespace std;

void RandGen(vector<int>& vec, int cnt )
{
	vec.clear();
	vec.reserve(cnt);
	for (int i = 0; i < cnt ; ++i)
	{
		vec.push_back(rand()%1000);
	}
	for each(auto& it in vec)
	{
		cout << it <<" ";
	}

}


int main()
{
	vector<int> vec;
	RandGen(vec, 100);
	cout << endl;

	QSort(vec, 0, 99);

	for each( auto& it in vec)
	{
		cout << it <<" ";
	}
	cout<<endl;

	RandGen(vec, 30);
	cout << "begin Merge" <<endl;
	
	vector<int> res ;
	res.reserve(vec.capacity());
	res = vec;
	MergeSort(vec, 0, 29, res);

	cout <<"after sout" <<endl;
	for each(auto& it in res)
	{
		cout <<it << " ";
	}
	cout <<endl;
}