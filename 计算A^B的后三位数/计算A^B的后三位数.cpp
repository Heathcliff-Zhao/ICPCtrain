// 计算A^B的后三位数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
unsigned long long power(unsigned long long A, unsigned long long B)
{
    unsigned long long ans;
    if (B == 0)
        ans = 1;
    else
    {
        ans = power(A * A % 1000, B / 2)%1000;
        if (B % 2 == 1)
            ans = A*ans%1000;
    }
    return ans%1000;
}
int main()
{
    unsigned long long A, B;
    int i = 0;
    unsigned long long* p = new unsigned long long[10000];
    cir:
    cin >> A >> B;

    while (A != 0 && B != 0)
    {
        p[i++] = power(A, B);
        goto cir;
    }
    for (int j = 0; j < i; j++)
        cout << p[j] << endl;
    delete[]p;
}

