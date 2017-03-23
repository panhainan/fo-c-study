#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sequence-list.h"
void testSequenceList() {
	SqList L= newSqList();
	addSqList(L, 12);
	addSqList(L, 13);
	printSqList(L);
	printSqList(L);
	setSqList(L, 4, 2);
	printSqList(L);
	printf("length:%d\n", L->length);
	ElemType *deleteElem = (void *)malloc(10);
	removeSqList(L, deleteElem);
	printSqList(L);
	printf("deleteElem:%d\n", *deleteElem);
	*deleteElem = NULL;
	removeSqListI(L, deleteElem, 4);
	printSqList(L);
	printf("deleteElem:%d\n", *deleteElem);
	ElemType *elem = (void *)malloc(10);
	lastSqList(L,elem);
	printf("elem:%d\n", *elem);
	*elem = NULL;
	getSqList(L, elem, 1);
	printf("elem:%d\n", *elem);
	printf("clear\n");
	clearSqList(L);
	printSqList(L);
}