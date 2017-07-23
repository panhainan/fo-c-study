#define FALSE 0		//真
#define TRUE 1		//假
#define FAIL_NULL  -3	//操作失败（未初始化LinkList）
#define FAIL_LIMIT -2	//操作失败（参数越界）
#define FAIL_EMPTY -1	//操作失败（数组为空）
#define FAIL 0		//操作失败
#define SUCCESS 1	//操作成功
typedef int ElemType;
typedef int Status;
typedef struct LinkListNode{
	ElemType data;
	struct LinkListNode *next;
} LNode, *LinkList;


/*	新建线性表（带头结点，头结点存储的值为线性表长度）	*/
LinkList newLinkList();
/*	判断线性表是否为空	*/
Status isLinkListEmpty(LinkList L);
/*	判断位置是否在线性表范围内	*/
Status isInLinkListLimit(LinkList L, int position);
/*	在线性表末尾插入元素（尾插法）	*/
Status addLinkList(LinkList L, ElemType elem);
/*	在线性表头部插入元素（头插法）	*/
Status addLinkListHead(LinkList L, ElemType elem);
/*	在线性表指定位置插入元素	*/
Status addLinkListI(LinkList L, ElemType elem, int position);
/*	修改线性表指定位置的元素	*/
Status setLinkList(LinkList L, ElemType elem, int position);
/*	删除线性表末尾的元素	*/
Status removeLinkList(LinkList L, ElemType *elem);
/*	删除线性表指定位置的元素	*/
Status removeLinkListI(LinkList L, ElemType *elem, int position);
/*	获取线性表末尾的元素	*/
Status lastLinkList(LinkList L, ElemType *elem);
/*	获取线性表指定位置(实际为数组position-1位置)的元素	*/
Status getLinkList(LinkList L, ElemType *elem, int position);
/*	清空线性表	*/
Status freeLinkList(LinkList L);
/*	打印线性表(注意：这里只实现ElemType=int的打印，对于其他类型的则需要自行修改print函数的代码。)	*/
Status printLinkList(LinkList L);