// 顺序表 删除重复
//
// 编写算法，在一非递减的顺序表L中，删除所有值相等的多余元素。要求时间复杂度为O(n)，空间复杂度为O(1)。
//
// 函数原型如下：
void del_dupnum(SeqList *L)
    //
    // 相关定义如下：
    struct _seqlist
{
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;

#include "list.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

void del_dupnum(SeqList *L)
{
    int prev = -1; // 前指针
    int curr = 0;  // 当前指针

    while (curr <= L->last) // 需要整体来看，整体完成删除节点的工作
    {
        if (L->elem[prev] == L->elem[curr])
        {
            curr++;
        }
        else
        {
            prev++;
            L->elem[prev] = L->elem[curr];
            curr++;
        }
    }

    L->last = prev;
}