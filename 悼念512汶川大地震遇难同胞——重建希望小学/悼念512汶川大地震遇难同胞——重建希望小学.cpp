// 悼念512汶川大地震遇难同胞——重建希望小学.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int fff(int x)
{
	if (x < 0)
	{
		return 0;
	}
	if (x == 0)
	{
		return 1;
	}
	return 2 * fff(x - 2) + fff(x - 1);
}
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		int ans = fff(n);
		cout << ans << endl;
	}
	return 0;
}