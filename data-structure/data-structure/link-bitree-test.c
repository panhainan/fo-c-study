#include<stdio.h>
#include<stdlib.h>
#include "link-bitree.h"
void main() {
	BiTree T = NULL;
	int index = 0;
	ElemType ch[11] = { 'a','b','#','d','#','e','#','#','c','#','#' };
	T = ArrayToBiTree(T, ch, 11);
	//T = CreateBiTree(T);
	printf("PreOrder :");
	PreOrder(T);
	printf("\nPreOrder2:");
	PreOrder2(T);
	printf("\nInOrder :");
	InOrder(T);
	printf("\nInOrder2:");
	InOrder2(T);
	printf("\nPostOrder :");
	PostOrder(T);
	printf("\nPostOrder2:");
	PostOrder2(T);
	printf("\n");
}