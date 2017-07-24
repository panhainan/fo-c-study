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
		Visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void PreOrder2(BiTree T) {
	BiTNode *stack[MAXSIZE];
	int top = 0;
	BiTNode *p = T;
	while (p || top) {
		if (p) {
			Visit(p);
			stack[top++] = p;
			p = p->lchild;
		}
		else {
			p = stack[--top];
			p = p->rchild;
		}
	}
}

void InOrder(BiTree T)
{
	if (T != NULL) {
		InOrder(T->lchild);
		Visit(T);
		InOrder(T->rchild);
	}
}

void InOrder2(BiTree T)
{
	BiTNode *stack[MAXSIZE];
	int top = 0;
	BiTNode *p = T;
	while (p || top) {
		if (p) {
			stack[top++] = p;
			p = p->lchild;
		}
		else {
			p = stack[--top];
			Visit(p);
			p = p->rchild;
		}

	}
}

void PostOrder(BiTree T)
{
	if (T != NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		Visit(T);
	}
}
void PostOrder2(BiTree T) {
	BiTNode *stack[1000], *p = T, *r = NULL;
	int top = 0;
	while (p || top) {
		if (p) {	//如果节点不为空，则将其push入栈，然后继续判断其左子树的情况
			stack[top++] = p;
			p = p->lchild;
		} else {	
			//节点为空，说明该条路径左子树完全已经push入栈，弹出栈顶元素判断其右孩子的情况
			p = stack[top - 1];
			if (p->rchild&&p->rchild != r) {
				//判断右子树，不为空且未被访问则需要先遍历
				p = p->rchild;
				stack[top++] = p;//当前右子树压栈
				p = p->lchild;
			}
			else {
				//右子树为空，则直接访问
				p = stack[--top];
				Visit(p);
				r = p;//r保存节点
				p = NULL;
			}
		}
	}
}

void Visit(BiTree T)
{
	printf(" %c ", T->data);
}
