// Piggy-Bank.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//
//#include <iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//struct coin
//{
//	int value;
//	int weight;
//}c[505];
//int t, e, f, n, tot;
//int cmp(coin a, coin b)
//{
//	return a.value / a.weight < b.value / b.weight;
//}
//int full(coin c[])
//{
//	int num, sum, mod, delta;
//	num = tot / c[1].weight;
//	sum = num * c[1].value;
//	mod = tot % c[1].weight;
//	if (mod)
//	{
//		for (int i = 2; i <= n; i++)
//		{
//			delta = c[i].weight - c[1].weight;
//			for (int j = 1; j <= c[i].weight / delta; j++)
//				if ((mod + delta * j) % c[i].weight == 0 && j <= num)
//				{
//					sum = sum + delta * j;
//					return sum;
//				}
//		}
//		return 0;
//	}
//	else
//		return sum;
//}
//int main()
//{
//	cin >> t;
//	while (t--)
//	{
//		cin >> e >> f;
//		tot = f - e;
//		cin >> n;
//		for (int i = 1; i <= n; i++)
//			cin >> c[i].value >> c[i].weight;
//		sort(c + 1, c + n + 1, cmp);
//		int ans = full(c);
//		if (ans)
//			cout << "The minimum amount of money in the piggy-bank is " << ans << '.' << endl;
//		else
//			cout << "This is impossible." << endl;
//	}
//}

#define inf 99999999
#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct coin
{
	int value;
	int weight;
}c[505];
int dp[10002];
int t, e, f, n, tot;
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> e >> f;
		tot = f - e;
		cin >> n;
		fill(dp, dp + 10002, inf);
		dp[0] = 0;
		for (int i = 1; i <= n; i++)
			cin >> c[i].value >> c[i].weight;
		for (int i = 1; i <= n; i++)
			for (int j = c[i].weight; j <= tot; j++)
				dp[j] = min(dp[j], dp[j - c[i].weight] + c[i].value);
		if (dp[tot] == inf)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", dp[tot]);
	}
}
