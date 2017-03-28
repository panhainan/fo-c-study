#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"sequence-stack.h"

Status initStack(SqStack *S) {
	S->base = (SElemType)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!S->base)	exit(OVERFLOW);
	S->top = S->base;
	S->size = STACK_INIT_SIZE;
	return SUCCESS;
}
Status destroyStack(SqStack *S) {
	S->size = 0;
	free(S->base);
	S = NULL;
	return SUCCESS;
}
Status clearStack(SqStack *S) {
	S->top = S->base;
	return SUCCESS;
}
Status isEmpty(SqStack *S) {
	if (S->top == S->base)	return TRUE;
	else return FALSE;
}
Status length(SqStack *S) {
	return S->top - S->base;
}
Status getTopElem(SqStack *S, SElemType *e) {
	if (isEmpty(S))	return FAIL;
	*e = *(S->top-1);
	return SUCCESS;
}
Status push(SqStack *S, SElemType e) {
	if (length(S) >= S->size) {
		S->base = (SElemType)realloc(S->base,( S->size + STACK_INCREAM_SIZE) * sizeof(SElemType));
		S->top = S->base + STACK_INCREAM_SIZE;
		S->size += STACK_INCREAM_SIZE;
	}
	*(S->top) = e;
	S->top++;
	return SUCCESS;
}
Status pop(SqStack *S, SElemType *e) {
	if (isEmpty(S))	return FAIL;
	S->top--;
	*e = *(S->top);
	return SUCCESS;
}
