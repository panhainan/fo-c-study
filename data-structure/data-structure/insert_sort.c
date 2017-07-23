#include<stdio.h>
#define MAXSIZE 20	//定义顺序表最大长度
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
//*********插入排序**********************
//*********希尔插入排序(不稳定)***********
void sheel_insert_sort(SqList *L) {
	int i, j, dk;
	int len = L->length;
	for (dk = len / 2; dk >= 1; dk = dk / 2) {	//每扫描一次，对增量dk进行一次折半处理处理
		for (i = dk + 1; i <= len; ++i) {
			if (L->r[i].key < L->r[i - dk].key) {
				L->r[0]=L->r[i];	//暂存在r[0]
				for (j = i - dk; j > 0 && L->r[0].key < L->r[j].key; j -= dk)
					L->r[j + dk] = L->r[j];	//记录后移
				L->r[j + dk] = L->r[0];	//插入到正确位置
			}
		}
	}
}
//*********折半插入排序(稳定)***********
void half_insert_sort(SqList *L) {
	int i, j, low, high, mid, len = L->length;
	for (i = 2; i <= len; i++) {
		L->r[0] = L->r[i];	//暂存在r[0]
		low = 1;
		high = i - 1;
		while (low <= high) {
			mid = (low + high) / 2;	//折半
			if (L->r[mid].key > L->r[0].key)	
				high = mid - 1;	//插入点在低半区
			else
				low = mid + 1;	//插入点在高半区
		}
		for (j = i - 1; j >= high + 1; --j)
			L->r[j + 1] = L->r[j];	//记录后移
		L->r[high + 1]= L->r[0];	//插入到正确位置
	}
}
//*********直接插入排序(稳定)***********
void direct_insert_sort(SqList *L) {
	int i, j, len = L->length;
	for (i = 2; i <= len; i++) {
		if (L->r[i].key < L->r[i-1].key) {
			L->r[0] = L->r[i];		//L->r[0]用作哨兵位
			L->r[i] = L->r[i - 1];
			for (j = i - 2; L->r[0].key < L->r[j].key; --j) {
				L->r[j + 1] = L->r[j];		//记录后移
			}
			L->r[j + 1] = L->r[0];			//插入到正确位置
		}
	}
};

void insert_sort_test() {
	int length = 8;
	SqList L = { 
		{ 
			{ 0,0 },{ 21,'a' },{ 32,'b' },{ 46,'d' },{ 40,'c' },
			{ 80,'f' },{ 69,'e' },{ 90,'g' },{ 94,'h' }
		},
		length 
	};
	//direct_insert_sort(&L);
	//half_insert_sort(&L);
	sheel_insert_sort(&L);
	for (int i = 1; i <= length; i++){
		printf("{%d,%c}, ", L.r[i].key, L.r[i].otherinfo);
	}
	printf("\n");
	
};