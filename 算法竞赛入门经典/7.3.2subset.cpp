#include <stdio.h>

void print_subset(int n, int* B, int cur) {
	if(cur == n) {
		for(int i=0; i<cur; i++)
			if(B[i])
				printf("%d ", i);
		printf("\n");
		return ;
	}

	// choose B[cur]
	B[cur] = 1;
	print_subset(n, B, cur+1);

	// not choose B[cur]
	B[cur] = 0;
	print_subset(n, B, cur+1);
}

int main(void) {
	int n;
	int B[15];

	scanf("%d", &n);

	print_subset(n, B, 0);

	return 0;
}
