// 丑数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
int min(int a, int b, int c, int d) 
{
	int min;
	min = a < b ? a : b;
	min = min < c ? min : c;
	min = min < d ? min : d;
	return min;
}
int main() 
{
	int i = 1, j = 1, k = 1, n, p[6000], m = 1;
	p[1] = 1;
	for (n = 2; n <= 5842; n++) 
	{
		p[n] = min(p[i] * 2, p[j] * 3, p[k] * 5, p[m] * 7);
		if (p[n] == p[i] * 2)
			i++;
		if (p[n] == p[j] * 3)
			j++;
		if (p[n] == p[k] * 5)
			k++;
		if (p[n] == p[m] * 7)
			m++;
	}
	while (scanf("%d", &m) != EOF && m)
		printf("%d\n", p[m]);
	return 0;
}
