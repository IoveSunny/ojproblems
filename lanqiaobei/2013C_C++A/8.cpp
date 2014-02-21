/*
﻿
标题：买不到的数目

    小明开了一家糖果店。他别出心裁：把水果糖包成4颗一包和7颗一包的两种。糖果不能拆包卖。

    小朋友来买糖的时候，他就用这两种包装来组合。当然有些糖果数目是无法组合出来的，比如要买 10 颗糖。

    你可以用计算机测试一下，在这种包装情况下，最大不能买到的数量是17。大于17的任何数字都可以用4和7组合出来。

    本题的要求就是在已知两个包装的数量时，求最大不能组合出的数字。

输入：
两个正整数，表示每种包装中糖的颗数(都不多于1000)

要求输出：
一个正整数，表示最大不能买到的糖数

不需要考虑无解的情况

例如：
用户输入：
4 7
程序应该输出：
17

再例如：
用户输入：
3 5
程序应该输出：
7



 
资源约定：
峰值内存消耗 < 64M
CPU消耗  < 3000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

  
*/

/*
	证明：
	1、(x-1)(y-1)-1不能被ax+by表示
	2、大于等于(x-1)(y-1)都不能倍ax+by表示

	证、1：
		假设(x-1)(y-1)-1 = ax+by (a、b>=0)
			ax+by = xy - x -y;
			(a+1)x + (b+1)y=xy
		所以a+1要能整除y,设a+1=cy(c>0)
		    b+1要能整除x,设b+1=dx(d>0)
		则(c+d)xy=xy
			c+d=1;
		与c>0&&d>0&&整数矛盾
*/
#include <stdio.h>

int main(void) {
	int m, n;

	scanf("%d %d", &m, &n);

	// 
	printf("%d\n", (m-1)*(n-1)-1);
}