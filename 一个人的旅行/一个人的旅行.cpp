// 一个人的旅行.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<cmath>
#include <stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

#define inf 0x7FFFFFFF
#define M 1005
int Map[M][M], Dist[M], visit[M];
int main()
{
	int road, numofnear, numofwant, a, b, dis;
	while (cin >> road >> numofnear >> numofwant)
	{
		int start = 0, target = 1002, next = start, Min;
		for (int i = 0; i < M; i++)
		{
			Dist[i] = inf;
			visit[i] = 0;
			for (int j = 0; j < M; j++)
				Map[i][j] = inf;
		}
		while (road--)
		{
			cin >> a >> b >> dis;
			Map[a][b] = min(Map[a][b], dis);
			Map[b][a] = min(Map[b][a], dis);
		}
		while (numofnear--)
		{
			cin >> a;
			Map[start][a] = 0;
			Map[a][start] = 0;
		}
		while (numofwant--)
		{
			cin >> a;
			Map[target][a] = 0;
			Map[a][target] = 0;
		}
		while (start != target)
		{
			for (int i = 1; i < 1005; i++)
			{
				Min = inf;
				if (!visit[i] && Map[start][i] != inf)
				{
					Dist[i] = min(Dist[i], Map[start][i] + Dist[next]);
					next = i;
				}
				Min = min(Dist[i], Min);
			}
			if (Min == inf)
				break;
			start = next;
			visit[next] = 1;
		}
		cout << Dist[target] << endl;
	}
	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#define inf 0x3f3f3f3f
//#define M 1005
//using namespace std;
//int road, numofnear, numofwant, n;
//int Map[M][M], dist[M], visit[M];
//int near[M], want[M];
//int main() 
//{
//    while (scanf("%d%d%d", &road, &numofnear, &numofwant) != EOF)
//    {
//        int ans = inf;
//        int a, b, t;
//        n = 0;
//        memset(Map, inf, sizeof(Map));
//        for (int i = 0; i < road; i++)
//        {
//            scanf("%d%d%d", &a, &b, &t);
//            if (n < max(a, b))
//                n = max(a, b);
//            Map[a][b] = min(Map[a][b], t);
//            Map[b][a] = Map[a][b];
//        }
//        for (int i = 0; i <= n; i++)
//            Map[i][i] = 0;
//        for (int i = 0; i < numofnear; i++)
//            scanf("%d", &near[i]);
//        for (int i = 0; i < numofwant; i++)
//            scanf("%d", &want[i]);
//        for (int i = 0; i < numofnear; i++)
//        {
//            Map[near[i]][0] = 0;
//            Map[0][near[i]] = 0;
//        }
//        int Min, p;
//        memset(visit, 0, sizeof(visit));
//        for (int i = 0; i <= n; i++)
//            dist[i] = Map[0][i];
//        for (int k = 0; k <= n; k++)
//        {
//            Min = inf;
//            for (int next = 1; next <= n; next++)
//                if (!visit[next] && dist[next] < Min)
//                {
//                    p = next;
//                    Min = dist[next];
//                }
//            visit[p] = 1;
//            for (int i = 1; i <= n; i++)
//                dist[i] = min(dist[p] + Map[p][i], dist[i]);
//        }
//        for (int j = 0; j < numofwant; j++)
//            ans = min(dist[want[j]], ans);
//        printf("%d\n", ans);
//    }
//    return 0;
//}