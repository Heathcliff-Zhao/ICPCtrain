// 阿牛的EOF牛肉串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
using namespace std;
#include <cmath>

int main()
{
	int n;
	long long a[50] = { 0,3,8 };
	for (int i = 3; i < 50; i++)
		a[i] = 2 * (a[i - 1] + a[i - 2]);
	while (cin >> n)
		cout << a[n] << endl;
	return 0;
}