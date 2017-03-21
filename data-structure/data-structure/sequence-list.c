#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sequence-list.h"

Status initSqList(SqList *L) {
	//如果分配成功则返回指向被分配内存的指针(此存储区中的初始值不确定)，否则返回空指针NULL。
	(*L).elem = (ElemType *)malloc(DEFAULT_CAPACITY*sizeof(ElemType));
	if (!(*L).elem) exit(OVERFOLW);
	(*L).length = 0;
	(*L).capacity = DEFAULT_CAPACITY;
	return SUCCESS;
}
Status increamCapacity(SqList *L) {
	if ((*L).length >= (*L).capacity) {
		(*L).capacity = DEFAULT_CAPACITY * CAPACITY_INCREAM_MULTPLE;
		(*L).elem = (ElemType *)realloc((*L).elem, (*L).capacity * sizeof(ElemType));
	}
}
Status insertSqList(SqList *L, ElemType elem) {
	increamCapacity(L);
	(*L).elem[((*L).length++)] = elem;
	return SUCCESS;
}
Status insertSqListI(SqList *L, ElemType elem, int position) {
	increamCapacity(L);
	(*L).length++;
	for (int i = (*L).length-1; i >= position ; i--) {
		(*L).elem[i] = (*L).elem[i-1];
	}
	(*L).elem[position - 1] = elem;
	return SUCCESS;
}
Status deleteSqList(SqList *L, ElemType *elem) {
	return SUCCESS;
}
Status deleteSqListI(SqList *L, ElemType *elem,int position) {
	return SUCCESS;
}
Status clearSqList(SqList *L) {
	return SUCCESS;
}
Status printSqList(SqList *L) {
	char *s = (char *)malloc(DEFAULT_ELEM_LENGTH);
	*s = 0;
	// *s = 0 的替代方案：memset(s, 0, len);
	printf("SqList[");
	for (int i = 0; i <= (*L).length-2; i++){
		_itoa((*L).elem[i], s, 10);
		if (strlen(s) > 6) {
			char sTemp[DEFAULT_ELEM_LENGTH*ELEM_LEN_INCREAM_MULTPLE] = { 0 };
			strcat(sTemp, s);
			*s = (char *)malloc(DEFAULT_ELEM_LENGTH*ELEM_LEN_INCREAM_MULTPLE);
			*s = *sTemp;
		}
		printf("%s, ", s);
	}
	_itoa((*L).elem[(*L).length - 1], s, 10);
	printf("%s]\n", s);
	return SUCCESS;
}
