// 新定义斐波那契数列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int ans[] = { 1,2,0,2,2,1,0,1 };
	int n, i = 0;
	string* p = new string[10000];
	while (cin >> n)
	{
		if (ans[n % 8])
			p[i++] = "no";
		else
			p[i++] = "yes";
	}
	for (int j = 0; j < i; j++)
		cout << p[j] << endl;
	delete[]p;
}
