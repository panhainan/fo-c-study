#include<stdio.h>
#include"sequence-list.h"
void main() {
	SqList L;
	if (initSqList(&L)) {
		for (int i = 0; i < 12; i++) {
			ElemType e = i+10000000;
			insertSqList(&L, e);
		}
		printSqList(&L);
		insertSqListI(&L, 4, 4);
		printSqList(&L);
	}
}