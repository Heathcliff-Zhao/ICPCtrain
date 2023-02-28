// Knight Moves.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#define inf 0x7fffffff
using namespace std;
int main()
{
	int Map[12][12], txt[5], cnt = 0;
	char dat[6];
	while (cin.getline(dat, 6))
	{
		for (int i = 0; i < 5; i++)
		{
			if ((int)dat[i] < 60)
				txt[i] = dat[i] - '0';
			else
				txt[i] = dat[i] - '`';
		}
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				Map[i][j] = inf;
		Map[txt[0]][txt[1]] = 0;
		do {
			cnt = 0;
			for (int i = 1; i <= 8; i++)
			{
				for (int j = 1; j <= 8; j++)
				{
					if (Map[i][j] != inf)
					{
						if (i > 1 && j > 1)
						{
							Map[i - 1][j - 2] = min(Map[i - 1][j - 2], Map[i][j] + 1);
							Map[i + 1][j - 2] = min(Map[i + 1][j - 2], Map[i][j] + 1);
							Map[i - 2][j - 1] = min(Map[i - 2][j - 1], Map[i][j] + 1);
							Map[i - 2][j + 1] = min(Map[i - 2][j + 1], Map[i][j] + 1);
						}
						if (i < 2 && j>1)
						{
							Map[i - 1][j - 2] = min(Map[i - 1][j - 2], Map[i][j] + 1);
							Map[i + 1][j - 2] = min(Map[i + 1][j - 2], Map[i][j] + 1);
						}
						if (i > 1 && j < 2)
						{
							Map[i - 2][j - 1] = min(Map[i - 2][j - 1], Map[i][j] + 1);
							Map[i - 2][j + 1] = min(Map[i - 2][j + 1], Map[i][j] + 1);
						}
						Map[i + 1][j + 2] = min(Map[i + 1][j + 2], Map[i][j] + 1);
						Map[i + 2][j + 1] = min(Map[i + 2][j + 1], Map[i][j] + 1);
						Map[i - 1][j + 2] = min(Map[i - 1][j + 2], Map[i][j] + 1);
						Map[i + 2][j - 1] = min(Map[i + 2][j - 1], Map[i][j] + 1);
					}
					else
						cnt++;
				}
			}
		} while (cnt);
		printf("To get from %c%c to %c%c takes %d knight moves.\n",
			dat[0], dat[1], dat[3], dat[4], Map[txt[3]][txt[4]]);
	}
}