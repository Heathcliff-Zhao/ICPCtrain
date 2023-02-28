// A strange lift.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<algorithm> 
#include<cstring>
using namespace std;
int n, a, b;
int dat[201], visit[201];
void dfs(int p, int q)
{
	if (q == visit[b]) 
	if (p == b)
		visit[b] = min(visit[b], q);
	if (p + dat[p] <= n && visit[p + dat[p]] > q + 1)
	{
		visit[p + dat[p]] = q + 1;
		dfs(p + dat[p], q + 1);
	}
	if (p - dat[p] > 0 && visit[p - dat[p]] > q + 1)
	{
		visit[p - dat[p]] = q + 1;
		dfs(p - dat[p], q + 1);
	}
}
int main()
{
	while (cin>>n && n)
	{
		cin >> a >> b;
		for (int i = 1; i <= n; i++)
		{
			cin >> dat[i];
			visit[i] = 9999;
		}
		visit[a] = 0;
		dfs(a, 0);
		if (visit[b] != 9999)
			cout << visit[b] << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}