// 连通性判定.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
////方法一
//#include<stdio.h>
//int max, n, depth = 0;
//#define max 25
//int G[max][max];
//bool vis[max] = { false };  //用来标记已经访问过的点 ，未访问的为false
//int main() 
//{
//	void dfs(int u, int depth);
//	printf("输入图的顶点数：\n");
//	scanf("%d", &n);    //输入顶点数
//	int i, j;
//	printf("输入矩阵：\n");
//	for (i = 1; i <= n; i++)    //输入矩阵 
//		for (j = 1; j <= n; j++) 
//			scanf("%d", &G[i][j]);
//	dfs(1, 1);//开始从起点遍历 
//	int k = 0;
//	for (i = 1; i <= n; i++) 
//		if (vis[i] == false)k = 1;
//	if (k)printf("这个图是不连通的\n");
//	else printf("这个图是连通的\n");
//	return 0;
//}
//void dfs(int u, int depth) 
//{   //dfs遍历子函数 
//	vis[u] = true;             //访问该点并且做上标记该点为ture  
//	for (int v = 1; v <= n; v++) 
//		if (vis[v] == false && G[u][v] == 1)
//			dfs(v, depth++);//找到与该点相连的点，并且该点没有被访问 
//}
 

////方法二
//#include<stdio.h>
//int father[25];
//int main()
//{
//	int find(int x);   //查找父节点子函数 
//	void Union(int a, int b);//合并两个集合 
//	int m, n, V, E, i, k = 0;
//	printf("输入图的边数和点数\n");
//	scanf("%d%d", &V, &E);   //输入边和点的个数 
//	for (i = 1; i <= E; i++) 
//		father[i] = i;    //初始化数组 
//	printf("输入所有的边（一行输一条边，即它的两个端点）\n");
//	for (i = 1; i <= V; i++) 
//	{
//		scanf("%d%d", &m, &n);   //输入所有的边，输入边的两个端点 
//		Union(m, n);
//	}
//	//图已经搭好了，接下来看它们根节点是否相同，如只有一个相同的根节点，则说明是一个连通图 
//
//	for (i = 1; i <= E; i++)    //判断图的连通性 
//		if (father[i] == i)
//			k++;
//	if (k == 1)
//		printf("图是连通的\n");
//	else 
//		printf("图不是连通的\n");
//	return 0;
//}
//int find(int x) 
//{           //查找根节点的函数 
//	int a;
//	a = x;
//	while (x != father[x])
//		x = father[x];
//	while (a != father[a]) 
//	{    //路径压缩 
//		int z = a;
//		a = father[a];
//		father[z] = x;
//	}
//	return x;
//}
//void Union(int a, int b) 
//{   //合并的子函数 
//	int fx = find(a);
//	int fy = find(b);
//	if (fx != fy)
//		father[fx] = fy;
//
//}

