#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;

// [ capture list] (params list) mutable exception-> return type { function body }
/*
������ʽ	˵��
[]	�������κ��ⲿ����
[������, ��]	Ĭ����ֵ����ʽ����ָ���Ķ���ⲿ�������ö��ŷָ�����������ò�����Ҫ��ʾ������ʹ��&˵������
[this]	��ֵ����ʽ����thisָ��
[=]	��ֵ����ʽ���������ⲿ����
[&]	��������ʽ���������ⲿ����
[=, &x]	����x��������ʽ������������Դ�ֵ��ʽ����
[&, x]	����x��ֵ����ʽ�������������������ʽ����
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


	sort(vec.begin(), vec.end(), [](int a, int b)  -> bool { return a < b; });   // Lambda���ʽ

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