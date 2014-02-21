/*
基础练习 数列排序  
时间限制：1.0s   内存限制：512.0MB
    
	问题描述
	　　给定一个长度为n的数列，将这个数列按从小到大的顺序排列。1=n=200
	输入格式
	　　第一行为一个整数n。 
	　　第二行包含n个整数，为待排序的数，每个整数的绝对值小于10000。
	输出格式
	　　输出一行，按从小到大的顺序输出排序后的数列。
	样例输入
	5
	8 3 6 4 9 
	样例输出
	3 4 6 8 9 
*/

/*
	解题思路:
		sort or qsort
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int cmp(int a, int b) {
	// 从小到大
	return a < b;
}

int main(void) {
	int n;
	int array[200];

	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &array[i]);
	}

	// 快速排序
	sort(array, array+n, cmp);

	for(int i=0; i<n; i++)
		printf("%d ", array[i]);
	printf("\n");

	return 0;
}
