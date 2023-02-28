// 非常可乐.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
using namespace std;
int gcd(int a, int b)
{
    if (b)
        return gcd(b, a % b);
    return a;
}
int main()
{
    int a, b, c;
    while (cin >> a >> b >> c, a + b + c)
    {
        a /= gcd(b, c);
        if (a & 1)
            cout << "NO" << endl;
        else 
            cout<< a - 1<<endl;
    }
    return 0;
}
