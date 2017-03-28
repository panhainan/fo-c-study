#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
#include"sequence-stack.h"
void _10conversion(int num, int newRadix) {
	SqStack S;
	int result = num;
	initStack(&S);
	while (num) {
		push(&S, num%newRadix);
		num = num / newRadix;
	}
	SElemType e = (SElemType)malloc(sizeof(SElemType));
	while (!isEmpty(&S)){
		pop(&S, &e);
		printf("%d", e);
	}
	printf("\n");
	//printf("%o\n", result);
}