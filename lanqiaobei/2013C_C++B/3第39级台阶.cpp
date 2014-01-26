#include <stdio.h>

int mv[] = {1, 2};
int count;

// num台阶数, step步数
void dfs(int num, int step) {
	if(num >= 39) {
		if(step % 2 == 0 && num == 39)
			count++;
		return ;
	}

	for(int i=0; i<2; i++) {
		dfs(num+mv[i], step+1);
	}
}

int main(void) {
	
	count = 0;
	dfs(0, 0);

	printf("%d\n", count);

	return 0;
}
