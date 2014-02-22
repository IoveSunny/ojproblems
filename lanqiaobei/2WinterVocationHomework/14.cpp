#include <cstdio>
#include <algorithm>
using namespace std;

int cmp(int a, int b) {
	return a > b;
}

int main(void) {
	int n, m;
	int an[1001], l, r, k;
	int am[1001];

	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &an[i]);

	scanf("%d", &m);
	while(m--) {
		scanf("%d%d%d", &l, &r, &k);
		for(int i=l; i<=r; i++) {
			am[i-l] = an[i];
		 }
		sort(am, am+r-l+1, cmp);
		printf("%d\n", am[k-1]);
	}

	return 0;
}
