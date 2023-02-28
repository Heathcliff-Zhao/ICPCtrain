// 搬桌子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
	int times, num, road[200];
	int head, tail, temp;
	cin >> times;
	while(times--)
	{
		for (int i = 0; i < 200; i++)
			road[i] = 0;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			cin >> head >> tail;
			head = (head - 1) / 2;
			tail = (tail - 1) / 2;
			if (head > tail)
			{
				temp = head;
				head = tail;
				tail = temp;
			}
			for (int k = head; k <= tail; k++)
				road[k]++;
		}
		int maxnum = -10;
		for (int i = 0; i < 200; i++)
			if (road[i] > maxnum)
				maxnum = road[i];
		cout << maxnum * 10 << endl;
	}
}
