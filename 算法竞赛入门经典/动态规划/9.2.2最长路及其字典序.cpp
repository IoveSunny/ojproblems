/*
	状态转移方程: d(i) = max{d(j)+1|(i,j) in E}, E为边集
*/

int dp(int i) {
	// 声明引用，所有对ans的修改都是对d[i]的修改
	int& ans = d[i];
	if(ans > 0)
		return ans;
	ans = 1;
	for(int j=1; j<=n; j++)
		if(G[i][j])
			if(ans < dp(j)+1)
				ans = dp(j)+1;
	return ans;
}

// 字典序
void print_ans(int i) {
	printf("%d", i);
	for(int j=1; j<=n; j++) {
		if(G[i][j] && d[i]==d[j]+1) {
			print_ans(j);
			break;
		}
	}
}
