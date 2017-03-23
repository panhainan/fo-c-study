/*
Status（操作结果）:
0：操作失败，
1：操作成功.
*/
#define FALSE 0		//真
#define TRUE 1		//假
#define FAIL_LIMIT -2	//操作失败（参数越界）
#define FAIL_EMPTY -1	//操作失败（数组为空）
#define FAIL 0		//操作失败
#define SUCCESS 1	//操作成功
#define OVERFOLW -1 //定义 -1 为 OVERFOLW 错误
#define DEFAULT_CAPACITY 10			//默认初始容量大小
#define CAPACITY_INCREAM_MULTPLE 1.5	//默认扩容倍数

#define DEFAULT_ELEM_LENGTH 10			//默认元素的字符长度（用于打印元素）
#define ELEM_LEN_INCREAM_MULTPLE 1.5	//默认元素字符长度的增长倍数（用于打印元素）
typedef int ElemType;	//目前只能支持固定类型的元素，因为在打印时需要做处理
typedef int Status;

typedef struct SequenceList{
	ElemType *elem;	//存储空间基址
	int length;		//当前长度
	int capacity;	//容量
} *SqList;
/*	新建线性表	*/
SqList newSqList();
/*	线性表扩容	*/
void increamSqListCapacity(SqList L);
/*	判断线性表是否为空	*/
Status isSqListEmpty(SqList L);
/*	判断位置是否在线性表范围内	*/
Status isInSqListLimit(SqList L, int position);
/*	在线性表末尾插入元素	*/
Status addSqList(SqList L, ElemType elem);
/*	修改线性表指定位置(实际为数组position-1位置)的元素《==》	*/
Status setSqList(SqList L, ElemType elem, int position);
/*	删除线性表末尾的元素	*/
Status removeSqList(SqList L, ElemType *elem);
/*	删除线性表指定位置(实际为数组position-1位置)的元素	*/
Status removeSqListI(SqList L, ElemType *elem, int position);
/*	获取线性表末尾的元素	*/
Status lastSqList(SqList L, ElemType *elem);
/*	获取线性表指定位置(实际为数组position-1位置)的元素	*/
Status getSqList(SqList L, ElemType *elem, int position);
/*	清空线性表	*/
Status clearSqList(SqList L);
/*	打印线性表	*/
Status printSqList(SqList L);