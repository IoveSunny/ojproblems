/*
	动态规划的核心 = 状态a[i][j] + 状态转移方程d[i][j]
*/

#include <cstdio>

int main(void) {
	int i, j;
	int a[10][10], d[10][10];

	a[1][1] = 1;
	a[2][1] = 3, a[2][2] = 2;
	a[3][1] = 4, a[3][2] = 10, a[3][3] = 1;
	a[4][1] = 4, a[4][2] = 3, a[4][3] = 2, a[4][4] = 20;

	int n = 4;
	// 逆序枚举,第n层最先
	for(j=1; j<=n; j++)
		d[n][j] = a[n][j];
	
	// i是层数，j是列数
	for(i=n-1; i>=1; i--) {
		for(j=1; j<=i; j++) {
			d[i][j] = a[i][j] + (d[i+1][j]>d[i+1][j+1]?d[i+1][j]:d[i+1][j+1]);
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}

	printf("%d\n", d[1][1]);
	

	return 0;
}
