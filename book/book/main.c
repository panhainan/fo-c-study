#include<stdio.h>

void print_i(int num);
void print_l(long num);
void print_d(double num);
void print_f(float num);

//	chapter01/hello.c
hello();
//	chapter01/fahr2cels.c
fahr2cels();
//	chapter01/copy.c
copy();
//	chapter01/countcharacter.c
count_character();
many_space_to_one();
replace_character();
count_words();
//	chapter01/power.c
double power(int a,int x);
//	chapter01/characterarray.c
character_array();

void chapter01() {
	//hello();

	//fahr2cels();

	//copy();

	//count_character();
	//many_space_to_one();
	//replace_character();
	//count_words();

	/* power() start */
	/*
	int a = 10;
	int x = 10;
	double result = power(a, x);
	if (result > 0) {
		if (x >= 0) {
			printf("%d的%d次方等于%0.0lf\n", a, x, result);
		}
		else {
			printf("%d的%d次方等于%0.12lf\n", a, x, result);
		}
	}
	*/
	/* power() end */

	character_array();

}

//	chapter02/typerange.c
void type_range();
void chapter02() {
	type_range();
}

//	chapter05/pointer.c
value_test();
void swap(int *x, int *y);
//	pointer/array_str_pointer.c
test();
void pointer() {
	//value_test();

	/*swap start*/
	/*
	int x = 10,
		y = 5;
	printf("x=%d\ty=%d\n", x, y);
	swap(&x, &y);
	printf("x=%d\ty=%d\n", x, y);
	*/
	/*swap end*/
	test();
}

//	chapter05/array.c
void array_test();
f0();
void char_array();
void array() {
	//array_test();
	//f0();
	char_array();
}
//	chapter06/struct.c
test_point();
void test_size_of();

//	chapter07/print.c
test_print();
test_sprint();
test_scanf();
main() {
	//chapter01();
	//chapter02();


	pointer();
	//array();

	//test_point();
	//test_size_of();

	//test_print();
	//test_sprint();
	//test_scanf();
}
/*
命令行参数程序1 
命令行输入：book c pintor
输出：c pintor
*/
/*
main(int argc, char *argv[]) {
	int i;
	for (i = 1; i < argc; i++) {
		printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
	}
	printf("\n");
	return 0;
}
*/

/*
命令行参数程序2
命令行输入：book c pintor
输出：c pintor
*/
/*
main(int argc, char *argv[]) {
	while (--argc > 0) {
		printf("%s%s", *++argv, (argc > 1) ? " " : "");
	}
	printf("\n");
	return 0;
}
*/