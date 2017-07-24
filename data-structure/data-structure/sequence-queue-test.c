#include<stdio.h>
#include "sequence-queue.h"
void main() {
	SqQueue Q;
	InitQueue(&Q);
	printf("QueueEmpty:%d\n",QueueEmpty(&Q));
	printf("QueueFull:%d\n", QueueFull(&Q));
	printf("QueueLength:%d\n", QueueLength(&Q));
	printf("\n");

	ElemType x = 10,y,z;
	printf("the first enqueue.\n");
	EnQueue(&Q, x);
	printf("QueueEmpty:%d\n", QueueEmpty(&Q));
	printf("QueueFull:%d\n", QueueFull(&Q));
	printf("QueueLength:%d\n", QueueLength(&Q));
	printf("\n");

	GetHead(&Q, &y);
	printf("y=%d\n", y);
	printf("QueueEmpty:%d\n", QueueEmpty(&Q));
	printf("QueueFull:%d\n", QueueFull(&Q));
	printf("QueueLength:%d\n", QueueLength(&Q));
	
	printf("\n");
	printf("the first dequeue.\n");
	DeQueue(&Q, &z);
	printf("z=%d\n",z);
	printf("QueueEmpty:%d\n", QueueEmpty(&Q));
	printf("QueueFull:%d\n", QueueFull(&Q));
	printf("QueueLength:%d\n", QueueLength(&Q));
	printf("\n");

	x = 26;
	printf("the second enqueue.\n");
	EnQueue(&Q, x);
	printf("QueueEmpty:%d\n", QueueEmpty(&Q));
	printf("QueueFull:%d\n", QueueFull(&Q));
	printf("QueueLength:%d\n", QueueLength(&Q));
	printf("\n");

	GetHead(&Q, &y);
	printf("y=%d\n", y);
	printf("QueueEmpty:%d\n", QueueEmpty(&Q));
	printf("QueueFull:%d\n", QueueFull(&Q));
	printf("QueueLength:%d\n", QueueLength(&Q));
	printf("\n");

	x = 88;
	printf("the third enqueue.\n");
	EnQueue(&Q, x);
	printf("QueueEmpty:%d\n", QueueEmpty(&Q));
	printf("QueueFull:%d\n", QueueFull(&Q));
	printf("QueueLength:%d\n", QueueLength(&Q));
	printf("\n");

	GetHead(&Q, &y);
	printf("y=%d\n", y);
	printf("QueueEmpty:%d\n", QueueEmpty(&Q));
	printf("QueueFull:%d\n", QueueFull(&Q));
	printf("QueueLength:%d\n", QueueLength(&Q));

	printf("\n");
	printf("the second dequeue.\n");
	DeQueue(&Q, &z);
	printf("z=%d\n", z);
	printf("QueueEmpty:%d\n", QueueEmpty(&Q));
	printf("QueueFull:%d\n", QueueFull(&Q));
	printf("QueueLength:%d\n", QueueLength(&Q));
	printf("\n");
}