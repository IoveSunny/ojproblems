/*
基础练习 回文数  
时间限制：1.0s   内存限制：512.0MB
    
	问题描述
	　　1221是一个非常特殊的数，它从左边读和从右边读是一样的，编程求所有这样的四位十
	进制数。
	输出格式
	　　按从小到大的顺序输出满足条件的四位十进制数。
*/

/*
	解题思路:
		思路一：
			第一位与第四位相同;
			第二位与第三位相同;
		思路二:
			暴力破解(数据很小)
*/

#include <cstdio>

int main(void) {
	int a, b, c, d;
	int count;

	count = 0;
	for(int i=1001; i<10000; i++) {
		a = i / 1000;
		b = i / 100 % 10;
		c = i % 100 / 10;
		d = i % 10;

		if(a==d && b==c) {
			//printf("%d %d %d %d\n", a, b, c, d);
			printf("%d\n", i);
			count++;
		}
	}
	printf("count: %d\n", count);

	return 0;
}
