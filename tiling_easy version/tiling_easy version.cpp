// tiling_easy version.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<cmath>
using namespace std;
int func(int t)
{
	if (t == 1)
		return 1;
	else
		return 2 * func(t - 1) + pow(-1, t);
}
int main()
{
	int n, t;
	cin >> n;
	while (n--)
	{
		cin >> t;
		cout << func(t) << endl;
	}
}