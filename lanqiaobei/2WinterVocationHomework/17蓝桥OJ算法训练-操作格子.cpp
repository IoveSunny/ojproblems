/*
 算法训练 操作格子
 时间限制：1.0s   内存限制：256.0MB

 问题描述
 有n个格子，从左到右放成一排，编号为1-n。
 共有m次操作，有3种操作类型：
 1.修改一个格子的权值，
 2.求连续一段格子权值和，
 3.求连续一段格子的最大值。
 对于每个2、3操作输出你所求出的结果。
 输入格式
 第一行2个整数n，m。
 接下来一行n个整数表示n个格子的初始权值。
 接下来m行，每行3个整数p,x,y，p表示操作类型，p=1时表示修改格子x的权值为y，p=2时表
 示求区间[x,y]内格子权值和，p=3时表示求区间[x,y]内格子最大的权值。
 输出格式
 有若干行，行数等于p=2或3的操作总数。
 每行1个整数，对应了每个p=2或3操作的结果。
 样例输入
 4 3
 1 2 3 4
 2 1 3
 1 4 3
 3 1 4
 样例输出
 6
 3
 数据规模与约定
 对于20%的数据n <= 100，m <= 200。
 对于50%的数据n <= 5000，m <= 5000。
 对于100%的数据1 <= n <= 100000，m <= 100000，0 <= 格子权值 <= 10000。
*/

/*
	解题思路：
		模拟即可
*/
#include <cstdio>
#include <cstdlib>

// int modify(int x, int y);
int sum(int x, int y, int *a);
int maxvalue(int x, int y, int *a);

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	int *a = (int *)malloc(sizeof(int)*(n+1));

	for(int i=1; i<=n; i++) {
		scanf("%d", a+i);
		// printf("%d ", a[i]);
	}

	for(int i=0; i<m; i++) {
		int p, x, y;
		scanf("%d%d%d", &p, &x, &y);
		switch(p) {
			case 1:
				*(a+x) = y;
				break;
			case 2:
				sum(x, y, a);
				break;
			case 3:
				maxvalue(x, y, a);
				break;
			default:
				break;
		}
	}

	return 0;
}

int sum(int x, int y, int *a) {
	int s = 0;
	for(int i=x; i<=y; i++)
		s += *(a+i);
	printf("%d\n", s);
	return 0;
}

int maxvalue(int x, int y, int *a) {
	int maxv = -1;
	for(int i=x; i<=y; i++)
		if(maxv < *(a+i))
			maxv = *(a+i);
	printf("%d\n", maxv);
	return 0;
}
