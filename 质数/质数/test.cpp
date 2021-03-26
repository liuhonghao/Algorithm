#define _CRT_SECURE_NO_WARNINGS 1

//试除法判断素数

//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//using namespace std;
////O(n)写法
//bool is_prime(int n)
//{
//	if (n < 2) return false;
//	//O(根号n）
//	for (int i = 2; i <=n/i; i++)
//	{
//		if (n%i == 0)
//			return false;
//	}
//	return true;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		int a;
//		scanf("%d", &a);
//		if (is_prime(a))
//			printf("Yes\n");
//		else
//			printf("No\n");
//
//	}
//	return 0;
//}

//分解质因数


//#include <bits/stdc++.h>
//using namespace std;
//
//void divide(int n)
//{
//	for (int i = 2; i <= n/i; i++)
//	{
//		if (n%i == 0)//i一定是质数;
//		{
//			int s = 0;
//			while (n%i == 0)
//			{
//				n /= i;
//				s++;
//			}
//			printf("%d %d\n", i, s);//底数和指数
//		}
//	}
//	if (n > 1)printf("%d %d\n", n, 1);
//	puts("");
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	while (n--)
//	{
//		int a;
//		scanf("%d", &a);
//		divide(a);
//	}
//	return 0;
//}

//筛选法求素数

#include <iostream>
using namespace std;
const int N = 1e6 + 10;

int prime[N], cnt;
bool st[N];

//朴素筛法-O(nlogn)
void get_primes(int n) {
	for (int i = 2; i <= n; i++) {
		if (!st[i]) prime[cnt++] = i;
		for (int j = i + i; j <= n; j += i)
			st[j] = true;
	}
}

//埃式筛法-O(nloglogn)
void get_primes(int n) {
	for (int i = 2; i <= n; i++) {
		if (!st[i]){
			prime[cnt++] = i;
			for (int j = i; j <= n; j += i)
				st[j] = true;
		}
	}
}

//线性筛法-O(n), n = 1e7的时候基本就比埃式筛法快一倍了
//算法核心：x仅会被其最小质因子筛去
void get_primes(int x) {
	for (int i = 2; i <= x; i++) {
		if (!st[i]) prime[cnt++] = i;
		for (int j = 0; prime[j] <= x / i; j++) {
			//对于任意一个合数x，假设pj为x最小质因子，当i<x/pj时，一定会被筛掉
			st[prime[j] * i] = true;
			if (i % prime[j] == 0) break;
			/*
			1.i%pj == 0, pj定为i最小质因子，pj也定为pj*i最小质因子
			2.i%pj != 0, pj定小于i的所有质因子，所以pj也为pj*i最小质因子
			*/
		}
	}
}

int main() 
{
	int n;
	cin >> n;
	get_primes(n);
	cout << cnt << endl;
	return 0;
}