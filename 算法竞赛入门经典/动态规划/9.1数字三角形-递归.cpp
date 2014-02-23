/*
	动态规划的核心 = 状态a[i][j] + 状态转移方程d[i][j]
	递归：标记或记录计算过的，防止重复计算
*/

#include <cstdio>
#include <cstring>

int a[10][10], d[10][10];
int n = 4;

int max(int a, int b) {
	return a>b?a:b;
}

// 和递推差不多，只不过思维逆转，先到最底层，再回溯
int recursion(int i, int j) {
	if(d[i][j] >= 0)
		return d[i][j];
	return d[i][j] = a[i][j] + (i==n?0:max(recursion(i+1,j),recursion(i+1,j+1)));
}

int main(void) {
	int i, j;

	a[1][1] = 1;
	a[2][1] = 3, a[2][2] = 2;
	a[3][1] = 4, a[3][2] = 10, a[3][3] = 1;
	a[4][1] = 4, a[4][2] = 3, a[4][3] = 2, a[4][4] = 20;

	memset(d, -1, sizeof(d));	
	
	printf("%d\n", recursion(1,1));	

	return 0;
}
