#include<stdio.h>
#include<stdlib.h>
#include "link-bitree.h"
void main() {
	BiTree T = NULL;
	int index = 0;
	ElemType ch[8] = { 'a','b','#','c','#','c','#','#' };
	//T=ArrayToBiTree(T, ch, 8);
	T = CreateBiTree(T);
	PreOrder(T);

}