#include <cstdio>
#include <queue>

using namespace std;

// 本题就是对STL优先队列+哈夫曼树的初步应用
long long Use_queue(int a[], int n) {
	int i;
	// 优先队列的使用
	priority_queue <int, vector<int>, greater<int> > w;
	
	for(i=0; i<n; i++)
		w.push(a[i]);

	long long temp = 0; 
	while(w.size() > 1) {
		int a = w.top();
		w.pop();

		int b = w.top();
		w.pop();
		
		//printf("%d %d\n", a, b);
		temp += (long long)(a+b);

		w.push(a+b);
	}

	return temp;
}

int main(void) {
	int G, n, i;
	int w[12000];

	scanf("%d", &G);

	while(G--) {
		scanf("%d", &n);
		for(i=0; i<n; i++)
			scanf("%d", &w[i]);
		printf("%lld\n", Use_queue(w, n));
	}
}
