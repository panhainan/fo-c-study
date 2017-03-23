#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"link-list.h"
void testLinkList() {
	LinkList LL = newLinkList();;
	printLinkList(LL);
	printf("isLinkListEmpty:%d\n", isLinkListEmpty(LL));
	addLinkListHead(LL, 10);
	printLinkList(LL);
	printf("isLinkListEmpty:%d\n", isLinkListEmpty(LL));
	ElemType *getElem = (ElemType *)malloc(sizeof(ElemType));
	getLinkList(LL, getElem, 1);
	printf("getElem:%d\n", *getElem);
	addLinkListHead(LL, 20);
	printLinkList(LL);
	getLinkList(LL, getElem, 1);
	printf("getElem:%d\n", *getElem);
	addLinkListI(LL, 201,1);
	printLinkList(LL);
	getLinkList(LL, getElem, 1);
	printf("getElem:%d\n", *getElem);
	setLinkList(LL, 200, 1);
	printLinkList(LL);
	getLinkList(LL, getElem, 1);
	printf("getElem:%d\n", *getElem);
	printf("isLinkListEmpty:%d\n", isLinkListEmpty(LL));
	ElemType *removeElem = (ElemType *)malloc(sizeof(ElemType));
	removeLinkListI(LL, removeElem,1);
	printf("removeElem:%d\n", *removeElem);
	removeLinkList(LL, removeElem);
	printf("removeElem:%d\n", *removeElem);
	
}