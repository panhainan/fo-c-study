#include<stdio.h>
#include "link-queue.h"
void link_queue_test() {
	LinkQueue Q;
	printf("init the enqueue.\n");
	InitLQueue(&Q);
	printf("LQueueEmpty:%d\n", LQueueEmpty(&Q));
	printf("LQueueLength:%d\n", LQueueLength(&Q));
	printf("\n");

	ElemType x = 10, y, z;
	printf("the first enqueue.\n");
	EnLQueue(&Q, x);
	printf("LQueueEmpty:%d\n", LQueueEmpty(&Q));
	printf("LQueueLength:%d\n", LQueueLength(&Q));
	printf("\n");

	GetLHead(&Q, &y);
	printf("y=%d\n", y);
	printf("LQueueEmpty:%d\n", LQueueEmpty(&Q));
	printf("LQueueLength:%d\n", LQueueLength(&Q));

	printf("\n");
	printf("the first dequeue.\n");
	DeLQueue(&Q, &z);
	printf("z=%d\n", z);
	printf("LQueueEmpty:%d\n", LQueueEmpty(&Q));
	printf("LQueueLength:%d\n", LQueueLength(&Q));
	printf("\n");

	x = 26;
	printf("the second enqueue.\n");
	EnLQueue(&Q, x);
	printf("LQueueEmpty:%d\n", LQueueEmpty(&Q));
	printf("LQueueLength:%d\n", LQueueLength(&Q));
	printf("\n");

	GetLHead(&Q, &y);
	printf("y=%d\n", y);
	printf("LQueueEmpty:%d\n", LQueueEmpty(&Q));
	printf("LQueueLength:%d\n", LQueueLength(&Q));
	printf("\n");

	x = 88;
	printf("the third enqueue.\n");
	EnLQueue(&Q, x);
	printf("LQueueEmpty:%d\n", LQueueEmpty(&Q));
	printf("LQueueLength:%d\n", LQueueLength(&Q));
	printf("\n");

	GetLHead(&Q, &y);
	printf("y=%d\n", y);
	printf("LQueueEmpty:%d\n", LQueueEmpty(&Q));
	printf("LQueueLength:%d\n", LQueueLength(&Q));

	printf("\n");
	printf("the second dequeue.\n");
	DeLQueue(&Q, &z);
	printf("z=%d\n", z);
	printf("LQueueEmpty:%d\n", LQueueEmpty(&Q));
	printf("LQueueLength:%d\n", LQueueLength(&Q));
	printf("\n");
}