#include <stdio.h>
#include <algorithm>

using namespace std;

void print_permutation(int n, int *A, int cur, int *p) {
	int i, j;

	if(cur == n) {
		for(i=0; i<n; i++)
			printf("%d ", A[i]);
		printf("\n");
		return ;
	}

  for(i=0; i<n; i++) 
  	// check p[i] ?= p[i-1]
  	if(!i || p[i] != p[i-1]){
		// can the same digit
		int c1=0, c2=0;

		// p[i] in A
		for(j=0; j<cur; j++)
			if(A[j] == p[i])
				c1++;

		// p[i] in p
		for(j=0; j<n; j++)
			if(p[j] == p[i])
				c2++;

		if(c1 < c2) {
			A[cur] = p[i];
			print_permutation(n, A, cur+1, p);
		}
	}

}

int cmp(int a, int b) {
	return a < b;
}

int main(void) {
	int n;
	int a[100];
	int p[100];

	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &p[i]);
	sort(p, p+n, cmp);

	print_permutation(n, a, 0, p);
}
