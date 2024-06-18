// 十字链表

// 十字链表相关定义如下：

typedef int ElemType;

//// 非零元素结点结构
typedef struct OLNode
{
    int row, col;
    ElemType value;
    struct OLNode *right, *down;
} OLNode, *OLink;

//// 十字链表结构
typedef struct
{
    OLink *rowhead, *colhead;
    int rows, cols, nums;
} CrossList, *PCrossList;

// 1）实现十字链表的初始化操作：

int init_cross_list(PCrossList L, const ElemType *A, int m, int n);
// 其中 L 指向 CrossList 结构，且各成员已被初始化为0；
// A 为 ElemType 类型数组中第一个元素的地址，元素的个数为 m×n 个，按行优先存储（即A[0] 为十字链表第1行第1列的元素；
// A[1] 为第1行第2列的元素，A[n] 为第2行第1列的元素，A[n + 1] 为第2行第2个元素）；
// m 表示十字链表的行数，n 表示十字链表的列数。
// init_cross_list 函数将 ElemType 数组中非0元素保存到十字链表中，函数返回非0元素的个数。

// 2）实现十字链表的删除操作：

int del_cross_list(PCrossList L, ElemType k);
// 其中 L 指向 要处理的 CrossList 结构，k 为要删除的元素；
// del_cross_list 函数删除十字链表中所有值为 k 的结点，并返回删除结点的个数。

#include "crosslist.h"
#include <stdio.h>
#include <stdlib.h>

int init_cross_list(PCrossList L, const ElemType *A, int m, int n)
{
}

int del_cross_list(PCrossList L, ElemType k)
{
}