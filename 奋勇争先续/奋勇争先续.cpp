// 奋勇争先续.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include<algorithm>
using namespace std;
struct Peo
{
	string name;
	int num;
	int time;
}da[10000];
int cmp(Peo a, Peo b)
{
	if (a.num == b.num)
		return a.time < b.time;
	return a.num > b.num;
}
int main()
{
	int t, N, M;
	cin >> t;
	while (t--)
	{
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			cin >> da[i].name >> da[i].num >> da[i].time;
		sort(da, da + N, cmp);
		for (int i = 0; i < M; i++)
			cout << da[i].name << " " << da[i].num << " " << da[i].time << endl;
	}
}
