#include<stdio.h>
#define MAXSIZE 20	//定义顺序表最大长度
#define TRUE 1  
#define FALSE 0 
typedef int KeyType;	//关键字类型
typedef char InfoType;	//其他数据项类型
typedef struct {
	KeyType key;	//关键字项
	InfoType otherinfo;	//其他数据项
} RedType;
typedef struct {
	RedType r[MAXSIZE + 1];	//r[0]闲置或用作哨兵单元
	int length;	//顺序表长度
}SqList;	//顺序表类型

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
		if (flag == FALSE) {
			return;	//本趟冒泡没有发生交换，说明表已经有序了，结束排序
		}
	}
};//*********冒泡排序-end***********

//****************快速排序-begin****************
int partition(SqList *L, int low, int high) {
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
	return low;	//返回存放枢纽的最终位置
}
void quick_sort1(SqList *L, int low, int high) {
	if (low < high) {	//递归跳出条件
		int pivotpos = partition(L, low, high);	//划分
		//依次对两个子表进行递归排序
		quick_sort1(L, low, pivotpos - 1);	
		quick_sort1(L, pivotpos + 1, high);
	}
}
void quick_sort(SqList *L) {
	quick_sort1(L, 1, L->length);
};//****************快速排序-end****************

void main() {
	int length = 8;
	SqList L = {
		{
			{ 0,0 },{ 21,'a' },{ 32,'b' },{ 46,'d' },{ 40,'c' },
			{ 80,'f' },{ 69,'e' },{ 90,'g' },{ 94,'h' }
		},
		length
	};
	//bubble_sort(&L);
	quick_sort(&L);
	for (int i = 1; i <= length; i++) {
		printf("{%d,%c}, ", L.r[i].key, L.r[i].otherinfo);
	}
	printf("\n");

};