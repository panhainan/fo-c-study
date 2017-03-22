#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sequence-list.h"
void testSequenceList() {
	SqList L;
	if (initSqList(&L)) {
		addSqList(&L, 12);
		addSqList(&L, 13);
		printSqList(&L);
		setSqList(&L, 4, 2);
		printSqList(&L);
		ElemType *deleteElem = (void *)malloc(10);
		removeSqList(&L, deleteElem);
		printSqList(&L);
		printf("deleteElem:%d\n", *deleteElem);
		removeSqListI(&L, deleteElem, 4);
		printSqList(&L);
		printf("deleteElem:%d\n", *deleteElem);
		clearSqList(&L);
		printSqList(&L);
	}
}