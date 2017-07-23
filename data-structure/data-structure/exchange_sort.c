#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20	//定义顺序表最大长度
#define TRUE 1  
#define FALSE 0 
typedef int KeyType;	//关键字类型
typedef char InfoType;	//其他数据项类型
typedef struct {
	KeyType key;	//关键字项
	//InfoType otherinfo;	//其他数据项
} RedType;
typedef struct {
	RedType r[MAXSIZE + 1];	//r[0]闲置或用作哨兵单元
	int length;	//顺序表长度
}SqList;	//顺序表类型
//*********交换排序（皆不稳定）*********
//*********冒泡排序-begin***********
void bubble_sort(SqList *L) {
	int i, j, flag, len = L->length;
	for (i = 1; i < len - 1; i++) {
		flag = FALSE; //用来标识本趟冒泡是否发生交换的标志
		for (j = len - 1; j > i; j--) {	//一趟冒泡过程
			if (L->r[j - 1].key > L->r[j].key) {	//若为逆序
				//进行交换
				L->r[0] = L->r[j - 1];	//暂存在r[0]
				L->r[j - 1] = L->r[j];
				L->r[j] = L->r[0];
				flag = TRUE;
			}
		}
		//测试代码,用于观察每一趟排序结果
		
		for (int m = 1; m < L->length; m++) {
			printf("%d, ", L->r[m].key);
		}
		printf("(第%d趟)\n",i);
		
		if (flag == FALSE) {
			return;	//本趟冒泡没有发生交换，说明表已经有序了，结束排序
		}
	}
};//*********冒泡排序-end***********

//****************快速排序-begin****************
//**********枢纽划分函数（重点）**************
int partition(SqList *L, int low, int high) {
	//一趟排序过程
	RedType pivot = L->r[low];	//设置第一个元素作为枢纽值，对表进行划分（快排算法的性能影响的关键之处）
	while (low < high) {	//循环跳出条件
		while (low < high && L->r[high].key >= pivot.key)
			--high;
		L->r[low] = L->r[high];	//将比枢纽值小的元素移动到左端
		while (low < high && L->r[low].key <= pivot.key)
			++low;
		L->r[high] = L->r[low];	//将比枢纽值大的元素移动到右端
	}
	L->r[low] = pivot;	//枢纽元素存放到最终位置

	//测试代码,用于观察每一趟排序结果
	
	for (int i = 1; i < L->length; i++) {
		printf("%d, ", L->r[i].key);
	}
	printf("(枢纽值：%d)\n", pivot.key);
	

	return low;	//返回存放枢纽的最终位置
}
//**********递归快速排序**************
void quick_sort_recurrence(SqList *L, int low, int high) {
	if (low < high) {	//递归跳出条件
		int pivotpos = partition(L, low, high);	//划分
		//依次对两个子表进行递归排序
		quick_sort_recurrence(L, low, pivotpos - 1);
		quick_sort_recurrence(L, pivotpos + 1, high);
	}
};
typedef struct {
	int begin;
	int end;
}Limits_1[MAXSIZE];
//针对非递归快速排序使用的辅助栈
typedef struct {
	Limits_1 limit;
	int top;
}LimitStack;
//针对非递归快速排序使用的辅助队列
typedef struct {
	Limits_1 limit;
	int font;
	int rear;
}LimitQueue;
//**********非递归快速排序（辅助栈实现）**************
void quick_sort_1(SqList *L, int low, int high) {
	int pivotpos;
	LimitStack limit_stack;
	limit_stack.top = -1;
	limit_stack.top++;
	limit_stack.limit[limit_stack.top].begin = low;
	limit_stack.limit[limit_stack.top].end = high;
	while (limit_stack.top >= 0) {
		low = limit_stack.limit[limit_stack.top].begin;
		high = limit_stack.limit[limit_stack.top].end;
		limit_stack.top--;
		if (low < high) {
			pivotpos = partition(
				L,low,high
			);
			if (limit_stack.top < MAXSIZE - 1) {
				limit_stack.top++;
			}
			else {
				printf("辅助栈已满，请增大辅助栈的长度后再尝试！\n");
				return;
			}
			limit_stack.limit[limit_stack.top].begin = low;
			limit_stack.limit[limit_stack.top].end = pivotpos - 1;
			
			if (limit_stack.top < MAXSIZE-1) {
				limit_stack.top++;
			}
			else {
				printf("辅助栈已满，请增大辅助栈的长度后再尝试！\n");
				return;
			}
			limit_stack.limit[limit_stack.top].begin = pivotpos + 1;
			limit_stack.limit[limit_stack.top].end = high;
		}
	}
}
//**********非递归快速排序（辅助队列实现，更加贴近递归快速排序的扫描排序情况）**************
void quick_sort_2(SqList *L, int low, int high) {
	int pivotpos;
	LimitQueue limit_queue;
	limit_queue.font = 0;
	limit_queue.rear = 0;
	limit_queue.limit[limit_queue.rear].begin = low;
	limit_queue.limit[limit_queue.rear].end = high;
	limit_queue.rear++;
	while (limit_queue.rear != limit_queue.font) {
		low = limit_queue.limit[limit_queue.font].begin;
		high = limit_queue.limit[limit_queue.font].end;
		limit_queue.font = (limit_queue.font + 1) % MAXSIZE;
		if (low < high) {
			pivotpos = partition(
				L, low, high
			);
			limit_queue.limit[limit_queue.rear].begin = low;
			limit_queue.limit[limit_queue.rear].end = pivotpos - 1;
			if ((limit_queue.rear + 1) % MAXSIZE != limit_queue.font ) {
				limit_queue.rear = (limit_queue.rear + 1) % MAXSIZE;
			}else {
				printf("辅助队列已满，请增大辅助队列的长度后再尝试！\n");
				return;
			}
			limit_queue.limit[limit_queue.rear].begin = pivotpos + 1;
			limit_queue.limit[limit_queue.rear].end = high;
			if ((limit_queue.rear + 1) % MAXSIZE != limit_queue.font) {
				limit_queue.rear = (limit_queue.rear + 1) % MAXSIZE;
			}else {
				printf("辅助队列已满，请增大辅助队列的长度后再尝试！\n");
				return;
			}
		}
	}
}
void quick_sort(SqList *L) {
	quick_sort_recurrence(L, 1, L->length-1);
	//quick_sort_1(L, 1, L->length - 1);
	//quick_sort_2(L, 1, L->length - 1);
};//****************快速排序-end****************

void exchange_sort() {
	SqList L1 = { { 0,21, 32,46, 40, 80, 69, 90, 94 }, 9 }; 
	SqList L = { { 0,25, 84,21,47,15, 27,68, 35,20 }, 10 };
	SqList L3 = { { 0, 46, 79,56, 38,40, 84 }, 7 };
	SqList L4 = { { 0,5,9,17,21,23,25,30 }, 8 };
	SqList L5 = { { 0,21,25,5,17,9,23,30 }, 8 };
	SqList L6 = { { 0,25,23,30,17,21,5,9 }, 8 };
	SqList L7 = { { 0,21,9,17,30,25,23,5 }, 8 };

	for (int i = 1; i < L.length; i++) {
		printf("%d, ", L.r[i].key);
	}
	printf("(排序前)\n");
	//bubble_sort(&L);
	quick_sort(&L);
	for (int i = 1; i <  L.length; i++) {
		printf("%d, ", L.r[i].key);
	}
	printf("(排序后)\n");

};