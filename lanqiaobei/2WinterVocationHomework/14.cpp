/*
算法训练 区间k大数查询  
时间限制：1.0s   内存限制：256.0MB
    
	问题描述
	给定一个序列，每次询问序列中第l个数到第r个数中第K大的数是哪个。
	输入格式
	第一行包含一个数n，表示序列长度。
	第二行包含n个正整数，表示给定的序列。
	第三个包含一个正整数m，表示询问个数。
	接下来m行，每行三个数l,r,K，表示询问序列从左往右第l个数到第r个数中，从大往小第K>大的数是哪个。序列元素从1开始标号。 
	输出格式
	总共输出m行，每行一个数，表示询问的答案。
	样例输入
	5
	1 2 3 4 5 
	2
	1 5 2 
	2 3 2 
	样例输出
	4
	2
	数据规模与约定
	对于30%的数据，n,m<=100；
	对于100%的数据，n,m<=1000；
	保证k<=(r-l+1)，序列中的数<=106。
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int cmp(int a, int b) {
	return a > b;
}

int main(void) {
	int n, m;
	int an[1001], l, r, k;
	int am[1001];

	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &an[i]);

	scanf("%d", &m);
	while(m--) {
		scanf("%d%d%d", &l, &r, &k);
		for(int i=l; i<=r; i++) {
			am[i-l] = an[i];
		 }
		sort(am, am+r-l+1, cmp);
		printf("%d\n", am[k-1]);
	}

	return 0;
}
