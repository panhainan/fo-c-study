#include<stdio.h>
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Boolean;
//定义链式存储的队列（设头结点，便于统一操作）
typedef struct {
	ElemType data;
	struct LinkNode *next;
} LinkNode;
typedef struct {
	LinkNode *front, *rear;
} LinkQueue;
/* 初始化队列 */
void InitLQueue(LinkQueue *Q);
/* 判断队列是否为空 */
Boolean LQueueEmpty(LinkQueue *Q);
/* 队列长度 */
int LQueueLength(LinkQueue *Q);
/* 入队*/
void EnLQueue(LinkQueue *Q, ElemType x);
/* 出队 */
void DeLQueue(LinkQueue *Q, ElemType *x);
/* 获取队列第一个元素 */
void GetLHead(LinkQueue *Q, ElemType *x);