#include<stdio.h>
#include<stdlib.h>
#define MAXSTRLEN 255
typedef struct {
	int data;
	struct NN *left, *right;
} NN ;
typedef struct {
	NN **base;
	NN **top;
	int size;
} SS;

void ttest() {

	SS *S = (SS*)malloc(sizeof(SS));
	S->base = (NN**)malloc(sizeof(NN*));
	S->top = S->base;
	S->size = 2;
	NN *p = (NN*)malloc(sizeof(NN));

	NN *q = (NN*)malloc(sizeof(NN));
	q->data = 60;
	q->right = q->left = NULL;

	NN *w = (NN*)malloc(sizeof(NN));
	w->data = 30;
	w->right = w->left = NULL;

	NN *o = (NN*)malloc(sizeof(NN));
	o->data = 10;
	o->right = o->left = NULL;

	NN *v = (NN*)malloc(sizeof(NN));
	v->data = 40;
	v->right = w;
	v->left = o;

	p->data = 100;
	p->left = q;
	p->right = v;

	*(S->top) = p;
	*(S->top)++;
	*(S->top) = q;
	*(S->top)++;
	*(S->top) = v;
	*(S->top)++;
	*(S->top) = o;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;
	*(S->top) = p;
	*(S->top)++;
	*(S->top) = q;
	*(S->top)++;
	*(S->top) = v;
	*(S->top)++;
	*(S->top) = o;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;
	*(S->top) = p;
	*(S->top)++;
	*(S->top) = q;
	*(S->top)++;
	*(S->top) = v;
	*(S->top)++;
	*(S->top) = o;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;
	*(S->top) = w;
	*(S->top)++;






	/*
	int *x = (int *)malloc(sizeof(int));
	*x = 9001;
	int **y = (int **)malloc(sizeof(int*));
	*y = x;
	*x = 5620;
	*y++;
	int *z = (int *)malloc(sizeof(int));
	*z = 123;
	*y = z;
	*y++;
	int *m = (int *)malloc(sizeof(int));
	*m = 2103;
	*y = m;
	*y++;
	int *l = (int *)malloc(sizeof(int));
	*l = 676;
	*y = l;
	*y++;
	int *s = (int *)malloc(sizeof(int));
	*s = 454565;
	*y = s;
	*y++;
	int *n= (int *)malloc(sizeof(int));
	n = *(y-1);
	*/

}



















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