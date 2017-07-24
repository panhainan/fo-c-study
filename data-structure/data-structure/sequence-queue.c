#include "sequence-queue.h"
#include<stdio.h>

void InitSQueue(SqQueue * Q)
{
	Q->front = 0;
	Q->rear = 0;
}

Boolean SQueueEmpty(SqQueue * Q)
{
	if (Q->rear == Q->front)	
		return TRUE;
	else
		return FALSE;
}

Boolean SQueueFull(SqQueue * Q)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front) 
		return TRUE;
	else
		return FALSE;
}

int SQueueLength(SqQueue * Q)
{
	return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}


void EnSQueue(SqQueue * Q, ElemType x)
{
	if (!SQueueFull(Q)) {
		Q->data[Q->rear] = x;
		Q->rear = (Q->rear + 1) % MAXSIZE;
	}
	else {
		printf("Error:The Queue is full!\n");
	}
	
}

void DeSQueue(SqQueue * Q, ElemType * x)
{
	if (!SQueueEmpty(Q)) {
		*x = Q->data[Q->front];
		Q->front = (Q->front + 1) % MAXSIZE;
	}
	else {
		printf("Error:The Queue is empty!\n");
	}
}

void GetSHead(SqQueue * Q, ElemType * x)
{
	if (!SQueueEmpty(Q)) {
		*x = Q->data[Q->front];
	}
	else {
		printf("Error:The Queue is empty!\n");
	}
}
