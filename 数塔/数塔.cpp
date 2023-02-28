// 数塔.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
	int t, i, j;
	int n, a[101][101];
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= i; j++)
				cin >> a[i][j];
		for (i = n; i >= 2; i--)
			for (j = 1; j < i; j++)
				a[i - 1][j] += a[i][j] > a[i][j + 1] ? a[i][j] : a[i][j + 1];
		cout << a[1][1] << endl;
	}
	return 0;
}


