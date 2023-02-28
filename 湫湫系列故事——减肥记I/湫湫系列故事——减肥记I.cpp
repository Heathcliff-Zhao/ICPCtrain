// 湫湫系列故事——减肥记I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<cstring>
using namespace std;
int dp[100001];
int cal[100001];
int hap[100001];
int main()
{
    int n, m;
    while (cin>>n)
    {
        int i, j, k;
        memset(dp, 0, sizeof(dp));
        for (i = 1; i <= n; i++)
            cin >> hap[i] >> cal[i];
        cin >> m;
        for (i = 1; i <= n; i++)
            for (j = cal[i]; j <= m; j++)
                dp[j] = max(dp[j], dp[j - cal[i]] + hap[i]);
        cout << dp[m] << endl;
    }
    return 0;
}
