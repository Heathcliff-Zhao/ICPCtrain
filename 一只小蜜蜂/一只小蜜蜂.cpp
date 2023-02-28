// 一只小蜜蜂.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
long long int ans[100000] = { 1,1,2 };
int main()
{
	int n, a, b, i;
	cin >> n;
	int* p = new int[n];
	while (n--)
	{
		cin >> a >> b;
		for (i = 2; i < b - a + 1; i++)
			ans[i] = ans[i - 1] + ans[i - 2];
		cout << ans[i-1] << endl;
	}
}
