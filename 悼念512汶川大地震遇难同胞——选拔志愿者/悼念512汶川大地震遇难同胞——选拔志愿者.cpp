// 悼念512汶川大地震遇难同胞——选拔志愿者.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<stdio.h>

int main()
{
	int n, m, t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		if (n % (m + 1) == 0)
			printf("Rabbit\n");
		else
			printf("Grass\n");
	}
	return 0;
}