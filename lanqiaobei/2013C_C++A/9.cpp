#include <cstdio>
#include <queue>

using namespace std;

int m, n;
int a[10][10];
int vis[10][10];
// mx列，my行, 上，右，下，左
int mx[] = {0,1,0,-1};
int my[] = {-1,0,1,0};
int half;

struct en {
	int x, y;
	int sum;
	int step;
};

int bfs() {
	struct en begin;
	// 坐标
	begin.x = 0;
	begin.y = 0;
	// 和
	begin.sum = a[0][0];
	// 最小步数
	begin.step = 1;
	// 标记
	vis[0][0] = 1;
	queue<struct en> proceso;
	proceso.push(begin);

	while(!proceso.empty()) {
		struct en temp = proceso.front();
		proceso.pop();
		
		//if(temp.sum > half)	return -1;

		// 满足一半，直接返回
		if(temp.sum == half)
			return temp.step;
		// printf("%d\n", temp.sum);

		// 四个方向前进
		for(int i=0; i<4; i++) {
			temp.x += mx[i];
			temp.y += my[i];

			if(temp.x>=0&&temp.x<m && temp.y>=0&&temp.y<n && !vis[temp.y][temp.x]) {
			vis[temp.y][temp.x] = 1;
			struct en end = temp;
			end.sum += a[temp.y][temp.x]; 
			end.step++;
			proceso.push(end);
			// Forget it
			vis[temp.y][temp.x] = 0;
			}

			temp.x -= mx[i];
			temp.y -= my[i];
		}
	}

	return -1;
}

int main(void) {
	int sum = 0;
	
	scanf("%d%d", &m, &n);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%d", &a[i][j]);
			sum += a[i][j];
		}
	}

	// 能否被2整除
	if(sum % 2 != 0)
		printf("-1\n");
	else {
		half = sum / 2;
		// printf("half:%d\n", half);
		printf("%d\n", bfs());
	}

	return 0;
}
