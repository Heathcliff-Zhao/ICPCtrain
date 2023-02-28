// Air Raid.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<cstring>
using namespace std;
int n, m, ans, G[350][350], match[350], visit[350];
int dfs(int x)
{
	for (int i = 1; i <= n; i++)
	{
		int y = G[x][i];
		if (y && !visit[i])
		{
			visit[i] = 1;
			if (match[i] == -1 || dfs(match[i]))
			{
				match[i] = x;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int t, u, v;
	cin >> t;
	while (t--)
	{
		ans = 0;
		memset(match, -1, sizeof(match));
		memset(G, 0, sizeof(G));
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v;
			G[u][v] = 1;
		}
		for (int i = 1; i <= n; i++)
		{
			memset(visit, 0, sizeof(visit));
			ans += dfs(i);
		}
		cout << n - ans << endl;
	}
	return 0;
}
