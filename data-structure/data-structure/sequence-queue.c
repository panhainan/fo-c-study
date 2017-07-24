#include "sequence-queue.h"
#include<stdio.h>

void InitQueue(SqQueue * Q)
{
	Q->front = 0;
	Q->rear = 0;
}

Boolean QueueEmpty(SqQueue * Q)
{
	if (Q->rear == Q->front)	
		return TRUE;
	else
		return FALSE;
}

Boolean QueueFull(SqQueue * Q)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front) 
		return TRUE;
	else
		return FALSE;
}

int QueueLength(SqQueue * Q)
{
	return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}


void EnQueue(SqQueue * Q, ElemType x)
{
	if (!QueueFull(Q)) {
		Q->data[Q->rear] = x;
		Q->rear = (Q->rear + 1) % MAXSIZE;
	}
	else {
		printf("Error:The Queue is full!\n");
	}
	
}

void DeQueue(SqQueue * Q, ElemType * x)
{
	if (!QueueEmpty(Q)) {
		*x = Q->data[Q->front];
		Q->front = (Q->front + 1) % MAXSIZE;
	}
	else {
		printf("Error:The Queue is empty!\n");
	}
}

void GetHead(SqQueue * Q, ElemType * x)
{
	if (!QueueEmpty(Q)) {
		*x = Q->data[Q->front];
	}
	else {
		printf("Error:The Queue is empty!\n");
	}
}
