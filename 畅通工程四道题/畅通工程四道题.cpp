// 畅通工程四道题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include <iostream>
//using namespace std;
//int bin[1002];
//int findx(int x)
//{
//    int r = x;
//	while (bin[r]!=r)
//		r = bin[r];
//	return r;
//}
//void merge(int x, int y)
//{
//	int fx, fy;
//	fx = findx(x);
//	fy = findx(y);
//	if (fx != fy)
//		bin[fx] = y;
//}
//int main()
//{
//	int n, m, i, x, y, count;
//	while (cin >> n,n)
//	{
//		for (i = 1; i <= n; i++)
//			bin[i] = i;
//		for (cin >> m; m > 0; m--)
//		{
//			cin >> x >> y;
//			merge(x, y);
//		}
//		for (count = -1, i = 1; i <= n; i++)
//			if (bin[i] == i)
//				count++;
//		cout << count << endl;
//	}
//	return 0;
//}

#include<cstring>
#include<iostream>
#define inf 0x7fffffff
using namespace std;
int Map[205][205], Dist[205], visit[205], n, m;
int getmin(int arr[])
{
	int Min = inf, ind = 0;
	for (int i = 0; i < 205; i++)
		if (Min > arr[i] && !visit[i])
		{
			Min = arr[i];
			ind = i;
		}
	visit[ind] = 1;
	return ind;
}
void Dijkstra()
{
	for (int i = 0; i < n; i++)
	{
		int fro = getmin(Dist);
		for (int j = 0; j < 205; j++)
			if (!visit[j] && Map[fro][j] != inf)
				Dist[j] = min(Dist[j], Dist[fro] + Map[fro][j]);
	}
}
int main()
{
	while (cin >> n >> m)
	{
		for (int i = 0; i < 205; i++)
		{
			Dist[i] = inf;
			for (int j = 0; j < 205; j++)
				Map[i][j] = inf;
		}
		memset(visit, 0, sizeof(visit));
		while (m--)
		{
			int a, b, s;
			cin >> a >> b >> s;
			Map[a][b] = min(Map[a][b], s);
			Map[b][a] = Map[a][b];
		}
		int start, end;
		cin >> start >> end;
		Dist[start] = 0;
		Dijkstra();
		if (Dist[end] == inf)
			cout << -1 << endl;
		else
			cout << Dist[end] << endl;
	}
}

//#define _CRT_SECURE_NO_WARNINGS
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int father[105];
//struct mess
//{
//	int b;
//	int e;
//	int v;
//}road[10005];
//int cmp(mess a, mess c)
//{
//	return a.v < c.v;
//}
//int find(int a)
//{
//	if (a == father[a])
//		return a;
//	else
//		return find(father[a]);
//}
//bool merge(int a, int c)
//{
//	int fx = find(a);
//	int fy = find(c);
//	if (fx != fy)
//	{
//		father[fy] = fx;
//		return 1;
//	}
//	return 0;
//}
//int main()
//{
//	int n, m, sum;
//	while (scanf("%d", &n), n)
//	{
//		m = n * (n - 1) / 2;
//		for (int i = 0; i < 105; i++)
//			father[i] = i;
//		for (int i = 0; i < m; i++)
//			scanf("%d%d%d", &road[i].b, &road[i].e, &road[i].v);
//		sort(road, road + m, cmp);
//		sum = 0;
//		for (int i = 0; i < m; i++)
//			if (merge(road[i].b, road[i].e))
//				sum += road[i].v;
//		printf("%d\n", sum);
//	}
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#define inf 0x7fffffff
//using namespace std;
//const int M = 110;
//int n, m, G[M][M];
//int d[M];
//bool visit[M];
//int algori() 
//{
//    for (int i = 0; i < M; i++)
//        d[i] = inf;
//    d[1] = 0;
//    int ans = 0;
//    for (int i = 1; i <= m; i++) 
//    {
//        int temp = -1, Min = inf;
//        for (int j = 1; j <= m; j++) 
//            if (visit[j] == 0 && d[j] < Min) 
//            {
//                temp = j;
//                Min = d[j];
//            }
//        if (temp == -1) 
//            return -1;
//        visit[temp] = 1;
//        ans += d[temp];
//        for (int v = 1; v <= m; v++) 
//            if (visit[v] == 0 && G[temp][v] != inf && G[temp][v] < d[v]) 
//                d[v] = G[temp][v];
//    }
//    return ans;
//}
//int main() 
//{
//    int start, end, price;
//    while (scanf("%d%d", &n, &m), n != 0) 
//    {
//        fill(G[0], G[0] + M * M, inf);
//        for (int i = 0; i < n; i++) 
//        {
//            scanf("%d%d%d", &start, &end, &price);
//            G[start][end] = G[end][start] = price;
//        }
//        int res = algori();
//        if (res != -1) 
//            printf("%d\n", res);
//        else 
//            printf("?\n");
//        fill(visit, visit + M, false);
//        for (int i = 0; i < M; i++)
//            visit[i] = 0;
//    }
//    return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <algorithm>
//#include <string.h>
//#include<iostream>
//using namespace std;
//int father[105];
//struct node
//{
//    int a;
//    int b;
//    int price;
//}c[5000];
//bool cmp(node x, node y)
//{
//    return x.price < y.price;
//}
//int find(int x)
//{
//    if (father[x] != x)
//        father[x] = find(father[x]);
//    return father[x];
//}
//int main()
//{
//    int n, x;
//    while (cin>>n && n)
//    {
//        memset(&c, 0, sizeof(&c));
//        for (int i = 1; i <= n; i++)
//            father[i] = i;
//        n = n * (n - 1) / 2;
//        for (int i = 0; i < n; i++)
//        {
//            cin >> c[i].a >> c[i].b >> c[i].price >> x;
//            if (x == 1)
//                c[i].price = 0;
//        }
//        sort(c, c + n, cmp);
//        int price = 0;
//        for (int i = 0; i < n; i++)
//        {
//            int x = find(c[i].a);
//            int y = find(c[i].b);
//            if (x != y)
//                father[x] = y, price += c[i].price;
//        }
//        printf("%d\n", price);
//    }
//    return 0;
//}


