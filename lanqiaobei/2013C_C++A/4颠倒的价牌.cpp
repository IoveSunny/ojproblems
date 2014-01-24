/*
标题: 颠倒的价牌


    小李的店里专卖其它店中下架的样品电视机，可称为：样品电视专卖店。

    其标价都是4位数字（即千元不等）。

    小李为了标价清晰、方便，使用了预制的类似数码管的标价签，只要用颜色笔涂数字就可以了（参见p1.jpg）。

    这种价牌有个特点，对一些数字，倒过来看也是合理的数字。如：1 2 5 6 8 9 0 都可以。这样一来，如果牌子挂倒了，有可能完全变成了另一个价格，比如：1958 倒着挂就是：8561，差了几千元啊!! 

    当然，多数情况不能倒读，比如，1110 就不能倒过来，因为0不能作为开始数字。

    有一天，悲剧终于发生了。某个店员不小心把店里的某两个价格牌给挂倒了。并且这两个价格牌的电视机都卖出去了!

    庆幸的是价格出入不大，其中一个价牌赔了2百多，另一个价牌却赚了8百多，综合起来，反而多赚了558元。

    请根据这些信息计算：赔钱的那个价牌正确的价格应该是多少？


答案是一个4位的整数，请通过浏览器直接提交该数字。
注意：不要提交解答过程，或其它辅助说明类的内容。

 * 注意：只含数字1 2 5 6 8 9 0 才正确
 * */

#include <stdio.h>

// swap digit like 1598 -> 8651; 1288 -> 8821
int swap(int n) {
	int temp = 0;
	for(int i=1; i<=4; i++) {
		int a = n % 10;
		n /= 10;
		if(a == 6)
			a = 9;
		else if(a == 9)
			a = 6;
		else if(a==3 || a==4 || a==7)
			return 0;
	//	else if(a == 2)
	//		a = 5;
	//	else if(a == 5)
	//		a = 2;
		temp = temp * 10 +a;
	}
	return temp;
}

struct node{
	int diff;
	int old;
} i_200[100], i_800[100];
int l2=0, l8=0;

void calc() {
	int i;
	int m=0, n=0;
	for(i=1001; i<=9999; i++) {
		// Exclude digits endswith 0 like 1010,1020,3000
		if(i % 10 == 0)
			continue;

		int b = swap(i);

		if((i-b) / 100 == 2) {
			n = b-i;
			i_200[l2].diff = n;
			i_200[l2].old = i;
			l2++;
		}
		else if((b-i) /100 == 8) {
			m = b - i;	
			i_800[l8].diff = m;
			i_800[l8].old = i;
			l8++;
		}

	}
}


int main(void) {
	int i, j;
	calc();

	for(i=0; i<l2; i++) {
		for(j=0; j<l8; j++)
			if(i_200[i].diff + i_800[j].diff == 558) {
				printf("注意：只含数字1 2 5 6 8 9 0才正确： %d\n", i_200[i].old);
				//return 0;
			}
	}

	return 0;
}
