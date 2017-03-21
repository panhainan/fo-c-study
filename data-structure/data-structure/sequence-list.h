/*
Status（操作结果）:
0：操作失败，
1：操作成功.
*/
#define FAIL 0
#define SUCCESS 1 //操作成功
#define OVERFOLW -1 //定义 -1 为 OVERFOLW 错误
#define DEFAULT_CAPACITY 10			//默认初始容量大小
#define CAPACITY_INCREAM_MULTPLE 1.5	//默认扩容倍数

#define DEFAULT_ELEM_LENGTH 10			//默认元素的字符长度（用于打印元素）
#define ELEM_LEN_INCREAM_MULTPLE 2	//默认元素字符长度的增长倍数（用于打印元素）
typedef void* ElemType;
typedef int Status;

typedef struct SequenceList{
	ElemType *elem;	//存储空间基址
	int length;		//当前长度
	int capacity;	//容量
} SqList;
/*	初始化线性表	*/
Status initSqList(SqList *L);
/*	线性表扩容	*/
Status increamCapacity(SqList *L);
/*	在线性表末尾插入元素	*/
Status insertSqList(SqList *L, ElemType elem);
/*	在线性表指定位置插入元素	*/
Status insertSqListI(SqList *L, ElemType elem, int position);
/*	删除线性表末尾的元素	*/
Status deleteSqList(SqList *L, ElemType *elem);
/*	删除线性表指定位置的元素	*/
Status deleteSqListI(SqList *L, ElemType *elem, int position);
/*	清空线性表	*/
Status clearSqList(SqList *L);
/*	打印线性表	*/
Status printSqList(SqList *L);