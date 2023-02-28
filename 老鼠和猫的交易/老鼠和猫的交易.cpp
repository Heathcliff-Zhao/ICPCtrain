// 老鼠和猫的交易.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include <algorithm>
#include<iomanip>
using namespace std;
double M;
int N;
double numofget = 0;

struct room 
{
	double zongjia;
	double zhiliang;
}a[20000];

bool cmp(room x, room y) 
{
	return (x.zhiliang / x.zongjia) > (y.zhiliang / y.zongjia);
}

int main() 
{
	while (cin>>M>>N)
	{
		if (M == -1 && N == -1)
			break;
		for (int i = 1; i <= N; i++) 
			cin >> a[i].zhiliang >> a[i].zongjia;
		sort(a + 1, a + 1 + N, cmp);
		for (int i = 1; i <= N; i++) 
		{
			if (M - a[i].zongjia >= 0) 
			{
				numofget += 1.0 * a[i].zhiliang * 1.0;
				M -= a[i].zongjia;
			}
			else 
			{
				numofget += 1.0 * a[i].zhiliang / a[i].zongjia * M;
				break;
			}
		}
		numofget *= 1000;
		numofget = (int)(numofget + 0.5);
		numofget /= 1000.0;
		cout <<setprecision(3)<<fixed<< numofget << endl;
		numofget = 0;
	}
	return 0;
}