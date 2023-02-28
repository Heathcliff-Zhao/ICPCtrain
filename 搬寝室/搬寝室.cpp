// 搬寝室.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<algorithm>
#define inf 0x7fffffff
using namespace std;
int a[2000], dp[2000][2000];
int main()
{
    int n, k, i, j;
	while (cin >> n >> k)
	{
        for (i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n);
        for (i = 0; i <= n; i++)
            for (j = 1; j <= k; j++)
                dp[j][i] = inf;
        dp[0][0] = 0;
        for (i = 2; i <= n; i++)
            for (j = 1; j * 2 <= i; j++)
                dp[j][i] = min(dp[j][i - 1], dp[j - 1][i - 2] + (a[i] - a[i - 1]) * (a[i] - a[i - 1]));
        cout << dp[k][n] << endl;
	}
}