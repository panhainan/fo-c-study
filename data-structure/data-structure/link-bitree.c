#include "link-bitree.h"
AssistStack* initAssistStack() {
	AssistStack *S = (AssistStack*)malloc(sizeof(AssistStack));
	S->top = S->base = (BiTNode**)malloc(ASSIST_STACK_SIZE * sizeof(BiTNode*));
	*(S->top) = *(S->base) = (BiTNode*)malloc(sizeof(BiTNode));
	if (!S->base)	exit(OVERFLOW);
	S->size = ASSIST_STACK_SIZE;
	return S;
}
Boolean isAssistStackEmpty(AssistStack *S) {
	if (*(S->top) == *(S->base))
		return TRUE;
	else
		return FALSE;
}
void isAssistStackFull(AssistStack *S) {
	if (S->top - S->base >= ASSIST_STACK_SIZE) {
		S->base = (BiTNode**)realloc(S->base, (S->size + ASSIST_STACK_SIZE/2) * sizeof(BiTNode));
		S->top = S->base + ASSIST_STACK_SIZE/2;
		S->size += ASSIST_STACK_SIZE/2;
	}
}
void pushAssistStack(AssistStack *S, BiTNode *p) {
	isAssistStackFull(S);
	*(S->top) = p;
	*(S->top)++;
}
BiTNode* topAssistStack(AssistStack *S) {
	if (!(isAssistStackEmpty(S))) {
		return *(S->top-1);
	}
	else {
		printf("Error:The AssistStack is empty!\n");
	}
}
BiTNode* popAssistStack(AssistStack *S) {
	if (!(isAssistStackEmpty(S))) {
		*(S->top)--;
		return *(S->top);
	}
	else {
		printf("Error:The AssistStack is empty!\n");
	}
}
AssistQueue* initAssistQueue() {
	AssistQueue *Q = (AssistQueue *)malloc(sizeof(AssistQueue));
	Q->front = 0;
	Q->rear = 0;
	return Q;
}
Boolean isAssistQueueEmpty(AssistQueue *Q) {
	if (Q->rear == Q->front)
		return TRUE;
	else
		return FALSE;
}
Boolean isAssistQueueFull(AssistQueue *Q) {
	if ((Q->rear + 1) % ASSIST_QUEUE_SIZE == Q->front)
		return TRUE;
	else
		return FALSE;
}
void enAssistQueue(AssistQueue *Q, BiTNode *p) {
	if (!isAssistQueueFull(Q)) {
		Q->data[Q->rear] = *p;
		Q->rear = (Q->rear + 1) % ASSIST_QUEUE_SIZE;
	}
	else {
		printf("Error:The AssistQueue is full!\n");
	}
	

}
BiTNode* deAssistQueue(AssistQueue *Q) {
	if (!isAssistQueueEmpty(Q)) {
		Q->front = (Q->front + 1) % ASSIST_QUEUE_SIZE;
		return &(Q->data[Q->front-1]);
	}
	else {
		printf("Error:The AssistQueue is empty!\n");
	}
}


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
	AssistStack *S = initAssistStack();
	BiTNode *p = T;
	while (p || !isAssistStackEmpty(S)) {
		if (p) {
			Visit(p);
			pushAssistStack(S, p);
			p = p->lchild;
		}
		else {
			p = popAssistStack(S);
			p = p->rchild;
		}
	}
	free(S);
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
	AssistStack *S = initAssistStack();
	BiTNode *p = T;
	while (p || !isAssistStackEmpty(S)) {
		if (p) {
			pushAssistStack(S, p);
			p = p->lchild;
		}
		else {
			p = popAssistStack(S);
			Visit(p);
			p = p->rchild;
		}

	}
	free(S);
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
	BiTNode *p = T, *r = NULL;
	AssistStack *S = initAssistStack();
	while (p || !isAssistStackEmpty(S)) {
		if (p) {	//如果节点不为空，则将其push入栈，然后继续判断其左子树的情况
			pushAssistStack(S, p);
			p = p->lchild;
		} else {	
			//节点为空，说明该条路径左子树完全已经push入栈，取栈顶元素判断其右孩子的情况
			p = topAssistStack(S);
			if (p->rchild&&p->rchild != r) {
				//判断右子树，不为空且未被访问则需要先遍历
				p = p->rchild;
				//当前右子树压栈
				pushAssistStack(S, p);
				p = p->lchild;
			}
			else {
				//右子树为空，则直接访问
				p = popAssistStack(S);
				Visit(p);
				r = p;//r保存上一个被访问的节点
				p = NULL;
			}
		}
	}
	free(S);
}

void LeverOrder(BiTree T)
{
	AssistQueue *Q= initAssistQueue();
	BiTNode *cur = T;
	enAssistQueue(Q, cur);
	while (!isAssistQueueEmpty(Q)) {
		cur = deAssistQueue(Q);
		Visit(cur);
		if (cur->lchild != NULL)
			enAssistQueue(Q, cur->lchild);
		if (cur->rchild != NULL)
			enAssistQueue(Q, cur->rchild);
	}
	free(Q);
}

void Visit(BiTree T)
{
	printf(" %c ", T->data);
}
