#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
int n;

void dfs(int begin, int m, string sub, bool vis[]) {
	int i;
	if(m <= 0) {
		cout << sub << endl;
		//while(next_permutation(sub.begin(), sub.end())) {
		//	cout << sub << endl;
		//}
		return ;
	}

	for(i=begin; i<=n; i++) {
		if(!vis[i]) {
			vis[i] = 1;
			string temp = sub;
			temp += '0'+i;
			dfs(begin+1, m-1, temp, vis);
		}	
	}
}

// 利用STL-string : 
// 	next_permutation(str.begin(), str.end())生成全排列
int main(void) {
	int N;
	int m;

	cin >> N;
	while(N--) {
		cin >> n >> m;
		bool vis[10];
		memset(vis,  0, sizeof(vis));
		
		dfs(1, m, "", vis);
	}
}
