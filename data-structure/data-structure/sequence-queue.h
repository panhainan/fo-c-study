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
/* 初始化队列 */
void InitSQueue(SqQueue *Q);
/* 判断队列是否为空 */
Boolean SQueueEmpty(SqQueue *Q);
/* 判断队列是否已满 */
Boolean SQueueFull(SqQueue *Q);
/* 队列长度 */
int SQueueLength(SqQueue *Q);
/* 入队*/
void EnSQueue(SqQueue *Q, ElemType x);
/* 获取队列第一个元素 */
void GetSHead(SqQueue *Q, ElemType *x);

