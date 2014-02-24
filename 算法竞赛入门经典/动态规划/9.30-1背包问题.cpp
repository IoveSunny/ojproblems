// 1、多阶段决策问题
// d(i,j) = max{d(i+1,j), d(i+1, j-V[i])+W[i]}
// d[1][C]
for(int i=n; i>=1; i--) {
	for(int j=0; j<=C; j++) {
		d[i][j] = (i==n? 0 : d[i+1][j]);
		if(j >= V[i])
			d[i][j] >?= d[i+1][j-V[i]]+W[i];
	}
}

// 2、规划方向
// 与多阶段决策对称
// f(i, j) = max{f(i-1,j), f(i-1, j-V[i])+W[i]}
// f(n, C)
for(int i=1; i<=n; i++) {
	for(int j=0; j<=C; j++) {
		f[i][j] = (i==1 ? 0 : f[i-1][j]);
		if(j >= V[i])
			f[i][j] >?= f[i-1][j-V[i]] + W[i];
	}
}

// 3、滚动数组
// 
memset(f, 0, sizeof(f));
for(int i=1; i<=n; i++) {
	scanf("%d%d", &V, &W);
	for(int j=C; j>=0; j--) {
		if(j >= V)
			f(j) >?= f[j-V] + W;
	}
}
