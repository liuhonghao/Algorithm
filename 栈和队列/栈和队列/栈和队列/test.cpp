#define _CRT_SECURE_NO_WARNINGS 1

//ջ

//#include<iostream>
//
//using namespace std;
//
//const int N = 100010;
//int stk[N], tt;//tt�±�

////����
// stk[++tt] = x;
////����
// tt--;
//
////�ж�ջ�Ƿ�Ϊ��
// if (tt >0 )not empty
// else empty;
////ջ��
// stk[tt];

//����
//
//int q[N], hh, tt=-1;//hh��ͷ��tt��β
//
////�ڶ�β����Ԫ�أ��ڶ�ͷ����Ԫ��;
//
////����
//q[++tt] = x;
////����
//hh++;
////�п�
//if (hh <= tt)not empty;
//else empty;
////ȡ����ͷԪ��
//q[hh];
////��βԪ��
//q[tt];

//����ջ;

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
//		while (tt&&stk[tt] >= x)tt--;//���ջ��Ϊ�գ�����ջ��Ԫ��һֱ����x������x
//		if (tt)printf("%d ", stk[tt]);//���ջ��Ϊ�գ����ջ��Ԫ��
//		else
//			printf("-1 ");//�Ҳ�������-1
//		stk[++tt] = x;//��x����ջ����
//	}
//
//	return 0;
//}

//��������
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
	int hh = 0, tt = -1;//��ʼ������
	for (int i = 0; i < n; i++)
	{
		//�ж϶�ͷ�Ƿ��Ѿ���������
		if (hh <= tt && i - k + 1>q[hh]) hh++;//�������Ϊ�ղ�
		while (hh <= tt && a[q[tt]] >= a[i])tt--;
		q[++tt] = i;//��i�����β
		if (i >= k - 1)printf("%d ", a[q[hh]]);
	}
	puts("");
	hh = 0, tt = -1;//��ʼ������
	for (int i = 0; i < n; i++)
	{
		//�ж϶�ͷ�Ƿ��Ѿ���������
		if (hh <= tt && i - k + 1>q[hh]) hh++;//�������Ϊ��
		while (hh <= tt && a[q[tt]] <= a[i])tt--;
		q[++tt] = i;//��i�����β
		if (i >= k - 1)printf("%d ", a[q[hh]]);
	}
	puts("");
	return 0;
}