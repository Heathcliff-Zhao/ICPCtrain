// 过山车.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int map[502][502];
int visit[502];
int drew[502];
int num, M;
int me(int x)
{
	for (int i = 1; i <= M; i++)
		if (map[x][i] && !visit[i])
		{
			visit[i] = 1; 
			if (drew[i] == -1 || me(drew[i])) 
			{
				drew[i] = x;  
				return 1;
			}
		}
	return 0;
}
int main()
{
	int partner, girl, boy;
	while (cin >> partner && partner)
	{
		cin >> num >> M;
		memset(drew, -1, sizeof(drew));
		memset(map, 0, sizeof(map));
		for (int i = 0; i < partner; i++)
		{
			cin >> girl >> boy;
			map[girl][boy] = 1; 
		}
		int ans = 0;
		for (int i = 1; i <= num; i++)
		{
			memset(visit, 0, sizeof(visit)); 
			if (me(i))
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}