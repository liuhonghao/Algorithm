#define _CRT_SECURE_NO_WARNINGS 1

//�Գ����ж�����

//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//using namespace std;
////O(n)д��
//bool is_prime(int n)
//{
//	if (n < 2) return false;
//	//O(����n��
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

//�ֽ�������


//#include <bits/stdc++.h>
//using namespace std;
//
//void divide(int n)
//{
//	for (int i = 2; i <= n/i; i++)
//	{
//		if (n%i == 0)//iһ��������;
//		{
//			int s = 0;
//			while (n%i == 0)
//			{
//				n /= i;
//				s++;
//			}
//			printf("%d %d\n", i, s);//������ָ��
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

//ɸѡ��������

#include <iostream>
using namespace std;
const int N = 1e6 + 10;

int prime[N], cnt;
bool st[N];

//����ɸ��-O(nlogn)
void get_primes(int n) {
	for (int i = 2; i <= n; i++) {
		if (!st[i]) prime[cnt++] = i;
		for (int j = i + i; j <= n; j += i)
			st[j] = true;
	}
}

//��ʽɸ��-O(nloglogn)
void get_primes(int n) {
	for (int i = 2; i <= n; i++) {
		if (!st[i]){
			prime[cnt++] = i;
			for (int j = i; j <= n; j += i)
				st[j] = true;
		}
	}
}

//����ɸ��-O(n), n = 1e7��ʱ������ͱȰ�ʽɸ����һ����
//�㷨���ģ�x���ᱻ����С������ɸȥ
void get_primes(int x) {
	for (int i = 2; i <= x; i++) {
		if (!st[i]) prime[cnt++] = i;
		for (int j = 0; prime[j] <= x / i; j++) {
			//��������һ������x������pjΪx��С�����ӣ���i<x/pjʱ��һ���ᱻɸ��
			st[prime[j] * i] = true;
			if (i % prime[j] == 0) break;
			/*
			1.i%pj == 0, pj��Ϊi��С�����ӣ�pjҲ��Ϊpj*i��С������
			2.i%pj != 0, pj��С��i�����������ӣ�����pjҲΪpj*i��С������
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