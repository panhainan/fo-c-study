#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SUCCESS 1
#define OVERFLOW 0
#define MAXSIZE 100
typedef char ElemType;
typedef int Status;

typedef struct {
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode,*BiTree;

/*
注意二叉树序列中节点为空在数组用#表示；如序列：AB#D##C##;

			A
		  /   \
		 B     C
	   /  \   /  \
	  #   D   #   #

      (#表示空节点)
	  若序列不对会去掉不对的节点
*/
BiTree ArrayToBiTree(BiTree T, ElemType elem[],int length);
/* 由命令行输入序列，节点为空用#表示 ；如序列：AB#D##C##;

			A
		  /   \
		 B     C
	   /  \   /  \
	  #   D   #   #

      (#表示空节点)
*/
BiTree CreateBiTree(BiTree T);
/* 先序遍历 */
void PreOrder(BiTree T);
/* 中序遍历 */
void InOrder(BiTree T);
/* 后序遍历 */
void PostOrder(BiTree T);
/* 访问T节点的值 */
void visit(BiTree T);