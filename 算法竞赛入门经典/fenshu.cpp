#include <stdio.h>
// x >= y
// 1/k = 1/x + 1/y 
// 1/x<=1/y
// 1/k <= 2/y
// 1/k >= 2/x --> x >= 2*k
// 1/y >= 1/k - 1/y  -->  2k >= y 

int main(void) {
	int k, x, y;
	int count;

	while(~scanf("%d", &k)) {
		count = 0;
		for(y=k+1; y<=2*k; y++) {
			for(x=2*k; ; x++) {
				if(x*y > k*x + k*y)
					break;

				if(x*y == k*x + k*y) {
					count++;
					printf("1/%d = 1/%d + 1/%d\n", k, x, y);
				}
			}
		}
		printf("%d\n", count);
	}

	return 0;
}
