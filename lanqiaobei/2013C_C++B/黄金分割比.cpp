#include <stdio.h>//从网上找的;
#define F 50
int main(void)
{
	unsigned long long int fib[1000];
	int f = 0;
	int a[101];
	fib[0] = 0;
	fib[1] = 1;
	for(int i = 2; fib[i] < 1e18; i++) 
	{
		fib[i] = fib[i - 1] + fib[i - 2];//计算斐波那契数列;
		f++;
	}
//	printf("%d\n", f);
	unsigned long long int x = fib[F - 2];
	unsigned long long int y = fib[F - 1];
	for(int i = 0; i < 101; i++) 
	{
		a[i] = x / y;//求黄金分割数的每一位;
		x = (x % y) * 10;//
		printf("%d", a[i]);
	}
	return 0;
}