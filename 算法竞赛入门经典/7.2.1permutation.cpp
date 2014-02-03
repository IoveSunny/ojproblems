#include <stdio.h>

void print_permutation(int n, int *A, int cur) {
	int i, j;

	if(cur == n) {
		for(i=0; i<n; i++) 
			printf("%d ", A[i]);
		printf("\n");
	}
	else {
		for(i=1; i<=n; i++) {
			int ok = 1;
			for(j=0; j<cur; j++) {
				if(A[j] == i)
					ok = 0;
			}

			if(!ok)
				continue;

			A[cur] = i;
			print_permutation(n, A, cur+1);
		}
	}
}

int main(void) {
	int n;
	int a[100];

	scanf("%d", &n);

	print_permutation(n, a, 0);
}
