// Oil Deposits.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, num;
int vis[105][105];
char map[105][105];
int vec[8][2] = { {0,-1},{0,1},{1,0},{-1,0},{1,-1},{1,1},{-1,-1},{-1,1} };
void dfs(int x, int y)
{
    if (map[x][y] == '#' || vis[x][y] != 0 
        || x < 0 || y < 0 || x >= n || y >= m)
        return;
    vis[x][y] = num;
    for (int i = 0; i < 8; i++)
    {
        int tx = x + vec[i][0];
        int ty = y + vec[i][1];
        if (map[tx][ty] == '@' && vis[tx][ty] == 0 
            && tx >= 0 && tx < n && ty >= 0 && ty < m)
            dfs(tx, ty);
    }
}
int main()
{
    while (cin >> n >> m, n + m)
    {
        num = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
            cin >> map[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (map[i][j] == '@' && vis[i][j] == 0)
                {
                    num++;
                    dfs(i, j);
                }
        cout << num << endl;
    }
}