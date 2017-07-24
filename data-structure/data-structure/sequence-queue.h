#include<stdio.h>
#define MAXSIZE 2
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Boolean;
//定义顺序存储的队列(循环队列)
typedef struct {
	ElemType data[MAXSIZE];
	int front, rear;
} SqQueue;

void InitQueue(SqQueue *Q);
Boolean QueueEmpty(SqQueue *Q);
Boolean QueueFull(SqQueue *Q);
int QueueLength(SqQueue *Q);
void EnQueue(SqQueue *Q, ElemType x);
void DeQueue(SqQueue *Q, ElemType *x);
void GetHead(SqQueue *Q, ElemType *x);

