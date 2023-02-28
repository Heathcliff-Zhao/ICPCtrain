// 多个数的最小公倍数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
using namespace std;
int gcd(int x, int y)
{
	while (y ^= x ^= y ^= x %= y);
	return x;
}
int main()
{
	int n, a, b, t;
	cin >> n;
	while (n--)
	{
		cin >> t >> a;
		t--;
		while (t--)
		{
			cin >> b;
			a = a / gcd(a, b) * b;
		}
		cout << a << endl;
	}
}