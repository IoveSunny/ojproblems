/*
	硬币问题;

*/

int dp(int S) {
	int& ans = d[S];
	if(ans >= 0)
		return ans;
	ans = 0;
	for(int i=1; i<=n; i++) {
		if(S > V[i])
			ans >?= dp(S-V[i])+1;
	}
}
