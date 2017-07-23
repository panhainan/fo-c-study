#include<stdio.h>
#include<stdlib.h>
test() {
	char *arr[] = { "abc","string","hello" };
	printf("%s\n", arr[0]);
	//free(arr[0]);



	//char *p = arr[0];//arr[0] 是一个字符指针,*p是指该指针指向的第0行文本行的首字符
	
	
	/*printf("%c\n", *p);
	printf("%s\n", p);

	printf("-------------\n");
	char *q;
	q = arr[0];
	printf("%c\n", *q);
	printf("%s\n", q);
	
	printf("%d\n", (p == q));*/
}