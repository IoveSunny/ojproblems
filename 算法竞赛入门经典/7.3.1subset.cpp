#include <cstdio>

void print_subset(int n, int *A, int cur) {
	for(int i=0; i<cur; i++)
		printf("%d ", A[i]);
	printf("\n");

	int s = cur ? A[cur-1]+1 : 0;

	for(int i=s; i<n; i++) {
		A[cur] = i;
		print_subset(n, A, cur+1);
	}
	
}


int main(void) {
	int n;
	int a[15];

	scanf("%d", &n);

	print_subset(n, a, 0);

	return 0;
}
