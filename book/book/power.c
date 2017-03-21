#include<stdio.h>
double power(int a, int x) {
	if (a <= 0 || a == 1) {
		printf("错误a=%d: 参数a必须满足(a>0且a!=1) !\n", a);
		return -1;
	}
	double result=1.0;
	if (x >= 0) {
		for (int i = 0; i < x; i++) {
			result = result * a;
		}
	}
	else {
		for (int i = 0; i < -x; i++) {
			result = result / a;
		}
	}
	printf("注意: 参数x建议为正整数,对于负整数的计算精度不能保证!\n");
	return result;
}