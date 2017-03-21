#include<stdio.h>
/*整型数据交换，指针实现*/
void swap(int *x,int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
value_test() {
	int x = 1,
		y = 2,
		z[] = {3,4,5};
	int *ip;
	ip = &x;
	printf("%d\n", ip);
	printf("%d\n", *ip);
	*ip = -1;
	printf("%d\n", ip);
	printf("%d\n", *ip);
	printf("%d\n", x);
	ip = &z[0];
	printf("%d\n", ip);
	printf("%d\n", *ip);


}