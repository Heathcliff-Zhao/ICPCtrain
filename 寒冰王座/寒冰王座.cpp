// 寒冰王座.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
	int n, z, mod, t;
	cin >> n;
	while (n--)
	{
		cin >> z;
		mod = z % 150;
		t = z / 150;
		if (mod <= 50)
			cout << mod << endl;
		else if (mod > 50)
			cout << mod - 50 * min((mod / 50), t) << endl;
	}
}