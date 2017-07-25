#include<stdio.h>
#include<stdlib.h>
#include "link-bitree.h"
//link_bitree_test
void link_bitree_test() {

	/******************测试二叉树，以下输出需要修改ElemType的定义为char型，以及visit中的printf改为%c**********************/
	/*
	printf("Test general Binary-Tree:\n");
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
	printf("\nLeverOrder:");
	LeverOrder(T);
	printf("\n\n");
	*/

	/******************测试二叉平衡树，以下输出需要修改ElemType定义为int型，以及visit中的printf改为%d**********************/
	printf("Test Binary-Sort-Tree:\n");
	ElemType elem[10] = { 20,30,40,15,25,46,32,58,6,11 };
	BSTree BST = CreateBSTree(elem, 10);
	printf("PreOrder :");
	PreOrder(BST);
	InsertBSTree(&BST, 14);
	printf("\nPreOrder2:");
	PreOrder2(BST);
	printf("\nInOrder :");
	InOrder(BST);
	printf("\nInOrder2:");
	InOrder2(BST);
	printf("\nPostOrder :");
	PostOrder(BST);
	printf("\nPostOrder2:");
	PostOrder2(BST);
	printf("\nLeverOrder:");
	LeverOrder(BST);
	printf("\n\n");
	ElemType e = 59;
	printf("Search elem(%d) in Binary-Sort-Tree...\n", e);
	BSTNode *b = SearchBSTree(BST, e);
	printf("Result : ");
	if (b == NULL)
		printf("NULL.");
	else
		printf("%d.",b->data);
	printf("\n\n");
	

	printf("Attention:\n\t1). 'xxxOrder' stands for recursive traversal.\n\t2). 'xxxOrder2' stands for non recursive traversal.\n");
}