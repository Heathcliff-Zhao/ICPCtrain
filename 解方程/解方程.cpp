
// 解方程.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include <iostream>
//#include<iomanip>
//using namespace std;
//double funcs(double x, double Y)
//{
//	return 8 * x * x * x * x + 7 * x * x * x + 2 * x * x + 3 * x + 6 - Y;
//}
//double a = 0, b = 100;
//bool judge(double Y)
//{
//	if (Y <= 6)
//		return 0;
//	else
//	{
//		while (b - a > 0.0000001)
//		{
//			if (funcs((a + b) / 2, Y) < 0)
//				a = (a + b) / 2;
//			else
//				b = (a + b) / 2;
//		}
//		return 1;
//	}
//}
//int main()
//{
//	double Y;
//	int n;
//	cin >> n;
//	double* p = new double[n];
//	string* q = new string[n];
//	int times = 0;
//	while (times < n)
//	{
//		cin >> Y;
//		if (judge(Y))
//		{
//			p[times] = (a + b) / 2;
//			a = 0;
//			b = 100;
//			times++;
//		}
//		else
//		{
//			if (Y == 6)
//				p[times] = 0;
//			else
//			{
//				p[times] = -1;
//				q[times] = "No solution!";
//			}
//			a = 0;
//			b = 100;
//			times++;
//		}
//	}
//	for (int i = 0; i < times; i++)
//	{
//		if (p[i] >= 0)
//			cout << setprecision(4) << fixed << p[i] << endl;
//		else
//			cout << q[i] << endl;
//	}
//	delete[] p;
//	delete[] q;
//}

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double func(double x)
{
	return 8 * pow(x, 4) + 7 * pow(x, 3) + 2 * pow(x, 2) + 3 * x + 6;
}
int main()
{
	int num;
	cin >> num;
	while (num--)
	{
		double Y;
		cin >> Y;
		double mid;
		if (Y >= func(0) && func(100) >= Y)
		{
			double a = 0;
			double b = 100;
			while (b - a > 1e-8)
			{
				mid = (a + b) / 2;
				if (func(mid) > Y)
					b = mid - 1e-9;
				else if (func(mid) < Y)
					a = mid + 1e-9;
				else
					break;
			}
			cout << setprecision(4) << fixed << (a + b) / 2 << endl;
		}
		else
			cout << "No solution!" << endl;
	}
	return 0;
}
