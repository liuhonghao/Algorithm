#define _CRT_SECURE_NO_WARNINGS 1

//�Գ�����Լ��

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
//			if (i != n / i)res.push_back(n / i);//i��n/i��ֻͬ��һ��
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

//Լ������
/*
���� n �������� ai�����������Щ���ĳ˻���Լ���������𰸶� 109+7 ȡģ��

�����ʽ
��һ�а������� n��

������ n �У�ÿ�а���һ������ ai��

�����ʽ
���һ����������ʾ�����������ĳ˻���Լ������������� 109+7 ȡģ��

���ݷ�Χ
1��n��100,
1��ai��2��109
����������
3
2
6
8
���������
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

//Լ��֮��
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

//���Լ��

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