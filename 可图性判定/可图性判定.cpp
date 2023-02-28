// 可图性判定.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int T, n;
	int tx[1000] = { 0 };
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> tx[i];
		sort(tx + 1, tx + n + 1, cmp);
		int judge = 0;
		while (1)
		{
			int temp = tx[1];
			if (temp < 0 || tx[n] < 0)
			{
				judge = 0;
				break;
			}
			else
				if (temp == 0)
				{
					judge = 1;
					break;
				}
				else
				{
					for (int i = 2; temp > 0; i++)
					{
						tx[i]--;
						if (tx[i] < 0)
						{
							judge = 0;
							break;
						}
						temp--;
					}
					tx[1] = 0;
					sort(tx + 1, tx + n + 1, cmp);
				}
			if (judge==1) 
				break;
		}
		if (judge==1)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}