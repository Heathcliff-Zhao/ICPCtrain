// 骨牌铺方格.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	long long arr[51];
	int num;
	arr[1] = 1; arr[2] = 2;
	for (int i = 3; i <= 50; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	while (scanf("%d", &num) != EOF)
	{
		printf("%lld\n", arr[num]);
	}
	return 0;
}