/*
算法训练 最大最小公倍数  
时间限制：1.0s   内存限制：256.0MB
    
	问题描述
	已知一个正整数N，问从1~N中任选出三个数，他们的最小公倍数最大可以为多少。
	输入格式
	输入一个正整数N。 
	输出格式
	输出一个整数，表示你找到的最小公倍数。
	样例输入
	9
	样例输出
	504
	数据规模与约定
	1 <= N <= 106。
*/

/*
	解题思路：
		1、先找出所有素数(N=106)
		2、相邻两个数不可能有公约数
		3、最大的两个数+第三个数
		3.1、只要三个数中，最大数或最小数是素数，则这三个数的最大公倍数是相邻的三个数
		4、第三个数x<=n-2 && x>=n/2
*/

#include <cstdio>
#include <cstring>
#include <cmath>

int multiple(int third, int n);

int main(void) {
	int n;
	int a[107];
	
	scanf("%d", &n);

	memset(a, 0, sizeof(a));

	// 找出所有素数
	for(int i=2; i<=53; i++) {
		for(int j=2; i*j<=106; j++) {
			if(a[i*j] == 0)
				a[i*j] = 1;
		}
	}

	int maxmultiple = n * (n-1);
	// 只要三个数中最大或最小的有一个是素数
	if((a[n]==0 || a[n-2]==0) && n!=4 ) {
		maxmultiple *= (n-2);
	}
	else {
		//最大的两个数，找第三个数
		// n=6是特殊
		if(n==6) {
			maxmultiple = 5*4*3;	
		}
		else if(n==4)
			maxmultiple = 4*3*1;
		else
				for(int third=n-2; third>=n/2; third--) {
					// 素数或1
					if(a[third] == 0) {
						maxmultiple *= third;
						break;
					}
					// 与前两个数没有公约数
					if(!multiple(third, n) && !multiple(third, n-1)) {
						maxmultiple *= third;
						break;
					}
				}
	}

	printf("%d\n", maxmultiple);
	return 0;
}

// 两者有公约数返回1,否则返回0
int multiple(int third, int n) {
	for(int i=2; i<=(int)sqrt(n); i++) {
		if(third%i==0 && n%i==0)
			return 1;
	}

	return 0;
}
