#define FALSE 0		//真
#define TRUE 1		//假
#define FAIL_NULL  -3	//操作失败（未初始化LinkList）
#define FAIL_LIMIT -2	//操作失败（参数越界）
#define FAIL_EMPTY -1	//操作失败（数组为空）
#define FAIL 0		//操作失败
#define SUCCESS 1	//操作成功
#define MAXSIZE 1000	//链表的最大长度
typedef int ElemType;
typedef int Status;
//设定 StaticList[0].cur为当前备用链表指向节点的位置；StaticList[MAXSIZE-1].cur为当前链表头结点的位置
typedef struct StaticLinkList {
	ElemType data;
	int cur;
} StaticLinkListNode, StaticLinkList[MAXSIZE];
/* 初始化 */
Status initStaticLinkList(StaticLinkList L);
/* 分配备用空间 */
int mallocStaticLinkList(StaticLinkList L);
/* 释放占用空间为备用空间 */
void freeStaticLinkList(StaticLinkList L, int position);
/* 插入（尾插法） */
Status addStaticLinkList(StaticLinkList L);
/* 修改 */
Status setStaticLinkList(StaticLinkList L);
/* 获取 */
ElemType getStaticLinkList(StaticLinkList L, int position);
/* 删除 */
ElemType removeStaticLinkList(StaticLinkList L, int position);

int lengthStaticLinkList(StaticLinkList L);
