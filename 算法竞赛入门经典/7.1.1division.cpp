#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(void) {
	//  2 <= n <= 79
	int n;
	int a,b,c,d,e,f,g,h,i,j;
	int x;

	scanf("%d", &n);

	for(x=1234; x<=98765; x++) {
		int result = n * x;
		if(result > 98765 || result < 12345)
			break;

		// fghij
		int tx = x;	// 5
		j = tx % 10;
		tx /= 10;	// 4
		i = tx % 10;
		tx /= 10;	// 3
		h = tx % 10; 
		tx /= 10;	// 2
		g = tx % 10;
		tx /= 10; 	// 1
		f = tx % 10;
		
		// printf("%d %d %d %d %d\n", f, g, h, i, j);

		if( f==g || f==h || f==i || f==j 
			|| g==h || g==i || g==j
			|| h==i || h==j || i==j
		)
			continue;

		// abcde
		int ty = result;
		e = ty % 10;
		ty /= 10;
		d = ty % 10;
		ty /= 10;
		c = ty % 10;
		ty /= 10;
		b = ty % 10;
		ty /= 10;
		a = ty % 10;
		
		//printf("%d %d %d %d %d\n", f, g, h, i, j);

		if( a==b || a==c || a==d || a==e
			|| b==c || b==d || b==e
			|| c==d || c==e || d==e
		)
			continue;
		
		// abcde fghij
		if( a==f || a==g || a==h || a==i || a==j
		 || b==f || b==g || b==h || b==i || b==j
		 || c==f || c==g || c==h || c==i || c==j
		 || d==f || d==g || d==h || d==i || d==j
		 || e==f || e==g || e==h ||	e==i || e==j
		)	
			continue;


		printf("%d / %05d = %d\n", result, x, n);

	}
	
	return 0;
}
