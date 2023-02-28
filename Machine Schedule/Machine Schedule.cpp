// Machine Schedule.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;
int Map[105][105];
int linker[105];
int n, m, k;
int visit[105];
int dfs(int x)
{
	for (int i = 0; i < m; i++)
		if (Map[x][i] && !visit[i])
		{
			visit[i] = 1;
			if (linker[i] == -1 || dfs(linker[i]))
			{
				linker[i] = x;
				return 1;
			}
		}
	return 0;
}
int main()
{
	while (cin >> n, n)
	{
		memset(Map, 0, sizeof(Map));
		cin >> m >> k;
		int t = k, i, x, y, ans = 0;
		while (t--)
		{
			cin >> i >> x >> y;
			if(x>0&&y>0)
				Map[x][y] = 1;
		}
		memset(linker, -1, sizeof(linker));
		for (int i = 0; i < n; i++)
		{
			memset(visit, 0, sizeof(visit));
			if (dfs(i))
				ans++;
		}
		cout << ans << endl;
	}
}
