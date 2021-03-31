#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//
//using namespace std;
//
//const int N = 1e6 + 10;
//
//int n, m;
//int p[N];
//
//int find(int x)//����x�����ڽڵ�+·��ѹ��
//{
//	if (p[x] != x) p[x] = find(p[x]);
//	return p[x];
//}
//int main()
//{
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++) p[i] = i;
//	while (m--)
//	{
//		char op[2];
//		int a, b;
//		scanf("%s%d%d", op,&a,&b);
//		if (op[0] == 'M')p[find(a)] = p[find(b)];//a�����ڽڵ�=b�����ڽڵ㣬ֱ�ӽ�����뵽a������ȥ
//		else
//		{
//			if (find(a) == find(b)) puts("Yes");//������ڵ���ͬ����һ������
//			else
//				puts("No");//����һ������
//		}
//	}
//	return 0;
//}

/*
���⣺
*/
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m;
int p[N], size[N];//size

int find(int x)
{
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
		size[i] = 1;
	}
	while (m--)
	{
		char op[5];
		int a, b;
		scanf("%s", op);
		if (op[0] == 'C')
		{
			scanf("%d%d", &a, &b);
			if (find(a) == find(b))
				continue;
			size[find(b)] += size[find(a)];
			p[find(a)] = p[find(b)];
		}
		else if (op[1] == '1')
		{
			scanf("%d%d", &a, &b);
			if (find(a) == find(b))puts("Yes");
			else puts("No");
		}
		else
		{
			scanf("%d", &a);
			printf("%d\n", size[find(a)]);
		}
	}
	return 0;
}