#include<stdio.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct {
	ElemType elem[MAXSIZE];
	int length;
} SqList;
//选择排序
//简单选择排序
void simple_select_sort(ElemType Elem[], int n) {
	int i, j, min;
	ElemType temp;
	for (i = 0; i < n - 1; i++) {	//一共进行n-1趟
		min = i;	//记录最小元素位置，使用每次循环的第一个元素
		for (j = i + 1; j < n; j++) {	//循环在i~n-1位置中最小的元素
			if (Elem[j] < Elem[min])
				min = j;	//更新最小元素位置
		}
		if (min != i) {	//与每次循环的第一个元素交换位置
			temp = Elem[i];
			Elem[i] = Elem[min];
			Elem[min] = temp;
		}
		for (int l = 0; l < n; l++) {
			printf("%d, ", Elem[l]);
		}
		printf("(第%d趟）\n",i+1);
	}
}

//堆排序1
void heap_adjust(SqList *L, int s, int m) {
	ElemType rc = L->elem[s];
	int j;
	for (j = 2 * s; j <= m; j *= 2) {
		if (j < m&&L->elem[j] < L->elem[j + 1])
			++j;
		if (rc >= L->elem[j])
			break;
		L->elem[s] = L->elem[j];
		s = j;
	}
	L->elem[s] = rc;
	for (int l = 1; l < L->length; l++) {
		printf("%d, ", L->elem[l]);
	}
	printf("\n");
}
void heap_sort(SqList *L) {
	int i;
	for (i = (L->length-1) / 2; i > 0; --i) {
		heap_adjust(L, i, L->length);
	}
	for (i = L->length-1; i > 1; --i) {
		L->elem[0] = L->elem[1];
		L->elem[1] = L->elem[i];
		L->elem[i] = L->elem[0];
		heap_adjust(L, 1, i-1);
	}
}

//堆排序2

void adjust_down(ElemType A[], int k, int len) {
	int i;
	A[0] = A[k];
	for (i = 2 * k; i <= len; i *= 2) {
		if (i < len && A[i] < A[i + 1])
			i++;
		if (A[0] >= A[i])
			break;
		else {
			A[k] = A[i];
			k = i;
		}
	}
	A[k] = A[0];
	for (int l = 1; l <= 10; l++) {
		printf("%d, ", A[l]);
	}
	printf("\n");
}
void build_max_heap(ElemType Elem[], int len) {
	int i;
	for (i = len / 2; i > 0; i--) {
		adjust_down(Elem, i, len);
	}
}
void heap_sort2(SqList *L) {
	int i, len = L->length - 1;
	build_max_heap(L->elem, len);
	for (i = len; i > 1; i--) {
		L->elem[0] = L->elem[1];
		L->elem[1] = L->elem[i];
		L->elem[i] = L->elem[0];
		adjust_down(L->elem, 1, i - 1);
	}
}
void main() {
	SqList S = { { 0,87,45,78,32,17,65,53,9,21,56 } ,11 };
	for (int i = 1; i < S.length; i++) {
		printf("%d, ", S.elem[i]);
	}
	printf("(排序前）\n");
	//simple_select_sort(S.elem,S.length);
	heap_sort2(&S);
	for (int i = 1; i < S.length; i++) {
		printf("%d, ", S.elem[i]);
	}
	printf("(排序后）\n");
}