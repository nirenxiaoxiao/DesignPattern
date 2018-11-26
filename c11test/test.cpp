#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;

// [ capture list] (params list) mutable exception-> return type { function body }
/*
捕获形式	说明
[]	不捕获任何外部变量
[变量名, …]	默认以值得形式捕获指定的多个外部变量（用逗号分隔），如果引用捕获，需要显示声明（使用&说明符）
[this]	以值的形式捕获this指针
[=]	以值的形式捕获所有外部变量
[&]	以引用形式捕获所有外部变量
[=, &x]	变量x以引用形式捕获，其余变量以传值形式捕获
[&, x]	变量x以值的形式捕获，其余变量以引用形式捕获
*/
void TestLambda()
{

	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(7);
	vec.push_back(3);
	vec.push_back(5);
	int sum = 0;
	for_each( vec.begin(), vec.end(), [&sum](int a){
		sum += a;
	});

	cout << "Sum is " << sum <<endl;
	sum = 0;


	sort(vec.begin(), vec.end(), [](int a, int b)  -> bool { return a < b; });   // Lambda表达式

	for_each( vec.begin(), vec.end(), [](int a)->void {
		cout << a <<endl; });

	auto func = [sum] { cout << sum <<endl;}; 

	func();
}


int main()
{
	TestLambda();
	return 0;
}