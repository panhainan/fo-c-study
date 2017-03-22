#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sequence-list.h"

struct SList {
	int *elem;
	int length;
};
test_free() {
	struct SList *sL = (struct SList *)malloc(100);
	sL->length = 5;
	sL->elem = (int *)malloc(4* sL->length);
	for (int i = 0; i < 5; i++) {
		sL->elem[i] = i + 11;
	}
	for (int i = 0; i < 5; i++) {
		printf("%d ",sL->elem[i]);
	}
	printf("\n");
	free(sL->elem);
	//free 用来释放动态内存分配的空间，如malloc等
	/*int i = 10;
	free(&i);*/

};
void main() {
	SqList L;
	if (initSqList(&L)) {
		addSqList(&L, "abc");
		addSqList(&L, "bcd");
		printSqList(&L);
		setSqList(&L, 4, 2);
		printSqList(&L);
		ElemType *deleteElem = (void *)malloc(10);
		removeSqList(&L, deleteElem);
		printSqList(&L);
		printf("deleteElem:%d\n", *deleteElem);
		removeSqListI(&L, deleteElem,4);
		printSqList(&L);
		printf("deleteElem:%d\n", *deleteElem);
		clearSqList(&L);
		printSqList(&L);
	}
}