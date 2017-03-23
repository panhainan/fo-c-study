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
Status isLinkListNull(LinkList L) {
	if (L == NULL)	return TRUE;
	else return FALSE;
}
Status isLinkListEmpty(LinkList L) {
	if (L->data == 0) {
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
	LNode *p;
	LNode *q;
	if (isLinkListNull(L))	return 	FAIL_NULL;
	p = (LNode *)malloc(sizeof(LNode));
	q = L;
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
	LNode *p;
	if (isLinkListNull(L))	return 	FAIL_NULL;
	p= (LNode *)malloc(sizeof(LNode));
	p->data = elem;
	p->next = L->next;
	L->next = p;
	L->data++;
	return SUCCESS;
}

Status addLinkListI(LinkList L, ElemType elem, int position) {
	LNode *p, *q;
	int i;
	if (isLinkListNull(L))	return 	FAIL_NULL;
	if (!isInLinkListLimit(L, position)) {
		return FAIL_LIMIT;
	}
	q = L;
	i = 0;
	while (q != NULL && i < position-1) {
		q = q->next;
		i++;
	}
	if (i != position-1) {
		return FAIL_LIMIT;
	}
	p = (LNode *)malloc(sizeof(LNode));
	p->data = elem;
	p->next = q->next;
	q->next = p;
	L->data++;
	return SUCCESS;
}
Status setLinkList(LinkList L, ElemType elem, int position) {
	LNode *p, *q;
	int i;
	if (isLinkListNull(L))	return 	FAIL_NULL;
	if (!isInLinkListLimit(L, position)) {
		return FAIL_LIMIT;
	}
	q = L;
	i = 0;
	while (q != NULL && i < position) {
		q = q->next;
		i++;
	}
	if (i != position) {
		return FAIL_LIMIT;
	}
	q->data = elem;
	return SUCCESS;
}
Status removeLinkList(LinkList L, ElemType *elem) {
	LNode *p, *q;
	if (isLinkListNull(L))	return 	FAIL_NULL;
	if (isLinkListEmpty(L)) {
		return FAIL_EMPTY;
	}
	q = L;
	p = q;
	while (p->next !=NULL) {
		q = p;
		p = p->next;
	}
	q->next = NULL;
	L->data--;
	*elem = p->data;
	return SUCCESS;
}
Status removeLinkListI(LinkList L, ElemType *elem, int position) {
	LNode *p,*q;
	int i;
	if (isLinkListNull(L))	return 	FAIL_NULL;
	if (!isInLinkListLimit(L, position)) {
		return FAIL_LIMIT;
	}
	q = L;
	p = q;
	i = 0;
	while (q->next != NULL && i<position) {
		p = q;
		q = q->next;
		i++;
	}
	if (i != position) return FAIL_LIMIT;
	*elem = q->data;
	p->next = q->next;
	L->data--;
	return SUCCESS;
}
Status lastLinkList(LinkList L, ElemType *elem) {
	LNode *q;
	q = L;
	if (isLinkListNull(L))	return 	FAIL_NULL;
	while (q->next != NULL) {
		q = q->next;
	}
	*elem = q->data;
	return SUCCESS;
}
Status getLinkList(LinkList L, ElemType *elem, int position) {
	LNode  *q;
	int i;
	if (isLinkListNull(L))	return 	FAIL_NULL;
	if (!isInLinkListLimit(L, position)) {
		return FAIL_LIMIT;
	}
	q = L;
	i = 0;
	while (q->next != NULL && i < position) {
		q = q->next;
		i++;
	}
	if (i != position) return FAIL_LIMIT;
	*elem = q->data;
	return SUCCESS;
}
Status freeLinkList(LinkList L) {
	if (isLinkListNull(L))	return 	FAIL_NULL;
	free(L);
	return SUCCESS;
}
Status printLinkList(LinkList L) {
	LNode *q;
	if (isLinkListNull(L))	return 	FAIL_NULL;
	q = L->next;
	printf("LinkList(length:%d)[", L->data);
	while (q != NULL) {
		if (q->next == NULL) {
			printf("%d", q->data);
		}
		else {
			printf("%d, ", q->data);
		}
		q = q->next;
		
	}
	printf("]\n");

}