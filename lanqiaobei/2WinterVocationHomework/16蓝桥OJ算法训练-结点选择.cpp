/*
 算法训练 结点选择  
 时间限制：1.0s   内存限制：256.0MB
       
	   问题描述
	   有一棵 n 个节点的树，树上每个节点都有一个正整数权值。如果一个点被选择了，那么在树上和它相邻的点都不能被选择。求选出的点的权值和最大是多少？
	   输入格式
	   第一行包含一个整数 n 。
	   接下来的一行包含 n 个正整数，第 i 个正整数代表点 i 的权值。
	   接下来一共 n-1 行，每行描述树上的一条边。
	   输出格式
	   输出一个整数，代表选出的点的权值和的最大值。
	   样例输入
	   5
	   1 2 3 4 5
	   1 2
	   1 3
	   2 4
	   2 5
	   样例输出
	   12
	   样例说明
	   选择3、4、5号点，权值和为 3+4+5 = 12 。
	   数据规模与约定
	   对于20%的数据， n <= 20。
	   对于50%的数据， n <= 1000。
	   对于100%的数据， n <= 100000。
	   权值均为不超过1000的正整数。
*/

/*
	解题思路：
		1、贪心算法
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct dot {
	int value;
	int place;
};

int cmp(struct dot a, struct dot b) {
	return a.value > b.value;
}

int main(void) {
	struct dot a[100000];
	bool vis[100000];
	bool side[1000][1000];
	int n;
	
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i].value);
		a[i].place = i;
		vis[i] = 0;
	}
	sort(a+1, a+n+1, cmp);
	for(int i=1; i<=n-1; i++) {
		int y, x;
		scanf("%d%d", &y, &x);
		side[y][x] = 1;
		side[x][y] = 1;
	}
	
	int maxvalue = 0; 
	for(int i=1; i<=n; i++) {
		// 这个结点是否可用; ==0可用, 1不可用
		if(vis[a[i].place] == 0) {
			maxvalue += a[i].value;
			// 标记与a[j].place相连的点
			for(int j=1; j<n-1; j++) {
				if(side[a[i].place][j])
					vis[j] = 1;
			}
		}
	}

	printf("%d\n", maxvalue);

	return 0;
}
