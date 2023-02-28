// Public Sale.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		if (n % (m + 1) == 0)
			cout << "none" << endl;
		else
		{
			for (int i = 1; i <= m; i++)
				if ((n - i) % (m + 1) == 0 || n <= i)
					cout << i << " ";
			cout << endl;
		}
	}
}