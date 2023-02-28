// 最少拦截系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<algorithm>
using namespace std;
struct d
{
	int num = 0;
	int L = 1;
};
int cmp(d x, d y)
{
	return x.L < y.L;
}
int main()
{
	int h;
	while (cin>>h)
	{	
		d data[100000];
		for (int i = 0; i < h; i++)
		{
			cin >> data[i].num;
			if (i > 0)
				sort(data, data + i - 1, cmp);
			for (int j = 0; j < i; j++)
				if (data[i].num > data[j].num)
					data[i].L = data[j].L + 1;
		}
		sort(data, data + h, cmp);
		if (h > 0)
			cout << data[h - 1].L << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}