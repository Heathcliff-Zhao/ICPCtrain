// 免费馅饼.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<cstring>
//#include<stdio.h>
//using namespace std;
//int dyx[100005][15];
//int maxnum(int a, int b, int c)
//{
//    return max(max(a, b), c);
//}
//int main()
//{
//    int n, time, point, nowtime, i, j;
//    while (scanf("%d", &n) && n)
//    {
//        nowtime = 0;
//        memset(dyx, 0, sizeof(dyx));
//        for (i = 1; i <= n; i++)
//        {
//            cin >> point >> time;
//            dyx[time][point]++;
//            nowtime = max(time, nowtime);
//        }
//        for (i = nowtime - 1; i >= 0; i--)
//        {
//            dyx[i][0] += max(dyx[i + 1][0], dyx[i + 1][1]);
//            for (j = 1; j <= 9; j++)
//                dyx[i][j] += maxnum(dyx[i + 1][j - 1], dyx[i + 1][j], dyx[i + 1][j + 1]);
//            dyx[i][10] += max(dyx[i + 1][10], dyx[i + 1][9]);
//        }
//        printf("%d\n", dyx[0][5]);
//    }
//    return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int dyx[100005][15];
int maxnum(int a, int b, int c)
{
    return max(max(a, b), c);
}
int main()
{
    int n, time, point, nowtime, i, j;
    while (scanf("%d", &n) && n)
    {
        nowtime = 0;
        memset(dyx, 0, sizeof(dyx));
        for (i = 1; i <= n; i++)
        {
            cin >> point >> time;
            dyx[time][point]++;
            nowtime = max(time, nowtime);
        }
        for (i = nowtime - 1; i >= 0; i--)
        {
            dyx[i][0] += max(dyx[i + 1][0], dyx[i + 1][1]);
            for (j = 1; j <= 9; j++)
                dyx[i][j] += maxnum(dyx[i + 1][j - 1], dyx[i + 1][j], dyx[i + 1][j + 1]);
            dyx[i][10] += max(dyx[i + 1][10], dyx[i + 1][9]);
        }
        printf("%d\n", dyx[0][5]);
    }
    return 0;
}
