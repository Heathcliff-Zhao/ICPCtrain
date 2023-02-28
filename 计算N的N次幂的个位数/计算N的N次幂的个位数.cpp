// 计算N的N次幂的个位数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
	int num, N;
	while (cin >> num)
	{
		int* p = new int[num];
		int i = 0;
		while (i < num)
		{
			cin >> N;
			p[i] = N;
			p[i] %= 10;
			int modN = p[i];
			if (modN == 4 || modN == 9)
			{
				if (N % 2 == 0)
					p[i] = (p[i] * p[i]) % 10;
				else if (N % 2 == 1)
					p[i] = p[i] % 10;
			}
			else if (modN == 2 || modN == 3 || modN == 7 || modN == 8)
			{
				if(N%4==0)
					p[i] = (p[i] * p[i] * p[i] * p[i]) % 10;
				else if(N%4==1)
					p[i] = (p[i]) % 10;
				else if(N%4==2)
					p[i] = (p[i] * p[i]) % 10;
				else if(N%4==3)
					p[i] = (p[i] * p[i] * p[i]) % 10;

			}
			i++;
		}
		for (int n = 0; n < num; n++)
			cout << p[n] << endl;
		delete[] p;
	}
}