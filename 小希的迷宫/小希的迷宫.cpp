// 小希的迷宫.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
using namespace std;
int x, y;
int bin[100002], mark[100002];
int findx(int x) 
{
    if (x != bin[x]) 
        bin[x] = findx(bin[x]);
    return bin[x];
}
bool merge(int x, int y) 
{
    if (findx(x) == findx(y)) 
        return 1;
    else 
    {
        bin[findx(y)] = findx(x);
        return 0;
    }
}
int main()
{
    int temp;
    bool flag = false;
    for (int i = 1; i < 100002; i++) 
        bin[i] = i;
    while (cin>>x>>y)
    {
        if (x == -1 && y == -1) 
            break;
        if (x != 0 && y != 0)
        {
            temp = merge(x, y);
            mark[x] = 1;
            mark[y] = 1;
            if (temp == 1) 
                flag = 1;
        }
        if (x == 0 && y == 0)
        {
            if (flag == 1) 
                cout << "No" << endl;
            else
            {
                int count = 0;
                for (int i = 1; i <= 100002; i++)
                {
                    if (bin[i] == i && mark[i] == 1) 
                        count++;
                }
                if (count > 1) 
                    cout << "No" << endl;
                else 
                    cout << "Yes" << endl;
            }
            for (int i = 1; i < 100002; i++)
                bin[i] = i;
            memset(mark, 0, sizeof(mark));
            flag = 0;
        }
    }
    return 0;
}