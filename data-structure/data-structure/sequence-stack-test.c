#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"sequence-stack.h"
testSequenceStack() {
	SqStack S;
	initStack(&S);
	SElemType e = (SElemType)malloc(sizeof(SElemType));
	e = 10;
	length(&S);
	push(&S, e);
	e=0;
	getTopElem(&S,&e);
	length(&S);
	e = 20;
	push(&S, e);
	length(&S);
	getTopElem(&S, &e);
	e = 0;
	pop(&S, &e);
	length(&S);
	pop(&S, &e);
	length(&S);
	pop(&S, &e);
	length(&S);
	destroyStack(&S);
}