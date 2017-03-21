#include<stdio.h>
copy() {
	int c;
	//printf(EOF);
	while ((c = getchar())!= EOF) {
		putchar(c);
	}
	// EOF = -1
	printf("EOF = %d\n",c);
}