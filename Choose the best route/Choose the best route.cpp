// Choose the best route.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <string.h>
int map[1005][1005];
int n;
int Dijkstra(int start, int end)
{
    bool visit[1005];
    int dist[1005];
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i <= n; i++)
        dist[i] = (i == start ? 0 : 1000000);
    for (int i = 0; i <= n; i++)
    {
        int index, Min = 1000000;
        for (int j = 0; j <= n; j++)
            if (!visit[j] && dist[j] < Min)
            {
                Min = dist[j];
                index = j;
            }
        visit[index] = 1;
        if (index == end)
            return dist[index];
        for (int j = 0; j <= n; j++)
            if (!visit[j] && dist[index] + map[index][j] < dist[j])
                dist[j] = dist[index] + map[index][j];
    }
    return -1;
}

int main()
{
    int m, s;
    int i, j, k;
    int p, q, t;
    int w, temp, ans;
    while (scanf("%d%d%d", &n, &m, &s) != EOF)
    {
        ans = 100000000;
        for (i = 0; i < 1005; i++)
            for (j = 0; j < 1005; j++)
            {
                if (i == j)
                    map[i][j] = 0;
                else
                    map[i][j] = 1000000;
            }
        while (m--)
        {
            scanf("%d%d%d", &p, &q, &t);
            if (t < map[p][q])
                map[p][q] = t;
        }
        scanf("%d", &w);
        while (w--)
        {
            scanf("%d", &temp);
            map[0][temp] = 0;
        }
        ans = Dijkstra(0, s);
        if (ans == -1)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}