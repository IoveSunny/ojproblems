/*目标题: 排它平方数

    小明正看着 203879 这个数字发呆。

    原来，203879 * 203879 = 41566646641

    这有什么神奇呢？仔细观察，203879 是个6位数，并且它的每个数位上的数字都是不同的，并且它平方后的所有数位上都不出现组成它自身的数字。

    具有这样特点的6位数还有一个，请你找出它！

    再归纳一下筛选要求：
    1. 6位正整数
    2. 每个数位上的数字不同
    3. 其平方数的每个数位不含原数字的任何组成数位

答案是一个6位的正整数。(639172)

请通过浏览器提交答案。
注意：只提交另一6位数，题中已经给出的这个不要提交。
注意：不要书写其它的内容（比如：说明性的文字）。
 * */

#include <stdio.h>

int main(void) {
	int i;
	int j, k, flag2, flag3;
	int a[7], b[20];

	
	// 1_6 positive integers
	for(i=103456; i<1000000; i++) {
		//printf("i = %d\n", i);
		flag2 = 0;
		int temp = i;
		// 2_each digist is different
		for(j=1; j<7; j++) {
			a[j] = temp % 10;
			temp /= 10;
		}
		for(j=1; j<=5; j++) {
			for(k=j+1; k<=6; k++) {
				if(a[j] == a[k]) {
					flag2 = 1; // Not suitable
					break;
				}
			}
			if(flag2 == 1)
				break;
		}
		// for test next positive interge
		if(flag2 == 1)
			continue;
	
		long long result = (long long)i * (long long)i;
		// 3_To result, each digit doesnot in i(a)
		for(j=1; result; j++) {
			b[j] = result % 10;
			result /= 10;
		}
		int len = j-1;
		flag3 = 0;
		for(j=1; j<=len; j++) {
			for(k=1; k<=6; k++) {
				if(b[j] == a[k]) {
					flag3 = 1;
					break;
				}
			}
			if(flag3 == 1)
				break;
		}

		if(flag3 == 1)
			continue;
		else 
			printf("%d\n", i);
	}

	return 0;
}
