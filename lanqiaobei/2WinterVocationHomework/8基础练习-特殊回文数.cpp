/*
基础练习 特殊回文数  
时间限制：1.0s   内存限制：512.0MB
    
	问题描述
	　　123321是一个非常特殊的数，它从左边读和从右边读是一样的。
	　　输入一个正整数n， 编程求所有这样的五位和六位十进制数，满足各位数字之和等于n 。
	输入格式
	　　输入一行，包含一个正整数n。 
	输出格式
	　　按从小到大的顺序输出满足条件的整数，每个整数占一行。
	样例输入
	52
	样例输出
	899998
	989989
	998899
	数据规模和约定
	　　1=n=54。
*/

/*
	解题思路:
		暴力破解：
			
*/
#include <cstdio>

int main(void) {
	int la, lb, lc;
	int ra, rb, rc;
	int mid;
	int n;

	scanf("%d", &n);
	
	// 5位数
	for(int i=10001; i<100000; i++) {
		la = i / 10000;
		lb = i / 1000 % 10;
		mid = i / 100 % 10;
		rb = i / 10 % 10;
		ra = i % 10;
		
		int sum = la + lb + mid + rb + ra;
		if(la==ra && lb==rb && sum==n)
			printf("%d\n", i);
	}

	// 6位数
	for(int i=100001; i<1000000; i++) {
		la = i / 100000;
		lb = i / 10000 % 10;
		lc = i / 1000 % 10;
		rc = i / 100 % 10;
		rb = i / 10 % 10;
		ra = i % 10;

		int sum = la + lb + lc + rc + rb + ra;
		if(la==ra && lb==rb && lc==rc && sum==n)
			printf("%d\n", i);
	}

	return 0;
}
