/*
问题描述
利用字母可以组成一些美丽的图形，下面给出了一个例子：
ABCDEFG
BABCDEF
CBABCDE
DCBABCD
EDCBABC
这是一个5行7列的图形，请找出这个图形的规律，并输出一个n行m列的图形。
输入格式
输入一行，包含两个整数n和m，分别表示你要输出的图形的行数的列数。
输出格式
输出n行，每个m个字符，为你的图形。
样例输入
5 7
样例输出
ABCDEFG
BABCDEF
CBABCDE
DCBABCD
EDCBABC
数据规模与约定
1 = n, m = 26。
*/

/*
	解题思路：
		以A为对称中心，左边加，右边平移,可用递归求解
*/

#include <cstdio>

int ch[] = {
	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
};
int n, m;

void dfs(int tn) {
	if(tn >= n+1)
		return ;
	
	for(int i=0; i<m; i++) {
		printf("%c", ch[i]);
	}
	printf("\n");

	for(int i=m-1; i>=0; i--) {
		ch[i] = ch[i-1];
	}
	ch[0] = (char)(tn + 'A');
	
	dfs(tn+1);

	return ;
}

int main(void) {
	scanf("%d%d", &n, &m);

	dfs(1);

	return 0;
}
