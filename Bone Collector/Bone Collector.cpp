// Bone Collector.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int worth[1001], volume[1001], dp[1001];
int main()
{
	int t;
	cin >> t;;
	while (t--)
	{
		int n, tot;
		cin >> n >> tot;;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
			cin >> worth[i];
		for (int i = 1; i <= n; i++)
			cin >> volume[i];
		for (int i = 1; i <= n; i++)
			for (int j = tot; j >= volume[i]; j--)
				dp[j] = max(dp[j], worth[i] + dp[j - volume[i]]);
		cout << dp[tot] << endl;
	}
}