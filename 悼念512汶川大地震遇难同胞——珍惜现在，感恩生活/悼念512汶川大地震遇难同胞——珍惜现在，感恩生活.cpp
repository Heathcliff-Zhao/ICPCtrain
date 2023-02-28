// 悼念512汶川大地震遇难同胞——珍惜现在，感恩生活.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include <iostream>
//#include<cstring>
//#include<algorithm>
//#include<cstdio>
//using namespace std;
//struct rice
//{
//	int price;
//	int weight;
//	int num;
//}a[105];
//int dp[105];
//int main()
//{
//int t;
//cin >> t;
//while (t--)
//{
//	memset(dp, 0, sizeof(dp));
//	int money, type;
//	cin >> money >> type;
//	for (int i = 0; i < type; i++)
//		cin >> a[i].price >> a[i].weight >> a[i].num;
//		for (int i = 0; i < type; i++)
//			for (int j = a[i].price; j <= money; j++)
//				if (a[i].num > 0)
//				{
//					dp[j] = max(dp[j], dp[j - a[i].price] + a[i].weight);
//					a[i].num--;
//				}
//		cout << dp[money] << endl;
//	}
//}

//#include <iostream>
//#include<cstring>
//#include<algorithm>
//#include<cstdio>
//using namespace std;
//struct rice
//{
//	int price;
//	int weight;
//	int num;
//}a[105];
//int cmp(rice a, rice b)
//{
//	return a.weight / a.price > b.weight / b.price;
//}
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int money, type, buy, sum = 0;
//		cin >> money >> type;
//		for (int i = 0; i < type; i++)
//			cin >> a[i].price >> a[i].weight >> a[i].num;
//		sort(a, a + type, cmp);
//		int i = 0;
//		while (i < type)
//		{
//			buy = money / a[i].price;
//			if (a[i].num >= buy)
//				a[i].num -= buy;
//			else
//			{
//				buy = a[i].num;
//				a[i].num = 0;
//			}
//			money -= buy * a[i].price;
//			sum += buy * a[i].weight;
//			i++;
//		}
//		cout << sum << endl;
//	}
//}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n, money, type, k, i, j;
int price[105], weight[105], num[105];
int dp[200];
void func1(int we, int v)
{
	int j;
	for (j = money; j >= v; j--)
		dp[j] = max(dp[j], dp[j - v] + we);
}
int main()
{
	scanf("%d", &n);
	while (n--)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d %d", &money, &type);
		for (i = 0; i < type; i++)
			scanf("%d %d %d", &price[i], &weight[i], &num[i]);
		for (i = 0; i < type; i++)
		{
			if (num[i] * price[i] > money)
				for (j = price[i]; j <= money; j++)
					dp[j] = max(dp[j], dp[j - price[i]] + weight[i]);
			else
			{
				k = 1;
				while (k <= num[i])
				{
					func1(weight[i] * k, price[i] * k);
					num[i] -= k;
					k = k * 2;
				}
				if (num[i] > 0)
					func1(weight[i] * num[i], price[i] * num[i]);
			}
		}
		printf("%d\n", dp[money]);
	}
	return 0;
}