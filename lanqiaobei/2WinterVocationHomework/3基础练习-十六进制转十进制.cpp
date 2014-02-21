/*
基础练习 十六进制转十进制  
时间限制：1.0s   内存限制：512.0MB
    
	问题描述
	　　从键盘输入一个不超过8位的正的十六进制数字符串，将它转换为正的十进制数后输出>。
	　　注：十六进制数中的10~15分别用大写的英文字母A、B、C、D、E、F表示。
	样例输入
	FFFF
	样例输出
	65535
*/

/*
	解题思路：十六进制数AnAn-1..A2A1A0
		思路一：Sn = An*16^n + An*16^(n-1)+...+A1*16^1+A0*16^0(利用pow函数)
		思路二：递归求解
*/

/*思路一*/
#include <cstdio>
#include <cmath>
#include <cstring>

int stand[75];

int main(void) {
	char maleficio[8];
	int decimal;
	
	// for convenience
	for(int i='0'; i<='9'; i++)
		stand[i] = i-'0';
	for(int i='A'; i<='F'; i++)
		stand[i] = i-'A'+10;

	//for(int i=0; i<75; i++)
	//	printf("%d ", stand[i]);

	scanf("%s", maleficio);
	decimal = 0;
	for(int i=0, k=strlen(maleficio)-1; maleficio[i]; i++, k--) {
		decimal += stand[maleficio[i]] * pow(16, k);
	}	
	printf("%d\n", decimal);

	return 0;
}

