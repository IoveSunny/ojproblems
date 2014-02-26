/*
	n个数排成一圈。第一次删除m,以后每数k个数删除一次,求最后一个被删除的数.
	输入格式：
		输入包含多组数据。每组三个数n,k,m。
		2<=n<=10000, 1<=k<=10000, 1<=m<=n.
		输入结束标志n=k=m=0.
	输出格式:
		对于每组数据，输出最后一个被删除的数。
	
	例如:
		8 5 3
		输出: 1
*/

/*
	解题思路：
	如果从零开始每k个数删除一个，最后留下的是f(n)
		f(1) = 0;
		f(n) = (f(n-1)+k)%n
	本题第一个删除的数是m,因此答案为(m-k+1+f(n))%n
*/

#include <cstdio>
const int maxn = 10000 + 2;
int f[maxn];

int main(void) {
	int n, k, m;
	while(scanf("%d %d %d", &n, &k, &m) == 3 && n) {
		f[1] = 0;
		for(int i=2; i<=n; i++)
			f[i] = (f[i-1]+k) % i;
		int ans = (m-k+1+f[n]) % n;
		if(ans <= 0)
			ans += n;
		printf("%d\n", ans);
	}

	return 0;
}

