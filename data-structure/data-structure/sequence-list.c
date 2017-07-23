#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sequence-list.h"

SqList newSqList() {
	SqList L = (SqList)malloc(sizeof(SqList));
	if (!L) exit(OVERFLOW);
	//如果分配成功则返回指向被分配内存的指针(此存储区中的初始值不确定)，否则返回空指针NULL。
	L->elem = (ElemType *)malloc(DEFAULT_CAPACITY * sizeof(ElemType));
	if (!L->elem) exit(OVERFLOW);
	L->length = 0;
	L->capacity = DEFAULT_CAPACITY;
	return L;
}
void increamSqListCapacity(SqList L) {
	if (L->length >= L->capacity) {
		L->capacity = L->capacity + DEFAULT_CAPACITY * CAPACITY_INCREAM_MULTPLE;
		L->elem = (ElemType *)realloc(L->elem, L->capacity * sizeof(ElemType));
		if (!L->elem) exit(OVERFLOW);
	}
}
Status isSqListEmpty(SqList L) {
	if (L->length == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
Status isInSqListLimit(SqList L,int position) {
	if (position<1 || position > L->length) {
		return FALSE;
	}
	else {
		return TRUE;
	}
}
Status addSqList(SqList L, ElemType elem) {
	increamSqListCapacity(L);
	L->elem[(L->length++)] = elem;
	return SUCCESS;
}
Status setSqList(SqList L, ElemType elem, int position) {
	if (!isInSqListLimit(L, position)) {
		return FAIL_LIMIT;
	}
	increamSqListCapacity(L);
	L->length++;
	for (int i = L->length-1; i >= position ; i--) {
		L->elem[i] = L->elem[i-1];
	}
	L->elem[position - 1] = elem;
	return SUCCESS;
}
Status removeSqList(SqList L, ElemType *elem) {
	if (isSqListEmpty(L)) {
		*elem = NULL;
		return FAIL_EMPTY;
	}
	*elem = L->elem[L->length - 1];
	L->elem[L->length - 1] = NULL;
	L->length--;
	
	return SUCCESS;
}
Status removeSqListI(SqList L, ElemType *elem,int position) {
	if (isSqListEmpty(L)) {
		*elem = NULL;
		return FAIL_EMPTY;
	}
	if (!isInSqListLimit(L, position)) {
		return FAIL_LIMIT;
	}
	*elem = L->elem[position - 1];
	for (int i = position - 1, len = L->length; i <= len - 2; i++) {
		L->elem[i] = L->elem[i + 1];
	}
	L->elem[L->length - 1] = NULL;
	L->length--;
	return SUCCESS;
}
Status lastSqList(SqList L, ElemType *elem) {
	if (isSqListEmpty(L)) {
		*elem = NULL;
		return FAIL_EMPTY;
	}
	*elem = L->elem[L->length - 1];
	return SUCCESS;
}

Status getSqList(SqList L, ElemType *elem, int position) {
	if (!isInSqListLimit(L, position)) {
		*elem = NULL;
		return FAIL_LIMIT;
	}
	*elem = L->elem[position - 1];
	return SUCCESS;
}
Status clearSqList(SqList L) {
	L->length = 0;
	return SUCCESS;
}
Status printSqList(SqList L) {
	char *s = (char *)malloc(DEFAULT_ELEM_LENGTH);
	*s = 0;
	// *s = 0 的替代方案：memset(s, 0, len);
	printf("SqList(length:%d)[",L->length);
	for (int i = 0, len = L->length; i <= len -1; i++){
		/*_itoa(L->elem[i], s, 10);
		if (strlen(s) > 6) {
			char sTemp[DEFAULT_ELEM_LENGTH*ELEM_LEN_INCREAM_MULTPLE] = { 0 };
			strcat(sTemp, s);
			*s = (char *)malloc(DEFAULT_ELEM_LENGTH*ELEM_LEN_INCREAM_MULTPLE);
			*s = *sTemp;
		}*/
		if (i != len - 1) {
			printf("%d, ", L->elem[i]);
		}
		else {
			printf("%d", L->elem[i]);
		}
	}
	printf("]\n");
	return SUCCESS;
}
