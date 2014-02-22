/*
基础练习 特殊的数字  
时间限制：1.0s   内存限制：512.0MB
    
	问题描述
	　　153是一个非常特殊的数，它等于它的每位数字的立方和，即153=1*1*1+5*5*5+3*3*3。编程求
	所有满足这种条件的三位十进制数。
	输出格式
	　　按从小到大的顺序输出满足条件的三位十进制数，每个数占一行。
*/
/*
	解题思路：
		暴力破解
*/
#include <cstdio>

int main(void) {
	int a, b, c;
	int aaa, bbb, ccc;

	for(int i=100; i<1000; i++) {
		a = i / 100;
		b = i / 10 % 10;
		c = i % 10;

		aaa = a*a*a;
		bbb = b*b*b;
		ccc = c*c*c;

		int sum = aaa+bbb+ccc;

		if(i == sum) {
			printf("%d\n", i);
		}
	}

	return 0;
}
