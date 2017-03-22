#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"link-list.h"
void testLinkList() {
	LinkList LL = newLinkList();;
	printf("isLinkListEmpty:%d\n", isLinkListEmpty(LL));
	addLinkListHead(LL, 10);
	printf("isLinkListEmpty:%d\n", isLinkListEmpty(LL));
	addLinkListHead(LL, 20);
	printf("isLinkListEmpty:%d\n", isLinkListEmpty(LL));
	ElemType *removeElem = (ElemType *)malloc(10);
	removeLinkList(LL, &removeElem);
}