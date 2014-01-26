#include <stdio.h>

int main(void) {
	int count;
	int a, b, c, d, e;
	int i, j;

	count = 0;
	for(i=10; i<=99; i++) {
		for(j=100; j<=999; j++) {
			int ti = i;
			int tj = j;
			
			a = ti / 10;
			b = ti % 10;
			c = tj / 100;
			d = tj /10 % 10;
			e = tj % 10;

			if(a==b || a==c || a==d || a==e ||
				b==c || b==d || b==e || c==d || c==e || d==e
			)
				continue;

			int newi = a*100 + d*10 + b;
			int newj = c*10 + e;

			if(i*j == newi*newj) {
				printf("%d * %d = %d * %d\n", i, j, newi, newj);
				count++;
			}
		}
	}
	printf("Count: %d\n", count);

	return 0;
}
