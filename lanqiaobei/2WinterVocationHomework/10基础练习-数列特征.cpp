/*
 基础练习 数列特征  
 时间限制：1.0s   内存限制：256.0MB
     
	 问题描述
	 给出n个数，找出这n个数的最大值，最小值，和。
	 输入格式
	 第一行为整数n，表示数的个数。
	 第二行有n个数，为给定的n个数，每个数的绝对值都小于10000。
	 输出格式
	 输出三行，每行一个整数。第一行表示这些数中的最大值，第二行表示这些数中的最小值，
	 第三行表示这些数的和。
	 样例输入
	 5
	 1 3 -2 4 5 
	 样例输出
	 5
	 -2
	 3
	 数据规模与约定
	 1 = n = 10000。
*/

/*
	解题思路:
		比较
*/
#include <cstdio>

int main(void) {
	int n;
	int max=-10000, min=10000;

	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		int temp;
		scanf("%d", &temp);
		if(max < temp)
			max = temp;
		else
			if(min > temp)
				min = temp;
	}
	
	printf("%d\n%d\n%d\n", max, min, max+min);

	return 0;
}
