#define OVERFLOW -1 //定义 -1 为 OVERFOLW 错误
#define STACK_INIT_SIZE 100
#define STACK_INCREAM_SIZE 50
#define SUCCESS 1
#define FAIL 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int SElemType;
typedef struct SequenceStack {
	SElemType *base;
	SElemType *top;
	int size;
} SqStack;

Status initStack(SqStack *S);
Status destroyStack(SqStack *S);
Status clearStack(SqStack *S);
Status isEmpty(SqStack *S);
Status length(SqStack *S);
Status getTopElem(SqStack *S, SElemType *e);
Status push(SqStack *S, SElemType e);
Status pop(SqStack *S, SElemType *e);

