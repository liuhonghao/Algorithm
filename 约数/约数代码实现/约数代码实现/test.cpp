#define _CRT_SECURE_NO_WARNINGS 1

//试除法求约数

//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//vector<int> get_divisors(int n)
//{
//	vector<int>res;
//	for (int i = 1; i <= n / i; i++)
//	{
//		if (n%i == 0)
//		{
//			res.push_back(i);
//			if (i != n / i)res.push_back(n / i);//i和n/i相同只加一个
//		}
//	}
//	sort(res.begin(), res.end());
//	return res;
//
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	while (n--)
//	{
//		int x;
//		cin >> x;
//		auto res = get_divisors(x);
//		for (auto t : res)
//			cout << t << ' ';
//		cout << endl;
//	}
//	return 0;
//}

//约数个数
/*
给定 n 个正整数 ai，请你输出这些数的乘积的约数个数，答案对 109+7 取模。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个整数 ai。

输出格式
输出一个整数，表示所给正整数的乘积的约数个数，答案需对 109+7 取模。

数据范围
1≤n≤100,
1≤ai≤2×109
输入样例：
3
2
6
8
输出样例：
12
*/
//#include <iostream>
//#include<algorithm>
//#include <unordered_map>
//using namespace std;
//
//typedef long long LL;
//const int mod = 1e9 + 7;
//int main()
//{
//	int n;
//	cin >> n;
//	unordered_map<int, int>primes;
//	while (n--)
//	{
//		int x;
//		cin >> x;
//		for (int i = 2; i <= x / i; i++)
//		{
//			while (x%i == 0){
//				x /= i;
//			primes[i]++;
		/*	}*/
//		}
//		if (x > 1)primes[x]++;
//	}
//	LL res = 1;
//	for (auto prime : primes)res = res*(prime.second + 1) % mod;
//	cout << res << endl;
//
//	return 0;
//}

//约数之和
//#include <iostream>
//#include<algorithm>
//#include <unordered_map>
//using namespace std;
//
//typedef long long LL;
//const int mod = 1e9 + 7;
//int main()
//{
//	int n;
//	cin >> n;
//	unordered_map<int, int>primes;
//	while (n--)
//	{
//		int x;
//		cin >> x;
//		for (int i = 2; i <= x / i; i++)
//		{
//			while (x%i == 0)
//			{
//				x /= i;
//				primes[i]++;
//			}
//		}
//		if (x > 1)primes[x]++;
//	}
//	LL res = 1;
//	for (auto prime : primes)
//	{
//		int p = prime.first;
//		int a = prime.second;
//		LL t = 1;
//		while (a--)
//		{
//			t = (t*p + 1) % mod;
//		}
//		res = res*t%mod;
//	}
//	cout << res << endl;
//
//	return 0;
//}

//最大公约数

#include <bits/stdc++.h>

using namespace std;


int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}
int main()
{
	int n;
	scanf("%d",&n);
	while (n--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", gcd(a,b));
	}
	return 0;
}