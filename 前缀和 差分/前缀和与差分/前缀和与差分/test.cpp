#define _CRT_SECURE_NO_WARNINGS 1

//前缀和
//#include <iostream>
//#include <cstdio>
//using namespace std;
//const int N = 1e6 + 10;
//int n, m;
//int a[N], s[N];
//
//int main()
//{
//	scanf("%d %d", &n, &m);
//	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
//	for (int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i];//前缀和初始化
//	while (m--)
//	{
//		int l, r;
//		scanf("%d%d", &l, &r);
//		printf("%d\n", s[r] - s[l - 1]);//区间和的计算
//
//	}
//	return 0;
//}
//for (int i = 1; i <= n; i++)
//{
//	s[i] = s[i - 1] + a[i];
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 1e6 + 10;
//int a[N], s[N];
//int n, m;
//int main()
//{
//	s[0] = 0;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		s[i] = s[i - 1] + a[i];//前缀和公式
//	}
//	while (m--)
//	{
//		int l, r;
//		cin >> l >> r;
//		printf("%d\n", s[r] - s[l - 1]);//区间和公式
//	}
//	return 0;
//}

////二维前缀和
//for (int i = 1; i <= n; i++)
//{
//	for (int j = 1; j <= m; j++)
//	{
//		s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
//	}
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 1010;
//int a[N][N], s[N][N];
//int n, m;
//int q;
//int main()
//{
//	scanf("%d%d%d", &n, &m, &q);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			scanf("%d", &a[i][j]);
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];//初始化前缀和
//		}
//	}
//	while (q--)
//	{
//		int x1, y1, x2, y2;
//		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
//		printf("%d\n", s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]);//输出前缀和
//	}
//	return 0;
//}


//一维差分

//#include <bits/stdc++.h>
//using namespace std;
//
//const int N = 1e6 + 10;
//int n, m;
//int a[N], b[N];
//void insert(int l, int r, int c)
//{
//	b[l] += c;
//	b[r + 1] -= c;
//}
//int main()
//{
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	for (int i = 1; i <= n; i++)
//		insert(i, i, a[i]);
//	while (m--)
//	{
//		int l, r, c;
//		scanf("%d%d%d", &l, &r, &c);
//		insert(l, r, c);
//	}
//	for (int i = 1; i <= n; i++)
//		b[i] += b[i - 1];
//	for (int i = 1; i <= n; i++)
//	{
//		printf("%d ", b[i]);
//	}
//	return 0;
//}
//二维差分：
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m, q;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c)
{
	b[x1][y1] += c;
	b[x2 + 1][y1] -= c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y2 + 1] += c;
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			insert(i, j, i, j, a[i][j]);
		}
	}
	while (q--)
	{
		int x1, y1, x2, y2, c;
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
		insert(x1, y1, x2, y2, c);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}