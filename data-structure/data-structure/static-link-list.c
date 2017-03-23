#include<stdio.h>
#include "static-link-list.h"


Status initStaticLinkList(StaticLinkList L) {
	int i;
	for (i = 0; i < MAXSIZE - 1; i++) {
		L[i].cur = i+1;
	}
	L[MAXSIZE - 1].cur = 0;
	return SUCCESS;
}

int mallocStaticLinkList(StaticLinkList L) {
	int index = L[0].cur;
	//备用链表非空，则返回分配的节点下标，否则返回0
	if (L[0].cur)
		L[0].cur = L[index].cur;
	return index;
}
void freeStaticLinkList(StaticLinkList L, int position) {
	//仅仅是释放这个位置到备用链表，并没有完成对该位置元素的删除操作善后。
	L[position].cur = L[0].cur;
	L[0].cur = position;
}

