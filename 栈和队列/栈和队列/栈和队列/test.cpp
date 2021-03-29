#define _CRT_SECURE_NO_WARNINGS 1

//栈

//#include<iostream>
//
//using namespace std;
//
//const int N = 100010;
//int stk[N], tt;//tt下标

////插入
// stk[++tt] = x;
////弹出
// tt--;
//
////判断栈是否为空
// if (tt >0 )not empty
// else empty;
////栈顶
// stk[tt];

//队列
//
//int q[N], hh, tt=-1;//hh队头，tt队尾
//
////在队尾插入元素，在队头弹出元素;
//
////插入
//q[++tt] = x;
////弹出
//hh++;
////判空
//if (hh <= tt)not empty;
//else empty;
////取出队头元素
//q[hh];
////队尾元素
//q[tt];

//单调栈;

//#include <iostream>
//#include <cstdio>
//using namespace std;
//const int N = 1e6 + 10;
//int n;
//int stk[N], tt;
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		int x;
//		scanf("%d", &x);
//		while (tt&&stk[tt] >= x)tt--;//如果栈不为空，并且栈顶元素一直大于x，弹出x
//		if (tt)printf("%d ", stk[tt]);//如果栈不为空，输出栈顶元素
//		else
//			printf("-1 ");//找不到返回-1
//		stk[++tt] = x;//将x插入栈顶；
//	}
//
//	return 0;
//}

//单调队列
#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int a[N], q[N];
int n, k;

int main()
{
	scanf("%d%d", &n,&k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int hh = 0, tt = -1;//初始化队列
	for (int i = 0; i < n; i++)
	{
		//判断队头是否已经滑出窗口
		if (hh <= tt && i - k + 1>q[hh]) hh++;//如果队列为空并
		while (hh <= tt && a[q[tt]] >= a[i])tt--;
		q[++tt] = i;//把i插入队尾
		if (i >= k - 1)printf("%d ", a[q[hh]]);
	}
	puts("");
	hh = 0, tt = -1;//初始化队列
	for (int i = 0; i < n; i++)
	{
		//判断队头是否已经滑出窗口
		if (hh <= tt && i - k + 1>q[hh]) hh++;//如果队列为空
		while (hh <= tt && a[q[tt]] <= a[i])tt--;
		q[++tt] = i;//把i插入队尾
		if (i >= k - 1)printf("%d ", a[q[hh]]);
	}
	puts("");
	return 0;
}