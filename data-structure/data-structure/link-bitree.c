#include "link-bitree.h"

int elem_index =0;	//数组元素当前定位，用于通过数组建立二叉树
BiTree ArrayToBiTree(BiTree T, ElemType elem[],int length) {
	ElemType ch = elem[elem_index];
	if (elem_index >= length || ch == '#') {
		T = NULL;
	}
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		if (!T)
			exit(OVERFLOW);
		T->data = ch;
		elem_index++;
		T->lchild = ArrayToBiTree(T->lchild, elem, length);
		elem_index++;
		T->rchild = ArrayToBiTree(T->rchild, elem, length);
	}
	return T;
}
BiTree CreateBiTree(BiTree T)
{
	ElemType ch;
	scanf("%c", &ch);
	if (ch == '#') {
		T = NULL;
	}
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		if (!T)
			exit(OVERFLOW);
		T->data = ch;
		T->lchild = CreateBiTree(T->lchild);
		T->rchild = CreateBiTree(T->rchild);
	}
	return T;
}

void PreOrder(BiTree T)
{
	if (T != NULL) {
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(BiTree T)
{
	if (T != NULL) {
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}

void PostOrder(BiTree T)
{
	if (T != NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}

void visit(BiTree T)
{
	printf(" %c ", T->data);
}
