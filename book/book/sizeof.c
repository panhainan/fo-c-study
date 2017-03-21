#include<stdio.h>
struct xy {
	long l;
	int x;
	short y;
	char c;
};
void print_size(int i, char *s) {
	printf("sizeof %s: %d\n", s, i);
}
void test_size_of() {
	print_size(sizeof(char), "char");
	print_size(sizeof(short), "short");
	print_size(sizeof(int),"int");
	print_size(sizeof(long), "long");
	struct xy xy;
	print_size(sizeof xy, "xy");

	
}
