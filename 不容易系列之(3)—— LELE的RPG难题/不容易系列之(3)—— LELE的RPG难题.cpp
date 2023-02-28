// 不容易系列之(3)—— LELE的RPG难题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
unsigned long long int a[100000] = { 0,3,6,6 };
int main()
{
	int n;
	for (int i = 4; i < 53; i++)
		a[i] = a[i - 1] + 2 * a[i - 2];
	while (cin >> n)
		cout << a[n] << endl;
}