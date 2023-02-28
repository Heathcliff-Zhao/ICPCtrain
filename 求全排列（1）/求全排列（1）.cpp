// 求全排列（1）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include<iostream>
//using namespace std;
//int ans[11][4000000][11], nowrow = 0;
//int fact[10] = { 1,2,6,24,120,720,5040,40320,362880,3628800 };
//void per(int k)
//{
//	if (k == 1)
//		ans[1][0][0] = 1;
//	else
//	{
//		per(k - 1);
//		int row = 0;
//		for (int i = 0; i < fact[k - 2]; i++)
//			for (int column = 0; column < k; column++)
//			{
//				for (int j = 0; j < column; j++)
//					ans[k][row][j] = ans[k - 1][i][j];
//				for (int j = k; j >= column; j--)
//					ans[k][row][j] = ans[k - 1][i][j - 1];
//				ans[k][row][column] = k;
//				row++;
//			}
//	}
//}
//int main()
//{
//	int n;
//	while (cin >> n && n)
//	{
//		per(n);
//		for (int i = 0; i < fact[n - 1]; i++)
//		{
//			for (int j = 0; j < n; j++)
//				cout << ans[n][i][j] << ' ';
//			cout << endl;
//		}
//	}
//}

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<cstring>
using namespace std;
int n, num[10], vis[10];
void dfs(int step)
{
	if (step == n + 1)
	{
		for (int i = 1; i <= n; i++)
			printf("%d ", num[i]);
		printf("\n");
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0)
		{
			num[step] = i;
			vis[i] = 1;
			dfs(step + 1);
			vis[i] = 0;
		}
	}
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		memset(vis, 0, sizeof(vis));
		dfs(1);
	}
}