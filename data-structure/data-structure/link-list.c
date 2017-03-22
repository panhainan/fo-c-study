#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"link-list.h"
LinkList newLinkList() {
	LinkList L = (LinkList)malloc(sizeof(LinkList));
	L->next = NULL;//建立头结点
	L->data = 0;//头结点的值为线性表的长度
	return L;
}
Status isLinkListEmpty(LinkList L) {
	if (L->next == NULL || L->data == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
Status isInLinkListLimit(LinkList L, int position) {
	if (position<1 || position > L->data) {
		return FALSE;
	}
	else {
		return TRUE;
	}
}
Status addLinkList(LinkList L, ElemType elem) {
	LNode *p = (LNode *)malloc(sizeof(LNode));
	LNode *q = L;
	while (q->next != NULL) {
		q = q->next;
	}
	p->data = elem;
	q->next = p;
	p->next = NULL;
	L->data++;
	return SUCCESS;
}
Status addLinkListHead(LinkList L, ElemType elem) {
	LNode *p = (LNode *)malloc(sizeof(LNode));
	p->data = elem;
	p->next = L->next;
	L->next = p;
	L->data++;
	return SUCCESS;
}

Status setLinkList(LinkList L, ElemType elem, int position) {
	if (!isInLinkListLimit(L, position)) {
		return FAIL_LIMIT;
	}
	LNode *q = L;
	int i = 0;
	while (q != NULL && i < position) {
		q = q->next;
		i++;
	}
	if (i != position) {
		return FAIL_LIMIT;
	}
	LNode *p = (LNode *)malloc(sizeof(LNode));
	p->data = elem;
	p->next = q->next;
	q->next = p;
	L->data++;
	free(p);
	return SUCCESS;
}

Status removeLinkList(LinkList L, ElemType *elem) {
	if (isLinkListEmpty(L)) {
		return FAIL_EMPTY;
	}
	LNode *q = L;
	LNode *p = (LNode *)malloc(sizeof(LNode));
	p = q;
	while (p->next !=NULL) {
		q = p;
		p = p->next;
	}
	q->next = NULL;
	L->data--;
	*elem = p->data;
	free(p);
	return SUCCESS;
}
Status removeLinkListI(LinkList L, ElemType *elem, int position) {
}
Status lastLinkList(LinkList L, ElemType *elem) {
}
Status getLinkList(LinkList L, ElemType *elem, int position) {
}
Status freeLinkList(LinkList L) {
}
Status printLinkList(LinkList L) {
}