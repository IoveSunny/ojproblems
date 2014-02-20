#include <stdio.h>
#include <string.h>

int main(void) {
	int a[10];
	int n;
	int x, y;
	int vis[10];
	int len[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
	int count = 0;

	scanf("%d", &n);
	
	memset(vis, 0, sizeof(vis));
	for(x=1; x<n; x++) {
		int tx = x;
		int m = 0;
		int t;
		// 整数部分
		while(tx) {
			t = tx % 10; // 从个位起
			vis[t] = 1; // 标记用过的数字
			a[m++] = t;
			tx /= 10;
		}
		int loc_dig = m; //整数位数

		// 分数部分
		int fenshu = n - x;
		for(y=1; y<len[(9-loc_dig)/2]; y++) {
			if(fenshu * y > len[9-loc_dig-1])
				break;

			// 分子
			int ty = y;
			int flag_2 = 0;
			while(ty) {
				t = ty % 10;

				if(vis[t]) {
					flag_2 = 1;
					break;
				}

				vis[t] = 1;
				a[m++] = t;
				ty /= 10;
			}
			if(flag_2)
				continue;

			// 分母
			ty = fenshu * y;
			int flag_3 = 0;
			while(ty) {
				t = ty % 10;
				if(vis[t]) {
					flag_3 = 1;
					break;
				}

				vis[t] = 1;
				a[m++] = t;
				ty /= 10;
			}
			if(flag_3)
				continue;

			// ??
			if(m >= 10) {
				break;
			}
		}


		int flag = 0; // 假设数字全用完
		for(y=1; y<=9; y++) {
			if(vis[y] == 0) {
				flag = 1;
				break;
			}
		}

		if(flag)
			continue;
		else
			count++;
	}

	printf("%d\n", count);

	return 0;
}
