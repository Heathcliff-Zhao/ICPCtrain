// 今年暑假不AC.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<algorithm>
using namespace std;
struct cat
{
	int start;
	int end;
}a[10000];
int cmp(cat a, cat b)
{
	if (a.start == b.start)
		return a.end < b.end;
	return a.start < b.start;
}
int main()
{
	int n;
	while (cin >> n, n)
	{
		int counts = 1;
		for (int i = 0; i < n; i++)
			cin >> a[i].start >> a[i].end;
		sort(a, a + n, cmp);
		int p = a[0].end;
		for (int i = 1; i < n; i++)
			if (p <= a[i].start)
			{
				p = a[i].end;
				counts++;
			}
			else if (p > a[i].end) 
				p = a[i].end;
		cout << counts << endl;
	}
}