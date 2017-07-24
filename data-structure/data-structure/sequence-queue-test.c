#include<stdio.h>
#include "sequence-queue.h"
void sequence_quue_test() {
	SqQueue Q;
	InitSQueue(&Q);
	printf("SQueueEmpty:%d\n",SQueueEmpty(&Q));
	printf("SQueueFull:%d\n", SQueueFull(&Q));
	printf("SQueueLength:%d\n", SQueueLength(&Q));
	printf("\n");

	ElemType x = 10,y,z;
	printf("the first enqueue.\n");
	EnSQueue(&Q, x);
	printf("SQueueEmpty:%d\n", SQueueEmpty(&Q));
	printf("SQueueFull:%d\n", SQueueFull(&Q));
	printf("SQueueLength:%d\n", SQueueLength(&Q));
	printf("\n");

	GetSHead(&Q, &y);
	printf("y=%d\n", y);
	printf("SQueueEmpty:%d\n", SQueueEmpty(&Q));
	printf("SQueueFull:%d\n", SQueueFull(&Q));
	printf("SQueueLength:%d\n", SQueueLength(&Q));
	
	printf("\n");
	printf("the first dequeue.\n");
	DeSQueue(&Q, &z);
	printf("z=%d\n",z);
	printf("SQueueEmpty:%d\n", SQueueEmpty(&Q));
	printf("SQueueFull:%d\n", SQueueFull(&Q));
	printf("SQueueLength:%d\n", SQueueLength(&Q));
	printf("\n");

	x = 26;
	printf("the second enqueue.\n");
	EnSQueue(&Q, x);
	printf("SQueueEmpty:%d\n", SQueueEmpty(&Q));
	printf("SQueueFull:%d\n", SQueueFull(&Q));
	printf("SQueueLength:%d\n", SQueueLength(&Q));
	printf("\n");

	GetSHead(&Q, &y);
	printf("y=%d\n", y);
	printf("SQueueEmpty:%d\n", SQueueEmpty(&Q));
	printf("SQueueFull:%d\n", SQueueFull(&Q));
	printf("SQueueLength:%d\n", SQueueLength(&Q));
	printf("\n");

	x = 88;
	printf("the third enqueue.\n");
	EnSQueue(&Q, x);
	printf("SQueueEmpty:%d\n", SQueueEmpty(&Q));
	printf("SQueueFull:%d\n", SQueueFull(&Q));
	printf("SQueueLength:%d\n", SQueueLength(&Q));
	printf("\n");

	GetSHead(&Q, &y);
	printf("y=%d\n", y);
	printf("SQueueEmpty:%d\n", SQueueEmpty(&Q));
	printf("SQueueFull:%d\n", SQueueFull(&Q));
	printf("SQueueLength:%d\n", SQueueLength(&Q));

	printf("\n");
	printf("the second dequeue.\n");
	DeSQueue(&Q, &z);
	printf("z=%d\n", z);
	printf("SQueueEmpty:%d\n", SQueueEmpty(&Q));
	printf("SQueueFull:%d\n", SQueueFull(&Q));
	printf("SQueueLength:%d\n", SQueueLength(&Q));
	printf("\n");
}