// 爬楼梯.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int funcs(int M)
{
	if (M == 1)
		return 1;
	else if (M == 2)
		return 1;
	else
		return funcs(M - 1) + funcs(M - 2);
}
int main()
{
	int n, M;
	cin >> n;
	int* p = new int[n];
	int times = 0;
	while (times < n)
	{
		cin >> M;
		p[times] = funcs(M);
		times++;
	}
	for (int i = 0; i < times; i++)
		cout << p[i] << endl;
}

