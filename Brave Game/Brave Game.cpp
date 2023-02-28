// Brave Game.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n, m, t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		if (n % (m + 1) == 0)
			printf("second\n");
		else
			printf("first\n");
	}
	return 0;
}