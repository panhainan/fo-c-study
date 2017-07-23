#include<stdio.h>
#include<stdlib.h>
#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN + 1];//0号单元存放串的长度

typedef struct {
	char *ch;
	int length;
} HString;
void get_nextS(SString T, int next[]) {
	//KMP模式匹配算法的next数组值
	int i = 1, j = 0, t_len = T[0]-48;
	next[1] = 0;
	while (i < t_len) {
		if (j == 0 || T[i] == T[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}
void get_nextH(HString T,int next[]) {
	//KMP模式匹配算法的next数组值
	int i = 1,j = 0;
	next[1] = 0;
	while (i < T.length) {
		if (j == 0 || T.ch[i] == T.ch[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}
int swap() {
	int a = 10;
	int b = 30;
	printf("a=%d\tb=%d\n", a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("a=%d\tb=%d\n", a, b);
	return 0;
}
/*
int main() {
	int n[9] = { 0 };

//HString 方式
	//HString t;
	//t.length = 6;
	//t.ch = (char *)malloc(t.length * sizeof(char));
	//t.ch = " abaabc";
	//get_nextH(t,n);

//SString 方式
	SString s = "8abaabcac";
	get_nextS(s, n);

	for (int i = 1; i < 9; i++) {
		printf("%d\t", n[i]);
	}
}
*/