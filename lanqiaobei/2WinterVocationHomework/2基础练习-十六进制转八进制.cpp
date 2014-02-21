/*
基础练习 十六进制转八进制  
时间限制：1.0s   内存限制：512.0MB
    
	问题描述
	　　给定n个十六进制正整数，输出它们对应的八进制数。
	输入格式
	　　输入的第一行为一个正整数n （1=n=10）。
	　　接下来n行，每行一个由0~9、大写字母A~F组成的字符串，表示要转换的十六进制正整>数，每个十六进制数长度不超过100000。
	输出格式
	　　输出n行，每行为输入对应的八进制正整数。
	注意
	　　输入的十六进制数不会有前导0，比如012A。
	　　输出的八进制数也不能有前导0。 
	样例输入
	2
	39
	123ABC
	样例输出
	71
	4435274
	提示
	　　先将十六进制数转换成某进制数，再由某进制数转换成八进制。

*/

/*
	解题思路：
		1、希望十六进制直接转八进制，没想到
		2、借助桥梁：a、16->10->8
					 b、16->2->8
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main(void) {
	string maleficio;
	int octal[100000];
	int decimal;
	int n;

	cin >> n;
	/*a、16->10->8*/
	int stand[75];
	for(int i='0'; i<='9'; i++)
		stand[i] = i-'0';
	for(int i='A'; i<='F'; i++)
		stand[i] = i - 'A' + 10;
	
	while(n--) {
		cin >> maleficio;
		decimal = 0;
		int k = 0;
		// 16 -> 10;
		for(int i=maleficio.length()-1; i>=0; i--) {
			decimal += stand[maleficio[i]]*pow(16, k);
			k++;
		}
		printf("D:%d\n", decimal);

		// 10 -> 8;
		k = 0;
		for(int i=0; decimal; i++) {
			octal[i] = decimal % 8;
			decimal /= 8;
			k++;
		}

		// print 8
		for(int i=k-1; i>=0; i--)
			printf("%d", octal[i]);
		printf("\n");
	}

	return 0;
}

