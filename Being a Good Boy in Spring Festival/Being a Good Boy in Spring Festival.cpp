// Being a Good Boy in Spring Festival.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
using namespace std;
int a[110];
int main()
{
    int m;
    while (cin >> m)
    {
        if (m == 0) 
            break;
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            cin >> a[i];
            ans ^= a[i];
        }
        if (ans == 0)
            cout << 0 << endl;
        else
        {
            int cnt = 0;
            for (int i = 1; i <= m; i++)
            {
                int tmp;
                tmp = ans ^ a[i];
                if (tmp < a[i]) 
                    cnt++;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}