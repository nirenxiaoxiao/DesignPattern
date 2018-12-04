#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
//#include <iter>

using namespace std;


int testlambda2()
{
	vector<int> v;
	for(int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}

	deque<int> dq;
	transform(v.begin(), v.end(), front_inserter(dq), [](int n)
	{
		return n*n*n;
	}
	);
	for_each(dq.begin(), dq.end(),[](int n){
		cout << n <<endl;
	}
	);
	return 0;
}

int testlambda()
{
	int i, sum = 0;

	std::vector<int> vct;

	for(i=1; i <= 100; i++)
	{
		vct.push_back(i);
	}

	for_each(vct.begin(), vct.end(), [&sum](int n) 
	{ 
		sum+=n ;
	}
	);
	cout << sum <<endl;
	return 0;
}

class Foo
{

public:
	Foo()
	{
		_index = ++_count;
	}
	~Foo()
	{
		--_count;
		cout << "~Foo: "<<_index <<endl;
	}
	int _index;
	static int _count;
};

int Foo::_count = 0;


int testmove()
{
	std::vector<Foo> v1(5), v2;
	auto it = std::next(v1.begin(), 5);
	std::move(v1.begin(), it, std::back_inserter(v2));
	for_each(v2.begin(), v2.end(),[](const Foo& n){
		cout << n._index <<endl;
	});
	v1.erase(v1.begin(), it);
	return 0;
}

int testmove2()
{
	std::vector<Foo> v1(5), v2;
	auto it = std::next(v1.begin(), 5);
	swap(v1, v2);
	for_each(v2.begin(), v2.end(),[](const Foo& n){
		cout << n._index <<endl;
	});

	return 0;
}

//template<typename T, std::size_t N>

int testmobike()
{
	double v[]={90.34,
		58.82,
		112.67,
		49.76,
		54.84,
		72.86,
		21.18,
		122.57,
		104.80,
		95.51
	};

	double v2[]= {
		115.80
		,12.51
		,42.14
		,155.45
		,98.70
		,100.95
	};
	double sum = 0;
	vector<double> vvmobike(&v[0], &v[sizeof(v)/sizeof(v[0])]);
	for_each(vvmobike.begin(), vvmobike.end(), [&sum](double n)
	{
		sum += n;
	});
	cout << "sum = " <<sum <<endl;

	sum = 0;
	vector<double> vvmobike2(&v2[0], &v2[sizeof(v2)/sizeof(v2[0])]);
	for_each(vvmobike2.begin(), vvmobike2.end(), [&sum](double n)
	{
		sum += n;
	});
	cout << "sum2 = " <<sum <<endl;
	return static_cast<int>(sum);
}

int test_make_shared()
{
	shared_ptr<Foo> ptr = make_shared<Foo>();
	cout << ptr->_count << ' ' << ptr->_index<<endl;
	return 0;
}

int main()
{
	test_make_shared();
	cout <<Foo::_count <<endl;
	testmobike();
	testmove();
	testmove2();
	testlambda2();
	typedef vector<shared_ptr<int> > vs;
	vs v(10);

	int i = 0;

	for (vs::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		(*iter).reset( new int(i));
		i++;
		cout << *(*iter) <<endl;
	}

	testlambda();

	return 0;
}